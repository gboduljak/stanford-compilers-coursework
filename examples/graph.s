# start of generated code
	.data
	.align	2
	.globl	class_nameTab
	.globl	Main_protObj
	.globl	Int_protObj
	.globl	String_protObj
	.globl	bool_const0
	.globl	bool_const1
	.globl	_int_tag
	.globl	_bool_tag
	.globl	_string_tag
_int_tag:
	.word	3
_bool_tag:
	.word	2
_string_tag:
	.word	4
	.globl	_MemMgr_INITIALIZER
_MemMgr_INITIALIZER:
	.word	_NoGC_Init
	.globl	_MemMgr_COLLECTOR
_MemMgr_COLLECTOR:
	.word	_NoGC_Collect
	.globl	_MemMgr_TEST
_MemMgr_TEST:
	.word	0
	.word	-1
str_const36:
	.word	4
	.word	6
	.word	String_dispTab
	.word	int_const6
	.ascii	"BoolOp"
	.byte	0	
	.align	2
	.word	-1
str_const35:
	.word	4
	.word	6
	.word	String_dispTab
	.word	int_const4
	.ascii	"Main"
	.byte	0	
	.align	2
	.word	-1
str_const34:
	.word	4
	.word	6
	.word	String_dispTab
	.word	int_const5
	.ascii	"Parse"
	.byte	0	
	.align	2
	.word	-1
str_const33:
	.word	4
	.word	6
	.word	String_dispTab
	.word	int_const5
	.ascii	"VCons"
	.byte	0	
	.align	2
	.word	-1
str_const32:
	.word	4
	.word	6
	.word	String_dispTab
	.word	int_const5
	.ascii	"VList"
	.byte	0	
	.align	2
	.word	-1
str_const31:
	.word	4
	.word	6
	.word	String_dispTab
	.word	int_const5
	.ascii	"ECons"
	.byte	0	
	.align	2
	.word	-1
str_const30:
	.word	4
	.word	6
	.word	String_dispTab
	.word	int_const5
	.ascii	"EList"
	.byte	0	
	.align	2
	.word	-1
str_const29:
	.word	4
	.word	6
	.word	String_dispTab
	.word	int_const4
	.ascii	"Edge"
	.byte	0	
	.align	2
	.word	-1
str_const28:
	.word	4
	.word	6
	.word	String_dispTab
	.word	int_const7
	.ascii	"Vertice"
	.byte	0	
	.align	2
	.word	-1
str_const27:
	.word	4
	.word	6
	.word	String_dispTab
	.word	int_const5
	.ascii	"Graph"
	.byte	0	
	.align	2
	.word	-1
str_const26:
	.word	4
	.word	6
	.word	String_dispTab
	.word	int_const6
	.ascii	"String"
	.byte	0	
	.align	2
	.word	-1
str_const25:
	.word	4
	.word	6
	.word	String_dispTab
	.word	int_const4
	.ascii	"Bool"
	.byte	0	
	.align	2
	.word	-1
str_const24:
	.word	4
	.word	5
	.word	String_dispTab
	.word	int_const3
	.ascii	"Int"
	.byte	0	
	.align	2
	.word	-1
str_const23:
	.word	4
	.word	5
	.word	String_dispTab
	.word	int_const2
	.ascii	"IO"
	.byte	0	
	.align	2
	.word	-1
str_const22:
	.word	4
	.word	6
	.word	String_dispTab
	.word	int_const6
	.ascii	"Object"
	.byte	0	
	.align	2
	.word	-1
str_const21:
	.word	4
	.word	7
	.word	String_dispTab
	.word	int_const10
	.ascii	"_prim_slot"
	.byte	0	
	.align	2
	.word	-1
str_const20:
	.word	4
	.word	7
	.word	String_dispTab
	.word	int_const9
	.ascii	"SELF_TYPE"
	.byte	0	
	.align	2
	.word	-1
str_const19:
	.word	4
	.word	7
	.word	String_dispTab
	.word	int_const9
	.ascii	"_no_class"
	.byte	0	
	.align	2
	.word	-1
str_const18:
	.word	4
	.word	8
	.word	String_dispTab
	.word	int_const11
	.ascii	"<basic class>"
	.byte	0	
	.align	2
	.word	-1
str_const17:
	.word	4
	.word	5
	.word	String_dispTab
	.word	int_const0
	.ascii	" "
	.byte	0	
	.align	2
	.word	-1
str_const16:
	.word	4
	.word	5
	.word	String_dispTab
	.word	int_const0
	.ascii	"-"
	.byte	0	
	.align	2
	.word	-1
str_const15:
	.word	4
	.word	5
	.word	String_dispTab
	.word	int_const0
	.ascii	"9"
	.byte	0	
	.align	2
	.word	-1
str_const14:
	.word	4
	.word	5
	.word	String_dispTab
	.word	int_const0
	.ascii	"8"
	.byte	0	
	.align	2
	.word	-1
str_const13:
	.word	4
	.word	5
	.word	String_dispTab
	.word	int_const0
	.ascii	"7"
	.byte	0	
	.align	2
	.word	-1
str_const12:
	.word	4
	.word	5
	.word	String_dispTab
	.word	int_const0
	.ascii	"6"
	.byte	0	
	.align	2
	.word	-1
str_const11:
	.word	4
	.word	5
	.word	String_dispTab
	.word	int_const0
	.ascii	"5"
	.byte	0	
	.align	2
	.word	-1
str_const10:
	.word	4
	.word	5
	.word	String_dispTab
	.word	int_const0
	.ascii	"4"
	.byte	0	
	.align	2
	.word	-1
str_const9:
	.word	4
	.word	5
	.word	String_dispTab
	.word	int_const0
	.ascii	"3"
	.byte	0	
	.align	2
	.word	-1
str_const8:
	.word	4
	.word	5
	.word	String_dispTab
	.word	int_const0
	.ascii	"2"
	.byte	0	
	.align	2
	.word	-1
str_const7:
	.word	4
	.word	5
	.word	String_dispTab
	.word	int_const0
	.ascii	"1"
	.byte	0	
	.align	2
	.word	-1
str_const6:
	.word	4
	.word	5
	.word	String_dispTab
	.word	int_const0
	.ascii	"0"
	.byte	0	
	.align	2
	.word	-1
str_const5:
	.word	4
	.word	5
	.word	String_dispTab
	.word	int_const1
	.byte	0	
	.align	2
	.word	-1
str_const4:
	.word	4
	.word	5
	.word	String_dispTab
	.word	int_const0
	.ascii	"\n"
	.byte	0	
	.align	2
	.word	-1
str_const3:
	.word	4
	.word	5
	.word	String_dispTab
	.word	int_const0
	.ascii	")"
	.byte	0	
	.align	2
	.word	-1
str_const2:
	.word	4
	.word	5
	.word	String_dispTab
	.word	int_const0
	.ascii	","
	.byte	0	
	.align	2
	.word	-1
str_const1:
	.word	4
	.word	5
	.word	String_dispTab
	.word	int_const2
	.ascii	" ("
	.byte	0	
	.align	2
	.word	-1
str_const0:
	.word	4
	.word	9
	.word	String_dispTab
	.word	int_const12
	.ascii	"examples/graph.cl"
	.byte	0	
	.align	2
	.word	-1
int_const12:
	.word	3
	.word	4
	.word	Int_dispTab
	.word	17
	.word	-1
int_const11:
	.word	3
	.word	4
	.word	Int_dispTab
	.word	13
	.word	-1
int_const10:
	.word	3
	.word	4
	.word	Int_dispTab
	.word	10
	.word	-1
int_const9:
	.word	3
	.word	4
	.word	Int_dispTab
	.word	9
	.word	-1
int_const8:
	.word	3
	.word	4
	.word	Int_dispTab
	.word	8
	.word	-1
int_const7:
	.word	3
	.word	4
	.word	Int_dispTab
	.word	7
	.word	-1
int_const6:
	.word	3
	.word	4
	.word	Int_dispTab
	.word	6
	.word	-1
int_const5:
	.word	3
	.word	4
	.word	Int_dispTab
	.word	5
	.word	-1
int_const4:
	.word	3
	.word	4
	.word	Int_dispTab
	.word	4
	.word	-1
int_const3:
	.word	3
	.word	4
	.word	Int_dispTab
	.word	3
	.word	-1
int_const2:
	.word	3
	.word	4
	.word	Int_dispTab
	.word	2
	.word	-1
int_const1:
	.word	3
	.word	4
	.word	Int_dispTab
	.word	0
	.word	-1
int_const0:
	.word	3
	.word	4
	.word	Int_dispTab
	.word	1
	.word	-1
bool_const0:
	.word	2
	.word	4
	.word	Bool_dispTab
	.word	0
	.word	-1
bool_const1:
	.word	2
	.word	4
	.word	Bool_dispTab
	.word	1
class_nameTab:
	.word	str_const22
	.word	str_const23
	.word	str_const25
	.word	str_const24
	.word	str_const26
	.word	str_const27
	.word	str_const36
	.word	str_const28
	.word	str_const29
	.word	str_const30
	.word	str_const32
	.word	str_const34
	.word	str_const31
	.word	str_const33
	.word	str_const35
class_objTab:
	.word	Object_protObj
	.word	Object_init
	.word	IO_protObj
	.word	IO_init
	.word	Bool_protObj
	.word	Bool_init
	.word	Int_protObj
	.word	Int_init
	.word	String_protObj
	.word	String_init
	.word	Graph_protObj
	.word	Graph_init
	.word	BoolOp_protObj
	.word	BoolOp_init
	.word	Vertice_protObj
	.word	Vertice_init
	.word	Edge_protObj
	.word	Edge_init
	.word	EList_protObj
	.word	EList_init
	.word	VList_protObj
	.word	VList_init
	.word	Parse_protObj
	.word	Parse_init
	.word	ECons_protObj
	.word	ECons_init
	.word	VCons_protObj
	.word	VCons_init
	.word	Main_protObj
	.word	Main_init
class_parentTab:
	.word	-1
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.word	1
	.word	1
	.word	1
	.word	1
	.word	1
	.word	9
	.word	10
	.word	11
Object_dispTab:
	.word	Object.abort
	.word	Object.type_name
	.word	Object.copy
IO_dispTab:
	.word	Object.abort
	.word	Object.type_name
	.word	Object.copy
	.word	IO.out_string
	.word	IO.out_int
	.word	IO.in_string
	.word	IO.in_int
Bool_dispTab:
	.word	Object.abort
	.word	Object.type_name
	.word	Object.copy
Int_dispTab:
	.word	Object.abort
	.word	Object.type_name
	.word	Object.copy
String_dispTab:
	.word	Object.abort
	.word	Object.type_name
	.word	Object.copy
	.word	String.length
	.word	String.concat
	.word	String.substr
Graph_dispTab:
	.word	Object.abort
	.word	Object.type_name
	.word	Object.copy
	.word	Graph.add_vertice
	.word	Graph.print_E
	.word	Graph.print_V
BoolOp_dispTab:
	.word	Object.abort
	.word	Object.type_name
	.word	Object.copy
	.word	BoolOp.and
	.word	BoolOp.or
Vertice_dispTab:
	.word	Object.abort
	.word	Object.type_name
	.word	Object.copy
	.word	IO.out_string
	.word	IO.out_int
	.word	IO.in_string
	.word	IO.in_int
	.word	Vertice.outgoing
	.word	Vertice.number
	.word	Vertice.init
	.word	Vertice.add_out
	.word	Vertice.print
Edge_dispTab:
	.word	Object.abort
	.word	Object.type_name
	.word	Object.copy
	.word	IO.out_string
	.word	IO.out_int
	.word	IO.in_string
	.word	IO.in_int
	.word	Edge.init
	.word	Edge.print
EList_dispTab:
	.word	Object.abort
	.word	Object.type_name
	.word	Object.copy
	.word	IO.out_string
	.word	IO.out_int
	.word	IO.in_string
	.word	IO.in_int
	.word	EList.isNil
	.word	EList.head
	.word	EList.tail
	.word	EList.cons
	.word	EList.append
	.word	EList.print
VList_dispTab:
	.word	Object.abort
	.word	Object.type_name
	.word	Object.copy
	.word	IO.out_string
	.word	IO.out_int
	.word	IO.in_string
	.word	IO.in_int
	.word	VList.isNil
	.word	VList.head
	.word	VList.tail
	.word	VList.cons
	.word	VList.print
Parse_dispTab:
	.word	Object.abort
	.word	Object.type_name
	.word	Object.copy
	.word	IO.out_string
	.word	IO.out_int
	.word	IO.in_string
	.word	IO.in_int
	.word	Parse.read_input
	.word	Parse.parse_line
	.word	Parse.c2i
	.word	Parse.a2i
	.word	Parse.a2i_aux
ECons_dispTab:
	.word	Object.abort
	.word	Object.type_name
	.word	Object.copy
	.word	IO.out_string
	.word	IO.out_int
	.word	IO.in_string
	.word	IO.in_int
	.word	ECons.isNil
	.word	ECons.head
	.word	ECons.tail
	.word	EList.cons
	.word	EList.append
	.word	ECons.print
	.word	ECons.isNil
	.word	ECons.head
	.word	ECons.tail
	.word	ECons.init
	.word	ECons.print
VCons_dispTab:
	.word	Object.abort
	.word	Object.type_name
	.word	Object.copy
	.word	IO.out_string
	.word	IO.out_int
	.word	IO.in_string
	.word	IO.in_int
	.word	VCons.isNil
	.word	VCons.head
	.word	VCons.tail
	.word	VList.cons
	.word	VCons.print
	.word	VCons.isNil
	.word	VCons.head
	.word	VCons.tail
	.word	VCons.init
	.word	VCons.print
Main_dispTab:
	.word	Object.abort
	.word	Object.type_name
	.word	Object.copy
	.word	IO.out_string
	.word	IO.out_int
	.word	IO.in_string
	.word	IO.in_int
	.word	Parse.read_input
	.word	Parse.parse_line
	.word	Parse.c2i
	.word	Parse.a2i
	.word	Parse.a2i_aux
	.word	Main.main
	.word	-1
Object_protObj:
	.word	0
	.word	3
	.word	Object_dispTab
	.word	-1
IO_protObj:
	.word	1
	.word	3
	.word	IO_dispTab
	.word	-1
Bool_protObj:
	.word	2
	.word	4
	.word	Bool_dispTab
	.word	0
	.word	-1
Int_protObj:
	.word	3
	.word	4
	.word	Int_dispTab
	.word	0
	.word	-1
String_protObj:
	.word	4
	.word	5
	.word	String_dispTab
	.word	int_const1
	.word	0
	.word	-1
Graph_protObj:
	.word	5
	.word	5
	.word	Graph_dispTab
	.word	0
	.word	0
	.word	-1
BoolOp_protObj:
	.word	6
	.word	3
	.word	BoolOp_dispTab
	.word	-1
Vertice_protObj:
	.word	7
	.word	5
	.word	Vertice_dispTab
	.word	int_const1
	.word	0
	.word	-1
Edge_protObj:
	.word	8
	.word	6
	.word	Edge_dispTab
	.word	int_const1
	.word	int_const1
	.word	int_const1
	.word	-1
EList_protObj:
	.word	9
	.word	4
	.word	EList_dispTab
	.word	0
	.word	-1
VList_protObj:
	.word	10
	.word	4
	.word	VList_dispTab
	.word	0
	.word	-1
Parse_protObj:
	.word	11
	.word	5
	.word	Parse_dispTab
	.word	0
	.word	str_const5
	.word	-1
ECons_protObj:
	.word	12
	.word	5
	.word	ECons_dispTab
	.word	0
	.word	0
	.word	-1
VCons_protObj:
	.word	13
	.word	5
	.word	VCons_dispTab
	.word	0
	.word	0
	.word	-1
Main_protObj:
	.word	14
	.word	6
	.word	Main_dispTab
	.word	0
	.word	str_const5
	.word	0
	.globl	heap_start
heap_start:
	.word	0
	.text
	.globl	Main_init
	.globl	Int_init
	.globl	String_init
	.globl	Bool_init
	.globl	Main.main
Object_init:
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	move	$a0 $s0
	lw	$ra 4($sp)
	lw	$s0 8($sp)
	lw	$fp 12($sp)
	addiu	$sp $sp 12
	jr	$ra	
IO_init:
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	jal	Object_init
	move	$a0 $s0
	lw	$ra 4($sp)
	lw	$s0 8($sp)
	lw	$fp 12($sp)
	addiu	$sp $sp 12
	jr	$ra	
Bool_init:
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	jal	Object_init
	move	$a0 $s0
	lw	$ra 4($sp)
	lw	$s0 8($sp)
	lw	$fp 12($sp)
	addiu	$sp $sp 12
	jr	$ra	
Int_init:
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	jal	Object_init
	move	$a0 $s0
	lw	$ra 4($sp)
	lw	$s0 8($sp)
	lw	$fp 12($sp)
	addiu	$sp $sp 12
	jr	$ra	
String_init:
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	jal	Object_init
	move	$a0 $s0
	lw	$ra 4($sp)
	lw	$s0 8($sp)
	lw	$fp 12($sp)
	addiu	$sp $sp 12
	jr	$ra	
Graph_init:
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	jal	Object_init
	la	$a0 VList_protObj
	jal	Object.copy
	jal	VList_init
	sw	$a0 12($s0)
	la	$a0 EList_protObj
	jal	Object.copy
	jal	EList_init
	sw	$a0 16($s0)
	move	$a0 $s0
	lw	$ra 4($sp)
	lw	$s0 8($sp)
	lw	$fp 12($sp)
	addiu	$sp $sp 12
	jr	$ra	
BoolOp_init:
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	jal	Object_init
	move	$a0 $s0
	lw	$ra 4($sp)
	lw	$s0 8($sp)
	lw	$fp 12($sp)
	addiu	$sp $sp 12
	jr	$ra	
Vertice_init:
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	jal	IO_init
	la	$a0 EList_protObj
	jal	Object.copy
	jal	EList_init
	sw	$a0 16($s0)
	move	$a0 $s0
	lw	$ra 4($sp)
	lw	$s0 8($sp)
	lw	$fp 12($sp)
	addiu	$sp $sp 12
	jr	$ra	
Edge_init:
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	jal	IO_init
	move	$a0 $s0
	lw	$ra 4($sp)
	lw	$s0 8($sp)
	lw	$fp 12($sp)
	addiu	$sp $sp 12
	jr	$ra	
EList_init:
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	jal	IO_init
	move	$a0 $s0
	lw	$ra 4($sp)
	lw	$s0 8($sp)
	lw	$fp 12($sp)
	addiu	$sp $sp 12
	jr	$ra	
VList_init:
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	jal	IO_init
	move	$a0 $s0
	lw	$ra 4($sp)
	lw	$s0 8($sp)
	lw	$fp 12($sp)
	addiu	$sp $sp 12
	jr	$ra	
Parse_init:
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	jal	IO_init
	la	$a0 BoolOp_protObj
	jal	Object.copy
	jal	BoolOp_init
	sw	$a0 12($s0)
	move	$a0 $s0
	lw	$ra 4($sp)
	lw	$s0 8($sp)
	lw	$fp 12($sp)
	addiu	$sp $sp 12
	jr	$ra	
ECons_init:
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	jal	EList_init
	move	$a0 $s0
	lw	$ra 4($sp)
	lw	$s0 8($sp)
	lw	$fp 12($sp)
	addiu	$sp $sp 12
	jr	$ra	
VCons_init:
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	jal	VList_init
	move	$a0 $s0
	lw	$ra 4($sp)
	lw	$s0 8($sp)
	lw	$fp 12($sp)
	addiu	$sp $sp 12
	jr	$ra	
Main_init:
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	jal	Parse_init
	move	$a0 $s0
	bne	$a0 $zero label0
	la	$a0 str_const0
	li	$t1 359
	jal	_dispatch_abort
label0:
	lw	$t1 8($a0)
	lw	$t1 28($t1)
	jalr		$t1
	sw	$a0 20($s0)
	move	$a0 $s0
	lw	$ra 4($sp)
	lw	$s0 8($sp)
	lw	$fp 12($sp)
	addiu	$sp $sp 12
	jr	$ra	
Graph.add_vertice:
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	lw	$a0 16($s0)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	lw	$a0 12($fp)
	bne	$a0 $zero label2
	la	$a0 str_const0
	li	$t1 44
	jal	_dispatch_abort
label2:
	lw	$t1 8($a0)
	lw	$t1 28($t1)
	jalr		$t1
	bne	$a0 $zero label1
	la	$a0 str_const0
	li	$t1 44
	jal	_dispatch_abort
label1:
	lw	$t1 8($a0)
	lw	$t1 44($t1)
	jalr		$t1
	sw	$a0 16($s0)
	lw	$a0 12($fp)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	lw	$a0 12($s0)
	bne	$a0 $zero label3
	la	$a0 str_const0
	li	$t1 45
	jal	_dispatch_abort
label3:
	lw	$t1 8($a0)
	lw	$t1 40($t1)
	jalr		$t1
	sw	$a0 12($s0)
	lw	$ra 4($sp)
	lw	$s0 8($sp)
	lw	$fp 12($sp)
	addiu	$sp $sp 12
	addiu	$sp $sp 4
	jr	$ra	
Graph.print_E:
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	lw	$a0 16($s0)
	bne	$a0 $zero label4
	la	$a0 str_const0
	li	$t1 48
	jal	_dispatch_abort
label4:
	lw	$t1 8($a0)
	lw	$t1 48($t1)
	jalr		$t1
	lw	$ra 4($sp)
	lw	$s0 8($sp)
	lw	$fp 12($sp)
	addiu	$sp $sp 12
	jr	$ra	
Graph.print_V:
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	lw	$a0 12($s0)
	bne	$a0 $zero label5
	la	$a0 str_const0
	li	$t1 49
	jal	_dispatch_abort
label5:
	lw	$t1 8($a0)
	lw	$t1 44($t1)
	jalr		$t1
	lw	$ra 4($sp)
	lw	$s0 8($sp)
	lw	$fp 12($sp)
	addiu	$sp $sp 12
	jr	$ra	
BoolOp.and:
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	lw	$a0 16($fp)
	lw	$t1 12($a0)
	beq	$t1 $zero label6
	lw	$a0 12($fp)
	j	label7
label6:
	la	$a0 bool_const0
label7:
	lw	$ra 4($sp)
	lw	$s0 8($sp)
	lw	$fp 12($sp)
	addiu	$sp $sp 12
	addiu	$sp $sp 4
	addiu	$sp $sp 4
	jr	$ra	
BoolOp.or:
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	lw	$a0 16($fp)
	lw	$t1 12($a0)
	beq	$t1 $zero label8
	la	$a0 bool_const1
	j	label9
label8:
	lw	$a0 12($fp)
label9:
	lw	$ra 4($sp)
	lw	$s0 8($sp)
	lw	$fp 12($sp)
	addiu	$sp $sp 12
	addiu	$sp $sp 4
	addiu	$sp $sp 4
	jr	$ra	
Vertice.outgoing:
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	lw	$a0 16($s0)
	lw	$ra 4($sp)
	lw	$s0 8($sp)
	lw	$fp 12($sp)
	addiu	$sp $sp 12
	jr	$ra	
Vertice.print:
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	lw	$a0 12($s0)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s0
	bne	$a0 $zero label10
	la	$a0 str_const0
	li	$t1 79
	jal	_dispatch_abort
label10:
	lw	$t1 8($a0)
	lw	$t1 16($t1)
	jalr		$t1
	lw	$a0 16($s0)
	bne	$a0 $zero label11
	la	$a0 str_const0
	li	$t1 80
	jal	_dispatch_abort
label11:
	lw	$t1 8($a0)
	lw	$t1 48($t1)
	jalr		$t1
	lw	$ra 4($sp)
	lw	$s0 8($sp)
	lw	$fp 12($sp)
	addiu	$sp $sp 12
	jr	$ra	
Vertice.number:
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	lw	$a0 12($s0)
	lw	$ra 4($sp)
	lw	$s0 8($sp)
	lw	$fp 12($sp)
	addiu	$sp $sp 12
	jr	$ra	
Vertice.init:
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	lw	$a0 12($fp)
	sw	$a0 12($s0)
	move	$a0 $s0
	lw	$ra 4($sp)
	lw	$s0 8($sp)
	lw	$fp 12($sp)
	addiu	$sp $sp 12
	addiu	$sp $sp 4
	jr	$ra	
Vertice.add_out:
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	lw	$a0 12($fp)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	lw	$a0 16($s0)
	bne	$a0 $zero label12
	la	$a0 str_const0
	li	$t1 72
	jal	_dispatch_abort
label12:
	lw	$t1 8($a0)
	lw	$t1 40($t1)
	jalr		$t1
	sw	$a0 16($s0)
	move	$a0 $s0
	lw	$ra 4($sp)
	lw	$s0 8($sp)
	lw	$fp 12($sp)
	addiu	$sp $sp 12
	addiu	$sp $sp 4
	jr	$ra	
Edge.print:
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	la	$a0 str_const1
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s0
	bne	$a0 $zero label13
	la	$a0 str_const0
	li	$t1 103
	jal	_dispatch_abort
label13:
	lw	$t1 8($a0)
	lw	$t1 12($t1)
	jalr		$t1
	lw	$a0 12($s0)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s0
	bne	$a0 $zero label14
	la	$a0 str_const0
	li	$t1 104
	jal	_dispatch_abort
label14:
	lw	$t1 8($a0)
	lw	$t1 16($t1)
	jalr		$t1
	la	$a0 str_const2
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s0
	bne	$a0 $zero label15
	la	$a0 str_const0
	li	$t1 105
	jal	_dispatch_abort
label15:
	lw	$t1 8($a0)
	lw	$t1 12($t1)
	jalr		$t1
	lw	$a0 16($s0)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s0
	bne	$a0 $zero label16
	la	$a0 str_const0
	li	$t1 106
	jal	_dispatch_abort
label16:
	lw	$t1 8($a0)
	lw	$t1 16($t1)
	jalr		$t1
	la	$a0 str_const3
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s0
	bne	$a0 $zero label17
	la	$a0 str_const0
	li	$t1 107
	jal	_dispatch_abort
label17:
	lw	$t1 8($a0)
	lw	$t1 12($t1)
	jalr		$t1
	lw	$a0 20($s0)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s0
	bne	$a0 $zero label18
	la	$a0 str_const0
	li	$t1 108
	jal	_dispatch_abort
label18:
	lw	$t1 8($a0)
	lw	$t1 16($t1)
	jalr		$t1
	lw	$ra 4($sp)
	lw	$s0 8($sp)
	lw	$fp 12($sp)
	addiu	$sp $sp 12
	jr	$ra	
Edge.init:
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	lw	$a0 20($fp)
	sw	$a0 12($s0)
	lw	$a0 16($fp)
	sw	$a0 16($s0)
	lw	$a0 12($fp)
	sw	$a0 20($s0)
	move	$a0 $s0
	lw	$ra 4($sp)
	lw	$s0 8($sp)
	lw	$fp 12($sp)
	addiu	$sp $sp 12
	addiu	$sp $sp 4
	addiu	$sp $sp 4
	addiu	$sp $sp 4
	jr	$ra	
EList.append:
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	move	$a0 $s0
	bne	$a0 $zero label21
	la	$a0 str_const0
	li	$t1 139
	jal	_dispatch_abort
label21:
	lw	$t1 8($a0)
	lw	$t1 28($t1)
	jalr		$t1
	lw	$t1 12($a0)
	beq	$t1 $zero label19
	lw	$a0 12($fp)
	j	label20
label19:
	move	$a0 $s0
	bne	$a0 $zero label23
	la	$a0 str_const0
	li	$t1 140
	jal	_dispatch_abort
label23:
	lw	$t1 8($a0)
	lw	$t1 32($t1)
	jalr		$t1
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	lw	$a0 12($fp)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s0
	bne	$a0 $zero label25
	la	$a0 str_const0
	li	$t1 140
	jal	_dispatch_abort
label25:
	lw	$t1 8($a0)
	lw	$t1 36($t1)
	jalr		$t1
	bne	$a0 $zero label24
	la	$a0 str_const0
	li	$t1 140
	jal	_dispatch_abort
label24:
	lw	$t1 8($a0)
	lw	$t1 44($t1)
	jalr		$t1
	bne	$a0 $zero label22
	la	$a0 str_const0
	li	$t1 140
	jal	_dispatch_abort
label22:
	lw	$t1 8($a0)
	lw	$t1 40($t1)
	jalr		$t1
label20:
	lw	$ra 4($sp)
	lw	$s0 8($sp)
	lw	$fp 12($sp)
	addiu	$sp $sp 12
	addiu	$sp $sp 4
	jr	$ra	
EList.cons:
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	lw	$a0 12($fp)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s0
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	la	$a0 ECons_protObj
	jal	Object.copy
	jal	ECons_init
	bne	$a0 $zero label26
	la	$a0 str_const0
	li	$t1 135
	jal	_dispatch_abort
label26:
	lw	$t1 8($a0)
	lw	$t1 64($t1)
	jalr		$t1
	lw	$ra 4($sp)
	lw	$s0 8($sp)
	lw	$fp 12($sp)
	addiu	$sp $sp 12
	addiu	$sp $sp 4
	jr	$ra	
EList.print:
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	la	$a0 str_const4
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s0
	bne	$a0 $zero label27
	la	$a0 str_const0
	li	$t1 145
	jal	_dispatch_abort
label27:
	lw	$t1 8($a0)
	lw	$t1 12($t1)
	jalr		$t1
	lw	$ra 4($sp)
	lw	$s0 8($sp)
	lw	$fp 12($sp)
	addiu	$sp $sp 12
	jr	$ra	
EList.isNil:
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	la	$a0 bool_const1
	lw	$ra 4($sp)
	lw	$s0 8($sp)
	lw	$fp 12($sp)
	addiu	$sp $sp 12
	jr	$ra	
EList.head:
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	move	$a0 $s0
	bne	$a0 $zero label28
	la	$a0 str_const0
	li	$t1 123
	jal	_dispatch_abort
label28:
	lw	$t1 8($a0)
	lw	$t1 0($t1)
	jalr		$t1
	lw	$a0 12($s0)
	lw	$ra 4($sp)
	lw	$s0 8($sp)
	lw	$fp 12($sp)
	addiu	$sp $sp 12
	jr	$ra	
EList.tail:
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	move	$a0 $s0
	bne	$a0 $zero label29
	la	$a0 str_const0
	li	$t1 125
	jal	_dispatch_abort
label29:
	lw	$t1 8($a0)
	lw	$t1 0($t1)
	jalr		$t1
	move	$a0 $s0
	lw	$ra 4($sp)
	lw	$s0 8($sp)
	lw	$fp 12($sp)
	addiu	$sp $sp 12
	jr	$ra	
VList.cons:
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	lw	$a0 12($fp)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s0
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	la	$a0 VCons_protObj
	jal	Object.copy
	jal	VCons_init
	bne	$a0 $zero label30
	la	$a0 str_const0
	li	$t1 213
	jal	_dispatch_abort
label30:
	lw	$t1 8($a0)
	lw	$t1 60($t1)
	jalr		$t1
	lw	$ra 4($sp)
	lw	$s0 8($sp)
	lw	$fp 12($sp)
	addiu	$sp $sp 12
	addiu	$sp $sp 4
	jr	$ra	
VList.print:
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	la	$a0 str_const4
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s0
	bne	$a0 $zero label31
	la	$a0 str_const0
	li	$t1 216
	jal	_dispatch_abort
label31:
	lw	$t1 8($a0)
	lw	$t1 12($t1)
	jalr		$t1
	lw	$ra 4($sp)
	lw	$s0 8($sp)
	lw	$fp 12($sp)
	addiu	$sp $sp 12
	jr	$ra	
VList.isNil:
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	la	$a0 bool_const1
	lw	$ra 4($sp)
	lw	$s0 8($sp)
	lw	$fp 12($sp)
	addiu	$sp $sp 12
	jr	$ra	
VList.head:
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	move	$a0 $s0
	bne	$a0 $zero label32
	la	$a0 str_const0
	li	$t1 201
	jal	_dispatch_abort
label32:
	lw	$t1 8($a0)
	lw	$t1 0($t1)
	jalr		$t1
	lw	$a0 12($s0)
	lw	$ra 4($sp)
	lw	$s0 8($sp)
	lw	$fp 12($sp)
	addiu	$sp $sp 12
	jr	$ra	
VList.tail:
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	move	$a0 $s0
	bne	$a0 $zero label33
	la	$a0 str_const0
	li	$t1 203
	jal	_dispatch_abort
label33:
	lw	$t1 8($a0)
	lw	$t1 0($t1)
	jalr		$t1
	move	$a0 $s0
	lw	$ra 4($sp)
	lw	$s0 8($sp)
	lw	$fp 12($sp)
	addiu	$sp $sp 12
	jr	$ra	
Parse.read_input:
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	la	$a0 Graph_protObj
	jal	Object.copy
	jal	Graph_init
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s0
	bne	$a0 $zero label34
	la	$a0 str_const0
	li	$t1 259
	jal	_dispatch_abort
label34:
	lw	$t1 8($a0)
	lw	$t1 20($t1)
	jalr		$t1
	sw	$a0 0($sp)
	addiu	$sp $sp -4
label35:
	lw	$a0 4($sp)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	la	$a0 str_const4
	addiu	$sp $sp 4
	lw	$t1 0($sp)
	move	$t2 $a0
	la	$a0 bool_const1
	la	$a1 bool_const0
	jal	equality_test
	lw	$t1 12($a0)
	beq	$t1 $zero label38
	la	$a0 bool_const0
	j	label39
label38:
	la	$a0 bool_const1
label39:
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	lw	$a0 8($sp)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	la	$a0 str_const5
	addiu	$sp $sp 4
	lw	$t1 0($sp)
	move	$t2 $a0
	la	$a0 bool_const1
	la	$a1 bool_const0
	jal	equality_test
	lw	$t1 12($a0)
	beq	$t1 $zero label42
	la	$a0 bool_const0
	j	label43
label42:
	la	$a0 bool_const1
label43:
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	lw	$a0 12($s0)
	bne	$a0 $zero label37
	la	$a0 str_const0
	li	$t1 260
	jal	_dispatch_abort
label37:
	lw	$t1 8($a0)
	lw	$t1 12($t1)
	jalr		$t1
	lw	$t1 12($a0)
	beq	$t1 $zero label36
	lw	$a0 4($sp)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s0
	bne	$a0 $zero label47
	la	$a0 str_const0
	li	$t1 263
	jal	_dispatch_abort
label47:
	lw	$t1 8($a0)
	lw	$t1 32($t1)
	jalr		$t1
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	lw	$a0 12($sp)
	bne	$a0 $zero label46
	la	$a0 str_const0
	li	$t1 263
	jal	_dispatch_abort
label46:
	lw	$t1 8($a0)
	lw	$t1 12($t1)
	jalr		$t1
	move	$a0 $s0
	bne	$a0 $zero label48
	la	$a0 str_const0
	li	$t1 264
	jal	_dispatch_abort
label48:
	lw	$t1 8($a0)
	lw	$t1 20($t1)
	jalr		$t1
	sw	$a0 4($sp)
	j	label35
label36:
	move	$a0 $zero
	addiu	$sp $sp 4
	lw	$a0 4($sp)
	addiu	$sp $sp 4
	lw	$ra 4($sp)
	lw	$s0 8($sp)
	lw	$fp 12($sp)
	addiu	$sp $sp 12
	jr	$ra	
Parse.parse_line:
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	lw	$a0 12($fp)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s0
	bne	$a0 $zero label50
	la	$a0 str_const0
	li	$t1 273
	jal	_dispatch_abort
label50:
	lw	$t1 8($a0)
	lw	$t1 40($t1)
	jalr		$t1
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	la	$a0 Vertice_protObj
	jal	Object.copy
	jal	Vertice_init
	bne	$a0 $zero label49
	la	$a0 str_const0
	li	$t1 273
	jal	_dispatch_abort
label49:
	lw	$t1 8($a0)
	lw	$t1 36($t1)
	jalr		$t1
	sw	$a0 0($sp)
	addiu	$sp $sp -4
label51:
	lw	$a0 16($s0)
	bne	$a0 $zero label57
	la	$a0 str_const0
	li	$t1 274
	jal	_dispatch_abort
label57:
	lw	$t1 8($a0)
	lw	$t1 12($t1)
	jalr		$t1
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	la	$a0 int_const1
	addiu	$sp $sp 4
	lw	$t1 0($sp)
	move	$t2 $a0
	la	$a0 bool_const1
	la	$a1 bool_const0
	jal	equality_test
	lw	$t1 12($a0)
	beq	$t1 $zero label53
	la	$a0 bool_const0
	j	label54
label53:
	la	$a0 bool_const1
label54:
	lw	$t1 12($a0)
	beq	$t1 $zero label52
	lw	$a0 16($s0)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s0
	bne	$a0 $zero label58
	la	$a0 str_const0
	li	$t1 277
	jal	_dispatch_abort
label58:
	lw	$t1 8($a0)
	lw	$t1 40($t1)
	jalr		$t1
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	lw	$a0 16($s0)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s0
	bne	$a0 $zero label59
	la	$a0 str_const0
	li	$t1 278
	jal	_dispatch_abort
label59:
	lw	$t1 8($a0)
	lw	$t1 40($t1)
	jalr		$t1
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	lw	$a0 12($sp)
	bne	$a0 $zero label62
	la	$a0 str_const0
	li	$t1 280
	jal	_dispatch_abort
label62:
	lw	$t1 8($a0)
	lw	$t1 32($t1)
	jalr		$t1
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	lw	$a0 12($sp)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	lw	$a0 12($sp)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	la	$a0 Edge_protObj
	jal	Object.copy
	jal	Edge_init
	bne	$a0 $zero label61
	la	$a0 str_const0
	li	$t1 280
	jal	_dispatch_abort
label61:
	lw	$t1 8($a0)
	lw	$t1 28($t1)
	jalr		$t1
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	lw	$a0 16($sp)
	bne	$a0 $zero label60
	la	$a0 str_const0
	li	$t1 280
	jal	_dispatch_abort
label60:
	lw	$t1 8($a0)
	lw	$t1 40($t1)
	jalr		$t1
	addiu	$sp $sp 4
	addiu	$sp $sp 4
	j	label51
label52:
	move	$a0 $zero
	lw	$a0 4($sp)
	addiu	$sp $sp 4
	lw	$ra 4($sp)
	lw	$s0 8($sp)
	lw	$fp 12($sp)
	addiu	$sp $sp 12
	addiu	$sp $sp 4
	jr	$ra	
Parse.a2i:
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	lw	$a0 12($fp)
	bne	$a0 $zero label67
	la	$a0 str_const0
	li	$t1 308
	jal	_dispatch_abort
label67:
	lw	$t1 8($a0)
	lw	$t1 12($t1)
	jalr		$t1
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	la	$a0 int_const1
	addiu	$sp $sp 4
	lw	$t1 0($sp)
	move	$t2 $a0
	la	$a0 bool_const1
	la	$a1 bool_const0
	jal	equality_test
	lw	$t1 12($a0)
	beq	$t1 $zero label63
	la	$a0 int_const1
	j	label64
label63:
	la	$a0 int_const1
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	la	$a0 int_const0
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	lw	$a0 12($fp)
	bne	$a0 $zero label72
	la	$a0 str_const0
	li	$t1 309
	jal	_dispatch_abort
label72:
	lw	$t1 8($a0)
	lw	$t1 20($t1)
	jalr		$t1
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	la	$a0 str_const16
	addiu	$sp $sp 4
	lw	$t1 0($sp)
	move	$t2 $a0
	la	$a0 bool_const1
	la	$a1 bool_const0
	jal	equality_test
	lw	$t1 12($a0)
	beq	$t1 $zero label68
	la	$a0 int_const0
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	lw	$a0 12($fp)
	bne	$a0 $zero label75
	la	$a0 str_const0
	li	$t1 309
	jal	_dispatch_abort
label75:
	lw	$t1 8($a0)
	lw	$t1 12($t1)
	jalr		$t1
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	la	$a0 int_const0
	jal	Object.copy
	addiu	$sp $sp 4
	lw	$t1 0($sp)
	lw	$t1 12($t1)
	lw	$t2 12($a0)
	sub	$t3 $t1 $t2
	sw	$t3 12($a0)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	lw	$a0 12($fp)
	bne	$a0 $zero label74
	la	$a0 str_const0
	li	$t1 309
	jal	_dispatch_abort
label74:
	lw	$t1 8($a0)
	lw	$t1 20($t1)
	jalr		$t1
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s0
	bne	$a0 $zero label73
	la	$a0 str_const0
	li	$t1 309
	jal	_dispatch_abort
label73:
	lw	$t1 8($a0)
	lw	$t1 44($t1)
	jalr		$t1
	jal	Object.copy
	lw	$t1 12($a0)
	neg	$t1 $t1
	sw	$t1 12($a0)
	j	label69
label68:
	la	$a0 int_const1
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	la	$a0 int_const0
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	lw	$a0 12($fp)
	bne	$a0 $zero label80
	la	$a0 str_const0
	li	$t1 310
	jal	_dispatch_abort
label80:
	lw	$t1 8($a0)
	lw	$t1 20($t1)
	jalr		$t1
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	la	$a0 str_const17
	addiu	$sp $sp 4
	lw	$t1 0($sp)
	move	$t2 $a0
	la	$a0 bool_const1
	la	$a1 bool_const0
	jal	equality_test
	lw	$t1 12($a0)
	beq	$t1 $zero label76
	la	$a0 int_const0
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	lw	$a0 12($fp)
	bne	$a0 $zero label83
	la	$a0 str_const0
	li	$t1 310
	jal	_dispatch_abort
label83:
	lw	$t1 8($a0)
	lw	$t1 12($t1)
	jalr		$t1
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	la	$a0 int_const0
	jal	Object.copy
	addiu	$sp $sp 4
	lw	$t1 0($sp)
	lw	$t1 12($t1)
	lw	$t2 12($a0)
	sub	$t3 $t1 $t2
	sw	$t3 12($a0)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	lw	$a0 12($fp)
	bne	$a0 $zero label82
	la	$a0 str_const0
	li	$t1 310
	jal	_dispatch_abort
label82:
	lw	$t1 8($a0)
	lw	$t1 20($t1)
	jalr		$t1
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s0
	bne	$a0 $zero label81
	la	$a0 str_const0
	li	$t1 310
	jal	_dispatch_abort
label81:
	lw	$t1 8($a0)
	lw	$t1 40($t1)
	jalr		$t1
	j	label77
label76:
	lw	$a0 12($fp)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s0
	bne	$a0 $zero label84
	la	$a0 str_const0
	li	$t1 311
	jal	_dispatch_abort
label84:
	lw	$t1 8($a0)
	lw	$t1 44($t1)
	jalr		$t1
label77:
label69:
label64:
	lw	$ra 4($sp)
	lw	$s0 8($sp)
	lw	$fp 12($sp)
	addiu	$sp $sp 12
	addiu	$sp $sp 4
	jr	$ra	
Parse.c2i:
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	lw	$a0 12($fp)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	la	$a0 str_const6
	addiu	$sp $sp 4
	lw	$t1 0($sp)
	move	$t2 $a0
	la	$a0 bool_const1
	la	$a1 bool_const0
	jal	equality_test
	lw	$t1 12($a0)
	beq	$t1 $zero label85
	la	$a0 int_const1
	j	label86
label85:
	lw	$a0 12($fp)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	la	$a0 str_const7
	addiu	$sp $sp 4
	lw	$t1 0($sp)
	move	$t2 $a0
	la	$a0 bool_const1
	la	$a1 bool_const0
	jal	equality_test
	lw	$t1 12($a0)
	beq	$t1 $zero label89
	la	$a0 int_const0
	j	label90
label89:
	lw	$a0 12($fp)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	la	$a0 str_const8
	addiu	$sp $sp 4
	lw	$t1 0($sp)
	move	$t2 $a0
	la	$a0 bool_const1
	la	$a1 bool_const0
	jal	equality_test
	lw	$t1 12($a0)
	beq	$t1 $zero label93
	la	$a0 int_const2
	j	label94
label93:
	lw	$a0 12($fp)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	la	$a0 str_const9
	addiu	$sp $sp 4
	lw	$t1 0($sp)
	move	$t2 $a0
	la	$a0 bool_const1
	la	$a1 bool_const0
	jal	equality_test
	lw	$t1 12($a0)
	beq	$t1 $zero label97
	la	$a0 int_const3
	j	label98
label97:
	lw	$a0 12($fp)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	la	$a0 str_const10
	addiu	$sp $sp 4
	lw	$t1 0($sp)
	move	$t2 $a0
	la	$a0 bool_const1
	la	$a1 bool_const0
	jal	equality_test
	lw	$t1 12($a0)
	beq	$t1 $zero label101
	la	$a0 int_const4
	j	label102
label101:
	lw	$a0 12($fp)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	la	$a0 str_const11
	addiu	$sp $sp 4
	lw	$t1 0($sp)
	move	$t2 $a0
	la	$a0 bool_const1
	la	$a1 bool_const0
	jal	equality_test
	lw	$t1 12($a0)
	beq	$t1 $zero label105
	la	$a0 int_const5
	j	label106
label105:
	lw	$a0 12($fp)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	la	$a0 str_const12
	addiu	$sp $sp 4
	lw	$t1 0($sp)
	move	$t2 $a0
	la	$a0 bool_const1
	la	$a1 bool_const0
	jal	equality_test
	lw	$t1 12($a0)
	beq	$t1 $zero label109
	la	$a0 int_const6
	j	label110
label109:
	lw	$a0 12($fp)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	la	$a0 str_const13
	addiu	$sp $sp 4
	lw	$t1 0($sp)
	move	$t2 $a0
	la	$a0 bool_const1
	la	$a1 bool_const0
	jal	equality_test
	lw	$t1 12($a0)
	beq	$t1 $zero label113
	la	$a0 int_const7
	j	label114
label113:
	lw	$a0 12($fp)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	la	$a0 str_const14
	addiu	$sp $sp 4
	lw	$t1 0($sp)
	move	$t2 $a0
	la	$a0 bool_const1
	la	$a1 bool_const0
	jal	equality_test
	lw	$t1 12($a0)
	beq	$t1 $zero label117
	la	$a0 int_const8
	j	label118
label117:
	lw	$a0 12($fp)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	la	$a0 str_const15
	addiu	$sp $sp 4
	lw	$t1 0($sp)
	move	$t2 $a0
	la	$a0 bool_const1
	la	$a1 bool_const0
	jal	equality_test
	lw	$t1 12($a0)
	beq	$t1 $zero label121
	la	$a0 int_const9
	j	label122
label121:
	move	$a0 $s0
	bne	$a0 $zero label125
	la	$a0 str_const0
	li	$t1 301
	jal	_dispatch_abort
label125:
	lw	$t1 8($a0)
	lw	$t1 0($t1)
	jalr		$t1
	la	$a0 int_const1
label122:
label118:
label114:
label110:
label106:
label102:
label98:
label94:
label90:
label86:
	lw	$ra 4($sp)
	lw	$s0 8($sp)
	lw	$fp 12($sp)
	addiu	$sp $sp 12
	addiu	$sp $sp 4
	jr	$ra	
Parse.a2i_aux:
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	la	$a0 int_const1
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	lw	$a0 12($fp)
	bne	$a0 $zero label126
	la	$a0 str_const0
	li	$t1 324
	jal	_dispatch_abort
label126:
	lw	$t1 8($a0)
	lw	$t1 12($t1)
	jalr		$t1
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	la	$a0 int_const1
	sw	$a0 0($sp)
	addiu	$sp $sp -4
label127:
	lw	$a0 4($sp)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	lw	$a0 12($sp)
	addiu	$sp $sp 4
	lw	$t1 0($sp)
	move	$t2 $a0
	lw	$t1 12($t1)
	lw	$t2 12($t2)
	blt	$t1 $t2 label129
	la	$a0 bool_const0
	j	label130
label129:
	la	$a0 bool_const1
label130:
	lw	$t1 12($a0)
	beq	$t1 $zero label128
	lw	$a0 4($sp)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	la	$a0 int_const0
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	lw	$a0 12($fp)
	bne	$a0 $zero label131
	la	$a0 str_const0
	li	$t1 327
	jal	_dispatch_abort
label131:
	lw	$t1 8($a0)
	lw	$t1 20($t1)
	jalr		$t1
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	lw	$a0 4($sp)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	la	$a0 str_const17
	addiu	$sp $sp 4
	lw	$t1 0($sp)
	move	$t2 $a0
	la	$a0 bool_const1
	la	$a1 bool_const0
	jal	equality_test
	lw	$t1 12($a0)
	beq	$t1 $zero label132
	lw	$a0 8($sp)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	la	$a0 int_const0
	jal	Object.copy
	addiu	$sp $sp 4
	lw	$t1 0($sp)
	lw	$t1 12($t1)
	lw	$t2 12($a0)
	add	$t3 $t1 $t2
	sw	$t3 12($a0)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	lw	$a0 12($fp)
	bne	$a0 $zero label137
	la	$a0 str_const0
	li	$t1 330
	jal	_dispatch_abort
label137:
	lw	$t1 8($a0)
	lw	$t1 12($t1)
	jalr		$t1
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	lw	$a0 16($sp)
	jal	Object.copy
	addiu	$sp $sp 4
	lw	$t1 0($sp)
	lw	$t1 12($t1)
	lw	$t2 12($a0)
	sub	$t3 $t1 $t2
	sw	$t3 12($a0)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	la	$a0 int_const0
	jal	Object.copy
	addiu	$sp $sp 4
	lw	$t1 0($sp)
	lw	$t1 12($t1)
	lw	$t2 12($a0)
	sub	$t3 $t1 $t2
	sw	$t3 12($a0)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	lw	$a0 12($fp)
	bne	$a0 $zero label136
	la	$a0 str_const0
	li	$t1 330
	jal	_dispatch_abort
label136:
	lw	$t1 8($a0)
	lw	$t1 20($t1)
	jalr		$t1
	sw	$a0 16($s0)
	lw	$a0 12($sp)
	sw	$a0 8($sp)
	j	label133
label132:
	lw	$a0 4($sp)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	la	$a0 str_const2
	addiu	$sp $sp 4
	lw	$t1 0($sp)
	move	$t2 $a0
	la	$a0 bool_const1
	la	$a1 bool_const0
	jal	equality_test
	lw	$t1 12($a0)
	beq	$t1 $zero label138
	lw	$a0 8($sp)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	la	$a0 int_const0
	jal	Object.copy
	addiu	$sp $sp 4
	lw	$t1 0($sp)
	lw	$t1 12($t1)
	lw	$t2 12($a0)
	add	$t3 $t1 $t2
	sw	$t3 12($a0)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	lw	$a0 12($fp)
	bne	$a0 $zero label143
	la	$a0 str_const0
	li	$t1 335
	jal	_dispatch_abort
label143:
	lw	$t1 8($a0)
	lw	$t1 12($t1)
	jalr		$t1
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	lw	$a0 16($sp)
	jal	Object.copy
	addiu	$sp $sp 4
	lw	$t1 0($sp)
	lw	$t1 12($t1)
	lw	$t2 12($a0)
	sub	$t3 $t1 $t2
	sw	$t3 12($a0)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	la	$a0 int_const0
	jal	Object.copy
	addiu	$sp $sp 4
	lw	$t1 0($sp)
	lw	$t1 12($t1)
	lw	$t2 12($a0)
	sub	$t3 $t1 $t2
	sw	$t3 12($a0)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	lw	$a0 12($fp)
	bne	$a0 $zero label142
	la	$a0 str_const0
	li	$t1 335
	jal	_dispatch_abort
label142:
	lw	$t1 8($a0)
	lw	$t1 20($t1)
	jalr		$t1
	sw	$a0 16($s0)
	lw	$a0 12($sp)
	sw	$a0 8($sp)
	j	label139
label138:
	lw	$a0 16($sp)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	la	$a0 int_const10
	jal	Object.copy
	addiu	$sp $sp 4
	lw	$t1 0($sp)
	lw	$t1 12($t1)
	lw	$t2 12($a0)
	mul	$t3 $t1 $t2
	sw	$t3 12($a0)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	lw	$a0 12($sp)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	la	$a0 int_const0
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	lw	$a0 12($fp)
	bne	$a0 $zero label145
	la	$a0 str_const0
	li	$t1 340
	jal	_dispatch_abort
label145:
	lw	$t1 8($a0)
	lw	$t1 20($t1)
	jalr		$t1
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s0
	bne	$a0 $zero label144
	la	$a0 str_const0
	li	$t1 340
	jal	_dispatch_abort
label144:
	lw	$t1 8($a0)
	lw	$t1 36($t1)
	jalr		$t1
	jal	Object.copy
	addiu	$sp $sp 4
	lw	$t1 0($sp)
	lw	$t1 12($t1)
	lw	$t2 12($a0)
	add	$t3 $t1 $t2
	sw	$t3 12($a0)
	sw	$a0 16($sp)
	lw	$a0 8($sp)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	la	$a0 int_const0
	jal	Object.copy
	addiu	$sp $sp 4
	lw	$t1 0($sp)
	lw	$t1 12($t1)
	lw	$t2 12($a0)
	add	$t3 $t1 $t2
	sw	$t3 12($a0)
	sw	$a0 8($sp)
	lw	$a0 8($sp)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	lw	$a0 16($sp)
	addiu	$sp $sp 4
	lw	$t1 0($sp)
	move	$t2 $a0
	la	$a0 bool_const1
	la	$a1 bool_const0
	jal	equality_test
	lw	$t1 12($a0)
	beq	$t1 $zero label146
	la	$a0 str_const5
	sw	$a0 16($s0)
	j	label147
label146:
	la	$a0 str_const5
label147:
label139:
label133:
	addiu	$sp $sp 4
	j	label127
label128:
	move	$a0 $zero
	addiu	$sp $sp 4
	addiu	$sp $sp 4
	lw	$a0 4($sp)
	addiu	$sp $sp 4
	lw	$ra 4($sp)
	lw	$s0 8($sp)
	lw	$fp 12($sp)
	addiu	$sp $sp 12
	addiu	$sp $sp 4
	jr	$ra	
ECons.print:
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	lw	$a0 12($s0)
	bne	$a0 $zero label150
	la	$a0 str_const0
	li	$t1 184
	jal	_dispatch_abort
label150:
	lw	$t1 8($a0)
	lw	$t1 32($t1)
	jalr		$t1
	lw	$a0 16($s0)
	bne	$a0 $zero label151
	la	$a0 str_const0
	li	$t1 185
	jal	_dispatch_abort
label151:
	lw	$t1 8($a0)
	lw	$t1 48($t1)
	jalr		$t1
	lw	$ra 4($sp)
	lw	$s0 8($sp)
	lw	$fp 12($sp)
	addiu	$sp $sp 12
	jr	$ra	
ECons.init:
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	lw	$a0 16($fp)
	sw	$a0 12($s0)
	lw	$a0 12($fp)
	sw	$a0 16($s0)
	move	$a0 $s0
	lw	$ra 4($sp)
	lw	$s0 8($sp)
	lw	$fp 12($sp)
	addiu	$sp $sp 12
	addiu	$sp $sp 4
	addiu	$sp $sp 4
	jr	$ra	
ECons.isNil:
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	la	$a0 bool_const0
	lw	$ra 4($sp)
	lw	$s0 8($sp)
	lw	$fp 12($sp)
	addiu	$sp $sp 12
	jr	$ra	
ECons.head:
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	lw	$a0 12($s0)
	lw	$ra 4($sp)
	lw	$s0 8($sp)
	lw	$fp 12($sp)
	addiu	$sp $sp 12
	jr	$ra	
ECons.tail:
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	lw	$a0 16($s0)
	lw	$ra 4($sp)
	lw	$s0 8($sp)
	lw	$fp 12($sp)
	addiu	$sp $sp 12
	jr	$ra	
VCons.print:
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	lw	$a0 12($s0)
	bne	$a0 $zero label152
	la	$a0 str_const0
	li	$t1 241
	jal	_dispatch_abort
label152:
	lw	$t1 8($a0)
	lw	$t1 44($t1)
	jalr		$t1
	lw	$a0 16($s0)
	bne	$a0 $zero label153
	la	$a0 str_const0
	li	$t1 242
	jal	_dispatch_abort
label153:
	lw	$t1 8($a0)
	lw	$t1 44($t1)
	jalr		$t1
	lw	$ra 4($sp)
	lw	$s0 8($sp)
	lw	$fp 12($sp)
	addiu	$sp $sp 12
	jr	$ra	
VCons.init:
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	lw	$a0 16($fp)
	sw	$a0 12($s0)
	lw	$a0 12($fp)
	sw	$a0 16($s0)
	move	$a0 $s0
	lw	$ra 4($sp)
	lw	$s0 8($sp)
	lw	$fp 12($sp)
	addiu	$sp $sp 12
	addiu	$sp $sp 4
	addiu	$sp $sp 4
	jr	$ra	
VCons.isNil:
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	la	$a0 bool_const0
	lw	$ra 4($sp)
	lw	$s0 8($sp)
	lw	$fp 12($sp)
	addiu	$sp $sp 12
	jr	$ra	
VCons.head:
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	lw	$a0 12($s0)
	lw	$ra 4($sp)
	lw	$s0 8($sp)
	lw	$fp 12($sp)
	addiu	$sp $sp 12
	jr	$ra	
VCons.tail:
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	lw	$a0 16($s0)
	lw	$ra 4($sp)
	lw	$s0 8($sp)
	lw	$fp 12($sp)
	addiu	$sp $sp 12
	jr	$ra	
Main.main:
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	lw	$a0 20($s0)
	bne	$a0 $zero label154
	la	$a0 str_const0
	li	$t1 363
	jal	_dispatch_abort
label154:
	lw	$t1 8($a0)
	lw	$t1 20($t1)
	jalr		$t1
	lw	$a0 20($s0)
	bne	$a0 $zero label155
	la	$a0 str_const0
	li	$t1 364
	jal	_dispatch_abort
label155:
	lw	$t1 8($a0)
	lw	$t1 16($t1)
	jalr		$t1
	lw	$ra 4($sp)
	lw	$s0 8($sp)
	lw	$fp 12($sp)
	addiu	$sp $sp 12
	jr	$ra	

# end of generated code
