#include "cool-tree.h"
#include "symtab.h"
#include "emit.h"

#include <vector>
#include <map>
#include <set>

#ifndef cgen_class_definition_h
#define cgen_class_definition_h

typedef struct cgen_class_definition
{
   int                              tag;
   bool                             is_primitive_type;
   Symbol                           name;
   std::vector<Symbol>              dispatch_table;
   std::vector<Symbol>              attrs;
   std::map<Symbol, int>            attr_offset;
   std::map<Symbol, int>            method_offset;
   std::map<Symbol, Symbol>         method_definition_containing_class;
   std::map<Symbol, attr_class*>    attr_definitions;
   std::map<Symbol, method_class*>  method_definitions;
   std::set<Symbol>                 directly_owned_attrs;

   int size() {
      return DEFAULT_OBJFIELDS + attrs.size();
   }

   bool is_directly_owned(Symbol symbol) {
      return directly_owned_attrs.find(symbol) != directly_owned_attrs.end();
   }

   bool is_defining_method(Symbol symbol) {
      return method_definition_containing_class[symbol] == name;
   }

} cgen_class_definition;

#endif