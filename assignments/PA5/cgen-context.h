#include "cool-tree.h"
#include "symtab.h"
#include <vector>
#include <map>

#ifndef cgen_context_h
#define cgen_context_h

class Class__class;
typedef Class__class *Class_;

typedef struct cgen_context {
	Symbol              self_name;
	Symbol              method_name;
	std::vector<Symbol>                     scope_symbols;
	std::map<Symbol, int>                   class_attr_offset;
	std::map<Symbol, int>                   classtag_of;
	std::map<Symbol, int>                   method_attr_offset;
	std::map<Symbol, std::map<Symbol, int>> dispatch_offsets_of_class_methods;
	Class_                                  self_class_definition;

	void push_scope_identifier(Symbol identifier) {
		scope_symbols.push_back(identifier);
	}

	void pop_scope_identifier() {
		scope_symbols.pop_back();
	}

	int get_scope_identifier_offset(Symbol identifier) {
		if (!scope_symbols.size())
			return -1;
		int offset = scope_symbols.size() - 1;
		while(offset >= 0 && scope_symbols[offset] != identifier)
			offset--;
		int offset_from_scope_start = scope_symbols.size() - 1 - offset;
		return (
			scope_symbols[offset] == identifier ? offset_from_scope_start : -1
		);
	}

	int get_method_attr_offset(Symbol identifier) {
		return (
			method_attr_offset.find(identifier) != method_attr_offset.end() ?
			method_attr_offset[identifier] :
			-1
		);
	}

	int get_class_attribute_identifier_offset(Symbol identifier) {
		return (
			class_attr_offset.find(identifier) != class_attr_offset.end() ?
			class_attr_offset[identifier] :
			-1
		);
	}

	int get_class_method_dispatch_offset(Symbol class_name, Symbol method_name) {
	 	return dispatch_offsets_of_class_methods[class_name][method_name];
	}
} cgen_context;

#endif
