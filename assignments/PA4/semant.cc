

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include "semant.h"
#include "utilities.h"
#include <symtab.h>
#include <vector>
#include <map>
#include <queue>
#include <set>

extern int semant_debug;
extern char *curr_filename;

void raise_error();
Symbol type_check(method_class* method);
Symbol type_check(attr_class* attr);
Symbol type_check(Feature f);
std::map<Symbol, attr_class*> get_class_attributes(Class_ class_definition);

SymbolTable<Symbol,Symbol> *objects_table;
ClassTable *class_table;

//////////////////////////////////////////////////////////////////////
//                        TYPING ENVIRONMENT
//////////////////////////////////////////////////////////////////////

Symbol current_class_name;
Class_ current_class_definition;

std::map<Symbol, method_class*> current_class_methods;
std::map<Symbol, attr_class*> current_class_attrs;

std::map<Symbol, std::map<Symbol, method_class*>> class_methods;
std::map<Symbol, std::map<Symbol, attr_class*>> class_attrs;

//////////////////////////////////////////////////////////////////////
//
// Symbols
//
// For convenience, a large number of symbols are predefined here.
// These symbols include the primitive type and method names, as well
// as fixed names used by the runtime system.
//
//////////////////////////////////////////////////////////////////////
static Symbol 
    arg,
    arg2,
    Bool,
    concat,
    cool_abort,
    copy,
    Int,
    in_int,
    in_string,
    IO,
    length,
    Main,
    main_meth,
    No_class,
    No_type,
    Object,
    out_int,
    out_string,
    prim_slot,
    self,
    SELF_TYPE,
    Str,
    str_field,
    substr,
    type_name,
    val;

//
// Initializing the predefined symbols.
//
static void initialize_constants(void)
{
    arg         = idtable.add_string("arg");
    arg2        = idtable.add_string("arg2");
    Bool        = idtable.add_string("Bool");
    concat      = idtable.add_string("concat");
    cool_abort  = idtable.add_string("abort");
    copy        = idtable.add_string("copy");
    Int         = idtable.add_string("Int");
    in_int      = idtable.add_string("in_int");
    in_string   = idtable.add_string("in_string");
    IO          = idtable.add_string("IO");
    length      = idtable.add_string("length");
    Main        = idtable.add_string("Main");
    main_meth   = idtable.add_string("main");
    //   _no_class is a symbol that can't be the name of any 
    //   user-defined class.
    No_class    = idtable.add_string("_no_class");
    No_type     = idtable.add_string("_no_type");
    Object      = idtable.add_string("Object");
    out_int     = idtable.add_string("out_int");
    out_string  = idtable.add_string("out_string");
    prim_slot   = idtable.add_string("_prim_slot");
    self        = idtable.add_string("self");
    SELF_TYPE   = idtable.add_string("SELF_TYPE");
    Str         = idtable.add_string("String");
    str_field   = idtable.add_string("_str_field");
    substr      = idtable.add_string("substr");
    type_name   = idtable.add_string("type_name");
    val         = idtable.add_string("_val");
}

////////////////////////////////////////////////////////////////////
//                          CLASS TABLE
////////////////////////////////////////////////////////////////////

ClassTable::ClassTable(Classes classes) : semant_errors(0) , error_stream(cerr) {
   this->install_basic_classes();
}

void ClassTable::install_basic_classes() {

    // The tree package uses these globals to annotate the classes built below.
   // curr_lineno  = 0;
    Symbol filename = stringtable.add_string("<basic class>");
    
    // The following demonstrates how to create dummy parse trees to
    // refer to basic Cool classes.  There's no need for method
    // bodies -- these are already built into the runtime system.
    
    // IMPORTANT: The results of the following expressions are
    // stored in local variables.  You will want to do something
    // with those variables at the end of this method to make this
    // code meaningful.

    // 
    // The Object class has no parent class. Its methods are
    //        abort() : Object    aborts the program
    //        type_name() : Str   returns a string representation of class name
    //        copy() : SELF_TYPE  returns a copy of the object
    //
    // There is no need for method bodies in the basic classes---these
    // are already built in to the runtime system.

    Class_ Object_class =
	class_(Object, 
	       No_class,
	       append_Features(
			       append_Features(
					       single_Features(method(cool_abort, nil_Formals(), Object, no_expr())),
					       single_Features(method(type_name, nil_Formals(), Str, no_expr()))),
			       single_Features(method(copy, nil_Formals(), SELF_TYPE, no_expr()))),
	       filename);

    // 
    // The IO class inherits from Object. Its methods are
    //        out_string(Str) : SELF_TYPE       writes a string to the output
    //        out_int(Int) : SELF_TYPE            "    an int    "  "     "
    //        in_string() : Str                 reads a string from the input
    //        in_int() : Int                      "   an int     "  "     "
    //
    Class_ IO_class = 
	class_(IO, 
	       Object,
	       append_Features(
			       append_Features(
					       append_Features(
							       single_Features(method(out_string, single_Formals(formal(arg, Str)),
										      SELF_TYPE, no_expr())),
							       single_Features(method(out_int, single_Formals(formal(arg, Int)),
										      SELF_TYPE, no_expr()))),
					       single_Features(method(in_string, nil_Formals(), Str, no_expr()))),
			       single_Features(method(in_int, nil_Formals(), Int, no_expr()))),
	       filename);  

    //
    // The Int class has no methods and only a single attribute, the
    // "val" for the integer. 
    //
    Class_ Int_class =
	class_(Int, 
	       Object,
	       single_Features(attr(val, prim_slot, no_expr())),
	       filename);

    //
    // Bool also has only the "val" slot.
    //
    Class_ Bool_class =
	class_(Bool, Object, single_Features(attr(val, prim_slot, no_expr())),filename);

    //
    // The class Str has a number of slots and operations:
    //       val                                  the length of the string
    //       str_field                            the string itself
    //       length() : Int                       returns length of the string
    //       concat(arg: Str) : Str               performs string concatenation
    //       substr(arg: Int, arg2: Int): Str     substring selection
    //       
    Class_ Str_class =
	class_(Str, 
	       Object,
	       append_Features(
			       append_Features(
					       append_Features(
							       append_Features(
									       single_Features(attr(val, Int, no_expr())),
									       single_Features(attr(str_field, prim_slot, no_expr()))),
							       single_Features(method(length, nil_Formals(), Int, no_expr()))),
					       single_Features(method(concat, 
								      single_Formals(formal(arg, Str)),
								      Str, 
								      no_expr()))),
			       single_Features(method(substr, 
						      append_Formals(single_Formals(formal(arg, Int)), 
								     single_Formals(formal(arg2, Int))),
						      Str, 
						      no_expr()))),
	       filename);

    this->class_lookup[Object] = Object_class;
    this->class_lookup[IO] = IO_class;
    this->class_lookup[Int] = Int_class;
    this->class_lookup[Bool] = Bool_class;
    this->class_lookup[Str] = Str_class;
}

bool ClassTable::install_custom_classes(Classes classes) {
    for (int i = classes->first(); classes->more(i); i = classes->next(i))
    {
        Class_ current_class = classes->nth(i);
        Symbol class_name = current_class->get_name();
        if (
            class_name == Int    ||
            class_name == Bool   ||
            class_name == Str    ||
            class_name == Object ||
            class_name == SELF_TYPE
        ) 
        {
            semant_error(current_class) << "Redefinition of " << class_name << " is not allowed. \n";
            return false;
        }
        else if (this->class_lookup.find(class_name) != this->class_lookup.end())
        {
            semant_error(current_class) << "Class " << class_name << " was previously defined.\n";
            return false;
        }
        else
            this->class_lookup[class_name] = current_class;
    }
    return true;
}

bool ClassTable::build_inheritance_graph() {

    for (auto const& x : this->class_lookup)
    {
        Symbol class_name = x.first;

        if (class_name == Object)
            continue;

        Class_ class_definition = x.second;
        Symbol class_parent_name = class_definition->get_parent_name();

        parent_type_of[class_name] = class_parent_name;

        if( 
            class_parent_name == Str ||  
            class_parent_name == Int || 
            class_parent_name == Bool ||
            class_parent_name == SELF_TYPE
        )
        {
            this->semant_error(class_definition)
                << "Class "
                << class_definition->get_name()
                << " cannot inherit class "
                << class_parent_name
                << ".\n";
            return false;
        }
        
        if (this->class_lookup.find(class_parent_name) == this->class_lookup.end())
        {
            semant_error(x.second) << "Class "
                << class_name 
                << " inherits from an undefined class "
                << class_parent_name
                << ".\n";
            return false;
        }

        if (this->inheritance_graph.find(class_parent_name) == this->inheritance_graph.end()) 
            this->inheritance_graph[class_parent_name] = std::vector<Symbol>();
    
        this->inheritance_graph[class_parent_name].push_back(class_name);
    } 
    return true;
}

enum SymbolColor { gray, black, white };
std::map<Symbol, SymbolColor> color_of;

bool ClassTable::inheritance_dfs(Symbol symbol) {
    color_of[symbol] = gray;
    for (auto const& x : inheritance_graph[symbol])
    {
        if(color_of[x] == gray)
        {
            semant_error() << "There exists an (in) direct circular dependency between: ";
            symbol->print(semant_error());
            semant_error() << " and ";
            x->print(semant_error());
            return false;
        }
        else 
        {
            if (!inheritance_dfs(x))
                return false;
        }
    }
    color_of[symbol] = black;
    return true;
}

bool ClassTable::is_inheritance_graph_acyclic() {

    color_of.clear();
    for (auto const& x : this->class_lookup)
        color_of[x.first] = white;

    for (auto const& x : this->class_lookup)
        if (color_of[x.first] == white) 
            if (!this->inheritance_dfs(x.first))
                return false;

    return true;
}


bool ClassTable::is_class_table_valid() {
    if (!this->is_inheritance_graph_acyclic())
        return false;

    if (!this->is_type_defined(Main)) {
        semant_error() << "Class Main is not defined.\n";
        return false;
    }
    return true;
}

bool ClassTable::is_subtype_of(Symbol candidate, Symbol desired_type) {
    if (candidate == No_type)
        return true;
        
    if (candidate == SELF_TYPE) {
        if (desired_type == SELF_TYPE)
            return true;
        else
            candidate = current_class_name; 
    }

    Symbol current = candidate;

    while (current != Object && current != desired_type)
        current = parent_type_of[current];

    return current == desired_type;
}

Symbol ClassTable::least_common_ancestor_type(Symbol lhs, Symbol rhs) {
    if (lhs == SELF_TYPE)
        lhs = current_class_name; 
    if (rhs == SELF_TYPE)
        rhs = current_class_name;

    Symbol current_lhs = lhs;
    Symbol current_rhs = rhs;
    std::set<Symbol> rhs_ancestors;
    
    while (current_rhs != Object) 
    {
        rhs_ancestors.insert(current_rhs);
        current_rhs = parent_type_of[current_rhs];
    }
    while (current_lhs != Object) 
    {
        if (rhs_ancestors.find(current_lhs)!=rhs_ancestors.end())
            return current_lhs;
        current_lhs = parent_type_of[current_lhs];
    }
    return Object;
}

Symbol ClassTable::get_parent_type_of(Symbol symbol) {
    if (this->parent_type_of.find(symbol) == this->parent_type_of.end())
        return No_type;

    return parent_type_of[symbol];
}

bool ClassTable::is_type_defined(Symbol symbol) {
    return class_lookup.find(symbol) != class_lookup.end();
}

bool ClassTable::is_primitive(Symbol symbol) {
    return (
        symbol == Object ||
        symbol == IO     ||
        symbol == Int    ||
        symbol == Bool   ||
        symbol == Str
    );
}
////////////////////////////////////////////////////////////////////
//                          CLASS UTILITIES
////////////////////////////////////////////////////////////////////

std::map<Symbol, method_class*> get_class_methods(Class_ class_definition) {
    std::map<Symbol, method_class*> class_methods;
    Symbol class_name = class_definition->get_name();
    Features class_features = class_definition->get_features();

    for (int i = class_features->first(); class_features->more(i); i = class_features->next(i)) 
    {
        Feature feature = class_features->nth(i);

        if (!feature->is_method())
            continue;

        method_class* method = static_cast<method_class*>(feature);
        Symbol method_name = method->get_name();
        
        if (class_methods.find(method_name) != class_methods.end())
        {
            ostream& error_stream = class_table->semant_error(class_definition);
            error_stream << "The method :";
            method_name->print(error_stream);
            error_stream << " has already been defined!\n";
        }
        else
        {
            class_methods[method_name] = method;
        }
    }
    return class_methods;
}

method_class* get_class_method(Symbol class_name, Symbol method_name) {
    std::map<Symbol, method_class*> methods = class_methods[class_name];

    if (methods.find(method_name) == methods.end())
        return nullptr;

    return methods[method_name];
}


attr_class* get_class_attr(Symbol class_name, Symbol attr_name) {
    std::map<Symbol, attr_class*> attrs = class_attrs[class_name];

    if (attrs.find(attr_name) == attrs.end())
        return nullptr;

    return attrs[attr_name];
}

void ensure_class_attributes_are_unique(Class_ class_definition) {
    std::set<Symbol> class_attrs;
    Symbol class_name = class_definition->get_name();
    Features class_features = class_definition->get_features();

    for (int i = class_features->first(); class_features->more(i); i = class_features->next(i)) 
    {
        Feature feature = class_features->nth(i);

        if (!feature->is_attr())
            continue;

        attr_class* attr = static_cast<attr_class*>(feature);
        Symbol attr_name = attr->get_name();
        
        if (class_attrs.find(attr_name) != class_attrs.end())
        {
            class_table->semant_error(class_definition)
                << "The attribute :"
                << attr_name
                << " has already been defined!\n";
        }
        class_attrs.insert(attr_name);
    }
}

std::map<Symbol, attr_class*> get_class_attributes(Class_ class_definition) {
    std::map<Symbol, attr_class*> class_attrs;
    Symbol class_name = class_definition->get_name();
    Features class_features = class_definition->get_features();

    for (int i = class_features->first(); class_features->more(i); i = class_features->next(i)) 
    {
        Feature feature = class_features->nth(i);

        if (!feature->is_attr())
            continue;

        attr_class* attr = static_cast<attr_class*>(feature);
        Symbol attr_name = attr->get_name();
        class_attrs[attr_name] = attr;
    }

    return class_attrs;
}

////////////////////////////////////////////////////////////////////
//                          TYPECHECKING
////////////////////////////////////////////////////////////////////

void build_attribute_scopes(Class_ current_class) {
    objects_table->enterscope();
    std::map<Symbol, attr_class*> attrs = get_class_attributes(current_class);
    for(const auto &x : attrs) {
        attr_class* attr_definition = x.second;
        objects_table->addid(
            attr_definition->get_name(), 
            new Symbol(attr_definition->get_type())
        );
    }

    if(current_class->get_name() == Object)
        return;

    Symbol parent_type_name = class_table->get_parent_type_of(current_class->get_name());
    Class_ parent_definition = class_table->class_lookup[parent_type_name];
    build_attribute_scopes(parent_definition);
}

void process_attr(Class_ current_class, attr_class* attr) {
    if (get_class_attr(current_class->get_name(), attr->get_name()) != nullptr)
    {
        class_table->semant_error(current_class_definition) 
            << " Attribute " 
            << attr->get_name()
            << " is an attribute of an inherited class.\n";
        raise_error();
    }

    Symbol parent_type_name = class_table->get_parent_type_of(current_class->get_name());
    if (parent_type_name == No_type)
        return;

    Class_ parent_definition = class_table->class_lookup[parent_type_name];
    process_attr(parent_definition, attr);
}

void process_method(Class_ current_class, method_class* original_method, method_class* parent_method) {
    if (parent_method == nullptr)
        return;

    Formals original_method_args = original_method->get_formals();
    Formals parent_method_args = parent_method->get_formals();
    
    int original_formal_ix = 0;
    int parent_formal_ix = 0;
    
    if(original_method->get_return_type() != parent_method->get_return_type()) {
        class_table->semant_error(current_class) 
            << "In redefined method " 
            << original_method->get_name() 
            << ", the return type " 
            << original_method->get_return_type() 
            << " differs from the ancestor method return type "
            << parent_method->get_return_type() 
            << ".\n";
    }

    int original_methods_formals = 0;
    int parent_method_formals = 0;

    while (original_method_args->more(original_methods_formals))
        original_methods_formals = original_method_args->next(original_methods_formals);

    while (parent_method_args->more(parent_method_formals))
        parent_method_formals = parent_method_args->next(parent_method_formals);

    if (original_methods_formals != parent_method_formals) {
        class_table->semant_error(current_class) 
            << "In redefined method " 
            << original_method->get_name() 
            << ", the number of arguments " 
            << "(" << original_methods_formals << ")"
            << " differs from the ancestor method's "
            << "number of arguments "
            << "(" << parent_method_formals << ")"
            << ".\n";
    }

    while (
        original_method_args->more(original_formal_ix) &&
        parent_method_args->more(parent_formal_ix)
    )
    {
        Formal original_formal = original_method_args->nth(original_formal_ix);
        Formal parent_formal = parent_method_args->nth(parent_formal_ix);

        if (original_formal->get_type() != parent_formal->get_type()) {
            class_table->semant_error(current_class) 
                << "In redefined method " 
                << original_method->get_name() 
                << ", the return type of argument " 
                << original_formal->get_type() 
                << " differs from the corresponding ancestor method argument return type "
                << parent_formal->get_type() 
                << ".\n";
        }

        original_formal_ix = original_method_args->next(original_formal_ix);
        parent_formal_ix = parent_method_args->next(parent_formal_ix);
    }

    Symbol parent_type_name = class_table->get_parent_type_of(current_class->get_name());

    if (parent_type_name == No_type)
        return;

    Class_ parent_class_definition = class_table->class_lookup[parent_type_name];

    process_method(
        parent_class_definition, 
        original_method,
        get_class_method(
            parent_type_name, 
            original_method->get_name()
        )
    );
}

void register_class_and_its_methods(Class_ class_definition) {
    class_methods[class_definition->get_name()] = get_class_methods(class_definition);
    class_attrs[class_definition->get_name()] = get_class_attributes(class_definition);
}

void type_check(Class_ next_class) {
    current_class_name = next_class->get_name();
    current_class_definition = next_class;
    current_class_methods = get_class_methods(next_class);
    ensure_class_attributes_are_unique(next_class);
    current_class_attrs = get_class_attributes(next_class);

    objects_table = new SymbolTable<Symbol, Symbol>();
    objects_table->enterscope();
    objects_table->addid(self, new Symbol(current_class_definition->get_name()));

    build_attribute_scopes(next_class);
    
    for (const auto &x : current_class_methods) {
        process_method(next_class, x.second, x.second);
    }

    for (const auto &x : current_class_attrs) {
        Symbol parent_type_name = class_table->get_parent_type_of(current_class_name);
        Class_ parent_definition = class_table->class_lookup[parent_type_name];
        process_attr(parent_definition, x.second);
    }

    for (const auto &x : current_class_attrs) {
        x.second->type_check();
    }

    for (const auto &x : current_class_methods) {
        x.second->type_check();
    }

    objects_table->exitscope();
}

Symbol object_class::type_check() {
    if (name == self) {
        this->set_type(SELF_TYPE);
        return SELF_TYPE;
    }

    Symbol* object_type = objects_table->lookup(name);
    if (object_type != nullptr){
        this->set_type(*object_type);
        return *object_type;
    }

    this->set_type(Object);
    class_table->semant_error(this)
        << "The referenced object "
        << name
        << " is undefined in relevant scopes.\n";
    return Object;
}

Symbol no_expr_class::type_check() {
    this->set_type(No_type);
    return No_type;
}

Symbol isvoid_class::type_check() {
    e1->type_check();
    this->set_type(Bool);
    return Bool;
}

Symbol new__class::type_check() {
    if(type_name != SELF_TYPE && !class_table->is_type_defined(type_name))
    {
        this->set_type(Object);
        class_table->semant_error(this)
            << "Tried to instantiate an object of undefined type: "
            << type_name
            << " .\n";
        return Object;
    }
    this->set_type(type_name);
    return type_name;
}

Symbol comp_class::type_check() {
    Symbol expr_type = e1->type_check();
    if (expr_type == Bool) {
        this->set_type(expr_type);
        return expr_type;
    }
    this->set_type(Object);
    class_table->semant_error(this)
        << "Argument of 'not' has type " 
        << expr_type 
        << " instead of Bool.\n";
    return Object;
}

Symbol leq_class::type_check() {
    Symbol left_type = e1->type_check();
    Symbol right_type = e2->type_check();

    if(left_type == Int && right_type == Int) {
        this->set_type(Bool);
        return Bool;
    }
    else
    {
        this->set_type(Object);
        class_table->semant_error(this) 
            << "Expected both arguments of operator <= to be of type Int"
            << " but got arguments of types "
            << left_type
            << " and "
            << right_type
            << ".\n";
    }
    return this->get_type();
}

Symbol eq_class::type_check() {
    Symbol left_type = e1->type_check();
    Symbol right_type = e2->type_check();
    
    bool is_left_type_primitive = left_type == Int || left_type == Bool || left_type == Str;
    bool is_right_type_primitive = right_type == Int || right_type == Bool || right_type == Str;

    if ((is_left_type_primitive && is_right_type_primitive) && left_type != right_type)
    {
        class_table->semant_error(this) << "Illegal comparison with a basic type.\n";
    }

    this->set_type(Bool);
    return Bool;
}

Symbol lt_class::type_check() {
    Symbol left_type = e1->type_check();
    Symbol right_type = e2->type_check();

    if(left_type == Int && right_type == Int) {
        this->set_type(Bool);
        return Bool;
    }
    else
    {
        this->set_type(Object);
        class_table->semant_error(this) 
            << "Expected both arguments of operator < to be of type Int"
            << " but got arguments of types "
            << left_type
            << " and "
            << right_type
            << ".\n";
    }
    return this->get_type();
}

Symbol neg_class::type_check() {
    Symbol inner_expr_type = e1->type_check();
    if (inner_expr_type != Int)
    {
        this->set_type(Object);
        class_table -> semant_error(this) 
            << "Argument of the operator '~' has type " 
            << inner_expr_type 
            << " instead of Int.\n";
        return Object;
    }
    this->set_type(Int);
    return Int;
}

Symbol divide_class::type_check() {
    Symbol left_type = e1->type_check();
    Symbol right_type = e2->type_check();
    if(left_type == Int && right_type == Int)
        this->set_type(Int);
    else
    {
        class_table->semant_error(this) 
            << "Expected both arguments of operator / to be of type Int"
            << " but got arguments of types "
            << left_type
            << " and "
            << right_type
            << ".\n";
        this->set_type(Object);
    }
    return this->get_type();
}

Symbol mul_class::type_check() {
    Symbol left_type = e1->type_check();
    Symbol right_type = e2->type_check();
    if(left_type == Int && right_type == Int)
        this->set_type(Int);
    else
    {
        class_table->semant_error(this) 
            << "Expected both arguments of operator * to be of type Int"
            << " but got arguments of types "
            << left_type
            << " and "
            << right_type
            << ".\n";
        this->set_type(Object);
    }
    return this->get_type();
}

Symbol sub_class::type_check() {
    Symbol left_type = e1->type_check();
    Symbol right_type = e2->type_check();
    if(left_type == Int && right_type == Int)
        this->set_type(Int);
    else
    {
        class_table->semant_error(this) 
            << "Expected both arguments of operator - to be of type Int"
            << " but got arguments of types "
            << left_type
            << " and "
            << right_type
            << ".\n";
        this->set_type(Object);
    }
    return this->get_type();
}

Symbol plus_class::type_check() {
    Symbol left_type = e1->type_check();
    Symbol right_type = e2->type_check();
    if(left_type == Int && right_type == Int)
        this->set_type(Int);
    else
    {
        class_table->semant_error(this) 
            << "Expected both arguments of operator +to be of type Int"
            << " but got arguments of types "
            << left_type
            << " and "
            << right_type
            << ".\n";
        this->set_type(Object);
    }
    return this->get_type();
}

Symbol let_class::type_check() {
    objects_table->enterscope();
    if (identifier == self)
        class_table->semant_error(this) << "'self' cannot be bound in a 'let' expression.\n";

    Symbol init_type = init->type_check();

    if (type_decl != SELF_TYPE && !class_table->is_type_defined(type_decl))
        class_table->semant_error(this) 
            << "Type " 
            << type_decl 
            << " of let-bound identifier "
            << identifier 
            << " is undefined.\n";

    else if (init_type != No_type && !class_table->is_subtype_of(init_type, type_decl))
        class_table->semant_error(this)
            << "Inferred type " 
            << init_type 
            << " in initialization of " 
            << identifier 
            << " is not compatible with identifier's declared type " 
            << type_decl << ".\n";
            
    objects_table->addid(identifier, new Symbol(type_decl));
    this->set_type(body->type_check());
    objects_table->exitscope();
    return type;
}

Symbol block_class::type_check() {
    Symbol last_body_expr_type = Object;
    for (int i = body->first(); body->more(i); i = body->next(i))
        last_body_expr_type = body->nth(i)->type_check();
    this->set_type(last_body_expr_type);
    return last_body_expr_type;
}

Symbol branch_class::type_check() {
    Symbol declaration_type = type_decl;
    Symbol declaration_id = name;
    if (declaration_id == self) {
        class_table->semant_error(this) << "'self' cannot be bound in a 'branch' expression.";
    }
    objects_table->enterscope();
    objects_table->addid(declaration_id, new Symbol(declaration_type));
    Symbol branch_expr_type = expr->type_check();
    this->set_type(branch_expr_type);
    objects_table->exitscope();
    return branch_expr_type;
}

Symbol typcase_class::type_check() {
    Symbol expr_type = expr->type_check();

    std::set<Symbol> branch_declaration_types;
    Symbol branch_result_type = Object;

    for (int i = cases->first(); cases->more(i); i = cases->next(i)) {
        branch_class* branch = static_cast<branch_class*>(cases->nth(i));
        Symbol branch_declaration_type = branch->get_declaration_type();
        if (branch_declaration_types.find(branch_declaration_type) != branch_declaration_types.end())
            class_table->semant_error(branch) 
                << "Duplicate branch type" 
                << branch_declaration_type 
                << " in case statement.\n";
        else
            branch_declaration_types.insert(branch_declaration_type);

        if (i == cases->first())
            branch_result_type = branch->type_check();
        else
            branch_result_type = class_table->least_common_ancestor_type(
                branch_result_type,
                branch->type_check()
            );
    }

    this->set_type(branch_result_type);
    return branch_result_type;
}


Symbol loop_class::type_check() {
    Symbol pred_type = pred->type_check();
    Symbol body_type = body->type_check();

    if (pred_type != Bool)
    {
        class_table->semant_error(this) 
            << "Expected the predicate of while to be of type Bool"
            << " but got the predicate of type "
            << pred_type
            << " instead .\n";
    }

    this->set_type(Object);
    return Object; 
}

Symbol cond_class::type_check() {
    Symbol pred_type = pred->type_check();
    Symbol then_type = then_exp->type_check();
    Symbol else_type = else_exp->type_check();

    if (pred_type != Bool)
    {
        class_table->semant_error(this) 
            << "Expected the predicate of if to be of type Bool"
            << " but got the predicate of type "
            << pred_type
            << " instead .\n";
    }

    Symbol cond_type = class_table->least_common_ancestor_type(then_type, else_type);
    this->set_type(cond_type);
    return cond_type;
}

method_class* lookup_method_in_chain(Symbol class_name, Symbol method_name) {  
    if (class_name == No_type)
        return nullptr;

    method_class* definition = get_class_method(class_name, method_name);
    if (definition)
        return definition;

    Symbol parent_type_name = class_table->get_parent_type_of(class_name);
    return lookup_method_in_chain(parent_type_name, method_name);
}

method_class* lookup_method(Symbol class_name, Symbol method_name) {  
    method_class* chain_method = lookup_method_in_chain(class_name, method_name);

    if (chain_method)
        return chain_method;

    if (class_table->is_primitive(class_name)) 
    {
        return get_class_method(class_name, method_name);
    }
    return nullptr;
}

Symbol dispatch_class::type_check() {

    Symbol expr_type = expr->type_check();

    if (expr_type != SELF_TYPE && !class_table->is_type_defined(expr_type)) {

        class_table->semant_error(this) 
            << "Dispatch on undefined class " 
            << expr_type 
            << ".\n";

        this->set_type(Object);
        return type;
    }
    
    Symbol expr_type_name = expr_type == SELF_TYPE ? current_class_name : expr_type;
    method_class* method_definition = lookup_method(expr_type_name, name);
  
    if (!method_definition) 
    {
        class_table->semant_error(this) 
            << "Dispatch to undefined method " 
            << name 
            << ".\n";
        
        this->set_type(Object);
        return Object;
    }

    Symbol declared_return_type = method_definition->get_return_type();
    Formals declared_method_args = method_definition->get_formals();
    Expressions actual_method_args = this->actual;

    int declared_method_args_count = 0;
    int actual_method_args_count = 0;

    while (declared_method_args->more(declared_method_args_count))
        declared_method_args_count = declared_method_args->next(declared_method_args_count);
    while (actual_method_args->more(actual_method_args_count))
        actual_method_args_count = actual_method_args->next(actual_method_args_count);

    if (declared_method_args_count != actual_method_args_count) {
        class_table->semant_error(this) 
            << "In the dispatch to method " 
            << method_definition->get_name() 
            << ", given number of arguments " 
            << "(" << actual_method_args_count << ")"
            << " differs from the declared method's "
            << "number of arguments "
            << "(" << declared_method_args_count << ")"
            << ".\n";
    }

    int declared_argument_ix = declared_method_args->first();
    int actual_argument_ix = actual_method_args->first();

    Formal declared_argument;
    Expression actual_argument;
    bool is_dispatch_valid = true;

    while (
        actual_method_args->more(actual_argument_ix) && 
        declared_method_args->more(declared_argument_ix)
    )
    {
        actual_argument = actual_method_args->nth(actual_argument_ix);
        declared_argument = declared_method_args->nth(declared_argument_ix);

        Symbol actual_argument_type = actual_argument->type_check();
        Symbol declared_argument_type = declared_argument->get_type();

        if (!class_table->is_subtype_of(actual_argument_type, declared_argument_type)) {
            is_dispatch_valid = false;

            class_table->semant_error(this) 
                << "In the dispatch of the method " 
                << method_definition->get_name() 
                << ", type "
                << actual_argument_type 
                << " of provided argument " 
                << declared_argument->get_name() 
                << " is not compatible with the corresponding signature type " 
                << declared_argument_type 
                << " .\n";
        }

        actual_argument_ix = actual_method_args->next(actual_argument_ix);
        declared_argument_ix = declared_method_args->next(declared_argument_ix);
    }
    
    if (!is_dispatch_valid)
    {
        this->set_type(Object);
        return Object;
    }

    Symbol dispatch_type = declared_return_type == SELF_TYPE ? expr_type : declared_return_type;
    this->set_type(dispatch_type);
    return dispatch_type;
}

Symbol static_dispatch_class::type_check() {
    Symbol expr_type = expr->type_check();

    if (this->type_name != SELF_TYPE && !class_table->is_type_defined(type_name)) {
        class_table->semant_error(this) 
            << "Static dispatch on undefined class " 
            << type_name 
            << ".\n";

        this->set_type(Object);
        return Object;
    }
    if (expr_type != SELF_TYPE && !class_table->is_type_defined(expr_type)) {
        this->set_type(Object);
        return type;
    }

    bool is_dispatch_valid = true;

    if (!class_table->is_subtype_of(expr_type, this->type_name)) {
        is_dispatch_valid = true;
        class_table -> semant_error(this) 
            << "Expression type " 
            << expr_type 
            << " is not compatible with declared static dispatch type " 
            << this->type_name 
            <<  ".\n";
    }
    
    method_class* method_definition = lookup_method(type_name, name);
    if (!method_definition) 
    {
        class_table->semant_error(this) 
            << "Dispatch to undefined method " 
            << name 
            << ".\n";
        
        this->set_type(Object);
        return Object;
    }

    Symbol declared_return_type = method_definition->get_return_type();
    Formals declared_method_args = method_definition->get_formals();
    Expressions actual_method_args = this->actual;

    int declared_method_args_count = 0;
    int actual_method_args_count = 0;

    while (declared_method_args->more(declared_method_args_count))
        declared_method_args_count = declared_method_args->next(declared_method_args_count);
    while (actual_method_args->more(actual_method_args_count))
        actual_method_args_count = actual_method_args->next(actual_method_args_count);

    if (declared_method_args_count != actual_method_args_count) {
        class_table->semant_error(this) 
            << "In the dispatch to method " 
            << method_definition->get_name() 
            << ", given number of arguments " 
            << "(" << actual_method_args_count << ")"
            << " differs from the declared method's "
            << "number of arguments "
            << "(" << declared_method_args_count << ")"
            << ".\n";
    }

    int declared_argument_ix = declared_method_args->first();
    int actual_argument_ix = actual_method_args->first();
    Formal declared_argument;
    Expression actual_argument;

    while (
        actual_method_args->more(actual_argument_ix) && 
        declared_method_args->more(declared_argument_ix)
    )
    {
        actual_argument = actual_method_args->nth(actual_argument_ix);
        declared_argument = declared_method_args->nth(declared_argument_ix);

        Symbol actual_argument_type = actual_argument->type_check();
        Symbol declared_argument_type = declared_argument->get_type();

        if (!class_table->is_subtype_of(actual_argument_type, declared_argument_type)) {
            is_dispatch_valid = false;

            class_table->semant_error(this) 
                << "In the dispatch of the method " 
                << method_definition->get_name() 
                << ", type "
                << actual_argument_type 
                << " of provided argument " 
                << declared_argument->get_name() 
                << " is not compatible with the corresponding signature type " 
                << declared_argument_type 
                << " .\n";
        }

        actual_argument_ix = actual_method_args->next(actual_argument_ix);
        declared_argument_ix = declared_method_args->next(declared_argument_ix);
    }
    
    if (!is_dispatch_valid)
    {
        this->set_type(Object);
        return Object;
    }

    Symbol dispatch_type = declared_return_type == SELF_TYPE ? expr_type : declared_return_type;
    this->set_type(dispatch_type);
    return dispatch_type;
}

Symbol assign_class::type_check() {
    Symbol identifier = name;
    Expression assign_expr = expr;

    if (identifier == self) {
        class_table->semant_error(this) << "Cannot assign to 'self'" << ".\n";
        return Object;
    }

    Symbol* identifier_type = objects_table->lookup(identifier);

    if (!identifier_type) {
        class_table->semant_error(this) 
            << "Tried to assign undeclared identifier " 
            << identifier 
            << ".\n";

        this->set_type(Object);
        return this->get_type();
    }

    Symbol assign_expr_type = assign_expr->type_check();

    bool does_assign_conform_declared = class_table->is_subtype_of(
        assign_expr_type, 
        *identifier_type
    );

    if (!does_assign_conform_declared) {
        class_table->semant_error(this) 
            << "The identifier " 
            << identifier 
            << " has been declared as "
            << *identifier_type
            << " but assigned with incompatible type "
            << assign_expr_type
            << ".\n";

        this->set_type(Object);
        return Object;
    }

    this->set_type(assign_expr_type);
    return assign_expr_type;
}


Symbol method_class::type_check() {
    objects_table->enterscope();
    std::set<Symbol> defined_arguments;

    for (int formal_ix = formals->first(); formals->more(formal_ix); formal_ix = formals->next(formal_ix))
    {
        Formal argument = formals->nth(formal_ix);
        Symbol argument_name = argument->get_name();
        Symbol argument_type = argument->get_type();

        if(argument_name == self)
            class_table->semant_error(argument) << "'self' cannot be the name of a method argument.\n";
        else if(defined_arguments.find(argument_name) != defined_arguments.end())
            class_table->semant_error(argument) 
                << "The argument " 
                << argument_name 
                << " in the signature of method "
                << get_name()
                << " has already been defined.\n";
        else
        {
           defined_arguments.insert(argument_name);
        }
        
        if (!class_table->is_type_defined(argument_type))
            class_table->semant_error(argument) 
                << "The argument " 
                << argument_name 
                << " in the signature of method "
                << get_name()
                << " has undefined type "
                << argument_type
                << " .\n";
        else
            objects_table->addid(argument_name, new Symbol(argument_type));
    }

    Symbol expected_return_type = get_return_type();
    Symbol actual_return_type = this->expr->type_check();

    if (!class_table->is_subtype_of(actual_return_type, expected_return_type))
    {
        class_table->semant_error(this)
            << "Inferred return type "
            << actual_return_type << 
            " of the method " 
            << this->get_name() 
            << " is not compatible with declared return type " 
            << expected_return_type 
            << ".\n";
    }
    
    objects_table->exitscope();
    return this->get_return_type();
}

Symbol attr_class::type_check() {
    Expression init_expr = this->get_init_expr();
    Symbol init_expr_type = init_expr->type_check();
    init_expr_type = init_expr_type == SELF_TYPE ? current_class_name : init_expr_type;
    
    if (dynamic_cast<const no_expr_class*>(init_expr) != nullptr)
        return this->get_type();

    if (this->get_name() == self) {
        class_table->semant_error(this) << "'self' cannot be the name of an attribute.\n";
        return this->get_type();
    }
    
    if (!class_table->is_type_defined(this->get_type())) {
        class_table->semant_error(init_expr)
            << "The attribute "
            << this->get_name()
            << " is defined as "
            << this->get_type()
            << " but type "
            << this->get_type()
            << " is undefined. \n";
        return this->get_type();
    }

    bool does_init_type_match_defined_type = class_table->is_subtype_of(
        init_expr_type,
        this->get_type()
    );

    if(!does_init_type_match_defined_type) {
        class_table->semant_error(init_expr)
            << "The attribute "
            << this->get_name()
            << " is defined as "
            << this->get_type()
            << " but is initialized with "
            << init_expr_type
            << ".\n";
    }
    return this->get_type();
}

Symbol int_const_class::type_check() {
    this->set_type(Int);
    return Int;
}

Symbol bool_const_class::type_check() {
    this->set_type(Bool);
    return Bool;
}

Symbol string_const_class::type_check() {
    this->set_type(Str);
    return Str;
}

////////////////////////////////////////////////////////////////////
//
// semant_error is an overloaded function for reporting errors
// during semantic analysis.  There are three versions:
//
//    ostream& ClassTable::semant_error()                
//
//    ostream& ClassTable::semant_error(Class_ c)
//       print line number and filename for `c'
//
//    ostream& ClassTable::semant_error(Symbol filename, tree_node *t)  
//       print a line number and filename
//
///////////////////////////////////////////////////////////////////

ostream& ClassTable::semant_error(Class_ c)
{                                                             
    return semant_error(c->get_filename(),c);
}    

ostream& ClassTable::semant_error(Symbol filename, tree_node *t)
{
    error_stream << filename << ":" << t->get_line_number() << ": ";
    return semant_error();
}

ostream& ClassTable::semant_error(tree_node *t) {
    error_stream << current_class_definition->get_filename() << ":" << t->get_line_number() << ": ";
    return semant_error();
}

ostream& ClassTable::semant_error()                  
{                                                 
    semant_errors++;                            
    return error_stream;
} 

/*   This is the entry point to the semantic checker.

     Your checker should do the following two things:

     1) Check that the program is semantically correct
     2) Decorate the abstract syntax tree with type information
        by setting the `type' field in each Expression node.
        (see `tree.h')

     You are free to first do 1), make sure you catch all semantic
     errors. Part 2) can be done in a second stage, when you want
     to build mycoolc.
 */

void raise_error() {
  cerr << "Compilation halted due to static semantic errors." << endl;
  exit(1);
}


void program_class::semant()
{
    initialize_constants();

    /* ClassTable constructor may do some semantic analysis */
    class_table = new ClassTable(classes);
    objects_table = new SymbolTable<Symbol, Symbol>();

    if(!class_table->install_custom_classes(classes))
        raise_error();
    if(!class_table->build_inheritance_graph())
        raise_error();
    if(!class_table->is_class_table_valid())
        raise_error();
    if (class_table->errors())
        raise_error();
    for (const auto &x : class_table->class_lookup)
        register_class_and_its_methods(x.second);
    for (int i = classes->first(); classes->more(i); i = classes->next(i))
        type_check(classes->nth(i));
    if (class_table->errors())
        raise_error();
}