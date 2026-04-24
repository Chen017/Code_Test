	.file	"maximum.c"
	.def	___main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
	.align 4
LC0:
	.ascii "Up to 20 arguments supported (%d)\12\0"
LC1:
	.ascii "The maximum number is: %d\12\0"
	.text
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
LFB14:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	andl	$-16, %esp
	subl	$112, %esp
	call	___main
	cmpl	$21, 8(%ebp)
	jle	L2
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC0, (%esp)
	call	_printf
	movl	$1, (%esp)
	call	_exit
L2:
	movl	$0, 108(%esp)
	jmp	L3
L4:
	movl	108(%esp), %eax
	addl	$1, %eax
	leal	0(,%eax,4), %edx
	movl	12(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %eax
	movl	%eax, (%esp)
	call	_atoi
	movl	%eax, %edx
	movl	108(%esp), %eax
	movl	%edx, 24(%esp,%eax,4)
	addl	$1, 108(%esp)
L3:
	movl	8(%ebp), %eax
	subl	$1, %eax
	cmpl	108(%esp), %eax
	jg	L4
	movl	8(%ebp), %eax
	subl	$1, %eax
	movl	%eax, 4(%esp)
	leal	24(%esp), %eax
	movl	%eax, (%esp)
	call	_maximum
	movl	%eax, 104(%esp)
	movl	104(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$LC1, (%esp)
	call	_printf
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE14:
	.globl	_maximum
	.def	_maximum;	.scl	2;	.type	32;	.endef
_maximum:
LFB15:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$16, %esp
	movl	$-1, -4(%ebp)
	movl	$0, -8(%ebp)
	jmp	L6
L8:
	movl	-8(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %eax
	cmpl	-4(%ebp), %eax
	jl	L7
	movl	-8(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %eax
	movl	%eax, -4(%ebp)
L7:
	addl	$1, -8(%ebp)
L6:
	movl	-8(%ebp), %eax
	cmpl	12(%ebp), %eax
	jl	L8
	movl	-4(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE15:
	.ident	"GCC: (MinGW.org GCC-6.3.0-1) 6.3.0"
	.def	_printf;	.scl	2;	.type	32;	.endef
	.def	_exit;	.scl	2;	.type	32;	.endef
	.def	_atoi;	.scl	2;	.type	32;	.endef
