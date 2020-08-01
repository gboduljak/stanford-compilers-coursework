#include <assert.h>
#include <stdio.h>
#include "cgen-class-definition.h"
#include <vector>
#include <map>
#include <algorithm>
#include <set>
#include <queue>
#include <functional>
#include <string>

enum Basicness     {Basic, NotBasic};
#define TRUE 1
#define FALSE 0

class CgenClassTable;
typedef CgenClassTable *CgenClassTableP;

class CgenNode;
typedef CgenNode *CgenNodeP;


class CgenClassTable : public SymbolTable<Symbol,CgenNode> {
private:
   List<CgenNode> *nds;
   ostream& str;
   int stringclasstag;
   int intclasstag;
   int boolclasstag;
   int objectclasstag;
   int ioclasstag;
   int objectparenttag;
   int current_classtag = 0;

   std::map<Symbol, std::vector<Symbol>>              class_attributes;
   std::map<Symbol, std::set<Symbol>>                 class_directly_owned_attributes;
   std::map<Symbol, std::map<Symbol, attr_class*>>    class_attribute_defs;
   std::map<Symbol, std::vector<Symbol>>              class_methods;
   std::map<Symbol, std::map<Symbol, method_class*>>  class_method_defs;
   std::map<Symbol, std::map<Symbol, Symbol>>         class_method_defined_in;
   std::map<Symbol, Class_>                           class_definitions;
   std::map<Symbol, std::map<Symbol, int>>            dispatch_offsets_of_class_methods;
   std::map<Symbol, cgen_class_definition>            cgen_class_definition_of;
   std::vector<Symbol>                                cgen_class_names;
   std::map<Symbol, int>                              classtag_of;
   std::vector<Symbol>                                inheritance_tree_traversal;
   std::map<Symbol, Symbol>                           inheritance_parent;

// The following methods emit code forttt
// constants and global declarations.

   void code_global_data();
   void code_global_text();
   void code_bools(int);
   void code_select_gc();
   void code_constants();
   int next_classtag();

// The following creates an inheritance graph from
// a list of classes.  The graph is implemented as
// a tree of `CgenNode', and class names are placed
// in the base class symbol table.

   void install_basic_classes();
   void install_class(CgenNodeP nd);
   void install_classes(Classes cs);
   void build_inheritance_tree();
   void traverse_inheritance_tree();
   void set_relations(CgenNodeP nd);

   void construct_protObjs();
   int get_classtag_for(Symbol);
   void attach_inherited_definitions_to(Class_, Class_);
   void register_properties_and_definitions_of(Class_);
   cgen_class_definition construct_cgen_class_definition(Class_);
   void emit_default_value_for_attr_type(Symbol);
   void emit_protObj_from(cgen_class_definition);
   void emit_nameTab();
   void emit_objTab();
   void emit_protObjs();
   void emit_dispatch_table(cgen_class_definition);
   void emit_dispatch_tables();
   void emit_initialiser(cgen_class_definition);
   void emit_initialisers();
   void emit_method(cgen_class_definition, method_class*);
   void emit_methods(cgen_class_definition);
   void emit_class_methods();
   void emit_parentTab();

public:
   CgenClassTable(Classes, ostream& str);
   void code();
   CgenNodeP root();
};


class CgenNode : public class__class {
private: 
   CgenNodeP parentnd;                        // Parent of class
   List<CgenNode> *children;                  // Children of class
   Basicness basic_status;                    // `Basic' if class is basic
                                              // `NotBasic' otherwise
   Class_ c;

public:
   CgenNode(Class_ c,
            Basicness bstatus,
            CgenClassTableP class_table);

   void add_child(CgenNodeP child);
   List<CgenNode> *get_children() { return children; }
   void set_parentnd(CgenNodeP p);
   CgenNodeP get_parentnd() { return parentnd; }
   int basic() { return (basic_status == Basic); }
   Class_ get_class_definition() { return c; }
};

class BoolConst 
{
 private: 
  int val;
 public:
  BoolConst(int);
  void code_def(ostream&, int boolclasstag);
  void code_ref(ostream&) const;
};

