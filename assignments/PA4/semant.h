#ifndef SEMANT_H_
#define SEMANT_H_

#include <assert.h>
#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <algorithm>

#include "cool-tree.h"
#include "stringtab.h"
#include "symtab.h"
#include "list.h"

#define TRUE 1
#define FALSE 0

class ClassTable;
typedef ClassTable *ClassTableP;

// This is a structure that may be used to contain the semantic
// information such as the inheritance graph.  You may use it or not as
// you like: it is only here to provide a container for the supplied
// methods.

class ClassTable {
private:
  int semant_errors;
  void install_basic_classes();
  bool inheritance_dfs(Symbol symbol);
  ostream& error_stream;
  std::map<Symbol, std::vector<Symbol>> inheritance_graph;
  std::map<Symbol, Symbol> parent_type_of;


 public:
  ClassTable(Classes);
  int errors() { return semant_errors; }
  bool install_custom_classes(Classes);
  bool build_inheritance_graph();
  bool is_inheritance_graph_acyclic();
  bool is_class_table_valid();
  bool is_subtype_of(Symbol, Symbol);
  bool is_type_defined(Symbol);
  bool is_primitive(Symbol);
  
  Symbol least_common_ancestor_type(Symbol, Symbol);
  Symbol get_parent_type_of(Symbol);
  std::map<Symbol, Class_> class_lookup;
  ostream& semant_error();
  ostream& semant_error(Class_ c);
  ostream& semant_error(Symbol filename, tree_node *t);
  ostream& semant_error(tree_node *t);
};


#endif

