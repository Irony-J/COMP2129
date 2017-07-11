	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 12
	.file	1 "/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.12.sdk/usr/include/i386" "_types.h"
	.file	2 "/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.12.sdk/usr/include/sys/_types" "_size_t.h"
	.file	3 "ParallelSum.c"
	.globl	_worker
	.align	4, 0x90
_worker:                                ## @worker
Lfunc_begin0:
	.loc	3 16 0                  ## ParallelSum.c:16:0
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp0:
	.cfi_def_cfa_offset 16
Ltmp1:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp2:
	.cfi_def_cfa_register %rbp
	movq	%rdi, -8(%rbp)
	.loc	3 17 38 prologue_end    ## ParallelSum.c:17:38
Ltmp3:
	movq	-8(%rbp), %rdi
	.loc	3 17 15 is_stmt 0       ## ParallelSum.c:17:15
	movq	%rdi, -16(%rbp)
	.loc	3 18 23 is_stmt 1       ## ParallelSum.c:18:23
	movq	-16(%rbp), %rdi
	.loc	3 18 33 is_stmt 0       ## ParallelSum.c:18:33
	imulq	$12500000, (%rdi), %rdi ## imm = 0xBEBC20
	.loc	3 18 15                 ## ParallelSum.c:18:15
	movq	%rdi, -24(%rbp)
	.loc	3 19 21 is_stmt 1       ## ParallelSum.c:19:21
	movq	-16(%rbp), %rdi
	.loc	3 19 31 is_stmt 0       ## ParallelSum.c:19:31
	cmpq	$7, (%rdi)
	.loc	3 19 21                 ## ParallelSum.c:19:21
	jne	LBB0_2
## BB#1:
	movl	$100000000, %eax        ## imm = 0x5F5E100
	movl	%eax, %ecx
	movq	%rcx, -48(%rbp)         ## 8-byte Spill
	jmp	LBB0_3
LBB0_2:
	.loc	3 19 59                 ## ParallelSum.c:19:59
	movq	-16(%rbp), %rax
	.loc	3 19 66                 ## ParallelSum.c:19:66
	movq	(%rax), %rax
	.loc	3 19 69                 ## ParallelSum.c:19:69
	addq	$1, %rax
	.loc	3 19 74                 ## ParallelSum.c:19:74
	imulq	$12500000, %rax, %rax   ## imm = 0xBEBC20
	movq	%rax, -48(%rbp)         ## 8-byte Spill
LBB0_3:
	.loc	3 19 21                 ## ParallelSum.c:19:21
	movq	-48(%rbp), %rax         ## 8-byte Reload
	.loc	3 19 15                 ## ParallelSum.c:19:15
	movq	%rax, -32(%rbp)
	.loc	3 21 18 is_stmt 1       ## ParallelSum.c:21:18
Ltmp4:
	movq	-24(%rbp), %rax
	.loc	3 21 14 is_stmt 0       ## ParallelSum.c:21:14
	movq	%rax, -40(%rbp)
LBB0_4:                                 ## =>This Inner Loop Header: Depth=1
	.loc	3 21 25                 ## ParallelSum.c:21:25
Ltmp5:
	movq	-40(%rbp), %rax
	.loc	3 21 27                 ## ParallelSum.c:21:27
	cmpq	-32(%rbp), %rax
Ltmp6:
	.loc	3 21 2                  ## ParallelSum.c:21:2
	jae	LBB0_7
## BB#5:                                ##   in Loop: Header=BB0_4 Depth=1
	.loc	3 22 33 is_stmt 1       ## ParallelSum.c:22:33
Ltmp7:
	movq	-40(%rbp), %rax
	.loc	3 22 20 is_stmt 0       ## ParallelSum.c:22:20
	movq	-16(%rbp), %rcx
	.loc	3 22 27                 ## ParallelSum.c:22:27
	movq	8(%rcx), %rcx
	.loc	3 22 20                 ## ParallelSum.c:22:20
	movq	(%rcx,%rax,8), %rax
	.loc	3 22 3                  ## ParallelSum.c:22:3
	movq	-16(%rbp), %rcx
	.loc	3 22 17                 ## ParallelSum.c:22:17
	addq	16(%rcx), %rax
	movq	%rax, 16(%rcx)
Ltmp8:
## BB#6:                                ##   in Loop: Header=BB0_4 Depth=1
	.loc	3 21 35 is_stmt 1       ## ParallelSum.c:21:35
	movq	-40(%rbp), %rax
	addq	$1, %rax
	movq	%rax, -40(%rbp)
	.loc	3 21 2 is_stmt 0        ## ParallelSum.c:21:2
	jmp	LBB0_4
Ltmp9:
LBB0_7:
	xorl	%eax, %eax
                                        ## 
	.loc	3 24 2 is_stmt 1        ## ParallelSum.c:24:2
	popq	%rbp
	retq
Ltmp10:
Lfunc_end0:
	.cfi_endproc

	.globl	_main
	.align	4, 0x90
_main:                                  ## @main
Lfunc_begin1:
	.loc	3 28 0                  ## ParallelSum.c:28:0
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp11:
	.cfi_def_cfa_offset 16
Ltmp12:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp13:
	.cfi_def_cfa_register %rbp
	subq	$208, %rsp
	movl	$800000000, %eax        ## imm = 0x2FAF0800
	movl	%eax, %edi
	movq	___stack_chk_guard@GOTPCREL(%rip), %rcx
	movq	(%rcx), %rcx
	movq	%rcx, -8(%rbp)
	movl	$0, -84(%rbp)
	.loc	3 29 18 prologue_end    ## ParallelSum.c:29:18
Ltmp14:
	callq	_malloc
	.loc	3 29 8 is_stmt 0        ## ParallelSum.c:29:8
	movq	%rax, -96(%rbp)
	.loc	3 30 14 is_stmt 1       ## ParallelSum.c:30:14
Ltmp15:
	movq	$0, -104(%rbp)
LBB1_1:                                 ## =>This Inner Loop Header: Depth=1
	.loc	3 30 23 is_stmt 0       ## ParallelSum.c:30:23
Ltmp16:
	cmpq	$100000000, -104(%rbp)  ## imm = 0x5F5E100
Ltmp17:
	.loc	3 30 2                  ## ParallelSum.c:30:2
	jae	LBB1_4
## BB#2:                                ##   in Loop: Header=BB1_1 Depth=1
	.loc	3 31 22 is_stmt 1       ## ParallelSum.c:31:22
Ltmp18:
	movq	-104(%rbp), %rax
	.loc	3 31 24 is_stmt 0       ## ParallelSum.c:31:24
	addq	$1, %rax
	.loc	3 31 17                 ## ParallelSum.c:31:17
	movq	-104(%rbp), %rcx
	.loc	3 31 9                  ## ParallelSum.c:31:9
	movq	-96(%rbp), %rdx
	.loc	3 31 20                 ## ParallelSum.c:31:20
	movq	%rax, (%rdx,%rcx,8)
Ltmp19:
## BB#3:                                ##   in Loop: Header=BB1_1 Depth=1
	.loc	3 30 34 is_stmt 1       ## ParallelSum.c:30:34
	movq	-104(%rbp), %rax
	addq	$1, %rax
	movq	%rax, -104(%rbp)
	.loc	3 30 2 is_stmt 0        ## ParallelSum.c:30:2
	jmp	LBB1_1
Ltmp20:
LBB1_4:
	movl	$192, %eax
	movl	%eax, %edi
	.loc	3 33 22 is_stmt 1       ## ParallelSum.c:33:22
	callq	_malloc
	.loc	3 33 15 is_stmt 0       ## ParallelSum.c:33:15
	movq	%rax, -112(%rbp)
	.loc	3 34 14 is_stmt 1       ## ParallelSum.c:34:14
Ltmp21:
	movq	$1, -120(%rbp)
LBB1_5:                                 ## =>This Loop Header: Depth=1
                                        ##     Child Loop BB1_7 Depth 2
                                        ##     Child Loop BB1_11 Depth 2
                                        ##     Child Loop BB1_15 Depth 2
                                        ##     Child Loop BB1_19 Depth 2
	.loc	3 34 23 is_stmt 0       ## ParallelSum.c:34:23
Ltmp22:
	cmpq	$10, -120(%rbp)
Ltmp23:
	.loc	3 34 2                  ## ParallelSum.c:34:2
	ja	LBB1_24
## BB#6:                                ##   in Loop: Header=BB1_5 Depth=1
	.loc	3 35 15 is_stmt 1       ## ParallelSum.c:35:15
Ltmp24:
	movq	$0, -128(%rbp)
LBB1_7:                                 ##   Parent Loop BB1_5 Depth=1
                                        ## =>  This Inner Loop Header: Depth=2
	.loc	3 35 24 is_stmt 0       ## ParallelSum.c:35:24
Ltmp25:
	cmpq	$8, -128(%rbp)
Ltmp26:
	.loc	3 35 3                  ## ParallelSum.c:35:3
	jae	LBB1_10
## BB#8:                                ##   in Loop: Header=BB1_7 Depth=2
	.loc	3 36 10 is_stmt 1       ## ParallelSum.c:36:10
Ltmp27:
	movq	-128(%rbp), %rax
	.loc	3 36 5 is_stmt 0        ## ParallelSum.c:36:5
	imulq	$24, %rax, %rax
	addq	-112(%rbp), %rax
	.loc	3 37 27 is_stmt 1       ## ParallelSum.c:37:27
	movq	-128(%rbp), %rcx
	.loc	3 36 29                 ## ParallelSum.c:36:29
	movq	%rcx, -152(%rbp)
	.loc	3 38 27                 ## ParallelSum.c:38:27
	movq	-96(%rbp), %rcx
	.loc	3 36 29                 ## ParallelSum.c:36:29
	movq	%rcx, -144(%rbp)
	movq	$0, -136(%rbp)
	.loc	3 36 15 is_stmt 0       ## ParallelSum.c:36:15
	movq	-152(%rbp), %rcx
	movq	%rcx, (%rax)
	movq	-144(%rbp), %rcx
	movq	%rcx, 8(%rax)
	movq	-136(%rbp), %rcx
	movq	%rcx, 16(%rax)
Ltmp28:
## BB#9:                                ##   in Loop: Header=BB1_7 Depth=2
	.loc	3 35 37 is_stmt 1       ## ParallelSum.c:35:37
	movq	-128(%rbp), %rax
	addq	$1, %rax
	movq	%rax, -128(%rbp)
	.loc	3 35 3 is_stmt 0        ## ParallelSum.c:35:3
	jmp	LBB1_7
Ltmp29:
LBB1_10:                                ##   in Loop: Header=BB1_5 Depth=1
	.loc	3 44 15 is_stmt 1       ## ParallelSum.c:44:15
	movq	$0, -160(%rbp)
LBB1_11:                                ##   Parent Loop BB1_5 Depth=1
                                        ## =>  This Inner Loop Header: Depth=2
	.loc	3 44 24 is_stmt 0       ## ParallelSum.c:44:24
Ltmp30:
	cmpq	$8, -160(%rbp)
Ltmp31:
	.loc	3 44 3                  ## ParallelSum.c:44:3
	jae	LBB1_14
## BB#12:                               ##   in Loop: Header=BB1_11 Depth=2
	xorl	%eax, %eax
	movl	%eax, %esi
	leaq	_worker(%rip), %rdx
	leaq	-80(%rbp), %rcx
	.loc	3 45 32 is_stmt 1       ## ParallelSum.c:45:32
Ltmp32:
	movq	-160(%rbp), %rdi
	.loc	3 45 30 is_stmt 0       ## ParallelSum.c:45:30
	shlq	$3, %rdi
	addq	%rdi, %rcx
	.loc	3 45 49                 ## ParallelSum.c:45:49
	movq	-112(%rbp), %rdi
	.loc	3 45 54                 ## ParallelSum.c:45:54
	imulq	$24, -160(%rbp), %r8
	addq	%r8, %rdi
	.loc	3 45 4                  ## ParallelSum.c:45:4
	movq	%rdi, -192(%rbp)        ## 8-byte Spill
	movq	%rcx, %rdi
	movq	-192(%rbp), %rcx        ## 8-byte Reload
	callq	_pthread_create
	movl	%eax, -196(%rbp)        ## 4-byte Spill
Ltmp33:
## BB#13:                               ##   in Loop: Header=BB1_11 Depth=2
	.loc	3 44 37 is_stmt 1       ## ParallelSum.c:44:37
	movq	-160(%rbp), %rax
	addq	$1, %rax
	movq	%rax, -160(%rbp)
	.loc	3 44 3 is_stmt 0        ## ParallelSum.c:44:3
	jmp	LBB1_11
Ltmp34:
LBB1_14:                                ##   in Loop: Header=BB1_5 Depth=1
	.loc	3 48 15 is_stmt 1       ## ParallelSum.c:48:15
	movq	$0, -168(%rbp)
LBB1_15:                                ##   Parent Loop BB1_5 Depth=1
                                        ## =>  This Inner Loop Header: Depth=2
	.loc	3 48 24 is_stmt 0       ## ParallelSum.c:48:24
Ltmp35:
	cmpq	$8, -168(%rbp)
Ltmp36:
	.loc	3 48 3                  ## ParallelSum.c:48:3
	jae	LBB1_18
## BB#16:                               ##   in Loop: Header=BB1_15 Depth=2
	xorl	%eax, %eax
	movl	%eax, %esi
	.loc	3 49 28 is_stmt 1       ## ParallelSum.c:49:28
Ltmp37:
	movq	-168(%rbp), %rcx
	.loc	3 49 17 is_stmt 0       ## ParallelSum.c:49:17
	movq	-80(%rbp,%rcx,8), %rdi
	.loc	3 49 4                  ## ParallelSum.c:49:4
	callq	_pthread_join
	movl	%eax, -200(%rbp)        ## 4-byte Spill
Ltmp38:
## BB#17:                               ##   in Loop: Header=BB1_15 Depth=2
	.loc	3 48 37 is_stmt 1       ## ParallelSum.c:48:37
	movq	-168(%rbp), %rax
	addq	$1, %rax
	movq	%rax, -168(%rbp)
	.loc	3 48 3 is_stmt 0        ## ParallelSum.c:48:3
	jmp	LBB1_15
Ltmp39:
LBB1_18:                                ##   in Loop: Header=BB1_5 Depth=1
	.loc	3 52 8 is_stmt 1        ## ParallelSum.c:52:8
	movq	$0, -176(%rbp)
	.loc	3 54 15                 ## ParallelSum.c:54:15
Ltmp40:
	movq	$0, -184(%rbp)
LBB1_19:                                ##   Parent Loop BB1_5 Depth=1
                                        ## =>  This Inner Loop Header: Depth=2
	.loc	3 54 24 is_stmt 0       ## ParallelSum.c:54:24
Ltmp41:
	cmpq	$8, -184(%rbp)
Ltmp42:
	.loc	3 54 3                  ## ParallelSum.c:54:3
	jae	LBB1_22
## BB#20:                               ##   in Loop: Header=BB1_19 Depth=2
	.loc	3 55 16 is_stmt 1       ## ParallelSum.c:55:16
Ltmp43:
	movq	-184(%rbp), %rax
	.loc	3 55 11 is_stmt 0       ## ParallelSum.c:55:11
	imulq	$24, %rax, %rax
	addq	-112(%rbp), %rax
	.loc	3 55 19                 ## ParallelSum.c:55:19
	movq	16(%rax), %rax
	.loc	3 55 8                  ## ParallelSum.c:55:8
	addq	-176(%rbp), %rax
	movq	%rax, -176(%rbp)
Ltmp44:
## BB#21:                               ##   in Loop: Header=BB1_19 Depth=2
	.loc	3 54 37 is_stmt 1       ## ParallelSum.c:54:37
	movq	-184(%rbp), %rax
	addq	$1, %rax
	movq	%rax, -184(%rbp)
	.loc	3 54 3 is_stmt 0        ## ParallelSum.c:54:3
	jmp	LBB1_19
Ltmp45:
LBB1_22:                                ##   in Loop: Header=BB1_5 Depth=1
	leaq	L_.str(%rip), %rdi
	.loc	3 57 42 is_stmt 1       ## ParallelSum.c:57:42
	movq	-120(%rbp), %rsi
	.loc	3 57 45 is_stmt 0       ## ParallelSum.c:57:45
	movq	-176(%rbp), %rdx
	.loc	3 57 3                  ## ParallelSum.c:57:3
	movb	$0, %al
	callq	_printf
	movl	%eax, -204(%rbp)        ## 4-byte Spill
Ltmp46:
## BB#23:                               ##   in Loop: Header=BB1_5 Depth=1
	.loc	3 34 37 is_stmt 1       ## ParallelSum.c:34:37
	movq	-120(%rbp), %rax
	addq	$1, %rax
	movq	%rax, -120(%rbp)
	.loc	3 34 2 is_stmt 0        ## ParallelSum.c:34:2
	jmp	LBB1_5
Ltmp47:
LBB1_24:
	.loc	3 60 7 is_stmt 1        ## ParallelSum.c:60:7
	movq	-112(%rbp), %rax
	.loc	3 60 2 is_stmt 0        ## ParallelSum.c:60:2
	movq	%rax, %rdi
	callq	_free
	.loc	3 61 10 is_stmt 1       ## ParallelSum.c:61:10
	movq	-96(%rbp), %rax
	.loc	3 61 5 is_stmt 0        ## ParallelSum.c:61:5
	movq	%rax, %rdi
	callq	_free
	movq	___stack_chk_guard@GOTPCREL(%rip), %rax
	.loc	3 62 1 is_stmt 1        ## ParallelSum.c:62:1
	movl	-84(%rbp), %ecx
	movq	(%rax), %rax
	cmpq	-8(%rbp), %rax
	movl	%ecx, -208(%rbp)        ## 4-byte Spill
	jne	LBB1_26
## BB#25:
	movl	-208(%rbp), %eax        ## 4-byte Reload
	addq	$208, %rsp
	popq	%rbp
	retq
Ltmp48:
LBB1_26:
	callq	___stack_chk_fail
Lfunc_end1:
	.cfi_endproc

	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"Run %2zu: total sum is %ld\n"

	.file	4 "/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.12.sdk/usr/include/sys/_pthread" "_pthread_types.h"
	.file	5 "/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.12.sdk/usr/include/sys/_pthread" "_pthread_t.h"
	.section	__DWARF,__debug_str,regular,debug
Linfo_string:
	.asciz	"Apple LLVM version 8.0.0 (clang-800.0.42.1)" ## string offset=0
	.asciz	"ParallelSum.c"         ## string offset=44
	.asciz	"/Users/irony/Documents/Code/COMP2129" ## string offset=58
	.asciz	"worker_args"           ## string offset=95
	.asciz	"id"                    ## string offset=107
	.asciz	"size_t"                ## string offset=110
	.asciz	"__darwin_size_t"       ## string offset=117
	.asciz	"long unsigned int"     ## string offset=133
	.asciz	"array"                 ## string offset=151
	.asciz	"long int"              ## string offset=157
	.asciz	"result"                ## string offset=166
	.asciz	"worker"                ## string offset=173
	.asciz	"main"                  ## string offset=180
	.asciz	"int"                   ## string offset=185
	.asciz	"args"                  ## string offset=189
	.asciz	"wargs"                 ## string offset=194
	.asciz	"start"                 ## string offset=200
	.asciz	"end"                   ## string offset=206
	.asciz	"i"                     ## string offset=210
	.asciz	"numbers"               ## string offset=212
	.asciz	"n"                     ## string offset=220
	.asciz	"thread_ids"            ## string offset=222
	.asciz	"pthread_t"             ## string offset=233
	.asciz	"__darwin_pthread_t"    ## string offset=243
	.asciz	"_opaque_pthread_t"     ## string offset=262
	.asciz	"__sig"                 ## string offset=280
	.asciz	"__cleanup_stack"       ## string offset=286
	.asciz	"__darwin_pthread_handler_rec" ## string offset=302
	.asciz	"__routine"             ## string offset=331
	.asciz	"__arg"                 ## string offset=341
	.asciz	"__next"                ## string offset=347
	.asciz	"__opaque"              ## string offset=354
	.asciz	"char"                  ## string offset=363
	.asciz	"sizetype"              ## string offset=368
	.asciz	"sum"                   ## string offset=377
	.section	__DWARF,__debug_loc,regular,debug
Lsection_debug_loc:
	.section	__DWARF,__debug_abbrev,regular,debug
Lsection_abbrev:
	.byte	1                       ## Abbreviation Code
	.byte	17                      ## DW_TAG_compile_unit
	.byte	1                       ## DW_CHILDREN_yes
	.byte	37                      ## DW_AT_producer
	.byte	14                      ## DW_FORM_strp
	.byte	19                      ## DW_AT_language
	.byte	5                       ## DW_FORM_data2
	.byte	3                       ## DW_AT_name
	.byte	14                      ## DW_FORM_strp
	.byte	16                      ## DW_AT_stmt_list
	.byte	6                       ## DW_FORM_data4
	.byte	27                      ## DW_AT_comp_dir
	.byte	14                      ## DW_FORM_strp
	.byte	17                      ## DW_AT_low_pc
	.byte	1                       ## DW_FORM_addr
	.byte	18                      ## DW_AT_high_pc
	.byte	1                       ## DW_FORM_addr
	.byte	0                       ## EOM(1)
	.byte	0                       ## EOM(2)
	.byte	2                       ## Abbreviation Code
	.byte	15                      ## DW_TAG_pointer_type
	.byte	0                       ## DW_CHILDREN_no
	.byte	73                      ## DW_AT_type
	.byte	19                      ## DW_FORM_ref4
	.byte	0                       ## EOM(1)
	.byte	0                       ## EOM(2)
	.byte	3                       ## Abbreviation Code
	.byte	22                      ## DW_TAG_typedef
	.byte	0                       ## DW_CHILDREN_no
	.byte	73                      ## DW_AT_type
	.byte	19                      ## DW_FORM_ref4
	.byte	3                       ## DW_AT_name
	.byte	14                      ## DW_FORM_strp
	.byte	58                      ## DW_AT_decl_file
	.byte	11                      ## DW_FORM_data1
	.byte	59                      ## DW_AT_decl_line
	.byte	11                      ## DW_FORM_data1
	.byte	0                       ## EOM(1)
	.byte	0                       ## EOM(2)
	.byte	4                       ## Abbreviation Code
	.byte	19                      ## DW_TAG_structure_type
	.byte	1                       ## DW_CHILDREN_yes
	.byte	11                      ## DW_AT_byte_size
	.byte	11                      ## DW_FORM_data1
	.byte	58                      ## DW_AT_decl_file
	.byte	11                      ## DW_FORM_data1
	.byte	59                      ## DW_AT_decl_line
	.byte	11                      ## DW_FORM_data1
	.byte	0                       ## EOM(1)
	.byte	0                       ## EOM(2)
	.byte	5                       ## Abbreviation Code
	.byte	13                      ## DW_TAG_member
	.byte	0                       ## DW_CHILDREN_no
	.byte	3                       ## DW_AT_name
	.byte	14                      ## DW_FORM_strp
	.byte	73                      ## DW_AT_type
	.byte	19                      ## DW_FORM_ref4
	.byte	58                      ## DW_AT_decl_file
	.byte	11                      ## DW_FORM_data1
	.byte	59                      ## DW_AT_decl_line
	.byte	11                      ## DW_FORM_data1
	.byte	56                      ## DW_AT_data_member_location
	.byte	10                      ## DW_FORM_block1
	.byte	0                       ## EOM(1)
	.byte	0                       ## EOM(2)
	.byte	6                       ## Abbreviation Code
	.byte	36                      ## DW_TAG_base_type
	.byte	0                       ## DW_CHILDREN_no
	.byte	3                       ## DW_AT_name
	.byte	14                      ## DW_FORM_strp
	.byte	62                      ## DW_AT_encoding
	.byte	11                      ## DW_FORM_data1
	.byte	11                      ## DW_AT_byte_size
	.byte	11                      ## DW_FORM_data1
	.byte	0                       ## EOM(1)
	.byte	0                       ## EOM(2)
	.byte	7                       ## Abbreviation Code
	.byte	15                      ## DW_TAG_pointer_type
	.byte	0                       ## DW_CHILDREN_no
	.byte	0                       ## EOM(1)
	.byte	0                       ## EOM(2)
	.byte	8                       ## Abbreviation Code
	.byte	46                      ## DW_TAG_subprogram
	.byte	1                       ## DW_CHILDREN_yes
	.byte	17                      ## DW_AT_low_pc
	.byte	1                       ## DW_FORM_addr
	.byte	18                      ## DW_AT_high_pc
	.byte	1                       ## DW_FORM_addr
	.byte	64                      ## DW_AT_frame_base
	.byte	10                      ## DW_FORM_block1
	.byte	3                       ## DW_AT_name
	.byte	14                      ## DW_FORM_strp
	.byte	58                      ## DW_AT_decl_file
	.byte	11                      ## DW_FORM_data1
	.byte	59                      ## DW_AT_decl_line
	.byte	11                      ## DW_FORM_data1
	.byte	39                      ## DW_AT_prototyped
	.byte	12                      ## DW_FORM_flag
	.byte	73                      ## DW_AT_type
	.byte	19                      ## DW_FORM_ref4
	.byte	63                      ## DW_AT_external
	.byte	12                      ## DW_FORM_flag
	.byte	0                       ## EOM(1)
	.byte	0                       ## EOM(2)
	.byte	9                       ## Abbreviation Code
	.byte	5                       ## DW_TAG_formal_parameter
	.byte	0                       ## DW_CHILDREN_no
	.byte	2                       ## DW_AT_location
	.byte	10                      ## DW_FORM_block1
	.byte	3                       ## DW_AT_name
	.byte	14                      ## DW_FORM_strp
	.byte	58                      ## DW_AT_decl_file
	.byte	11                      ## DW_FORM_data1
	.byte	59                      ## DW_AT_decl_line
	.byte	11                      ## DW_FORM_data1
	.byte	73                      ## DW_AT_type
	.byte	19                      ## DW_FORM_ref4
	.byte	0                       ## EOM(1)
	.byte	0                       ## EOM(2)
	.byte	10                      ## Abbreviation Code
	.byte	52                      ## DW_TAG_variable
	.byte	0                       ## DW_CHILDREN_no
	.byte	2                       ## DW_AT_location
	.byte	10                      ## DW_FORM_block1
	.byte	3                       ## DW_AT_name
	.byte	14                      ## DW_FORM_strp
	.byte	58                      ## DW_AT_decl_file
	.byte	11                      ## DW_FORM_data1
	.byte	59                      ## DW_AT_decl_line
	.byte	11                      ## DW_FORM_data1
	.byte	73                      ## DW_AT_type
	.byte	19                      ## DW_FORM_ref4
	.byte	0                       ## EOM(1)
	.byte	0                       ## EOM(2)
	.byte	11                      ## Abbreviation Code
	.byte	11                      ## DW_TAG_lexical_block
	.byte	1                       ## DW_CHILDREN_yes
	.byte	17                      ## DW_AT_low_pc
	.byte	1                       ## DW_FORM_addr
	.byte	18                      ## DW_AT_high_pc
	.byte	1                       ## DW_FORM_addr
	.byte	0                       ## EOM(1)
	.byte	0                       ## EOM(2)
	.byte	12                      ## Abbreviation Code
	.byte	38                      ## DW_TAG_const_type
	.byte	0                       ## DW_CHILDREN_no
	.byte	73                      ## DW_AT_type
	.byte	19                      ## DW_FORM_ref4
	.byte	0                       ## EOM(1)
	.byte	0                       ## EOM(2)
	.byte	13                      ## Abbreviation Code
	.byte	1                       ## DW_TAG_array_type
	.byte	1                       ## DW_CHILDREN_yes
	.byte	73                      ## DW_AT_type
	.byte	19                      ## DW_FORM_ref4
	.byte	0                       ## EOM(1)
	.byte	0                       ## EOM(2)
	.byte	14                      ## Abbreviation Code
	.byte	33                      ## DW_TAG_subrange_type
	.byte	0                       ## DW_CHILDREN_no
	.byte	73                      ## DW_AT_type
	.byte	19                      ## DW_FORM_ref4
	.byte	55                      ## DW_AT_count
	.byte	11                      ## DW_FORM_data1
	.byte	0                       ## EOM(1)
	.byte	0                       ## EOM(2)
	.byte	15                      ## Abbreviation Code
	.byte	19                      ## DW_TAG_structure_type
	.byte	1                       ## DW_CHILDREN_yes
	.byte	3                       ## DW_AT_name
	.byte	14                      ## DW_FORM_strp
	.byte	11                      ## DW_AT_byte_size
	.byte	5                       ## DW_FORM_data2
	.byte	58                      ## DW_AT_decl_file
	.byte	11                      ## DW_FORM_data1
	.byte	59                      ## DW_AT_decl_line
	.byte	11                      ## DW_FORM_data1
	.byte	0                       ## EOM(1)
	.byte	0                       ## EOM(2)
	.byte	16                      ## Abbreviation Code
	.byte	19                      ## DW_TAG_structure_type
	.byte	1                       ## DW_CHILDREN_yes
	.byte	3                       ## DW_AT_name
	.byte	14                      ## DW_FORM_strp
	.byte	11                      ## DW_AT_byte_size
	.byte	11                      ## DW_FORM_data1
	.byte	58                      ## DW_AT_decl_file
	.byte	11                      ## DW_FORM_data1
	.byte	59                      ## DW_AT_decl_line
	.byte	11                      ## DW_FORM_data1
	.byte	0                       ## EOM(1)
	.byte	0                       ## EOM(2)
	.byte	17                      ## Abbreviation Code
	.byte	21                      ## DW_TAG_subroutine_type
	.byte	1                       ## DW_CHILDREN_yes
	.byte	39                      ## DW_AT_prototyped
	.byte	12                      ## DW_FORM_flag
	.byte	0                       ## EOM(1)
	.byte	0                       ## EOM(2)
	.byte	18                      ## Abbreviation Code
	.byte	5                       ## DW_TAG_formal_parameter
	.byte	0                       ## DW_CHILDREN_no
	.byte	73                      ## DW_AT_type
	.byte	19                      ## DW_FORM_ref4
	.byte	0                       ## EOM(1)
	.byte	0                       ## EOM(2)
	.byte	19                      ## Abbreviation Code
	.byte	33                      ## DW_TAG_subrange_type
	.byte	0                       ## DW_CHILDREN_no
	.byte	73                      ## DW_AT_type
	.byte	19                      ## DW_FORM_ref4
	.byte	55                      ## DW_AT_count
	.byte	5                       ## DW_FORM_data2
	.byte	0                       ## EOM(1)
	.byte	0                       ## EOM(2)
	.byte	20                      ## Abbreviation Code
	.byte	36                      ## DW_TAG_base_type
	.byte	0                       ## DW_CHILDREN_no
	.byte	3                       ## DW_AT_name
	.byte	14                      ## DW_FORM_strp
	.byte	11                      ## DW_AT_byte_size
	.byte	11                      ## DW_FORM_data1
	.byte	62                      ## DW_AT_encoding
	.byte	11                      ## DW_FORM_data1
	.byte	0                       ## EOM(1)
	.byte	0                       ## EOM(2)
	.byte	0                       ## EOM(3)
	.section	__DWARF,__debug_info,regular,debug
Lsection_info:
Lcu_begin0:
	.long	775                     ## Length of Unit
	.short	2                       ## DWARF version number
Lset0 = Lsection_abbrev-Lsection_abbrev ## Offset Into Abbrev. Section
	.long	Lset0
	.byte	8                       ## Address Size (in bytes)
	.byte	1                       ## Abbrev [1] 0xb:0x300 DW_TAG_compile_unit
	.long	0                       ## DW_AT_producer
	.short	12                      ## DW_AT_language
	.long	44                      ## DW_AT_name
Lset1 = Lline_table_start0-Lsection_line ## DW_AT_stmt_list
	.long	Lset1
	.long	58                      ## DW_AT_comp_dir
	.quad	Lfunc_begin0            ## DW_AT_low_pc
	.quad	Lfunc_end1              ## DW_AT_high_pc
	.byte	2                       ## Abbrev [2] 0x2e:0x5 DW_TAG_pointer_type
	.long	51                      ## DW_AT_type
	.byte	3                       ## Abbrev [3] 0x33:0xb DW_TAG_typedef
	.long	62                      ## DW_AT_type
	.long	95                      ## DW_AT_name
	.byte	3                       ## DW_AT_decl_file
	.byte	13                      ## DW_AT_decl_line
	.byte	4                       ## Abbrev [4] 0x3e:0x2f DW_TAG_structure_type
	.byte	24                      ## DW_AT_byte_size
	.byte	3                       ## DW_AT_decl_file
	.byte	9                       ## DW_AT_decl_line
	.byte	5                       ## Abbrev [5] 0x42:0xe DW_TAG_member
	.long	107                     ## DW_AT_name
	.long	109                     ## DW_AT_type
	.byte	3                       ## DW_AT_decl_file
	.byte	10                      ## DW_AT_decl_line
	.byte	2                       ## DW_AT_data_member_location
	.byte	35
	.byte	0
	.byte	5                       ## Abbrev [5] 0x50:0xe DW_TAG_member
	.long	151                     ## DW_AT_name
	.long	138                     ## DW_AT_type
	.byte	3                       ## DW_AT_decl_file
	.byte	11                      ## DW_AT_decl_line
	.byte	2                       ## DW_AT_data_member_location
	.byte	35
	.byte	8
	.byte	5                       ## Abbrev [5] 0x5e:0xe DW_TAG_member
	.long	166                     ## DW_AT_name
	.long	143                     ## DW_AT_type
	.byte	3                       ## DW_AT_decl_file
	.byte	12                      ## DW_AT_decl_line
	.byte	2                       ## DW_AT_data_member_location
	.byte	35
	.byte	16
	.byte	0                       ## End Of Children Mark
	.byte	3                       ## Abbrev [3] 0x6d:0xb DW_TAG_typedef
	.long	120                     ## DW_AT_type
	.long	110                     ## DW_AT_name
	.byte	2                       ## DW_AT_decl_file
	.byte	30                      ## DW_AT_decl_line
	.byte	3                       ## Abbrev [3] 0x78:0xb DW_TAG_typedef
	.long	131                     ## DW_AT_type
	.long	117                     ## DW_AT_name
	.byte	1                       ## DW_AT_decl_file
	.byte	92                      ## DW_AT_decl_line
	.byte	6                       ## Abbrev [6] 0x83:0x7 DW_TAG_base_type
	.long	133                     ## DW_AT_name
	.byte	7                       ## DW_AT_encoding
	.byte	8                       ## DW_AT_byte_size
	.byte	2                       ## Abbrev [2] 0x8a:0x5 DW_TAG_pointer_type
	.long	143                     ## DW_AT_type
	.byte	6                       ## Abbrev [6] 0x8f:0x7 DW_TAG_base_type
	.long	157                     ## DW_AT_name
	.byte	5                       ## DW_AT_encoding
	.byte	8                       ## DW_AT_byte_size
	.byte	7                       ## Abbrev [7] 0x96:0x1 DW_TAG_pointer_type
	.byte	8                       ## Abbrev [8] 0x97:0x78 DW_TAG_subprogram
	.quad	Lfunc_begin0            ## DW_AT_low_pc
	.quad	Lfunc_end0              ## DW_AT_high_pc
	.byte	1                       ## DW_AT_frame_base
	.byte	86
	.long	173                     ## DW_AT_name
	.byte	3                       ## DW_AT_decl_file
	.byte	16                      ## DW_AT_decl_line
	.byte	1                       ## DW_AT_prototyped
	.long	150                     ## DW_AT_type
	.byte	1                       ## DW_AT_external
	.byte	9                       ## Abbrev [9] 0xb6:0xe DW_TAG_formal_parameter
	.byte	2                       ## DW_AT_location
	.byte	145
	.byte	120
	.long	189                     ## DW_AT_name
	.byte	3                       ## DW_AT_decl_file
	.byte	16                      ## DW_AT_decl_line
	.long	150                     ## DW_AT_type
	.byte	10                      ## Abbrev [10] 0xc4:0xe DW_TAG_variable
	.byte	2                       ## DW_AT_location
	.byte	145
	.byte	112
	.long	194                     ## DW_AT_name
	.byte	3                       ## DW_AT_decl_file
	.byte	17                      ## DW_AT_decl_line
	.long	46                      ## DW_AT_type
	.byte	10                      ## Abbrev [10] 0xd2:0xe DW_TAG_variable
	.byte	2                       ## DW_AT_location
	.byte	145
	.byte	104
	.long	200                     ## DW_AT_name
	.byte	3                       ## DW_AT_decl_file
	.byte	18                      ## DW_AT_decl_line
	.long	586                     ## DW_AT_type
	.byte	10                      ## Abbrev [10] 0xe0:0xe DW_TAG_variable
	.byte	2                       ## DW_AT_location
	.byte	145
	.byte	96
	.long	206                     ## DW_AT_name
	.byte	3                       ## DW_AT_decl_file
	.byte	19                      ## DW_AT_decl_line
	.long	586                     ## DW_AT_type
	.byte	11                      ## Abbrev [11] 0xee:0x20 DW_TAG_lexical_block
	.quad	Ltmp4                   ## DW_AT_low_pc
	.quad	Ltmp9                   ## DW_AT_high_pc
	.byte	10                      ## Abbrev [10] 0xff:0xe DW_TAG_variable
	.byte	2                       ## DW_AT_location
	.byte	145
	.byte	88
	.long	210                     ## DW_AT_name
	.byte	3                       ## DW_AT_decl_file
	.byte	21                      ## DW_AT_decl_line
	.long	109                     ## DW_AT_type
	.byte	0                       ## End Of Children Mark
	.byte	0                       ## End Of Children Mark
	.byte	8                       ## Abbrev [8] 0x10f:0x134 DW_TAG_subprogram
	.quad	Lfunc_begin1            ## DW_AT_low_pc
	.quad	Lfunc_end1              ## DW_AT_high_pc
	.byte	1                       ## DW_AT_frame_base
	.byte	86
	.long	180                     ## DW_AT_name
	.byte	3                       ## DW_AT_decl_file
	.byte	28                      ## DW_AT_decl_line
	.byte	1                       ## DW_AT_prototyped
	.long	579                     ## DW_AT_type
	.byte	1                       ## DW_AT_external
	.byte	10                      ## Abbrev [10] 0x12e:0xf DW_TAG_variable
	.byte	3                       ## DW_AT_location
	.byte	145
	.ascii	"\240\177"
	.long	212                     ## DW_AT_name
	.byte	3                       ## DW_AT_decl_file
	.byte	29                      ## DW_AT_decl_line
	.long	138                     ## DW_AT_type
	.byte	10                      ## Abbrev [10] 0x13d:0xf DW_TAG_variable
	.byte	3                       ## DW_AT_location
	.byte	145
	.ascii	"\220\177"
	.long	189                     ## DW_AT_name
	.byte	3                       ## DW_AT_decl_file
	.byte	33                      ## DW_AT_decl_line
	.long	46                      ## DW_AT_type
	.byte	11                      ## Abbrev [11] 0x14c:0x21 DW_TAG_lexical_block
	.quad	Ltmp15                  ## DW_AT_low_pc
	.quad	Ltmp20                  ## DW_AT_high_pc
	.byte	10                      ## Abbrev [10] 0x15d:0xf DW_TAG_variable
	.byte	3                       ## DW_AT_location
	.byte	145
	.ascii	"\230\177"
	.long	210                     ## DW_AT_name
	.byte	3                       ## DW_AT_decl_file
	.byte	30                      ## DW_AT_decl_line
	.long	109                     ## DW_AT_type
	.byte	0                       ## End Of Children Mark
	.byte	11                      ## Abbrev [11] 0x16d:0xd5 DW_TAG_lexical_block
	.quad	Ltmp21                  ## DW_AT_low_pc
	.quad	Ltmp47                  ## DW_AT_high_pc
	.byte	10                      ## Abbrev [10] 0x17e:0xf DW_TAG_variable
	.byte	3                       ## DW_AT_location
	.byte	145
	.ascii	"\210\177"
	.long	220                     ## DW_AT_name
	.byte	3                       ## DW_AT_decl_file
	.byte	34                      ## DW_AT_decl_line
	.long	109                     ## DW_AT_type
	.byte	11                      ## Abbrev [11] 0x18d:0xb4 DW_TAG_lexical_block
	.quad	Ltmp24                  ## DW_AT_low_pc
	.quad	Ltmp46                  ## DW_AT_high_pc
	.byte	10                      ## Abbrev [10] 0x19e:0xf DW_TAG_variable
	.byte	3                       ## DW_AT_location
	.byte	145
	.ascii	"\260\177"
	.long	222                     ## DW_AT_name
	.byte	3                       ## DW_AT_decl_file
	.byte	42                      ## DW_AT_decl_line
	.long	591                     ## DW_AT_type
	.byte	10                      ## Abbrev [10] 0x1ad:0xf DW_TAG_variable
	.byte	3                       ## DW_AT_location
	.byte	145
	.ascii	"\320~"
	.long	377                     ## DW_AT_name
	.byte	3                       ## DW_AT_decl_file
	.byte	52                      ## DW_AT_decl_line
	.long	143                     ## DW_AT_type
	.byte	11                      ## Abbrev [11] 0x1bc:0x21 DW_TAG_lexical_block
	.quad	Ltmp24                  ## DW_AT_low_pc
	.quad	Ltmp29                  ## DW_AT_high_pc
	.byte	10                      ## Abbrev [10] 0x1cd:0xf DW_TAG_variable
	.byte	3                       ## DW_AT_location
	.byte	145
	.ascii	"\200\177"
	.long	210                     ## DW_AT_name
	.byte	3                       ## DW_AT_decl_file
	.byte	35                      ## DW_AT_decl_line
	.long	109                     ## DW_AT_type
	.byte	0                       ## End Of Children Mark
	.byte	11                      ## Abbrev [11] 0x1dd:0x21 DW_TAG_lexical_block
	.quad	Ltmp29                  ## DW_AT_low_pc
	.quad	Ltmp34                  ## DW_AT_high_pc
	.byte	10                      ## Abbrev [10] 0x1ee:0xf DW_TAG_variable
	.byte	3                       ## DW_AT_location
	.byte	145
	.ascii	"\340~"
	.long	210                     ## DW_AT_name
	.byte	3                       ## DW_AT_decl_file
	.byte	44                      ## DW_AT_decl_line
	.long	109                     ## DW_AT_type
	.byte	0                       ## End Of Children Mark
	.byte	11                      ## Abbrev [11] 0x1fe:0x21 DW_TAG_lexical_block
	.quad	Ltmp34                  ## DW_AT_low_pc
	.quad	Ltmp39                  ## DW_AT_high_pc
	.byte	10                      ## Abbrev [10] 0x20f:0xf DW_TAG_variable
	.byte	3                       ## DW_AT_location
	.byte	145
	.ascii	"\330~"
	.long	210                     ## DW_AT_name
	.byte	3                       ## DW_AT_decl_file
	.byte	48                      ## DW_AT_decl_line
	.long	109                     ## DW_AT_type
	.byte	0                       ## End Of Children Mark
	.byte	11                      ## Abbrev [11] 0x21f:0x21 DW_TAG_lexical_block
	.quad	Ltmp40                  ## DW_AT_low_pc
	.quad	Ltmp45                  ## DW_AT_high_pc
	.byte	10                      ## Abbrev [10] 0x230:0xf DW_TAG_variable
	.byte	3                       ## DW_AT_location
	.byte	145
	.ascii	"\310~"
	.long	210                     ## DW_AT_name
	.byte	3                       ## DW_AT_decl_file
	.byte	54                      ## DW_AT_decl_line
	.long	109                     ## DW_AT_type
	.byte	0                       ## End Of Children Mark
	.byte	0                       ## End Of Children Mark
	.byte	0                       ## End Of Children Mark
	.byte	0                       ## End Of Children Mark
	.byte	6                       ## Abbrev [6] 0x243:0x7 DW_TAG_base_type
	.long	185                     ## DW_AT_name
	.byte	5                       ## DW_AT_encoding
	.byte	4                       ## DW_AT_byte_size
	.byte	12                      ## Abbrev [12] 0x24a:0x5 DW_TAG_const_type
	.long	109                     ## DW_AT_type
	.byte	13                      ## Abbrev [13] 0x24f:0xc DW_TAG_array_type
	.long	603                     ## DW_AT_type
	.byte	14                      ## Abbrev [14] 0x254:0x6 DW_TAG_subrange_type
	.long	771                     ## DW_AT_type
	.byte	8                       ## DW_AT_count
	.byte	0                       ## End Of Children Mark
	.byte	3                       ## Abbrev [3] 0x25b:0xb DW_TAG_typedef
	.long	614                     ## DW_AT_type
	.long	233                     ## DW_AT_name
	.byte	5                       ## DW_AT_decl_file
	.byte	30                      ## DW_AT_decl_line
	.byte	3                       ## Abbrev [3] 0x266:0xb DW_TAG_typedef
	.long	625                     ## DW_AT_type
	.long	243                     ## DW_AT_name
	.byte	4                       ## DW_AT_decl_file
	.byte	118                     ## DW_AT_decl_line
	.byte	2                       ## Abbrev [2] 0x271:0x5 DW_TAG_pointer_type
	.long	630                     ## DW_AT_type
	.byte	15                      ## Abbrev [15] 0x276:0x34 DW_TAG_structure_type
	.long	262                     ## DW_AT_name
	.short	8192                    ## DW_AT_byte_size
	.byte	4                       ## DW_AT_decl_file
	.byte	103                     ## DW_AT_decl_line
	.byte	5                       ## Abbrev [5] 0x27f:0xe DW_TAG_member
	.long	280                     ## DW_AT_name
	.long	143                     ## DW_AT_type
	.byte	4                       ## DW_AT_decl_file
	.byte	104                     ## DW_AT_decl_line
	.byte	2                       ## DW_AT_data_member_location
	.byte	35
	.byte	0
	.byte	5                       ## Abbrev [5] 0x28d:0xe DW_TAG_member
	.long	286                     ## DW_AT_name
	.long	682                     ## DW_AT_type
	.byte	4                       ## DW_AT_decl_file
	.byte	105                     ## DW_AT_decl_line
	.byte	2                       ## DW_AT_data_member_location
	.byte	35
	.byte	8
	.byte	5                       ## Abbrev [5] 0x29b:0xe DW_TAG_member
	.long	354                     ## DW_AT_name
	.long	751                     ## DW_AT_type
	.byte	4                       ## DW_AT_decl_file
	.byte	106                     ## DW_AT_decl_line
	.byte	2                       ## DW_AT_data_member_location
	.byte	35
	.byte	16
	.byte	0                       ## End Of Children Mark
	.byte	2                       ## Abbrev [2] 0x2aa:0x5 DW_TAG_pointer_type
	.long	687                     ## DW_AT_type
	.byte	16                      ## Abbrev [16] 0x2af:0x33 DW_TAG_structure_type
	.long	302                     ## DW_AT_name
	.byte	24                      ## DW_AT_byte_size
	.byte	4                       ## DW_AT_decl_file
	.byte	57                      ## DW_AT_decl_line
	.byte	5                       ## Abbrev [5] 0x2b7:0xe DW_TAG_member
	.long	331                     ## DW_AT_name
	.long	738                     ## DW_AT_type
	.byte	4                       ## DW_AT_decl_file
	.byte	58                      ## DW_AT_decl_line
	.byte	2                       ## DW_AT_data_member_location
	.byte	35
	.byte	0
	.byte	5                       ## Abbrev [5] 0x2c5:0xe DW_TAG_member
	.long	341                     ## DW_AT_name
	.long	150                     ## DW_AT_type
	.byte	4                       ## DW_AT_decl_file
	.byte	59                      ## DW_AT_decl_line
	.byte	2                       ## DW_AT_data_member_location
	.byte	35
	.byte	8
	.byte	5                       ## Abbrev [5] 0x2d3:0xe DW_TAG_member
	.long	347                     ## DW_AT_name
	.long	682                     ## DW_AT_type
	.byte	4                       ## DW_AT_decl_file
	.byte	60                      ## DW_AT_decl_line
	.byte	2                       ## DW_AT_data_member_location
	.byte	35
	.byte	16
	.byte	0                       ## End Of Children Mark
	.byte	2                       ## Abbrev [2] 0x2e2:0x5 DW_TAG_pointer_type
	.long	743                     ## DW_AT_type
	.byte	17                      ## Abbrev [17] 0x2e7:0x8 DW_TAG_subroutine_type
	.byte	1                       ## DW_AT_prototyped
	.byte	18                      ## Abbrev [18] 0x2e9:0x5 DW_TAG_formal_parameter
	.long	150                     ## DW_AT_type
	.byte	0                       ## End Of Children Mark
	.byte	13                      ## Abbrev [13] 0x2ef:0xd DW_TAG_array_type
	.long	764                     ## DW_AT_type
	.byte	19                      ## Abbrev [19] 0x2f4:0x7 DW_TAG_subrange_type
	.long	771                     ## DW_AT_type
	.short	8176                    ## DW_AT_count
	.byte	0                       ## End Of Children Mark
	.byte	6                       ## Abbrev [6] 0x2fc:0x7 DW_TAG_base_type
	.long	363                     ## DW_AT_name
	.byte	6                       ## DW_AT_encoding
	.byte	1                       ## DW_AT_byte_size
	.byte	20                      ## Abbrev [20] 0x303:0x7 DW_TAG_base_type
	.long	368                     ## DW_AT_name
	.byte	8                       ## DW_AT_byte_size
	.byte	7                       ## DW_AT_encoding
	.byte	0                       ## End Of Children Mark
	.section	__DWARF,__debug_ranges,regular,debug
Ldebug_range:
	.section	__DWARF,__debug_macinfo,regular,debug
Ldebug_macinfo:
Lcu_macro_begin0:
	.byte	0                       ## End Of Macro List Mark
	.section	__DWARF,__apple_names,regular,debug
Lnames_begin:
	.long	1212240712              ## Header Magic
	.short	1                       ## Header Version
	.short	0                       ## Header Hash Function
	.long	2                       ## Header Bucket Count
	.long	2                       ## Header Hash Count
	.long	12                      ## Header Data Length
	.long	0                       ## HeaderData Die Offset Base
	.long	1                       ## HeaderData Atom Count
	.short	1                       ## DW_ATOM_die_offset
	.short	6                       ## DW_FORM_data4
	.long	0                       ## Bucket 0
	.long	1                       ## Bucket 1
	.long	2090499946              ## Hash in Bucket 0
	.long	630054751               ## Hash in Bucket 1
	.long	LNames0-Lnames_begin    ## Offset in Bucket 0
	.long	LNames1-Lnames_begin    ## Offset in Bucket 1
LNames0:
	.long	180                     ## main
	.long	1                       ## Num DIEs
	.long	271
	.long	0
LNames1:
	.long	173                     ## worker
	.long	1                       ## Num DIEs
	.long	151
	.long	0
	.section	__DWARF,__apple_objc,regular,debug
Lobjc_begin:
	.long	1212240712              ## Header Magic
	.short	1                       ## Header Version
	.short	0                       ## Header Hash Function
	.long	1                       ## Header Bucket Count
	.long	0                       ## Header Hash Count
	.long	12                      ## Header Data Length
	.long	0                       ## HeaderData Die Offset Base
	.long	1                       ## HeaderData Atom Count
	.short	1                       ## DW_ATOM_die_offset
	.short	6                       ## DW_FORM_data4
	.long	-1                      ## Bucket 0
	.section	__DWARF,__apple_namespac,regular,debug
Lnamespac_begin:
	.long	1212240712              ## Header Magic
	.short	1                       ## Header Version
	.short	0                       ## Header Hash Function
	.long	1                       ## Header Bucket Count
	.long	0                       ## Header Hash Count
	.long	12                      ## Header Data Length
	.long	0                       ## HeaderData Die Offset Base
	.long	1                       ## HeaderData Atom Count
	.short	1                       ## DW_ATOM_die_offset
	.short	6                       ## DW_FORM_data4
	.long	-1                      ## Bucket 0
	.section	__DWARF,__apple_types,regular,debug
Ltypes_begin:
	.long	1212240712              ## Header Magic
	.short	1                       ## Header Version
	.short	0                       ## Header Hash Function
	.long	11                      ## Header Bucket Count
	.long	11                      ## Header Hash Count
	.long	20                      ## Header Data Length
	.long	0                       ## HeaderData Die Offset Base
	.long	3                       ## HeaderData Atom Count
	.short	1                       ## DW_ATOM_die_offset
	.short	6                       ## DW_FORM_data4
	.short	3                       ## DW_ATOM_die_tag
	.short	5                       ## DW_FORM_data2
	.short	4                       ## DW_ATOM_type_flags
	.short	11                      ## DW_FORM_data1
	.long	0                       ## Bucket 0
	.long	-1                      ## Bucket 1
	.long	1                       ## Bucket 2
	.long	3                       ## Bucket 3
	.long	4                       ## Bucket 4
	.long	5                       ## Bucket 5
	.long	7                       ## Bucket 6
	.long	-1                      ## Bucket 7
	.long	-1                      ## Bucket 8
	.long	10                      ## Bucket 9
	.long	-1                      ## Bucket 10
	.long	2090147939              ## Hash in Bucket 0
	.long	1297205472              ## Hash in Bucket 2
	.long	1595644866              ## Hash in Bucket 2
	.long	-282664779              ## Hash in Bucket 3
	.long	-1880351968             ## Hash in Bucket 4
	.long	2065860549              ## Hash in Bucket 5
	.long	-80380739               ## Hash in Bucket 5
	.long	77135977                ## Hash in Bucket 6
	.long	193495088               ## Hash in Bucket 6
	.long	-1197896181             ## Hash in Bucket 6
	.long	466678419               ## Hash in Bucket 9
	.long	Ltypes10-Ltypes_begin   ## Offset in Bucket 0
	.long	Ltypes1-Ltypes_begin    ## Offset in Bucket 2
	.long	Ltypes8-Ltypes_begin    ## Offset in Bucket 2
	.long	Ltypes0-Ltypes_begin    ## Offset in Bucket 3
	.long	Ltypes6-Ltypes_begin    ## Offset in Bucket 4
	.long	Ltypes2-Ltypes_begin    ## Offset in Bucket 5
	.long	Ltypes5-Ltypes_begin    ## Offset in Bucket 5
	.long	Ltypes3-Ltypes_begin    ## Offset in Bucket 6
	.long	Ltypes7-Ltypes_begin    ## Offset in Bucket 6
	.long	Ltypes4-Ltypes_begin    ## Offset in Bucket 6
	.long	Ltypes9-Ltypes_begin    ## Offset in Bucket 9
Ltypes10:
	.long	363                     ## char
	.long	1                       ## Num DIEs
	.long	764
	.short	36
	.byte	0
	.long	0
Ltypes1:
	.long	233                     ## pthread_t
	.long	1                       ## Num DIEs
	.long	603
	.short	22
	.byte	0
	.long	0
Ltypes8:
	.long	243                     ## __darwin_pthread_t
	.long	1                       ## Num DIEs
	.long	614
	.short	22
	.byte	0
	.long	0
Ltypes0:
	.long	117                     ## __darwin_size_t
	.long	1                       ## Num DIEs
	.long	120
	.short	22
	.byte	0
	.long	0
Ltypes6:
	.long	157                     ## long int
	.long	1                       ## Num DIEs
	.long	143
	.short	36
	.byte	0
	.long	0
Ltypes2:
	.long	302                     ## __darwin_pthread_handler_rec
	.long	1                       ## Num DIEs
	.long	687
	.short	19
	.byte	0
	.long	0
Ltypes5:
	.long	133                     ## long unsigned int
	.long	1                       ## Num DIEs
	.long	131
	.short	36
	.byte	0
	.long	0
Ltypes3:
	.long	262                     ## _opaque_pthread_t
	.long	1                       ## Num DIEs
	.long	630
	.short	19
	.byte	0
	.long	0
Ltypes7:
	.long	185                     ## int
	.long	1                       ## Num DIEs
	.long	579
	.short	36
	.byte	0
	.long	0
Ltypes4:
	.long	95                      ## worker_args
	.long	1                       ## Num DIEs
	.long	51
	.short	22
	.byte	0
	.long	0
Ltypes9:
	.long	110                     ## size_t
	.long	1                       ## Num DIEs
	.long	109
	.short	22
	.byte	0
	.long	0
	.section	__DWARF,__apple_exttypes,regular,debug
Lexttypes_begin:
	.long	1212240712              ## Header Magic
	.short	1                       ## Header Version
	.short	0                       ## Header Hash Function
	.long	1                       ## Header Bucket Count
	.long	0                       ## Header Hash Count
	.long	12                      ## Header Data Length
	.long	0                       ## HeaderData Die Offset Base
	.long	1                       ## HeaderData Atom Count
	.short	7                       ## DW_ATOM_ext_types
	.short	6                       ## DW_FORM_data4
	.long	-1                      ## Bucket 0

.subsections_via_symbols
	.section	__DWARF,__debug_line,regular,debug
Lsection_line:
Lline_table_start0:
