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
str_const11:
	.word	4
	.word	5
	.word	String_dispTab
	.word	int_const0
	.byte	0	
	.align	2
	.word	-1
str_const10:
	.word	4
	.word	6
	.word	String_dispTab
	.word	int_const3
	.ascii	"Main"
	.byte	0	
	.align	2
	.word	-1
str_const9:
	.word	4
	.word	6
	.word	String_dispTab
	.word	int_const4
	.ascii	"String"
	.byte	0	
	.align	2
	.word	-1
str_const8:
	.word	4
	.word	6
	.word	String_dispTab
	.word	int_const3
	.ascii	"Bool"
	.byte	0	
	.align	2
	.word	-1
str_const7:
	.word	4
	.word	5
	.word	String_dispTab
	.word	int_const5
	.ascii	"Int"
	.byte	0	
	.align	2
	.word	-1
str_const6:
	.word	4
	.word	5
	.word	String_dispTab
	.word	int_const6
	.ascii	"IO"
	.byte	0	
	.align	2
	.word	-1
str_const5:
	.word	4
	.word	6
	.word	String_dispTab
	.word	int_const4
	.ascii	"Object"
	.byte	0	
	.align	2
	.word	-1
str_const4:
	.word	4
	.word	7
	.word	String_dispTab
	.word	int_const7
	.ascii	"_prim_slot"
	.byte	0	
	.align	2
	.word	-1
str_const3:
	.word	4
	.word	7
	.word	String_dispTab
	.word	int_const8
	.ascii	"SELF_TYPE"
	.byte	0	
	.align	2
	.word	-1
str_const2:
	.word	4
	.word	7
	.word	String_dispTab
	.word	int_const8
	.ascii	"_no_class"
	.byte	0	
	.align	2
	.word	-1
str_const1:
	.word	4
	.word	8
	.word	String_dispTab
	.word	int_const9
	.ascii	"<basic class>"
	.byte	0	
	.align	2
	.word	-1
str_const0:
	.word	4
	.word	7
	.word	String_dispTab
	.word	int_const10
	.ascii	"./not.cl"
	.byte	0	
	.align	2
	.word	-1
int_const10:
	.word	3
	.word	4
	.word	Int_dispTab
	.word	8
	.word	-1
int_const9:
	.word	3
	.word	4
	.word	Int_dispTab
	.word	13
	.word	-1
int_const8:
	.word	3
	.word	4
	.word	Int_dispTab
	.word	9
	.word	-1
int_const7:
	.word	3
	.word	4
	.word	Int_dispTab
	.word	10
	.word	-1
int_const6:
	.word	3
	.word	4
	.word	Int_dispTab
	.word	2
	.word	-1
int_const5:
	.word	3
	.word	4
	.word	Int_dispTab
	.word	3
	.word	-1
int_const4:
	.word	3
	.word	4
	.word	Int_dispTab
	.word	6
	.word	-1
int_const3:
	.word	3
	.word	4
	.word	Int_dispTab
	.word	4
	.word	-1
int_const2:
	.word	3
	.word	4
	.word	Int_dispTab
	.word	1
	.word	-1
int_const1:
	.word	3
	.word	4
	.word	Int_dispTab
	.word	100
	.word	-1
int_const0:
	.word	3
	.word	4
	.word	Int_dispTab
	.word	0
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
	.word	str_const5
	.word	str_const6
	.word	str_const8
	.word	str_const7
	.word	str_const9
	.word	str_const10
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
	.word	Main_protObj
	.word	Main_init
class_parentTab:
	.word	-1
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
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
Main_dispTab:
	.word	Object.abort
	.word	Object.type_name
	.word	Object.copy
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
	.word	int_const0
	.word	0
	.word	-1
Main_protObj:
	.word	5
	.word	3
	.word	Main_dispTab
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
Main_init:
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
Main.main:
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	la	$a0 int_const0
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $zero
	la	$a0 bool_const0
	sw	$a0 0($sp)
	addiu	$sp $sp -4
label0:
	lw	$a0 8($sp)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	la	$a0 int_const1
	addiu	$sp $sp 4
	lw	$t1 0($sp)
	move	$t2 $a0
	lw	$t1 12($t1)
	lw	$t2 12($t2)
	blt	$t1 $t2 label2
	la	$a0 bool_const0
	j	label3
label2:
	la	$a0 bool_const1
label3:
	lw	$t1 12($a0)
	beq	$t1 $zero label1
	lw	$a0 4($sp)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	lw	$a0 8($sp)
	lw	$t1 12($a0)
	beq	$t1 $zero label26
	la	$a0 bool_const0
	j	label27
label26:
	la	$a0 bool_const1
label27:
	lw	$t1 12($a0)
	beq	$t1 $zero label24
	la	$a0 bool_const0
	j	label25
label24:
	la	$a0 bool_const1
label25:
	lw	$t1 12($a0)
	beq	$t1 $zero label22
	la	$a0 bool_const0
	j	label23
label22:
	la	$a0 bool_const1
label23:
	lw	$t1 12($a0)
	beq	$t1 $zero label20
	la	$a0 bool_const0
	j	label21
label20:
	la	$a0 bool_const1
label21:
	lw	$t1 12($a0)
	beq	$t1 $zero label18
	la	$a0 bool_const0
	j	label19
label18:
	la	$a0 bool_const1
label19:
	lw	$t1 12($a0)
	beq	$t1 $zero label16
	la	$a0 bool_const0
	j	label17
label16:
	la	$a0 bool_const1
label17:
	lw	$t1 12($a0)
	beq	$t1 $zero label14
	la	$a0 bool_const0
	j	label15
label14:
	la	$a0 bool_const1
label15:
	lw	$t1 12($a0)
	beq	$t1 $zero label12
	la	$a0 bool_const0
	j	label13
label12:
	la	$a0 bool_const1
label13:
	lw	$t1 12($a0)
	beq	$t1 $zero label10
	la	$a0 bool_const0
	j	label11
label10:
	la	$a0 bool_const1
label11:
	lw	$t1 12($a0)
	beq	$t1 $zero label8
	la	$a0 bool_const0
	j	label9
label8:
	la	$a0 bool_const1
label9:
	lw	$t1 12($a0)
	beq	$t1 $zero label6
	la	$a0 bool_const0
	j	label7
label6:
	la	$a0 bool_const1
label7:
	addiu	$sp $sp 4
	lw	$t1 0($sp)
	move	$t2 $a0
	la	$a0 bool_const1
	la	$a1 bool_const0
	jal	equality_test
	lw	$a0 4($sp)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	lw	$a0 8($sp)
	lw	$t1 12($a0)
	beq	$t1 $zero label50
	la	$a0 bool_const0
	j	label51
label50:
	la	$a0 bool_const1
label51:
	lw	$t1 12($a0)
	beq	$t1 $zero label48
	la	$a0 bool_const0
	j	label49
label48:
	la	$a0 bool_const1
label49:
	lw	$t1 12($a0)
	beq	$t1 $zero label46
	la	$a0 bool_const0
	j	label47
label46:
	la	$a0 bool_const1
label47:
	lw	$t1 12($a0)
	beq	$t1 $zero label44
	la	$a0 bool_const0
	j	label45
label44:
	la	$a0 bool_const1
label45:
	lw	$t1 12($a0)
	beq	$t1 $zero label42
	la	$a0 bool_const0
	j	label43
label42:
	la	$a0 bool_const1
label43:
	lw	$t1 12($a0)
	beq	$t1 $zero label40
	la	$a0 bool_const0
	j	label41
label40:
	la	$a0 bool_const1
label41:
	lw	$t1 12($a0)
	beq	$t1 $zero label38
	la	$a0 bool_const0
	j	label39
label38:
	la	$a0 bool_const1
label39:
	lw	$t1 12($a0)
	beq	$t1 $zero label36
	la	$a0 bool_const0
	j	label37
label36:
	la	$a0 bool_const1
label37:
	lw	$t1 12($a0)
	beq	$t1 $zero label34
	la	$a0 bool_const0
	j	label35
label34:
	la	$a0 bool_const1
label35:
	lw	$t1 12($a0)
	beq	$t1 $zero label32
	la	$a0 bool_const0
	j	label33
label32:
	la	$a0 bool_const1
label33:
	lw	$t1 12($a0)
	beq	$t1 $zero label30
	la	$a0 bool_const0
	j	label31
label30:
	la	$a0 bool_const1
label31:
	addiu	$sp $sp 4
	lw	$t1 0($sp)
	move	$t2 $a0
	la	$a0 bool_const1
	la	$a1 bool_const0
	jal	equality_test
	lw	$a0 4($sp)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	lw	$a0 8($sp)
	lw	$t1 12($a0)
	beq	$t1 $zero label74
	la	$a0 bool_const0
	j	label75
label74:
	la	$a0 bool_const1
label75:
	lw	$t1 12($a0)
	beq	$t1 $zero label72
	la	$a0 bool_const0
	j	label73
label72:
	la	$a0 bool_const1
label73:
	lw	$t1 12($a0)
	beq	$t1 $zero label70
	la	$a0 bool_const0
	j	label71
label70:
	la	$a0 bool_const1
label71:
	lw	$t1 12($a0)
	beq	$t1 $zero label68
	la	$a0 bool_const0
	j	label69
label68:
	la	$a0 bool_const1
label69:
	lw	$t1 12($a0)
	beq	$t1 $zero label66
	la	$a0 bool_const0
	j	label67
label66:
	la	$a0 bool_const1
label67:
	lw	$t1 12($a0)
	beq	$t1 $zero label64
	la	$a0 bool_const0
	j	label65
label64:
	la	$a0 bool_const1
label65:
	lw	$t1 12($a0)
	beq	$t1 $zero label62
	la	$a0 bool_const0
	j	label63
label62:
	la	$a0 bool_const1
label63:
	lw	$t1 12($a0)
	beq	$t1 $zero label60
	la	$a0 bool_const0
	j	label61
label60:
	la	$a0 bool_const1
label61:
	lw	$t1 12($a0)
	beq	$t1 $zero label58
	la	$a0 bool_const0
	j	label59
label58:
	la	$a0 bool_const1
label59:
	lw	$t1 12($a0)
	beq	$t1 $zero label56
	la	$a0 bool_const0
	j	label57
label56:
	la	$a0 bool_const1
label57:
	lw	$t1 12($a0)
	beq	$t1 $zero label54
	la	$a0 bool_const0
	j	label55
label54:
	la	$a0 bool_const1
label55:
	addiu	$sp $sp 4
	lw	$t1 0($sp)
	move	$t2 $a0
	la	$a0 bool_const1
	la	$a1 bool_const0
	jal	equality_test
	lw	$a0 4($sp)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	lw	$a0 8($sp)
	lw	$t1 12($a0)
	beq	$t1 $zero label98
	la	$a0 bool_const0
	j	label99
label98:
	la	$a0 bool_const1
label99:
	lw	$t1 12($a0)
	beq	$t1 $zero label96
	la	$a0 bool_const0
	j	label97
label96:
	la	$a0 bool_const1
label97:
	lw	$t1 12($a0)
	beq	$t1 $zero label94
	la	$a0 bool_const0
	j	label95
label94:
	la	$a0 bool_const1
label95:
	lw	$t1 12($a0)
	beq	$t1 $zero label92
	la	$a0 bool_const0
	j	label93
label92:
	la	$a0 bool_const1
label93:
	lw	$t1 12($a0)
	beq	$t1 $zero label90
	la	$a0 bool_const0
	j	label91
label90:
	la	$a0 bool_const1
label91:
	lw	$t1 12($a0)
	beq	$t1 $zero label88
	la	$a0 bool_const0
	j	label89
label88:
	la	$a0 bool_const1
label89:
	lw	$t1 12($a0)
	beq	$t1 $zero label86
	la	$a0 bool_const0
	j	label87
label86:
	la	$a0 bool_const1
label87:
	lw	$t1 12($a0)
	beq	$t1 $zero label84
	la	$a0 bool_const0
	j	label85
label84:
	la	$a0 bool_const1
label85:
	lw	$t1 12($a0)
	beq	$t1 $zero label82
	la	$a0 bool_const0
	j	label83
label82:
	la	$a0 bool_const1
label83:
	lw	$t1 12($a0)
	beq	$t1 $zero label80
	la	$a0 bool_const0
	j	label81
label80:
	la	$a0 bool_const1
label81:
	lw	$t1 12($a0)
	beq	$t1 $zero label78
	la	$a0 bool_const0
	j	label79
label78:
	la	$a0 bool_const1
label79:
	addiu	$sp $sp 4
	lw	$t1 0($sp)
	move	$t2 $a0
	la	$a0 bool_const1
	la	$a1 bool_const0
	jal	equality_test
	lw	$a0 4($sp)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	lw	$a0 8($sp)
	lw	$t1 12($a0)
	beq	$t1 $zero label122
	la	$a0 bool_const0
	j	label123
label122:
	la	$a0 bool_const1
label123:
	lw	$t1 12($a0)
	beq	$t1 $zero label120
	la	$a0 bool_const0
	j	label121
label120:
	la	$a0 bool_const1
label121:
	lw	$t1 12($a0)
	beq	$t1 $zero label118
	la	$a0 bool_const0
	j	label119
label118:
	la	$a0 bool_const1
label119:
	lw	$t1 12($a0)
	beq	$t1 $zero label116
	la	$a0 bool_const0
	j	label117
label116:
	la	$a0 bool_const1
label117:
	lw	$t1 12($a0)
	beq	$t1 $zero label114
	la	$a0 bool_const0
	j	label115
label114:
	la	$a0 bool_const1
label115:
	lw	$t1 12($a0)
	beq	$t1 $zero label112
	la	$a0 bool_const0
	j	label113
label112:
	la	$a0 bool_const1
label113:
	lw	$t1 12($a0)
	beq	$t1 $zero label110
	la	$a0 bool_const0
	j	label111
label110:
	la	$a0 bool_const1
label111:
	lw	$t1 12($a0)
	beq	$t1 $zero label108
	la	$a0 bool_const0
	j	label109
label108:
	la	$a0 bool_const1
label109:
	lw	$t1 12($a0)
	beq	$t1 $zero label106
	la	$a0 bool_const0
	j	label107
label106:
	la	$a0 bool_const1
label107:
	lw	$t1 12($a0)
	beq	$t1 $zero label104
	la	$a0 bool_const0
	j	label105
label104:
	la	$a0 bool_const1
label105:
	lw	$t1 12($a0)
	beq	$t1 $zero label102
	la	$a0 bool_const0
	j	label103
label102:
	la	$a0 bool_const1
label103:
	addiu	$sp $sp 4
	lw	$t1 0($sp)
	move	$t2 $a0
	la	$a0 bool_const1
	la	$a1 bool_const0
	jal	equality_test
	lw	$a0 8($sp)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	la	$a0 int_const2
	jal	Object.copy
	addiu	$sp $sp 4
	lw	$t1 0($sp)
	lw	$t1 12($t1)
	lw	$t2 12($a0)
	add	$t3 $t1 $t2
	sw	$t3 12($a0)
	sw	$a0 8($sp)
	j	label0
label1:
	move	$a0 $zero
	lw	$a0 4($sp)
	lw	$t1 12($a0)
	beq	$t1 $zero label124
	move	$a0 $s0
	bne	$a0 $zero label126
	la	$a0 str_const0
	li	$t1 18
	jal	_dispatch_abort
label126:
	lw	$t1 8($a0)
	lw	$t1 0($t1)
	jalr		$t1
	j	label125
label124:
	la	$a0 int_const0
label125:
	addiu	$sp $sp 4
	addiu	$sp $sp 4
	lw	$ra 4($sp)
	lw	$s0 8($sp)
	lw	$fp 12($sp)
	addiu	$sp $sp 12
	jr	$ra	

# end of generated code
