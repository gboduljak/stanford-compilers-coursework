
//**************************************************************
//
// Code generator SKELETON
//
// Read the comments carefully. Make sure to
//    initialize the base class tags in
//       `CgenClassTable::CgenClassTable'
//
//    Add the label for the dispatch tables to
//       `IntEntry::code_def'
//       `StringEntry::code_def'
//       `BoolConst::code_def'
//
//    Add code to emit everyting else that is needed
//       in `CgenClassTable::code'
//
//
// The files as provided will produce code to begin the code
// segments, declare globals, and emit constants.  You must
// fill in the rest.
//
//**************************************************************

#include "cgen.h"
#include "cgen_gc.h"
#include <vector>
#include <map>
#include <algorithm>
#include <set>
#include <queue>

extern void emit_string_constant(ostream& str, char *s);
extern int cgen_debug;

//
// Three symbols from the semantic analyzer (semant.cc) are used.
// If e : No_type, then no code is generated for e.
// Special code is generated for new SELF_TYPE.
// The name "self" also generates code different from other references.
//
//////////////////////////////////////////////////////////////////////
//
// Symbols
//
// For convenience, a large number of symbols are predefined here.
// These symbols include the primitive type and method names, as well
// as fixed names used by the runtime system.
//
//////////////////////////////////////////////////////////////////////
Symbol 
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

static char *gc_init_names[] =
  { "_NoGC_Init", "_GenGC_Init", "_ScnGC_Init" };
static char *gc_collect_names[] =
  { "_NoGC_Collect", "_GenGC_Collect", "_ScnGC_Collect" };


//  BoolConst is a class that implements code generation for operations
//  on the two booleans, which are given global names here.
BoolConst falsebool(FALSE);
BoolConst truebool(TRUE);

//*********************************************************
//
// Define method for code generation
//
// This is the method called by the compiler driver
// `cgtest.cc'. cgen takes an `ostream' to which the assembly will be
// emmitted, and it passes this and the class list of the
// code generator tree to the constructor for `CgenClassTable'.
// That constructor performs all of the work of the code
// generator.
//
//*********************************************************

void program_class::cgen(ostream &os) 
{
  // spim wants comments to start with '#'
  os << "# start of generated code\n";

  initialize_constants();
  CgenClassTable *codegen_classtable = new CgenClassTable(classes,os);

  os << "\n# end of generated code\n";
}


//////////////////////////////////////////////////////////////////////////////
//
//  emit_* procedures
//
//  emit_X  writes code for operation "X" to the output stream.
//  There is an emit_X for each opcode X, as well as emit_ functions
//  for generating names according to the naming conventions (see emit.h)
//  and calls to support functions defined in the trap handler.
//
//  Register names and addresses are passed as strings.  See `emit.h'
//  for symbolic names you can use to refer to the strings.
//
//////////////////////////////////////////////////////////////////////////////

static void emit_load(char *dest_reg, int offset, char *source_reg, ostream& s)
{
  s << LW << dest_reg << " " << offset * WORD_SIZE << "(" << source_reg << ")" 
    << endl;
}

static void emit_store(char *source_reg, int offset, char *dest_reg, ostream& s)
{
  s << SW << source_reg << " " << offset * WORD_SIZE << "(" << dest_reg << ")"
      << endl;
}

static void emit_load_imm(char *dest_reg, int val, ostream& s)
{ s << LI << dest_reg << " " << val << endl; }

static void emit_load_address(char *dest_reg, char *address, ostream& s)
{ s << LA << dest_reg << " " << address << endl; }

static void emit_partial_load_address(char *dest_reg, ostream& s)
{ s << LA << dest_reg << " "; }

static void emit_load_bool(char *dest, const BoolConst& b, ostream& s)
{
  emit_partial_load_address(dest,s);
  b.code_ref(s);
  s << endl;
}

static void emit_load_string(char *dest, StringEntry *str, ostream& s)
{
  emit_partial_load_address(dest,s);
  str->code_ref(s);
  s << endl;
}

static void emit_load_int(char *dest, IntEntry *i, ostream& s)
{
  emit_partial_load_address(dest,s);
  i->code_ref(s);
  s << endl;
}

static void emit_move(char *dest_reg, char *source_reg, ostream& s)
{ s << MOVE << dest_reg << " " << source_reg << endl; }

static void emit_neg(char *dest, char *src1, ostream& s)
{ s << NEG << dest << " " << src1 << endl; }

static void emit_add(char *dest, char *src1, char *src2, ostream& s)
{ s << ADD << dest << " " << src1 << " " << src2 << endl; }

static void emit_addu(char *dest, char *src1, char *src2, ostream& s)
{ s << ADDU << dest << " " << src1 << " " << src2 << endl; }

static void emit_addiu(char *dest, char *src1, int imm, ostream& s)
{ s << ADDIU << dest << " " << src1 << " " << imm << endl; }

static void emit_div(char *dest, char *src1, char *src2, ostream& s)
{ s << DIV << dest << " " << src1 << " " << src2 << endl; }

static void emit_mul(char *dest, char *src1, char *src2, ostream& s)
{ s << MUL << dest << " " << src1 << " " << src2 << endl; }

static void emit_sub(char *dest, char *src1, char *src2, ostream& s)
{ s << SUB << dest << " " << src1 << " " << src2 << endl; }

static void emit_sll(char *dest, char *src1, int num, ostream& s)
{ s << SLL << dest << " " << src1 << " " << num << endl; }

static void emit_jalr(char *dest, ostream& s)
{ s << JALR << "\t" << dest << endl; }

static void emit_jal(char *address,ostream &s)
{ s << JAL << address << endl; }

static void emit_jal_without_address(ostream &s)
{ s << JAL; }

static void emit_return(ostream& s)
{ s << RET << endl; }

static void emit_gc_assign(ostream& s)
{ s << JAL << "_GenGC_Assign" << endl; }

static void emit_disptable_ref(Symbol sym, ostream& s)
{  s << sym << DISPTAB_SUFFIX; }

static void emit_init_ref(Symbol sym, ostream& s)
{ s << sym << CLASSINIT_SUFFIX; }

static void emit_label_ref(int l, ostream &s)
{ s << "label" << l; }

static void emit_cgen_definitionbj_ref(Symbol sym, ostream& s)
{ s << sym << PROTOBJ_SUFFIX; }

static void emit_method_ref(Symbol classname, Symbol methodname, ostream& s)
{ s << classname << METHOD_SEP << methodname; }


static void emit_label_def(int l, ostream &s)
{
  emit_label_ref(l,s);
  s << ":" << endl;
}

static void emit_beqz(char *source, int label, ostream &s)
{
  s << BEQZ << source << " ";
  emit_label_ref(label,s);
  s << endl;
}

static void emit_beq(char *src1, char *src2, int label, ostream &s)
{
  s << BEQ << src1 << " " << src2 << " ";
  emit_label_ref(label,s);
  s << endl;
}

static void emit_bne(char *src1, char *src2, int label, ostream &s)
{
  s << BNE << src1 << " " << src2 << " ";
  emit_label_ref(label,s);
  s << endl;
}

static void emit_bleq(char *src1, char *src2, int label, ostream &s)
{
  s << BLEQ << src1 << " " << src2 << " ";
  emit_label_ref(label,s);
  s << endl;
}

static void emit_blt(char *src1, char *src2, int label, ostream &s)
{
  s << BLT << src1 << " " << src2 << " ";
  emit_label_ref(label,s);
  s << endl;
}

static void emit_blti(char *src1, int imm, int label, ostream &s)
{
  s << BLT << src1 << " " << imm << " ";
  emit_label_ref(label,s);
  s << endl;
}

static void emit_bgti(char *src1, int imm, int label, ostream &s)
{
  s << BGT << src1 << " " << imm << " ";
  emit_label_ref(label,s);
  s << endl;
}

static void emit_branch(int l, ostream& s)
{
  s << BRANCH;
  emit_label_ref(l,s);
  s << endl;
}

//
// Push a register on the stack. The stack grows towards smaller addresses.
//
static void emit_push(char *reg, ostream& str)
{
  emit_store(reg,0,SP,str);
  emit_addiu(SP,SP,-4,str);
}

static void emit_pop(char *reg, ostream& str)
{
  emit_addiu(SP,SP,4,str);
  emit_load(reg,0,SP,str);
}

static void emit_pop_without_load(ostream& str)
{
  emit_addiu(SP,SP,4,str);
}
//
// Fetch the integer value in an Int object.
// Emits code to fetch the integer value of the Integer object pointed
// to by register source into the register dest
//
static void emit_fetch_int(char *dest, char *source, ostream& s)
{ emit_load(dest, DEFAULT_OBJFIELDS, source, s); }

//
// Emits code to store the integer value contained in register source
// into the Integer object pointed to by dest.
//
static void emit_store_int(char *source, char *dest, ostream& s)
{ emit_store(source, DEFAULT_OBJFIELDS, dest, s); }


static void emit_test_collector(ostream &s)
{
  emit_push(ACC, s);
  emit_move(ACC, SP, s); // stack end
  emit_move(A1, ZERO, s); // allocate nothing
  s << JAL << gc_collect_names[cgen_Memmgr] << endl;
  emit_addiu(SP,SP,4,s);
  emit_load(ACC,0,SP,s);
}

static void emit_gc_check(char *source, ostream &s)
{
  if (source != (char*)A1) emit_move(A1, source, s);
  s << JAL << "_gc_check" << endl;
}


static void emit_spill_activation_record_registers(ostream&str) {
  emit_addiu(SP, SP, -12, str);
  emit_store(FP, 3, SP, str);
  emit_store(SELF, 2, SP, str);
  emit_store(RA, 1, SP, str);
}

static void emit_restore_activation_record_registers(ostream&str) {
  emit_load(RA, 1, SP, str);
  emit_load(SELF, 2, SP, str);
  emit_load(FP, 3, SP, str);
  emit_addiu(SP, SP, 12, str);
}

static void emit_setup_frame_pointer(ostream&str) {
  emit_addiu(FP, SP, 4, str);
}

static void emit_setup_self_pointer(ostream&str) {
  emit_move(SELF, ACC, str);
}

static void emit_jump_to_label(int label, ostream &s) {
  s << "\tj\t";
  emit_label_ref(label, s);
  s << endl;
}

static void emit_not(char* dest, char* src, ostream &s) {
  s << "\tnot\t" << dest << "\t" << src << endl;
}

///////////////////////////////////////////////////////////////////////////////
//
// coding strings, ints, and booleans
//
// Cool has three kinds of constants: strings, ints, and booleans.
// This section defines code generation for each type.
//
// All string constants are listed in the global "stringtable" and have
// type StringEntry.  StringEntry methods are defined both for String
// constant definitions and references.
//
// All integer constants are listed in the global "inttable" and have
// type IntEntry.  IntEntry methods are defined for Int
// constant definitions and references.
//
// Since there are only two Bool values, there is no need for a table.
// The two booleans are represented by instances of the class BoolConst,
// which defines the definition and reference methods for Bools.
//
///////////////////////////////////////////////////////////////////////////////

//
// Strings
//
void StringEntry::code_ref(ostream& s)
{
  s << STRCONST_PREFIX << index;
}

//
// Emit code for a constant String.
// You should fill in the code naming the dispatch table.
//

void StringEntry::code_def(ostream& s, int stringclasstag)
{
  IntEntryP lensym = inttable.add_int(len);

  // Add -1 eye catcher
  s << WORD << "-1" << endl;

  code_ref(s);  s  << LABEL                                             // label
      << WORD << stringclasstag << endl                                 // tag
      << WORD << (DEFAULT_OBJFIELDS + STRING_SLOTS + (len+4)/4) << endl // size
      << WORD;

  s << STRINGNAME << DISPTAB_SUFFIX;

      s << endl;                                              // dispatch table
      s << WORD;  lensym->code_ref(s);  s << endl;            // string length
  emit_string_constant(s,str);                                // ascii string
  s << ALIGN;                                                 // align to word
}

//
// StrTable::code_string
// Generate a string object definition for every string constant in the 
// stringtable.
//
void StrTable::code_string_table(ostream& s, int stringclasstag)
{  
  for (List<StringEntry> *l = tbl; l; l = l->tl())
    l->hd()->code_def(s,stringclasstag);
}

//
// Ints
//
void IntEntry::code_ref(ostream &s)
{
  s << INTCONST_PREFIX << index;
}

//
// Emit code for a constant Integer.
// You should fill in the code naming the dispatch table.
//

void IntEntry::code_def(ostream &s, int intclasstag)
{
  // Add -1 eye catcher
  s << WORD << "-1" << endl;

  code_ref(s);  s << LABEL                                // label
      << WORD << intclasstag << endl                      // class tag
      << WORD << (DEFAULT_OBJFIELDS + INT_SLOTS) << endl  // object size
      << WORD; 

  s << INTNAME << DISPTAB_SUFFIX;

 /***** Add dispatch information for class Int ******/

      s << endl;                                          // dispatch table
      s << WORD << str << endl;                           // integer value
}


//
// IntTable::code_string_table
// Generate an Int object definition for every Int constant in the
// inttable.
//
void IntTable::code_string_table(ostream &s, int intclasstag)
{
  for (List<IntEntry> *l = tbl; l; l = l->tl())
    l->hd()->code_def(s,intclasstag);
}


//
// Bools
//
BoolConst::BoolConst(int i) : val(i) { assert(i == 0 || i == 1); }

void BoolConst::code_ref(ostream& s) const
{
  s << BOOLCONST_PREFIX << val;
}
  
//
// Emit code for a constant Bool.
// You should fill in the code naming the dispatch table.
//

void BoolConst::code_def(ostream& s, int boolclasstag)
{
  // Add -1 eye catcher
  s << WORD << "-1" << endl;

  code_ref(s);  s << LABEL                                  // label
      << WORD << boolclasstag << endl                       // class tag
      << WORD << (DEFAULT_OBJFIELDS + BOOL_SLOTS) << endl   // object size
      << WORD;
  
  s << BOOLNAME << DISPTAB_SUFFIX;
  
      s << endl;                                            // dispatch table
      s << WORD << val << endl;                             // value (0 or 1)
}

//////////////////////////////////////////////////////////////////////////////
//
//  CgenClassTable methods
//
//////////////////////////////////////////////////////////////////////////////

//***************************************************
//
//  Emit code to start the .data segment and to
//  declare the global names.
//
//***************************************************

void CgenClassTable::code_global_data()
{
  Symbol main    = idtable.lookup_string(MAINNAME);
  Symbol string  = idtable.lookup_string(STRINGNAME);
  Symbol integer = idtable.lookup_string(INTNAME);
  Symbol boolc   = idtable.lookup_string(BOOLNAME);

  str << "\t.data\n" << ALIGN;
  //
  // The following global names must be defined first.
  //
  str << GLOBAL << CLASSNAMETAB << endl;
  str << GLOBAL; emit_cgen_definitionbj_ref(main,str);    str << endl;
  str << GLOBAL; emit_cgen_definitionbj_ref(integer,str); str << endl;
  str << GLOBAL; emit_cgen_definitionbj_ref(string,str);  str << endl;
  str << GLOBAL; falsebool.code_ref(str);  str << endl;
  str << GLOBAL; truebool.code_ref(str);   str << endl;
  str << GLOBAL << INTTAG << endl;
  str << GLOBAL << BOOLTAG << endl;
  str << GLOBAL << STRINGTAG << endl;

  //
  // We also need to know the tag of the Int, String, and Bool classes
  // during code generation.
  //
  str << INTTAG << LABEL
      << WORD << intclasstag << endl;
  str << BOOLTAG << LABEL 
      << WORD << boolclasstag << endl;
  str << STRINGTAG << LABEL 
      << WORD << stringclasstag << endl;    
}


//***************************************************
//
//  Emit code to start the .text segment and to
//  declare the global names.
//
//***************************************************

void CgenClassTable::code_global_text()
{
  str << GLOBAL << HEAP_START << endl
      << HEAP_START << LABEL 
      << WORD << 0 << endl
      << "\t.text" << endl
      << GLOBAL;
  emit_init_ref(idtable.add_string("Main"), str);
  str << endl << GLOBAL;
  emit_init_ref(idtable.add_string("Int"),str);
  str << endl << GLOBAL;
  emit_init_ref(idtable.add_string("String"),str);
  str << endl << GLOBAL;
  emit_init_ref(idtable.add_string("Bool"),str);
  str << endl << GLOBAL;
  emit_method_ref(idtable.add_string("Main"), idtable.add_string("main"), str);
  str << endl;
}

void CgenClassTable::code_bools(int boolclasstag)
{
  falsebool.code_def(str,boolclasstag);
  truebool.code_def(str,boolclasstag);
}

void CgenClassTable::code_select_gc()
{
  //
  // Generate GC choice constants (pointers to GC functions)
  //
  str << GLOBAL << "_MemMgr_INITIALIZER" << endl;
  str << "_MemMgr_INITIALIZER:" << endl;
  str << WORD << gc_init_names[cgen_Memmgr] << endl;
  str << GLOBAL << "_MemMgr_COLLECTOR" << endl;
  str << "_MemMgr_COLLECTOR:" << endl;
  str << WORD << gc_collect_names[cgen_Memmgr] << endl;
  str << GLOBAL << "_MemMgr_TEST" << endl;
  str << "_MemMgr_TEST:" << endl;
  str << WORD << (cgen_Memmgr_Test == GC_TEST) << endl;
}


//********************************************************
//
// Emit code to reserve space for and initialize all of
// the constants.  Class names should have been added to
// the string table (in the supplied code, is is done
// during the construction of the inheritance graph), and
// code for emitting string constants as a side effect adds
// the string's length to the integer table.  The constants
// are emmitted by running through the stringtable and inttable
// and producing code for each entry.
//
//********************************************************

void CgenClassTable::code_constants()
{
  //
  // Add constants that are required by the code generator.
  //
  stringtable.add_string("");
  inttable.add_string("0");

  stringtable.code_string_table(str,stringclasstag);
  inttable.code_string_table(str,intclasstag);
  code_bools(boolclasstag);
}


CgenClassTable::CgenClassTable(Classes classes, ostream& s) : nds(NULL) , str(s)
{
    current_classtag = 5;
    stringclasstag = 4;
    intclasstag = 3;
    boolclasstag = 2;
    ioclasstag     = 1;
    objectclasstag = 0;
    objectparenttag = INVALIDPARENTTAG;

    enterscope();
    if (cgen_debug) cout << "Building CgenClassTable" << endl;
    install_basic_classes();
    install_classes(classes);
    build_inheritance_tree();
    code();
    exitscope();
}

void CgenClassTable::install_basic_classes()
{

// The tree package uses these globals to annotate the classes built below.
  //curr_lineno  = 0;
  Symbol filename = stringtable.add_string("<basic class>");

//
// A few special class names are installed in the lookup table but not
// the class list.  Thus, these classes exist, but are not part of the
// inheritance hierarchy.
// No_class serves as the parent of Object and the other special classes.
// SELF_TYPE is the self class; it cannot be redefined or inherited.
// prim_slot is a class known to the code generator.
//
  addid(No_class,
	new CgenNode(class_(No_class,No_class,nil_Features(),filename),
			    Basic,this));
  addid(SELF_TYPE,
	new CgenNode(class_(SELF_TYPE,No_class,nil_Features(),filename),
			    Basic,this));
  addid(prim_slot,
	new CgenNode(class_(prim_slot,No_class,nil_Features(),filename),
			    Basic,this));

// 
// The Object class has no parent class. Its methods are
//        cool_abort() : Object    aborts the program
//        type_name() : Str        returns a string representation of class name
//        copy() : SELF_TYPE       returns a copy of the object
//
// There is no need for method bodies in the basic classes---these
// are already built in to the runtime system.
//
  install_class(
   new CgenNode(
    class_(Object, 
	   No_class,
	   append_Features(
           append_Features(
           single_Features(method(cool_abort, nil_Formals(), Object, no_expr())),
           single_Features(method(type_name, nil_Formals(), Str, no_expr()))),
           single_Features(method(copy, nil_Formals(), SELF_TYPE, no_expr()))),
	   filename),
    Basic,this));

// 
// The IO class inherits from Object. Its methods are
//        out_string(Str) : SELF_TYPE          writes a string to the output
//        out_int(Int) : SELF_TYPE               "    an int    "  "     "
//        in_string() : Str                    reads a string from the input
//        in_int() : Int                         "   an int     "  "     "
//
   install_class(
    new CgenNode(
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
	   filename),	    
    Basic,this));

//
// The Int class has no methods and only a single attribute, the
// "val" for the integer. 
//
   install_class(
    new CgenNode(
     class_(Int, 
	    Object,
            single_Features(attr(val, prim_slot, no_expr())),
	    filename),
     Basic,this));

//
// Bool also has only the "val" slot.
//
    install_class(
     new CgenNode(
      class_(Bool, Object, single_Features(attr(val, prim_slot, no_expr())),filename),
      Basic,this));

//
// The class Str has a number of slots and operations:
//       val                                  ???
//       str_field                            the string itself
//       length() : Int                       length of the string
//       concat(arg: Str) : Str               string concatenation
//       substr(arg: Int, arg2: Int): Str     substring
//       
   install_class(
    new CgenNode(
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
	     filename),
        Basic,this));

}

// CgenClassTable::install_class
// CgenClassTable::install_classes
//
// install_classes enters a list of classes in the symbol table.
//
void CgenClassTable::install_class(CgenNodeP nd)
{
  Symbol name = nd->get_name();

  if (probe(name))
    {
      return;
    }

  // The class name is legal, so add it to the list of classes
  // and the symbol table.
  nds = new List<CgenNode>(nd,nds);
  addid(name,nd);
}

void CgenClassTable::install_classes(Classes cs)
{
  for(int i = cs->first(); cs->more(i); i = cs->next(i))
    install_class(new CgenNode(cs->nth(i),NotBasic,this));
}

//
// CgenClassTable::build_inheritance_tree
//
void CgenClassTable::build_inheritance_tree()
{
  for(List<CgenNode> *l = nds; l; l = l->tl())
      set_relations(l->hd());
}

//
// CgenClassTable::set_relations
//
// Takes a CgenNode and locates its, and its parent's, inheritance nodes
// via the class table.  Parent and child pointers are added as appropriate.
//
void CgenClassTable::set_relations(CgenNodeP nd)
{
  CgenNode *parent_node = probe(nd->get_parent());
  nd->set_parentnd(parent_node);
  parent_node->add_child(nd);
}

void CgenNode::add_child(CgenNodeP n)
{
  children = new List<CgenNode>(n,children);
}

void CgenNode::set_parentnd(CgenNodeP p)
{
  assert(parentnd == NULL);
  assert(p != NULL);
  parentnd = p;
}

void CgenClassTable::code()
{
  if (cgen_debug) cout << "coding global data" << endl;
  code_global_data();

  if (cgen_debug) cout << "choosing gc" << endl;
  code_select_gc();

  if (cgen_debug) cout << "coding constants" << endl;
  code_constants();

  this->traverse_inheritance_tree();
  this->construct_protObjs();
  this->emit_nameTab();
  this->emit_objTab();
  this->emit_parentTab();
  this->emit_dispatch_tables();
  this->emit_protObjs();

  if (cgen_debug) cout << "coding global text" << endl;
  code_global_text();

  this->emit_initialisers();
  this->emit_class_methods();
}

CgenNodeP CgenClassTable::root()
{
  return probe(Object);
}


///////////////////////////////////////////////////////////////////////
//
// CgenNode methods
//
///////////////////////////////////////////////////////////////////////

CgenNode::CgenNode(Class_ nd, Basicness bstatus, CgenClassTableP ct) :
   class__class((const class__class &) *nd),
   parentnd(NULL),
   children(NULL),
   basic_status(bstatus)
{ 
   this->c = nd;
   stringtable.add_string(name->get_string());
}

std::vector<Symbol> get_class_methods(Class_ class_definition) {
    std::vector<Symbol> class_methods;

    Symbol class_name = class_definition->get_name();
    Features class_features = class_definition->get_features();

    for (int i = class_features->first(); class_features->more(i); i = class_features->next(i)) 
    {
        Feature feature = class_features->nth(i);

        if (!feature->is_method())
            continue;

        method_class* method = static_cast<method_class*>(feature);
        Symbol method_name = method->get_name();
        class_methods.push_back(method_name);
    }
    return class_methods;
}

std::map<Symbol, method_class*> get_class_method_defs(Class_ class_definition) {
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
        class_methods[method_name] = method;
    }
    return class_methods;
}

std::vector<Symbol> get_class_attributes(Class_ class_definition) {
    std::vector<Symbol> class_attrs;

    Symbol class_name = class_definition->get_name();
    Features class_features = class_definition->get_features();

    for (int i = class_features->first(); class_features->more(i); i = class_features->next(i)) 
    {
        Feature feature = class_features->nth(i);

        if (!feature->is_attr())
            continue;

        attr_class* attr = static_cast<attr_class*>(feature);
        Symbol attr_name = attr->get_name();
        class_attrs.push_back(attr_name);
    }
    return class_attrs;
}

std::map<Symbol, attr_class*> get_class_attribute_defs(Class_ class_definition) {
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

void CgenClassTable::attach_inherited_definitions_to(Class_ class_definition, Class_ parent_definition) {
  class_definitions[class_definition->get_name()] = class_definition;

  auto inherited_methods = class_methods[parent_definition->get_name()];
  auto inherited_method_defs = class_method_defs[parent_definition->get_name()];
  auto inherited_attrs = class_attributes[parent_definition->get_name()];
  auto inherited_attr_defs = class_attribute_defs[parent_definition->get_name()];
  inheritance_parent[class_definition->get_name()] = parent_definition->get_name();

  for (auto const &x : inherited_methods) {
    class_methods[class_definition->get_name()].push_back(x);
    class_method_defined_in[class_definition->get_name()][x] = class_method_defined_in[parent_definition->get_name()][x];
  }
  for (auto const &x : inherited_method_defs) {
    class_method_defs[class_definition->get_name()][x.first] = x.second;
  }
  for (auto const &x : inherited_attrs) {
    class_attributes[class_definition->get_name()].push_back(x);
  }
  for (auto const &x : inherited_attr_defs) {
    class_attribute_defs[class_definition->get_name()][x.first] = x.second;
  }
}

void CgenClassTable::register_properties_and_definitions_of(Class_ class_definition) {
  auto method_names = get_class_methods(class_definition);
  auto attr_names = get_class_attributes(class_definition);
  auto method_defs = get_class_method_defs(class_definition);
  auto attr_defs = get_class_attribute_defs(class_definition);

  for (auto const &method_name : method_names) {
    class_methods[class_definition->get_name()].push_back(method_name);
    class_method_defined_in[class_definition->get_name()][method_name] = class_definition->get_name();
  }
  for (auto const &attr_name : attr_names) {
    class_attributes[class_definition->get_name()].push_back(attr_name);
    class_directly_owned_attributes[class_definition->get_name()].insert(attr_name);
  }
  for (auto const &attr_def : attr_defs) {
    class_attribute_defs[class_definition->get_name()][attr_def.first] = attr_def.second;
  }
  for (auto const &method_def : method_defs) {
    class_method_defs[class_definition->get_name()][method_def.first] = method_def.second;
  }
}

void CgenClassTable::traverse_inheritance_tree() {
  std::queue<CgenNodeP> q;
  q.push(root());
  classtag_of[Object] = get_classtag_for(Object);

  while(!q.empty()) {
    CgenNodeP class_graph_node = q.front();
    q.pop();

    Class_ class_definition = class_graph_node->get_class_definition();
    class_definitions[class_definition->get_name()] = class_definition;

    if(class_graph_node->get_parentnd())
    {
      auto parent_class_definition = (
        class_graph_node
          ->get_parentnd()
          ->get_class_definition()
      );
      attach_inherited_definitions_to(class_definition, parent_class_definition);
    }

    register_properties_and_definitions_of(class_definition);

    auto *class_child_node = class_graph_node->get_children();
    while (class_child_node) {
      auto subclass_node = class_child_node->hd();
      auto subclass = subclass_node->get_class_definition();
      auto subclass_name = subclass->get_name();
      classtag_of[subclass_name] = get_classtag_for(subclass_name);
      q.push(subclass_node);
      class_child_node = class_child_node->tl();
    }
  }
}

void CgenClassTable::construct_protObjs() {
    for (auto *class_node = this->nds; class_node; class_node = class_node->tl()) {
      auto class_definition = class_node->hd()->get_class_definition();
      auto class_name = class_definition->get_name();
      cgen_class_definition_of[class_name] = construct_cgen_class_definition(class_definition);

      for (auto const &x : cgen_class_definition_of[class_name].method_offset) {
        Symbol method_name = x.first;
        int method_offset = x.second;
        dispatch_offsets_of_class_methods[class_name][method_name] = method_offset;
      }

      cgen_class_names.push_back(class_name);
    }

    std::sort(
      std::begin(cgen_class_names), 
      std::end(cgen_class_names), 
      [&](auto const &l, auto const &r) {
        return cgen_class_definition_of[l].tag < cgen_class_definition_of[r].tag;
      }
    );
}

int CgenClassTable::next_classtag() { return current_classtag++; }
int CgenClassTable::get_classtag_for(Symbol type) {
  if (type == Object)
    return objectclasstag;
  else if (type == Bool)
    return boolclasstag;
  else if (type == Int)
    return intclasstag;
  else if (type == Str)
    return stringclasstag;
  else if (type == IO)
    return ioclasstag;
  else
    return next_classtag();
}

cgen_class_definition CgenClassTable::construct_cgen_class_definition(Class_ class_) {
  Symbol class_name = class_->get_name();
  cgen_class_definition cgen_definition;
  cgen_definition.name = class_name;
  cgen_definition.is_primitive_type = (
    cgen_definition.name == Object  ||
    cgen_definition.name == Bool    ||
    cgen_definition.name == Int     ||
    cgen_definition.name == Str     ||
    cgen_definition.name == IO
  );
  cgen_definition.tag = classtag_of[class_name];
  cgen_definition.dispatch_table = this->class_methods[class_name];
  cgen_definition.attrs = this->class_attributes[class_name];
  cgen_definition.method_definitions = this->class_method_defs[class_name];
  cgen_definition.attr_definitions = this->class_attribute_defs[class_name];

  int attr_offset = DEFAULT_OBJFIELDS, method_offset = 0;
  for (auto const &attr : cgen_definition.attrs)
      cgen_definition.attr_offset[attr] = attr_offset++;
  for (auto const &method : cgen_definition.dispatch_table)
      cgen_definition.method_offset[method] = method_offset++;

  cgen_definition.method_definition_containing_class = class_method_defined_in[cgen_definition.name];
  cgen_definition.directly_owned_attrs = class_directly_owned_attributes[cgen_definition.name];
  return cgen_definition;
}

void CgenClassTable::emit_nameTab() {
  str << CLASSNAMETAB << ":" << endl;
  for (auto const &cgen_definition : cgen_class_names) {
    str << WORD;
    stringtable.lookup_string(cgen_definition->get_string())->code_ref(str);
    str << endl;
  }
}

void CgenClassTable::emit_objTab() {
  str << CLASSOBJTAB << ":" << endl;
  for (auto const &cgen_definition_name : cgen_class_names) {
    str << WORD << cgen_definition_name << PROTOBJ_SUFFIX << endl;
    str << WORD << cgen_definition_name << "_init" << endl;
  }
}

void CgenClassTable::emit_default_value_for_attr_type(Symbol type) {
  if (type == Int)
    inttable.lookup_string("0")->code_ref(str);
  else if (type == Bool)
    falsebool.code_ref(str);
  else if (type == Str)
    stringtable.lookup_string("")->code_ref(str);
  else
    str << "0";
}

void CgenClassTable::emit_protObj_from(cgen_class_definition cgen_definition) {
  str << WORD << -1 << endl;
  str << cgen_definition.name << PROTOBJ_SUFFIX << ":" << endl;
  str << WORD << cgen_definition.tag << endl;
  str << WORD << cgen_definition.size() << endl;
  str << WORD << cgen_definition.name << DISPTAB_SUFFIX << endl;

  for (auto const &attr : cgen_definition.attrs) {       
    str << WORD;
    emit_default_value_for_attr_type(cgen_definition.attr_definitions[attr]->get_type());
    str << endl;
  }
}

void CgenClassTable::emit_protObjs() {
  for (auto const &cgen_definition : cgen_class_names)
    emit_protObj_from(cgen_class_definition_of[cgen_definition]);
}

void CgenClassTable::emit_dispatch_table(cgen_class_definition cgen_definition) {
  str << cgen_definition.name << DISPTAB_SUFFIX << ":" << endl;
  for (auto const &method : cgen_definition.dispatch_table)
    str << WORD << cgen_definition.method_definition_containing_class[method] << "." << method << endl;
}

void CgenClassTable::emit_dispatch_tables() {
  for (auto const &cgen_definition : cgen_class_names)
    emit_dispatch_table(cgen_class_definition_of[cgen_definition]);
}

void CgenClassTable::emit_initialiser(cgen_class_definition cgen_definition) {
  str << cgen_definition.name << CLASSINIT_SUFFIX << LABEL;

  emit_spill_activation_record_registers(str);
  emit_setup_frame_pointer(str);
  emit_setup_self_pointer(str);

  if (cgen_definition.name != Object) {
    emit_jal_without_address(str);
    str << inheritance_parent[cgen_definition.name] << CLASSINIT_SUFFIX << endl;
  }

  cgen_context context;
  context.self_name = cgen_definition.name;
  context.class_attr_offset = cgen_definition.attr_offset;
  context.self_class_definition = class_definitions[cgen_definition.name];
  context.dispatch_offsets_of_class_methods = dispatch_offsets_of_class_methods;
  context.classtag_of = classtag_of;

  for (auto const& attr_name : cgen_definition.attrs) {
    Expression attr_init_expr = cgen_definition.attr_definitions[attr_name]->get_init_expr();
    bool has_init_expr = dynamic_cast<no_expr_class*>(attr_init_expr) == nullptr;
    if (has_init_expr && cgen_definition.is_directly_owned(attr_name)) {
      attr_init_expr->code(str, context);
      emit_store(ACC, cgen_definition.attr_offset[attr_name], SELF, str);
    }
  }

  emit_move(ACC, SELF, str);
  emit_restore_activation_record_registers(str);
  emit_return(str);
}

void CgenClassTable::emit_initialisers() {
  for (auto const &cgen_definition : cgen_class_names)
    emit_initialiser(cgen_class_definition_of[cgen_definition]);
}

void CgenClassTable::emit_parentTab() {
  str << CLASSPARENTTAB << LABEL;
  for (auto const &type : cgen_class_names) {
    if (type == Object) {
      str << WORD << objectparenttag << endl;
    }
    else
    {
      str << WORD << classtag_of[inheritance_parent[type]];
      str << endl;
    }
  }
}

std::map<Symbol, int> build_method_args_lookup(method_class* method_definition) {
    std::map<Symbol, int> arg_offset_map;

    Formals declared_method_args = method_definition->get_formals();
    int declared_argument_ix = declared_method_args->first();
    int argument_offset = 0;

    while (declared_method_args->more(declared_argument_ix))
    {
      argument_offset++;
      declared_argument_ix = declared_method_args->next(declared_argument_ix);
    }

    declared_method_args = method_definition->get_formals();
    declared_argument_ix = declared_method_args->first();
    argument_offset--;
    while (declared_method_args->more(declared_argument_ix))
    {
        Formal declared_argument = declared_method_args->nth(declared_argument_ix);
        Symbol declared_argument_name = declared_argument->get_name();
        arg_offset_map[declared_argument_name] = argument_offset;
        argument_offset--;
        declared_argument_ix = declared_method_args->next(declared_argument_ix);
    }
    return arg_offset_map;
}

void CgenClassTable::emit_method(cgen_class_definition cgen_definition, method_class* method_definition) {
  cgen_context ctx;
	ctx.self_name = cgen_definition.name;
  ctx.class_attr_offset = cgen_definition.attr_offset;
  ctx.method_attr_offset = build_method_args_lookup(method_definition);
  ctx.self_class_definition = class_definitions[cgen_definition.name];
  ctx.dispatch_offsets_of_class_methods = dispatch_offsets_of_class_methods;
  ctx.method_name = method_definition->get_name();
  ctx.classtag_of = classtag_of;

  emit_method_ref(ctx.self_name, ctx.method_name, str);
  str << LABEL;
  emit_spill_activation_record_registers(str);
  emit_setup_frame_pointer(str);
  emit_setup_self_pointer(str);

  method_definition->get_body_expr()->code(str, ctx);

  emit_restore_activation_record_registers(str);

  for (size_t i = 0; i < ctx.method_attr_offset.size(); i++) {
    emit_pop_without_load(str);
    ctx.pop_scope_identifier();
  }
  emit_return(str);  
}

void CgenClassTable::emit_methods(cgen_class_definition cgen_definition) {
  for (auto const& x: cgen_definition.method_definitions)
    if (cgen_definition.is_defining_method(x.first))
      emit_method(cgen_definition, x.second);
}

void CgenClassTable::emit_class_methods() {
  for (auto const &cgen_definition : cgen_class_names)
    if(!cgen_class_definition_of[cgen_definition].is_primitive_type)
      emit_methods(cgen_class_definition_of[cgen_definition]);
}


int current_label_ix = 0;
int next_label() {
  return current_label_ix++;
}

void assign_class::code(ostream &s, cgen_context ctx) {
  expr->code(s, ctx); // acc value

  int scope_stack_offset = ctx.get_scope_identifier_offset(name);
  int method_arg_offset = ctx.get_method_attr_offset(name);
  int class_attr_offset = ctx.get_class_attribute_identifier_offset(name);
  
  bool is_in_scope = scope_stack_offset != -1;
  bool is_method_argument = method_arg_offset != -1;
  bool is_class_attr = class_attr_offset != -1;

  if (is_in_scope) {
    emit_store(ACC, scope_stack_offset + 1, SP, s);
    if (cgen_Memmgr == GC_GENGC) {
      emit_addiu(A1, SP, 4 * (scope_stack_offset + 1), s);
      emit_gc_assign(s);
    }
    return;
  }
  if (is_method_argument) {
    emit_store(ACC, 3 + method_arg_offset, FP, s);
    if (cgen_Memmgr == GC_GENGC) {
      emit_addiu(A1, FP, 4 * (3 + method_arg_offset), s);
      emit_gc_assign(s);
    }
    return;
  }
  if (is_class_attr) {
    emit_store(ACC, class_attr_offset, SELF, s);
    if (cgen_Memmgr == GC_GENGC) {
      emit_addiu(A1, SELF, 4 * (class_attr_offset), s);
      emit_gc_assign(s);
    }
    return;
  }
}

void static_dispatch_class::code(ostream &s, cgen_context ctx) {
  Expressions actual_method_args = actual;
  Symbol dispatch_target_type = type_name;
  int actual_argument_ix = actual_method_args->first();
  int dispatch_start_label = next_label();
  int dispatch_offset = ctx.get_class_method_dispatch_offset(dispatch_target_type, name);
  Class_ class_definition = ctx.self_class_definition;

  while (actual_method_args->more(actual_argument_ix))
  {
      Expression actual_argument = actual_method_args->nth(actual_argument_ix);
      actual_argument->code(s, ctx);
      emit_push(ACC, s);
      ctx.push_scope_identifier(No_type);
      actual_argument_ix = actual_method_args->next(actual_argument_ix);
  }

  expr->code(s, ctx); // ACC has dispatch object

  //  Ensure dispatch to existing object
  emit_bne(ACC, ZERO, dispatch_start_label, s);
  //  Dispatch to void
  emit_partial_load_address(ACC, s);
  stringtable.lookup_string(class_definition->get_filename()->get_string())->code_ref(s);
  s << endl;
  emit_load_imm(T1, get_line_number(), s);
  emit_jal("_dispatch_abort", s);
  // Dispatch to valid object
  emit_label_def(dispatch_start_label, s);
  emit_load_address(T1, (char *) (std::string(type_name->get_string()) + DISPTAB_SUFFIX).c_str(), s);
  emit_load(T1, dispatch_offset, T1, s); // $t1 holds pointer to method entry
  emit_jalr(T1, s);
}


void dispatch_class::code(ostream &s, cgen_context ctx) {
  Expressions actual_method_args = actual;
  Symbol dispatch_target_type = expr->get_type() == SELF_TYPE ? ctx.self_name : expr->get_type();
  int actual_argument_ix = actual_method_args->first();
  int dispatch_start_label = next_label();
  int dispatch_offset = ctx.get_class_method_dispatch_offset(dispatch_target_type, name);
  Class_ class_definition = ctx.self_class_definition;

  while (actual_method_args->more(actual_argument_ix))
  {
      Expression actual_argument = actual_method_args->nth(actual_argument_ix);
      actual_argument->code(s, ctx);
      emit_push(ACC, s);
      ctx.push_scope_identifier(No_type);
      actual_argument_ix = actual_method_args->next(actual_argument_ix);
  }

  expr->code(s, ctx); // ACC has dispatch object

  //  Ensure dispatch to existing object
  emit_bne(ACC, ZERO, dispatch_start_label, s);
  //  Dispatch to void
  emit_partial_load_address(ACC, s);
  stringtable.lookup_string(class_definition->get_filename()->get_string())->code_ref(s);
  s << endl;
  emit_load_imm(T1, get_line_number(), s);
  emit_jal("_dispatch_abort", s);
  // Dispatch to valid object
  emit_label_def(dispatch_start_label, s);
  emit_load(T1, 2, ACC, s); // $t1 holds pointer to disptab
  emit_load(T1, dispatch_offset, T1, s); // $t1 holds pointer to method entry
  emit_jalr(T1, s);
}

void cond_class::code(ostream &s, cgen_context ctx) {
  int predicate_fails = next_label();
  int done_label = next_label();

  pred->code(s, ctx);
  emit_fetch_int(T1, ACC, s);
  emit_beq(T1, ZERO, predicate_fails, s);
  //
  then_exp->code(s, ctx);
  emit_jump_to_label(done_label, s);
  //
  emit_label_def(predicate_fails, s);
  else_exp->code(s, ctx);
  //
  emit_label_def(done_label, s);
}

void loop_class::code(ostream &s, cgen_context ctx) {
  int loop_begin_label = next_label();
  int loop_exit_label = next_label();

  emit_label_def(loop_begin_label, s);
  // loop begin
  pred->code(s, ctx);
  emit_fetch_int(T1, ACC, s);
  emit_beq(T1, ZERO, loop_exit_label, s);
  // predicate holds
  body->code(s, ctx); // execute body and loop again
  emit_jump_to_label(loop_begin_label, s);
  // predicate fails
  emit_label_def(loop_exit_label, s);
  
  emit_move(ACC, ZERO, s);
}

void typcase_class::code(ostream &s, cgen_context ctx) {
  Class_ class_definition = ctx.self_class_definition;
  int typcase_exp_save_to_check = next_label();
  int typcase_match_failure_label = next_label();
  int typcase_branch_match_succesfull_label = next_label();
  int ancestors_loop_start = next_label();
  int ancestors_cases_start = next_label();

  expr->code(s, ctx);
  // Ensure dispatch to existing object
  emit_bne(ACC, ZERO, typcase_exp_save_to_check, s);
  //  Dispatch to void
  emit_partial_load_address(ACC, s);
  stringtable.lookup_string(class_definition->get_filename()->get_string())->code_ref(s);
  s << endl;
  emit_load_imm(T1, get_line_number(), s);
  emit_jal("_case_abort2", s);

 
  // Dispatch to valid object
  emit_label_def(typcase_exp_save_to_check, s);
  emit_load(T1, TAG_OFFSET, ACC, s); // $t1 holds expr dynamic type tag

  // emit each case branch match
  // maybe sort branches topologically from least precise to most precise
  // consider them in order of decreasing precision
  std::map<Symbol, int> branches_match_labels;
  std::map<Symbol, int> branches_classtype_tags;
  std::map<Symbol, branch_class*> branches;
  std::vector<Symbol> branch_types;

  // analyse classes and tags
  for (int i = cases->first(); cases->more(i); i = cases->next(i)) {
    branch_class* branch = static_cast<branch_class*>(cases->nth(i));
    Symbol branch_static_type = branch->get_declaration_type();
    branches[branch_static_type] = branch;
    branches_classtype_tags[branch_static_type] = ctx.classtag_of[branch_static_type];
    branches_match_labels[branch_static_type] = next_label();
    branch_types.push_back(branch_static_type);
  }

  std::sort(
    std::begin(branch_types), 
    std::end(branch_types), 
    [&](auto const &l, auto const &r) {
      return branches_classtype_tags[l] > branches_classtype_tags[r];
    }
  );

  // emit beq for each class tag match in correct order
  // T4 current ancestor of expr type
  // T5 class_parentTab address
  // T6 invalid parent
  // T7 offset multiplier

  emit_move(T4, T1, s);
  emit_load_address(T5, CLASSPARENTTAB, s);
  emit_load_imm(T6, INVALIDPARENTTAG, s);
  emit_load_imm(T7, 4, s);
  emit_label_def(ancestors_loop_start, s);
  // check if ancestor is -1 then jump to
  emit_bne(T4, T6, ancestors_cases_start, s);
  emit_jump_to_label(typcase_match_failure_label, s);
  emit_label_def(ancestors_cases_start, s);
  // loop
  for (auto const &branch_type : branch_types) {
    int branch_matched_label = branches_match_labels[branch_type];
    int branch_classtag = branches_classtype_tags[branch_type];

    emit_load_imm(T2, branch_classtag, s); // $t2 -> branch_classtag
    emit_beq(T4, T2, branch_matched_label, s);
  }
  // load ancestor
  // $t4 = CLASSPARENTTAB[$t4]  
  emit_mul(T4, T4, T7, s);
  emit_addu(T4, T4, T5, s);
  emit_load(T4, 0, T4, s);
  emit_jump_to_label(ancestors_loop_start, s);

  
  emit_jump_to_label(typcase_match_failure_label, s);

  for (auto const &branch_type : branch_types) {
    int branch_matched_label = branches_match_labels[branch_type];
    int branch_classtag = branches_classtype_tags[branch_type];
    branch_class* branch = branches[branch_type];

    emit_label_def(branch_matched_label, s);

    emit_push(ACC, s);
    ctx.push_scope_identifier(branch->get_name());

    branch->expr->code(s, ctx);

    emit_pop_without_load(s);
    ctx.pop_scope_identifier();

    emit_jump_to_label(typcase_branch_match_succesfull_label, s);
  }

  // emit case match failure label
  // T3 holds class name, T1 classtag

  emit_label_def(typcase_match_failure_label, s);
  emit_load_address(T3, CLASSNAMETAB, s);
  emit_load_imm(T2, 4, s);
  emit_mul(T2, T1, T2, s); // T2 holds classtag address
  emit_addu(T3, T3,T2, s);
  emit_jal("_case_abort", s);

  // typcase_branch_match_succesfull_label
  emit_label_def(typcase_branch_match_succesfull_label, s);
}

void block_class::code(ostream &s, cgen_context ctx) {
  for (int i = body->first(); body->more(i); i = body->next(i))
    body->nth(i)->code(s, ctx);
}

void let_class::code(ostream &s, cgen_context ctx) {
  init->code(s, ctx);

  bool should_emit_default_init = dynamic_cast<no_expr_class*>(init) != nullptr;

  if (should_emit_default_init) {
    if (type_decl == Str) {
        emit_load_string(ACC, stringtable.lookup_string(""), s);
    } else if (type_decl == Int) {
        emit_load_int(ACC, inttable.lookup_string("0"), s);
    } else if (type_decl == Bool) {
        emit_load_bool(ACC, BoolConst(0), s);
    }
  }

  ctx.push_scope_identifier(identifier);
  emit_push(ACC, s);
  body->code(s, ctx);
  emit_pop_without_load(s);
  ctx.pop_scope_identifier();
}

void plus_class::code(ostream &s, cgen_context ctx) {
  this->e1->code(s, ctx);
  emit_push(ACC, s);
  ctx.push_scope_identifier(No_type);
  this->e2->code(s, ctx);
  emit_jal("Object.copy", s);
  emit_pop(T1, s);
  ctx.pop_scope_identifier();

  emit_fetch_int(T1, T1, s);
  emit_fetch_int(T2, ACC, s);
  emit_add(T3, T1, T2, s);
  emit_store_int(T3, ACC, s);
}

void sub_class::code(ostream &s, cgen_context ctx) {
  this->e1->code(s, ctx);
  emit_push(ACC, s);
  ctx.push_scope_identifier(No_type);
  this->e2->code(s, ctx);
  emit_jal("Object.copy", s);
  emit_pop(T1, s);
  ctx.pop_scope_identifier();
  emit_fetch_int(T1, T1, s);
  emit_fetch_int(T2, ACC, s);
  emit_sub(T3, T1, T2, s);
  emit_store_int(T3, ACC, s);
}

void mul_class::code(ostream &s, cgen_context ctx) {
  this->e1->code(s, ctx);
  emit_push(ACC, s);
  ctx.push_scope_identifier(No_type);
  this->e2->code(s, ctx);
  emit_jal("Object.copy", s);
  emit_pop(T1, s);
  ctx.pop_scope_identifier();
  emit_fetch_int(T1, T1, s);
  emit_fetch_int(T2, ACC, s);
  emit_mul(T3, T1, T2, s);
  emit_store_int(T3, ACC, s);
}

void divide_class::code(ostream &s, cgen_context ctx) {
  this->e1->code(s, ctx);
  emit_push(ACC, s);
  ctx.push_scope_identifier(No_type);
  this->e2->code(s, ctx);
  emit_jal("Object.copy", s);
  emit_pop(T1, s);
  ctx.pop_scope_identifier();
  emit_fetch_int(T1, T1, s);
  emit_fetch_int(T2, ACC, s);
  emit_div(T3, T1, T2, s);
  emit_store_int(T3, ACC, s);
}

void neg_class::code(ostream &s, cgen_context ctx) {
  e1->code(s, ctx);
  emit_jal("Object.copy", s);
  emit_fetch_int(T1, ACC, s);
  emit_neg(T1, T1, s);
  emit_store_int(T1, ACC, s);
}

void lt_class::code(ostream &s, cgen_context ctx) {
  int less_label = next_label();
  int done_label = next_label();

  e1->code(s, ctx);
  emit_push(ACC, s);
  ctx.push_scope_identifier(No_type);

  e2->code(s, ctx);
  emit_pop(T1, s);           // $t1 = e1_int
  ctx.pop_scope_identifier();

  emit_move(T2, ACC, s);     // $t2 = e2_int
  emit_fetch_int(T1, T1, s); // $t1 = e1_int.val
  emit_fetch_int(T2, T2, s); // $t2 = e2_int.val
  emit_blt(T1, T2, less_label, s);
  emit_load_bool(ACC, BoolConst(0), s);
  emit_jump_to_label(done_label, s);
  emit_label_def(less_label, s);
  emit_load_bool(ACC, BoolConst(1), s);
  emit_label_def(done_label, s);
}

void eq_class::code(ostream &s, cgen_context ctx) {
  int are_reference_equal = next_label();
  int done_label = next_label();
  e1->code(s, ctx);
  emit_push(ACC, s);
  ctx.push_scope_identifier(No_type);

  e2->code(s, ctx);
  emit_pop(T1, s);       // $t1 = e1_object
  ctx.pop_scope_identifier();

  emit_move(T2, ACC, s); // $t2 = e2_object

  if (e1->type == Int || e1->type == Str || e1->type == Bool) {
      emit_load_bool(ACC, BoolConst(1), s);
      emit_load_bool(A1, BoolConst(0), s);
      emit_jal("equality_test", s);
      return;
  }

  emit_beq(T1, T2, are_reference_equal, s);
  emit_load_bool(ACC, BoolConst(0), s);
  emit_jump_to_label(done_label, s);
  //
  emit_label_def(are_reference_equal, s);
  emit_load_bool(ACC, BoolConst(1), s);
  //
  emit_label_def(done_label, s);
}

void leq_class::code(ostream &s, cgen_context ctx) {
  int less_or_equal_label = next_label();
  int done_label = next_label();

  e1->code(s, ctx);
  emit_push(ACC, s);
  ctx.push_scope_identifier(No_type);
  e2->code(s, ctx);
  emit_pop(T1, s);      // $t1 = e1_int
  ctx.pop_scope_identifier();
  emit_move(T2, ACC, s); // $t2 = e2_int
  emit_fetch_int(T1, T1, s); // $t1 = e1_int.val
  emit_fetch_int(T2, T2, s); // $t2 = e2_int.val
  emit_bleq(T1, T2, less_or_equal_label, s);
  emit_load_bool(ACC, BoolConst(0), s);
  emit_jump_to_label(done_label, s);
  emit_label_def(less_or_equal_label, s);
  emit_load_bool(ACC, BoolConst(1), s);
  emit_label_def(done_label, s);
}

void comp_class::code(ostream &s, cgen_context ctx) {
  int is_false = next_label();
  int done_label = next_label();
  e1->code(s, ctx);
  emit_fetch_int(T1, ACC, s);
  emit_beq(T1, ZERO, is_false, s);
  emit_load_bool(ACC, BoolConst(0), s);
  emit_jump_to_label(done_label, s);
  emit_label_def(is_false, s);
  emit_load_bool(ACC, BoolConst(1), s);
  emit_label_def(done_label, s);
}

void int_const_class::code(ostream& s, cgen_context ctx)  
{
  emit_load_int(ACC,inttable.lookup_string(token->get_string()),s);
}

void string_const_class::code(ostream& s, cgen_context ctx)
{
  emit_load_string(ACC,stringtable.lookup_string(token->get_string()),s);
}

void bool_const_class::code(ostream& s, cgen_context ctx)
{
  emit_load_bool(ACC, BoolConst(val), s);
}

void new__class::code(ostream &s, cgen_context ctx) {
  Symbol static_type = this->get_type();
  if (type_name != SELF_TYPE) {
    std::string target_cgen_definition = std::string(static_type->get_string()) + PROTOBJ_SUFFIX;
    std::string target_cgen_definition_init = std::string(static_type->get_string()) + CLASSINIT_SUFFIX;
    emit_load_address(ACC, (char *) target_cgen_definition.c_str(), s);
    emit_jal("Object.copy", s);
    emit_jal((char *)target_cgen_definition_init.c_str(), s);
    return;
  }
  emit_load_address(T1, CLASSOBJTAB, s);
  emit_load(T2, TAG_OFFSET, SELF, s);
  emit_load_imm(T3, 8, s);
  emit_mul(T2, T2, T3, s);
  emit_addu(T1, T1, T2, s);
  emit_push(T1, s);
  emit_load(ACC, 0, T1, s);
  emit_jal("Object.copy", s);
  emit_pop(T1, s);
  emit_load(T1, 1, T1, s);
  emit_jalr(T1, s);
}

void isvoid_class::code(ostream &s, cgen_context ctx) {
  int void_label = next_label();
  int done_label = next_label();

  e1->code(s, ctx);
  emit_move(T1, ACC, s);
  emit_beq(T1, ZERO, void_label, s);
  emit_load_bool(ACC, BoolConst(0), s);
  emit_jump_to_label(done_label, s);
  emit_label_def(void_label, s);
  emit_load_bool(ACC, BoolConst(1), s);
  emit_label_def(done_label, s);
}

void no_expr_class::code(ostream &s, cgen_context ctx) {
  emit_move(ACC, ZERO, s);
}

void object_class::code(ostream &s, cgen_context ctx) {
  int scope_stack_offset = ctx.get_scope_identifier_offset(name);
  int method_arg_offset = ctx.get_method_attr_offset(name);
  int class_attr_offset = ctx.get_class_attribute_identifier_offset(name);

  bool is_in_scope = scope_stack_offset != -1;
  bool is_method_argument = method_arg_offset != -1;
  bool is_class_attr = class_attr_offset != -1;

  if (is_in_scope) {
    emit_load(ACC, scope_stack_offset + 1, SP, s);
    return;
  }
  if (is_method_argument) {
    emit_load(ACC, 3 + method_arg_offset, FP, s);
    return;
  }
  if (is_class_attr) {
    emit_load(ACC, class_attr_offset, SELF, s);
    return;
  }

  emit_move(ACC, SELF, s);
  return;
}
