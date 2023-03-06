
bomb:	file format Mach-O 64-bit x86-64

Disassembly of section __TEXT,__text:
__text:
1000006b0:	55 	pushq	%rbp
1000006b1:	48 89 e5 	movq	%rsp, %rbp
1000006b4:	48 83 ec 20 	subq	$32, %rsp
1000006b8:	48 89 7d f8 	movq	%rdi, -8(%rbp)
1000006bc:	48 8b 3d 45 09 00 00 	movq	2373(%rip), %rdi
1000006c3:	48 8b 3f 	movq	(%rdi), %rdi
1000006c6:	48 8b 55 f8 	movq	-8(%rbp), %rdx
1000006ca:	48 89 7d f0 	movq	%rdi, -16(%rbp)
1000006ce:	48 89 55 e8 	movq	%rdx, -24(%rbp)
1000006d2:	e8 8f 04 00 00 	callq	1167 <dyld_stub_binder+0x100000b66>
1000006d7:	8b 38 	movl	(%rax), %edi
1000006d9:	e8 d0 04 00 00 	callq	1232 <dyld_stub_binder+0x100000bae>
1000006de:	48 8d 35 ab 07 00 00 	leaq	1963(%rip), %rsi
1000006e5:	31 ff 	xorl	%edi, %edi
1000006e7:	40 88 f9 	movb	%dil, %cl
1000006ea:	48 8b 7d f0 	movq	-16(%rbp), %rdi
1000006ee:	48 8b 55 e8 	movq	-24(%rbp), %rdx
1000006f2:	88 4d e7 	movb	%cl, -25(%rbp)
1000006f5:	48 89 c1 	movq	%rax, %rcx
1000006f8:	8a 45 e7 	movb	-25(%rbp), %al
1000006fb:	e8 90 04 00 00 	callq	1168 <dyld_stub_binder+0x100000b90>
100000700:	bf 01 00 00 00 	movl	$1, %edi
100000705:	89 45 e0 	movl	%eax, -32(%rbp)
100000708:	e8 77 04 00 00 	callq	1143 <dyld_stub_binder+0x100000b84>
10000070d:	0f 1f 00 	nopl	(%rax)
100000710:	55 	pushq	%rbp
100000711:	48 89 e5 	movq	%rsp, %rbp
100000714:	48 83 ec 20 	subq	$32, %rsp
100000718:	66 89 d0 	movw	%dx, %ax
10000071b:	48 89 7d f8 	movq	%rdi, -8(%rbp)
10000071f:	89 75 f4 	movl	%esi, -12(%rbp)
100000722:	66 89 45 f2 	movw	%ax, -14(%rbp)
100000726:	48 8b 7d f8 	movq	-8(%rbp), %rdi
10000072a:	8b 75 f4 	movl	-12(%rbp), %esi
10000072d:	0f b7 55 f2 	movzwl	-14(%rbp), %edx
100000731:	b0 00 	movb	$0, %al
100000733:	e8 64 04 00 00 	callq	1124 <dyld_stub_binder+0x100000b9c>
100000738:	89 45 ec 	movl	%eax, -20(%rbp)
10000073b:	83 f8 00 	cmpl	$0, %eax
10000073e:	0f 8d 0c 00 00 00 	jge	12 <_Open+0x40>
100000744:	48 8d 3d 4d 07 00 00 	leaq	1869(%rip), %rdi
10000074b:	e8 60 ff ff ff 	callq	-160 <_unix_error>
100000750:	8b 45 ec 	movl	-20(%rbp), %eax
100000753:	48 83 c4 20 	addq	$32, %rsp
100000757:	5d 	popq	%rbp
100000758:	c3 	retq
100000759:	0f 1f 80 00 00 00 00 	nopl	(%rax)
100000760:	55 	pushq	%rbp
100000761:	48 89 e5 	movq	%rsp, %rbp
100000764:	48 83 ec 10 	subq	$16, %rsp
100000768:	89 7d fc 	movl	%edi, -4(%rbp)
10000076b:	8b 7d fc 	movl	-4(%rbp), %edi
10000076e:	e8 05 04 00 00 	callq	1029 <dyld_stub_binder+0x100000b78>
100000773:	89 45 f8 	movl	%eax, -8(%rbp)
100000776:	83 f8 00 	cmpl	$0, %eax
100000779:	0f 8d 0c 00 00 00 	jge	12 <_Close+0x2b>
10000077f:	48 8d 3d 1d 07 00 00 	leaq	1821(%rip), %rdi
100000786:	e8 25 ff ff ff 	callq	-219 <_unix_error>
10000078b:	48 83 c4 10 	addq	$16, %rsp
10000078f:	5d 	popq	%rbp
100000790:	c3 	retq
100000791:	66 2e 0f 1f 84 00 00 00 00 00 	nopw	%cs:(%rax,%rax)
10000079b:	0f 1f 44 00 00 	nopl	(%rax,%rax)
1000007a0:	55 	pushq	%rbp
1000007a1:	48 89 e5 	movq	%rsp, %rbp
1000007a4:	48 83 ec 20 	subq	$32, %rsp
1000007a8:	89 7d fc 	movl	%edi, -4(%rbp)
1000007ab:	48 89 75 f0 	movq	%rsi, -16(%rbp)
1000007af:	48 8b 7d f0 	movq	-16(%rbp), %rdi
1000007b3:	e8 fc 03 00 00 	callq	1020 <dyld_stub_binder+0x100000bb4>
1000007b8:	48 89 45 e8 	movq	%rax, -24(%rbp)
1000007bc:	8b 7d fc 	movl	-4(%rbp), %edi
1000007bf:	48 8b 75 f0 	movq	-16(%rbp), %rsi
1000007c3:	48 8b 55 e8 	movq	-24(%rbp), %rdx
1000007c7:	e8 fa 03 00 00 	callq	1018 <dyld_stub_binder+0x100000bc6>
1000007cc:	48 89 45 e0 	movq	%rax, -32(%rbp)
1000007d0:	48 83 f8 00 	cmpq	$0, %rax
1000007d4:	0f 8d 0c 00 00 00 	jge	12 <_WriteStr+0x46>
1000007da:	48 8d 3d ce 06 00 00 	leaq	1742(%rip), %rdi
1000007e1:	e8 ca fe ff ff 	callq	-310 <_unix_error>
1000007e6:	48 8b 45 e0 	movq	-32(%rbp), %rax
1000007ea:	48 83 c4 20 	addq	$32, %rsp
1000007ee:	5d 	popq	%rbp
1000007ef:	c3 	retq
1000007f0:	55 	pushq	%rbp
1000007f1:	48 89 e5 	movq	%rsp, %rbp
1000007f4:	48 81 ec a0 00 00 00 	subq	$160, %rsp
1000007fb:	48 89 7d f8 	movq	%rdi, -8(%rbp)
1000007ff:	48 8b 7d f8 	movq	-8(%rbp), %rdi
100000803:	48 8d b5 68 ff ff ff 	leaq	-152(%rbp), %rsi
10000080a:	e8 99 03 00 00 	callq	921 <dyld_stub_binder+0x100000ba8>
10000080f:	83 f8 00 	cmpl	$0, %eax
100000812:	0f 94 c1 	sete	%cl
100000815:	80 e1 01 	andb	$1, %cl
100000818:	0f b6 c1 	movzbl	%cl, %eax
10000081b:	48 81 c4 a0 00 00 00 	addq	$160, %rsp
100000822:	5d 	popq	%rbp
100000823:	c3 	retq
100000824:	66 2e 0f 1f 84 00 00 00 00 00 	nopw	%cs:(%rax,%rax)
10000082e:	66 90 	nop
100000830:	55 	pushq	%rbp
100000831:	48 89 e5 	movq	%rsp, %rbp
100000834:	48 83 ec 10 	subq	$16, %rsp
100000838:	48 89 7d f8 	movq	%rdi, -8(%rbp)
10000083c:	c7 45 f4 ff ff ff ff 	movl	$4294967295, -12(%rbp)
100000843:	48 8b 7d f8 	movq	-8(%rbp), %rdi
100000847:	e8 a4 ff ff ff 	callq	-92 <_file_exists>
10000084c:	83 f8 00 	cmpl	$0, %eax
10000084f:	0f 84 18 00 00 00 	je	24 <_create_or_append_for_writing+0x3d>
100000855:	31 d2 	xorl	%edx, %edx
100000857:	48 8b 7d f8 	movq	-8(%rbp), %rdi
10000085b:	be 09 00 00 00 	movl	$9, %esi
100000860:	e8 ab fe ff ff 	callq	-341 <_Open>
100000865:	89 45 f4 	movl	%eax, -12(%rbp)
100000868:	e9 24 00 00 00 	jmp	36 <_create_or_append_for_writing+0x61>
10000086d:	bf 12 00 00 00 	movl	$18, %edi
100000872:	e8 49 03 00 00 	callq	841 <dyld_stub_binder+0x100000bc0>
100000877:	48 8b 7d f8 	movq	-8(%rbp), %rdi
10000087b:	be 01 06 00 00 	movl	$1537, %esi
100000880:	ba b6 01 00 00 	movl	$438, %edx
100000885:	66 89 45 f2 	movw	%ax, -14(%rbp)
100000889:	e8 82 fe ff ff 	callq	-382 <_Open>
10000088e:	89 45 f4 	movl	%eax, -12(%rbp)
100000891:	8b 45 f4 	movl	-12(%rbp), %eax
100000894:	48 83 c4 10 	addq	$16, %rsp
100000898:	5d 	popq	%rbp
100000899:	c3 	retq
10000089a:	66 0f 1f 44 00 00 	nopw	(%rax,%rax)
1000008a0:	55 	pushq	%rbp
1000008a1:	48 89 e5 	movq	%rsp, %rbp
1000008a4:	48 83 ec 10 	subq	$16, %rsp
1000008a8:	48 8d 3d e1 03 00 00 	leaq	993(%rip), %rdi
1000008af:	b0 00 	movb	$0, %al
1000008b1:	e8 ec 02 00 00 	callq	748 <dyld_stub_binder+0x100000ba2>
1000008b6:	89 45 fc 	movl	%eax, -4(%rbp)
1000008b9:	48 83 c4 10 	addq	$16, %rsp
1000008bd:	5d 	popq	%rbp
1000008be:	c3 	retq
1000008bf:	90 	nop
1000008c0:	55 	pushq	%rbp
1000008c1:	48 89 e5 	movq	%rsp, %rbp
1000008c4:	48 83 ec 20 	subq	$32, %rsp
1000008c8:	31 c0 	xorl	%eax, %eax
1000008ca:	89 c1 	movl	%eax, %ecx
1000008cc:	48 89 7d f8 	movq	%rdi, -8(%rbp)
1000008d0:	48 89 cf 	movq	%rcx, %rdi
1000008d3:	e8 e2 02 00 00 	callq	738 <dyld_stub_binder+0x100000bba>
1000008d8:	48 8d 0d d9 07 00 00 	leaq	2009(%rip), %rcx
1000008df:	48 89 01 	movq	%rax, (%rcx)
1000008e2:	48 83 39 ff 	cmpq	$-1, (%rcx)
1000008e6:	0f 85 29 00 00 00 	jne	41 <_populate_time_str+0x55>
1000008ec:	48 8b 05 15 07 00 00 	movq	1813(%rip), %rax
1000008f3:	48 8b 38 	movq	(%rax), %rdi
1000008f6:	48 8d 35 be 05 00 00 	leaq	1470(%rip), %rsi
1000008fd:	31 c9 	xorl	%ecx, %ecx
1000008ff:	88 ca 	movb	%cl, %dl
100000901:	88 d0 	movb	%dl, %al
100000903:	e8 88 02 00 00 	callq	648 <dyld_stub_binder+0x100000b90>
100000908:	bf 01 00 00 00 	movl	$1, %edi
10000090d:	89 45 f4 	movl	%eax, -12(%rbp)
100000910:	e8 6f 02 00 00 	callq	623 <dyld_stub_binder+0x100000b84>
100000915:	48 8d 3d 9c 07 00 00 	leaq	1948(%rip), %rdi
10000091c:	e8 5d 02 00 00 	callq	605 <dyld_stub_binder+0x100000b7e>
100000921:	48 8d 3d 88 07 00 00 	leaq	1928(%rip), %rdi
100000928:	48 89 07 	movq	%rax, (%rdi)
10000092b:	48 83 3f 00 	cmpq	$0, (%rdi)
10000092f:	0f 85 29 00 00 00 	jne	41 <_populate_time_str+0x9e>
100000935:	48 8b 05 cc 06 00 00 	movq	1740(%rip), %rax
10000093c:	48 8b 38 	movq	(%rax), %rdi
10000093f:	48 8d 35 9a 05 00 00 	leaq	1434(%rip), %rsi
100000946:	31 c9 	xorl	%ecx, %ecx
100000948:	88 ca 	movb	%cl, %dl
10000094a:	88 d0 	movb	%dl, %al
10000094c:	e8 3f 02 00 00 	callq	575 <dyld_stub_binder+0x100000b90>
100000951:	bf 01 00 00 00 	movl	$1, %edi
100000956:	89 45 f0 	movl	%eax, -16(%rbp)
100000959:	e8 26 02 00 00 	callq	550 <dyld_stub_binder+0x100000b84>
10000095e:	31 f6 	xorl	%esi, %esi
100000960:	48 8d 05 49 07 00 00 	leaq	1865(%rip), %rax
100000967:	48 c7 c2 ff ff ff ff 	movq	$-1, %rdx
10000096e:	48 8b 7d f8 	movq	-8(%rbp), %rdi
100000972:	4c 8b 00 	movq	(%rax), %r8
100000975:	48 8d 0d 8a 05 00 00 	leaq	1418(%rip), %rcx
10000097c:	b0 00 	movb	$0, %al
10000097e:	e8 e9 01 00 00 	callq	489 <dyld_stub_binder+0x100000b6c>
100000983:	89 45 ec 	movl	%eax, -20(%rbp)
100000986:	48 83 c4 20 	addq	$32, %rsp
10000098a:	5d 	popq	%rbp
10000098b:	c3 	retq
10000098c:	0f 1f 40 00 	nopl	(%rax)
100000990:	55 	pushq	%rbp
100000991:	48 89 e5 	movq	%rsp, %rbp
100000994:	48 83 ec 10 	subq	$16, %rsp
100000998:	89 7d fc 	movl	%edi, -4(%rbp)
10000099b:	48 8d 3d 80 05 00 00 	leaq	1408(%rip), %rdi
1000009a2:	b0 00 	movb	$0, %al
1000009a4:	e8 f9 01 00 00 	callq	505 <dyld_stub_binder+0x100000ba2>
1000009a9:	48 8d 3d 10 07 00 00 	leaq	1808(%rip), %rdi
1000009b0:	89 45 f8 	movl	%eax, -8(%rbp)
1000009b3:	e8 08 ff ff ff 	callq	-248 <_populate_time_str>
1000009b8:	48 8d 35 01 07 00 00 	leaq	1793(%rip), %rsi
1000009bf:	8b 7d fc 	movl	-4(%rbp), %edi
1000009c2:	e8 d9 fd ff ff 	callq	-551 <_WriteStr>
1000009c7:	48 89 45 f0 	movq	%rax, -16(%rbp)
1000009cb:	48 83 c4 10 	addq	$16, %rsp
1000009cf:	5d 	popq	%rbp
1000009d0:	c3 	retq
1000009d1:	66 2e 0f 1f 84 00 00 00 00 00 	nopw	%cs:(%rax,%rax)
1000009db:	0f 1f 44 00 00 	nopl	(%rax,%rax)
1000009e0:	55 	pushq	%rbp
1000009e1:	48 89 e5 	movq	%rsp, %rbp
1000009e4:	89 7d fc 	movl	%edi, -4(%rbp)
1000009e7:	c7 45 f8 01 00 00 00 	movl	$1, -8(%rbp)
1000009ee:	83 7d fc 01 	cmpl	$1, -4(%rbp)
1000009f2:	0f 8e 3f 00 00 00 	jle	63 <_secret_sequence+0x57>
1000009f8:	8b 45 f8 	movl	-8(%rbp), %eax
1000009fb:	83 c0 01 	addl	$1, %eax
1000009fe:	89 45 f8 	movl	%eax, -8(%rbp)
100000a01:	8b 45 fc 	movl	-4(%rbp), %eax
100000a04:	99 	cltd
100000a05:	b9 02 00 00 00 	movl	$2, %ecx
100000a0a:	f7 f9 	idivl	%ecx
100000a0c:	83 fa 00 	cmpl	$0, %edx
100000a0f:	0f 85 13 00 00 00 	jne	19 <_secret_sequence+0x48>
100000a15:	8b 45 fc 	movl	-4(%rbp), %eax
100000a18:	99 	cltd
100000a19:	b9 02 00 00 00 	movl	$2, %ecx
100000a1e:	f7 f9 	idivl	%ecx
100000a20:	89 45 fc 	movl	%eax, -4(%rbp)
100000a23:	e9 0a 00 00 00 	jmp	10 <_secret_sequence+0x52>
100000a28:	6b 45 fc 03 	imull	$3, -4(%rbp), %eax
100000a2c:	83 c0 01 	addl	$1, %eax
100000a2f:	89 45 fc 	movl	%eax, -4(%rbp)
100000a32:	e9 b7 ff ff ff 	jmp	-73 <_secret_sequence+0xe>
100000a37:	8b 45 f8 	movl	-8(%rbp), %eax
100000a3a:	5d 	popq	%rbp
100000a3b:	c3 	retq
100000a3c:	0f 1f 40 00 	nopl	(%rax)
100000a40:	55 	pushq	%rbp
100000a41:	48 89 e5 	movq	%rsp, %rbp
100000a44:	48 83 ec 50 	subq	$80, %rsp
100000a48:	c7 45 fc 00 00 00 00 	movl	$0, -4(%rbp)
100000a4f:	89 7d f8 	movl	%edi, -8(%rbp)
100000a52:	48 89 75 f0 	movq	%rsi, -16(%rbp)
100000a56:	48 8d 3d 33 03 00 00 	leaq	819(%rip), %rdi
100000a5d:	e8 ce fd ff ff 	callq	-562 <_create_or_append_for_writing>
100000a62:	89 45 ec 	movl	%eax, -20(%rbp)
100000a65:	48 8d 35 dc 04 00 00 	leaq	1244(%rip), %rsi
100000a6c:	48 89 75 e0 	movq	%rsi, -32(%rbp)
100000a70:	48 8b 7d e0 	movq	-32(%rbp), %rdi
100000a74:	48 8d 35 d7 04 00 00 	leaq	1239(%rip), %rsi
100000a7b:	e8 0a 01 00 00 	callq	266 <dyld_stub_binder+0x100000b8a>
100000a80:	48 89 45 d8 	movq	%rax, -40(%rbp)
100000a84:	48 83 7d d8 00 	cmpq	$0, -40(%rbp)
100000a89:	0f 85 29 00 00 00 	jne	41 <_main+0x78>
100000a8f:	48 8b 75 e0 	movq	-32(%rbp), %rsi
100000a93:	48 8d 3d ba 04 00 00 	leaq	1210(%rip), %rdi
100000a9a:	b0 00 	movb	$0, %al
100000a9c:	e8 01 01 00 00 	callq	257 <dyld_stub_binder+0x100000ba2>
100000aa1:	8b 7d ec 	movl	-20(%rbp), %edi
100000aa4:	89 45 cc 	movl	%eax, -52(%rbp)
100000aa7:	e8 e4 fe ff ff 	callq	-284 <_explode_bomb>
100000aac:	c7 45 fc 01 00 00 00 	movl	$1, -4(%rbp)
100000ab3:	e9 a5 00 00 00 	jmp	165 <_main+0x11d>
100000ab8:	48 8d 3d ae 04 00 00 	leaq	1198(%rip), %rdi
100000abf:	b0 00 	movb	$0, %al
100000ac1:	e8 dc 00 00 00 	callq	220 <dyld_stub_binder+0x100000ba2>
100000ac6:	48 8b 55 d8 	movq	-40(%rbp), %rdx
100000aca:	48 8d 3d cf 05 00 00 	leaq	1487(%rip), %rdi
100000ad1:	48 8d 35 d0 05 00 00 	leaq	1488(%rip), %rsi
100000ad8:	89 45 c8 	movl	%eax, -56(%rbp)
100000adb:	e8 b6 00 00 00 	callq	182 <dyld_stub_binder+0x100000b96>
100000ae0:	48 8b 3d b9 05 00 00 	movq	1465(%rip), %rdi
100000ae7:	48 89 45 c0 	movq	%rax, -64(%rbp)
100000aeb:	e8 82 00 00 00 	callq	130 <dyld_stub_binder+0x100000b72>
100000af0:	89 45 d4 	movl	%eax, -44(%rbp)
100000af3:	8b 75 d4 	movl	-44(%rbp), %esi
100000af6:	48 8d 3d 83 04 00 00 	leaq	1155(%rip), %rdi
100000afd:	b0 00 	movb	$0, %al
100000aff:	e8 9e 00 00 00 	callq	158 <dyld_stub_binder+0x100000ba2>
100000b04:	8b 7d d4 	movl	-44(%rbp), %edi
100000b07:	89 45 bc 	movl	%eax, -68(%rbp)
100000b0a:	e8 d1 fe ff ff 	callq	-303 <_secret_sequence>
100000b0f:	89 45 d0 	movl	%eax, -48(%rbp)
100000b12:	83 7d d0 06 	cmpl	$6, -48(%rbp)
100000b16:	0f 85 16 00 00 00 	jne	22 <_main+0xf2>
100000b1c:	48 8d 3d 61 04 00 00 	leaq	1121(%rip), %rdi
100000b23:	b0 00 	movb	$0, %al
100000b25:	e8 78 00 00 00 	callq	120 <dyld_stub_binder+0x100000ba2>
100000b2a:	89 45 b8 	movl	%eax, -72(%rbp)
100000b2d:	e9 1c 00 00 00 	jmp	28 <_main+0x10e>
100000b32:	8b 75 d0 	movl	-48(%rbp), %esi
100000b35:	48 8d 3d 59 04 00 00 	leaq	1113(%rip), %rdi
100000b3c:	b0 00 	movb	$0, %al
100000b3e:	e8 5f 00 00 00 	callq	95 <dyld_stub_binder+0x100000ba2>
100000b43:	8b 7d ec 	movl	-20(%rbp), %edi
100000b46:	89 45 b4 	movl	%eax, -76(%rbp)
100000b49:	e8 42 fe ff ff 	callq	-446 <_explode_bomb>
100000b4e:	8b 7d ec 	movl	-20(%rbp), %edi
100000b51:	e8 0a fc ff ff 	callq	-1014 <_Close>
100000b56:	c7 45 fc 00 00 00 00 	movl	$0, -4(%rbp)
100000b5d:	8b 45 fc 	movl	-4(%rbp), %eax
100000b60:	48 83 c4 50 	addq	$80, %rsp
100000b64:	5d 	popq	%rbp
100000b65:	c3 	retq

_unix_error:
1000006b0:	55 	pushq	%rbp
1000006b1:	48 89 e5 	movq	%rsp, %rbp
1000006b4:	48 83 ec 20 	subq	$32, %rsp
1000006b8:	48 89 7d f8 	movq	%rdi, -8(%rbp)
1000006bc:	48 8b 3d 45 09 00 00 	movq	2373(%rip), %rdi
1000006c3:	48 8b 3f 	movq	(%rdi), %rdi
1000006c6:	48 8b 55 f8 	movq	-8(%rbp), %rdx
1000006ca:	48 89 7d f0 	movq	%rdi, -16(%rbp)
1000006ce:	48 89 55 e8 	movq	%rdx, -24(%rbp)
1000006d2:	e8 8f 04 00 00 	callq	1167 <dyld_stub_binder+0x100000b66>
1000006d7:	8b 38 	movl	(%rax), %edi
1000006d9:	e8 d0 04 00 00 	callq	1232 <dyld_stub_binder+0x100000bae>
1000006de:	48 8d 35 ab 07 00 00 	leaq	1963(%rip), %rsi
1000006e5:	31 ff 	xorl	%edi, %edi
1000006e7:	40 88 f9 	movb	%dil, %cl
1000006ea:	48 8b 7d f0 	movq	-16(%rbp), %rdi
1000006ee:	48 8b 55 e8 	movq	-24(%rbp), %rdx
1000006f2:	88 4d e7 	movb	%cl, -25(%rbp)
1000006f5:	48 89 c1 	movq	%rax, %rcx
1000006f8:	8a 45 e7 	movb	-25(%rbp), %al
1000006fb:	e8 90 04 00 00 	callq	1168 <dyld_stub_binder+0x100000b90>
100000700:	bf 01 00 00 00 	movl	$1, %edi
100000705:	89 45 e0 	movl	%eax, -32(%rbp)
100000708:	e8 77 04 00 00 	callq	1143 <dyld_stub_binder+0x100000b84>
10000070d:	0f 1f 00 	nopl	(%rax)

_Open:
100000710:	55 	pushq	%rbp
100000711:	48 89 e5 	movq	%rsp, %rbp
100000714:	48 83 ec 20 	subq	$32, %rsp
100000718:	66 89 d0 	movw	%dx, %ax
10000071b:	48 89 7d f8 	movq	%rdi, -8(%rbp)
10000071f:	89 75 f4 	movl	%esi, -12(%rbp)
100000722:	66 89 45 f2 	movw	%ax, -14(%rbp)
100000726:	48 8b 7d f8 	movq	-8(%rbp), %rdi
10000072a:	8b 75 f4 	movl	-12(%rbp), %esi
10000072d:	0f b7 55 f2 	movzwl	-14(%rbp), %edx
100000731:	b0 00 	movb	$0, %al
100000733:	e8 64 04 00 00 	callq	1124 <dyld_stub_binder+0x100000b9c>
100000738:	89 45 ec 	movl	%eax, -20(%rbp)
10000073b:	83 f8 00 	cmpl	$0, %eax
10000073e:	0f 8d 0c 00 00 00 	jge	12 <_Open+0x40>
100000744:	48 8d 3d 4d 07 00 00 	leaq	1869(%rip), %rdi
10000074b:	e8 60 ff ff ff 	callq	-160 <_unix_error>
100000750:	8b 45 ec 	movl	-20(%rbp), %eax
100000753:	48 83 c4 20 	addq	$32, %rsp
100000757:	5d 	popq	%rbp
100000758:	c3 	retq
100000759:	0f 1f 80 00 00 00 00 	nopl	(%rax)

_Close:
100000760:	55 	pushq	%rbp
100000761:	48 89 e5 	movq	%rsp, %rbp
100000764:	48 83 ec 10 	subq	$16, %rsp
100000768:	89 7d fc 	movl	%edi, -4(%rbp)
10000076b:	8b 7d fc 	movl	-4(%rbp), %edi
10000076e:	e8 05 04 00 00 	callq	1029 <dyld_stub_binder+0x100000b78>
100000773:	89 45 f8 	movl	%eax, -8(%rbp)
100000776:	83 f8 00 	cmpl	$0, %eax
100000779:	0f 8d 0c 00 00 00 	jge	12 <_Close+0x2b>
10000077f:	48 8d 3d 1d 07 00 00 	leaq	1821(%rip), %rdi
100000786:	e8 25 ff ff ff 	callq	-219 <_unix_error>
10000078b:	48 83 c4 10 	addq	$16, %rsp
10000078f:	5d 	popq	%rbp
100000790:	c3 	retq
100000791:	66 2e 0f 1f 84 00 00 00 00 00 	nopw	%cs:(%rax,%rax)
10000079b:	0f 1f 44 00 00 	nopl	(%rax,%rax)

_WriteStr:
1000007a0:	55 	pushq	%rbp
1000007a1:	48 89 e5 	movq	%rsp, %rbp
1000007a4:	48 83 ec 20 	subq	$32, %rsp
1000007a8:	89 7d fc 	movl	%edi, -4(%rbp)
1000007ab:	48 89 75 f0 	movq	%rsi, -16(%rbp)
1000007af:	48 8b 7d f0 	movq	-16(%rbp), %rdi
1000007b3:	e8 fc 03 00 00 	callq	1020 <dyld_stub_binder+0x100000bb4>
1000007b8:	48 89 45 e8 	movq	%rax, -24(%rbp)
1000007bc:	8b 7d fc 	movl	-4(%rbp), %edi
1000007bf:	48 8b 75 f0 	movq	-16(%rbp), %rsi
1000007c3:	48 8b 55 e8 	movq	-24(%rbp), %rdx
1000007c7:	e8 fa 03 00 00 	callq	1018 <dyld_stub_binder+0x100000bc6>
1000007cc:	48 89 45 e0 	movq	%rax, -32(%rbp)
1000007d0:	48 83 f8 00 	cmpq	$0, %rax
1000007d4:	0f 8d 0c 00 00 00 	jge	12 <_WriteStr+0x46>
1000007da:	48 8d 3d ce 06 00 00 	leaq	1742(%rip), %rdi
1000007e1:	e8 ca fe ff ff 	callq	-310 <_unix_error>
1000007e6:	48 8b 45 e0 	movq	-32(%rbp), %rax
1000007ea:	48 83 c4 20 	addq	$32, %rsp
1000007ee:	5d 	popq	%rbp
1000007ef:	c3 	retq

_file_exists:
1000007f0:	55 	pushq	%rbp
1000007f1:	48 89 e5 	movq	%rsp, %rbp
1000007f4:	48 81 ec a0 00 00 00 	subq	$160, %rsp
1000007fb:	48 89 7d f8 	movq	%rdi, -8(%rbp)
1000007ff:	48 8b 7d f8 	movq	-8(%rbp), %rdi
100000803:	48 8d b5 68 ff ff ff 	leaq	-152(%rbp), %rsi
10000080a:	e8 99 03 00 00 	callq	921 <dyld_stub_binder+0x100000ba8>
10000080f:	83 f8 00 	cmpl	$0, %eax
100000812:	0f 94 c1 	sete	%cl
100000815:	80 e1 01 	andb	$1, %cl
100000818:	0f b6 c1 	movzbl	%cl, %eax
10000081b:	48 81 c4 a0 00 00 00 	addq	$160, %rsp
100000822:	5d 	popq	%rbp
100000823:	c3 	retq
100000824:	66 2e 0f 1f 84 00 00 00 00 00 	nopw	%cs:(%rax,%rax)
10000082e:	66 90 	nop

_create_or_append_for_writing:
100000830:	55 	pushq	%rbp
100000831:	48 89 e5 	movq	%rsp, %rbp
100000834:	48 83 ec 10 	subq	$16, %rsp
100000838:	48 89 7d f8 	movq	%rdi, -8(%rbp)
10000083c:	c7 45 f4 ff ff ff ff 	movl	$4294967295, -12(%rbp)
100000843:	48 8b 7d f8 	movq	-8(%rbp), %rdi
100000847:	e8 a4 ff ff ff 	callq	-92 <_file_exists>
10000084c:	83 f8 00 	cmpl	$0, %eax
10000084f:	0f 84 18 00 00 00 	je	24 <_create_or_append_for_writing+0x3d>
100000855:	31 d2 	xorl	%edx, %edx
100000857:	48 8b 7d f8 	movq	-8(%rbp), %rdi
10000085b:	be 09 00 00 00 	movl	$9, %esi
100000860:	e8 ab fe ff ff 	callq	-341 <_Open>
100000865:	89 45 f4 	movl	%eax, -12(%rbp)
100000868:	e9 24 00 00 00 	jmp	36 <_create_or_append_for_writing+0x61>
10000086d:	bf 12 00 00 00 	movl	$18, %edi
100000872:	e8 49 03 00 00 	callq	841 <dyld_stub_binder+0x100000bc0>
100000877:	48 8b 7d f8 	movq	-8(%rbp), %rdi
10000087b:	be 01 06 00 00 	movl	$1537, %esi
100000880:	ba b6 01 00 00 	movl	$438, %edx
100000885:	66 89 45 f2 	movw	%ax, -14(%rbp)
100000889:	e8 82 fe ff ff 	callq	-382 <_Open>
10000088e:	89 45 f4 	movl	%eax, -12(%rbp)
100000891:	8b 45 f4 	movl	-12(%rbp), %eax
100000894:	48 83 c4 10 	addq	$16, %rsp
100000898:	5d 	popq	%rbp
100000899:	c3 	retq
10000089a:	66 0f 1f 44 00 00 	nopw	(%rax,%rax)

_print_greeting:
1000008a0:	55 	pushq	%rbp
1000008a1:	48 89 e5 	movq	%rsp, %rbp
1000008a4:	48 83 ec 10 	subq	$16, %rsp
1000008a8:	48 8d 3d e1 03 00 00 	leaq	993(%rip), %rdi
1000008af:	b0 00 	movb	$0, %al
1000008b1:	e8 ec 02 00 00 	callq	748 <dyld_stub_binder+0x100000ba2>
1000008b6:	89 45 fc 	movl	%eax, -4(%rbp)
1000008b9:	48 83 c4 10 	addq	$16, %rsp
1000008bd:	5d 	popq	%rbp
1000008be:	c3 	retq
1000008bf:	90 	nop

_populate_time_str:
1000008c0:	55 	pushq	%rbp
1000008c1:	48 89 e5 	movq	%rsp, %rbp
1000008c4:	48 83 ec 20 	subq	$32, %rsp
1000008c8:	31 c0 	xorl	%eax, %eax
1000008ca:	89 c1 	movl	%eax, %ecx
1000008cc:	48 89 7d f8 	movq	%rdi, -8(%rbp)
1000008d0:	48 89 cf 	movq	%rcx, %rdi
1000008d3:	e8 e2 02 00 00 	callq	738 <dyld_stub_binder+0x100000bba>
1000008d8:	48 8d 0d d9 07 00 00 	leaq	2009(%rip), %rcx
1000008df:	48 89 01 	movq	%rax, (%rcx)
1000008e2:	48 83 39 ff 	cmpq	$-1, (%rcx)
1000008e6:	0f 85 29 00 00 00 	jne	41 <_populate_time_str+0x55>
1000008ec:	48 8b 05 15 07 00 00 	movq	1813(%rip), %rax
1000008f3:	48 8b 38 	movq	(%rax), %rdi
1000008f6:	48 8d 35 be 05 00 00 	leaq	1470(%rip), %rsi
1000008fd:	31 c9 	xorl	%ecx, %ecx
1000008ff:	88 ca 	movb	%cl, %dl
100000901:	88 d0 	movb	%dl, %al
100000903:	e8 88 02 00 00 	callq	648 <dyld_stub_binder+0x100000b90>
100000908:	bf 01 00 00 00 	movl	$1, %edi
10000090d:	89 45 f4 	movl	%eax, -12(%rbp)
100000910:	e8 6f 02 00 00 	callq	623 <dyld_stub_binder+0x100000b84>
100000915:	48 8d 3d 9c 07 00 00 	leaq	1948(%rip), %rdi
10000091c:	e8 5d 02 00 00 	callq	605 <dyld_stub_binder+0x100000b7e>
100000921:	48 8d 3d 88 07 00 00 	leaq	1928(%rip), %rdi
100000928:	48 89 07 	movq	%rax, (%rdi)
10000092b:	48 83 3f 00 	cmpq	$0, (%rdi)
10000092f:	0f 85 29 00 00 00 	jne	41 <_populate_time_str+0x9e>
100000935:	48 8b 05 cc 06 00 00 	movq	1740(%rip), %rax
10000093c:	48 8b 38 	movq	(%rax), %rdi
10000093f:	48 8d 35 9a 05 00 00 	leaq	1434(%rip), %rsi
100000946:	31 c9 	xorl	%ecx, %ecx
100000948:	88 ca 	movb	%cl, %dl
10000094a:	88 d0 	movb	%dl, %al
10000094c:	e8 3f 02 00 00 	callq	575 <dyld_stub_binder+0x100000b90>
100000951:	bf 01 00 00 00 	movl	$1, %edi
100000956:	89 45 f0 	movl	%eax, -16(%rbp)
100000959:	e8 26 02 00 00 	callq	550 <dyld_stub_binder+0x100000b84>
10000095e:	31 f6 	xorl	%esi, %esi
100000960:	48 8d 05 49 07 00 00 	leaq	1865(%rip), %rax
100000967:	48 c7 c2 ff ff ff ff 	movq	$-1, %rdx
10000096e:	48 8b 7d f8 	movq	-8(%rbp), %rdi
100000972:	4c 8b 00 	movq	(%rax), %r8
100000975:	48 8d 0d 8a 05 00 00 	leaq	1418(%rip), %rcx
10000097c:	b0 00 	movb	$0, %al
10000097e:	e8 e9 01 00 00 	callq	489 <dyld_stub_binder+0x100000b6c>
100000983:	89 45 ec 	movl	%eax, -20(%rbp)
100000986:	48 83 c4 20 	addq	$32, %rsp
10000098a:	5d 	popq	%rbp
10000098b:	c3 	retq
10000098c:	0f 1f 40 00 	nopl	(%rax)

_explode_bomb:
100000990:	55 	pushq	%rbp
100000991:	48 89 e5 	movq	%rsp, %rbp
100000994:	48 83 ec 10 	subq	$16, %rsp
100000998:	89 7d fc 	movl	%edi, -4(%rbp)
10000099b:	48 8d 3d 80 05 00 00 	leaq	1408(%rip), %rdi
1000009a2:	b0 00 	movb	$0, %al
1000009a4:	e8 f9 01 00 00 	callq	505 <dyld_stub_binder+0x100000ba2>
1000009a9:	48 8d 3d 10 07 00 00 	leaq	1808(%rip), %rdi
1000009b0:	89 45 f8 	movl	%eax, -8(%rbp)
1000009b3:	e8 08 ff ff ff 	callq	-248 <_populate_time_str>
1000009b8:	48 8d 35 01 07 00 00 	leaq	1793(%rip), %rsi
1000009bf:	8b 7d fc 	movl	-4(%rbp), %edi
1000009c2:	e8 d9 fd ff ff 	callq	-551 <_WriteStr>
1000009c7:	48 89 45 f0 	movq	%rax, -16(%rbp)
1000009cb:	48 83 c4 10 	addq	$16, %rsp
1000009cf:	5d 	popq	%rbp
1000009d0:	c3 	retq
1000009d1:	66 2e 0f 1f 84 00 00 00 00 00 	nopw	%cs:(%rax,%rax)
1000009db:	0f 1f 44 00 00 	nopl	(%rax,%rax)

_secret_sequence:
1000009e0:	55 	pushq	%rbp
1000009e1:	48 89 e5 	movq	%rsp, %rbp
1000009e4:	89 7d fc 	movl	%edi, -4(%rbp)
1000009e7:	c7 45 f8 01 00 00 00 	movl	$1, -8(%rbp)
1000009ee:	83 7d fc 01 	cmpl	$1, -4(%rbp)
1000009f2:	0f 8e 3f 00 00 00 	jle	63 <_secret_sequence+0x57>
1000009f8:	8b 45 f8 	movl	-8(%rbp), %eax
1000009fb:	83 c0 01 	addl	$1, %eax
1000009fe:	89 45 f8 	movl	%eax, -8(%rbp)
100000a01:	8b 45 fc 	movl	-4(%rbp), %eax
100000a04:	99 	cltd
100000a05:	b9 02 00 00 00 	movl	$2, %ecx
100000a0a:	f7 f9 	idivl	%ecx
100000a0c:	83 fa 00 	cmpl	$0, %edx
100000a0f:	0f 85 13 00 00 00 	jne	19 <_secret_sequence+0x48>
100000a15:	8b 45 fc 	movl	-4(%rbp), %eax
100000a18:	99 	cltd
100000a19:	b9 02 00 00 00 	movl	$2, %ecx
100000a1e:	f7 f9 	idivl	%ecx
100000a20:	89 45 fc 	movl	%eax, -4(%rbp)
100000a23:	e9 0a 00 00 00 	jmp	10 <_secret_sequence+0x52>
100000a28:	6b 45 fc 03 	imull	$3, -4(%rbp), %eax
100000a2c:	83 c0 01 	addl	$1, %eax
100000a2f:	89 45 fc 	movl	%eax, -4(%rbp)
100000a32:	e9 b7 ff ff ff 	jmp	-73 <_secret_sequence+0xe>
100000a37:	8b 45 f8 	movl	-8(%rbp), %eax
100000a3a:	5d 	popq	%rbp
100000a3b:	c3 	retq
100000a3c:	0f 1f 40 00 	nopl	(%rax)

_main:
100000a40:	55 	pushq	%rbp
100000a41:	48 89 e5 	movq	%rsp, %rbp
100000a44:	48 83 ec 50 	subq	$80, %rsp
100000a48:	c7 45 fc 00 00 00 00 	movl	$0, -4(%rbp)
100000a4f:	89 7d f8 	movl	%edi, -8(%rbp)
100000a52:	48 89 75 f0 	movq	%rsi, -16(%rbp)
100000a56:	48 8d 3d 33 03 00 00 	leaq	819(%rip), %rdi
100000a5d:	e8 ce fd ff ff 	callq	-562 <_create_or_append_for_writing>
100000a62:	89 45 ec 	movl	%eax, -20(%rbp)
100000a65:	48 8d 35 dc 04 00 00 	leaq	1244(%rip), %rsi
100000a6c:	48 89 75 e0 	movq	%rsi, -32(%rbp)
100000a70:	48 8b 7d e0 	movq	-32(%rbp), %rdi
100000a74:	48 8d 35 d7 04 00 00 	leaq	1239(%rip), %rsi
100000a7b:	e8 0a 01 00 00 	callq	266 <dyld_stub_binder+0x100000b8a>
100000a80:	48 89 45 d8 	movq	%rax, -40(%rbp)
100000a84:	48 83 7d d8 00 	cmpq	$0, -40(%rbp)
100000a89:	0f 85 29 00 00 00 	jne	41 <_main+0x78>
100000a8f:	48 8b 75 e0 	movq	-32(%rbp), %rsi
100000a93:	48 8d 3d ba 04 00 00 	leaq	1210(%rip), %rdi
100000a9a:	b0 00 	movb	$0, %al
100000a9c:	e8 01 01 00 00 	callq	257 <dyld_stub_binder+0x100000ba2>
100000aa1:	8b 7d ec 	movl	-20(%rbp), %edi
100000aa4:	89 45 cc 	movl	%eax, -52(%rbp)
100000aa7:	e8 e4 fe ff ff 	callq	-284 <_explode_bomb>
100000aac:	c7 45 fc 01 00 00 00 	movl	$1, -4(%rbp)
100000ab3:	e9 a5 00 00 00 	jmp	165 <_main+0x11d>
100000ab8:	48 8d 3d ae 04 00 00 	leaq	1198(%rip), %rdi
100000abf:	b0 00 	movb	$0, %al
100000ac1:	e8 dc 00 00 00 	callq	220 <dyld_stub_binder+0x100000ba2>
100000ac6:	48 8b 55 d8 	movq	-40(%rbp), %rdx
100000aca:	48 8d 3d cf 05 00 00 	leaq	1487(%rip), %rdi
100000ad1:	48 8d 35 d0 05 00 00 	leaq	1488(%rip), %rsi
100000ad8:	89 45 c8 	movl	%eax, -56(%rbp)
100000adb:	e8 b6 00 00 00 	callq	182 <dyld_stub_binder+0x100000b96>
100000ae0:	48 8b 3d b9 05 00 00 	movq	1465(%rip), %rdi
100000ae7:	48 89 45 c0 	movq	%rax, -64(%rbp)
100000aeb:	e8 82 00 00 00 	callq	130 <dyld_stub_binder+0x100000b72>
100000af0:	89 45 d4 	movl	%eax, -44(%rbp)
100000af3:	8b 75 d4 	movl	-44(%rbp), %esi
100000af6:	48 8d 3d 83 04 00 00 	leaq	1155(%rip), %rdi
100000afd:	b0 00 	movb	$0, %al
100000aff:	e8 9e 00 00 00 	callq	158 <dyld_stub_binder+0x100000ba2>
100000b04:	8b 7d d4 	movl	-44(%rbp), %edi
100000b07:	89 45 bc 	movl	%eax, -68(%rbp)
100000b0a:	e8 d1 fe ff ff 	callq	-303 <_secret_sequence>
100000b0f:	89 45 d0 	movl	%eax, -48(%rbp)
100000b12:	83 7d d0 06 	cmpl	$6, -48(%rbp)
100000b16:	0f 85 16 00 00 00 	jne	22 <_main+0xf2>
100000b1c:	48 8d 3d 61 04 00 00 	leaq	1121(%rip), %rdi
100000b23:	b0 00 	movb	$0, %al
100000b25:	e8 78 00 00 00 	callq	120 <dyld_stub_binder+0x100000ba2>
100000b2a:	89 45 b8 	movl	%eax, -72(%rbp)
100000b2d:	e9 1c 00 00 00 	jmp	28 <_main+0x10e>
100000b32:	8b 75 d0 	movl	-48(%rbp), %esi
100000b35:	48 8d 3d 59 04 00 00 	leaq	1113(%rip), %rdi
100000b3c:	b0 00 	movb	$0, %al
100000b3e:	e8 5f 00 00 00 	callq	95 <dyld_stub_binder+0x100000ba2>
100000b43:	8b 7d ec 	movl	-20(%rbp), %edi
100000b46:	89 45 b4 	movl	%eax, -76(%rbp)
100000b49:	e8 42 fe ff ff 	callq	-446 <_explode_bomb>
100000b4e:	8b 7d ec 	movl	-20(%rbp), %edi
100000b51:	e8 0a fc ff ff 	callq	-1014 <_Close>
100000b56:	c7 45 fc 00 00 00 00 	movl	$0, -4(%rbp)
100000b5d:	8b 45 fc 	movl	-4(%rbp), %eax
100000b60:	48 83 c4 50 	addq	$80, %rsp
100000b64:	5d 	popq	%rbp
100000b65:	c3 	retq
Disassembly of section __TEXT,__stubs:
__stubs:
100000b66:	ff 25 ac 04 00 00 	jmpq	*1196(%rip)
100000b6c:	ff 25 ae 04 00 00 	jmpq	*1198(%rip)
100000b72:	ff 25 b0 04 00 00 	jmpq	*1200(%rip)
100000b78:	ff 25 b2 04 00 00 	jmpq	*1202(%rip)
100000b7e:	ff 25 b4 04 00 00 	jmpq	*1204(%rip)
100000b84:	ff 25 b6 04 00 00 	jmpq	*1206(%rip)
100000b8a:	ff 25 b8 04 00 00 	jmpq	*1208(%rip)
100000b90:	ff 25 ba 04 00 00 	jmpq	*1210(%rip)
100000b96:	ff 25 bc 04 00 00 	jmpq	*1212(%rip)
100000b9c:	ff 25 be 04 00 00 	jmpq	*1214(%rip)
100000ba2:	ff 25 c0 04 00 00 	jmpq	*1216(%rip)
100000ba8:	ff 25 c2 04 00 00 	jmpq	*1218(%rip)
100000bae:	ff 25 c4 04 00 00 	jmpq	*1220(%rip)
100000bb4:	ff 25 c6 04 00 00 	jmpq	*1222(%rip)
100000bba:	ff 25 c8 04 00 00 	jmpq	*1224(%rip)
100000bc0:	ff 25 ca 04 00 00 	jmpq	*1226(%rip)
100000bc6:	ff 25 cc 04 00 00 	jmpq	*1228(%rip)
Disassembly of section __TEXT,__stub_helper:
__stub_helper:
100000bcc:	4c 8d 1d 2d 04 00 00 	leaq	1069(%rip), %r11
100000bd3:	41 53 	pushq	%r11
100000bd5:	ff 25 35 04 00 00 	jmpq	*1077(%rip)
100000bdb:	90 	nop
100000bdc:	68 00 00 00 00 	pushq	$0
100000be1:	e9 e6 ff ff ff 	jmp	-26 <__stub_helper>
100000be6:	68 0f 00 00 00 	pushq	$15
100000beb:	e9 dc ff ff ff 	jmp	-36 <__stub_helper>
100000bf0:	68 24 00 00 00 	pushq	$36
100000bf5:	e9 d2 ff ff ff 	jmp	-46 <__stub_helper>
100000bfa:	68 30 00 00 00 	pushq	$48
100000bff:	e9 c8 ff ff ff 	jmp	-56 <__stub_helper>
100000c04:	68 3d 00 00 00 	pushq	$61
100000c09:	e9 be ff ff ff 	jmp	-66 <__stub_helper>
100000c0e:	68 4a 00 00 00 	pushq	$74
100000c13:	e9 b4 ff ff ff 	jmp	-76 <__stub_helper>
100000c18:	68 56 00 00 00 	pushq	$86
100000c1d:	e9 aa ff ff ff 	jmp	-86 <__stub_helper>
100000c22:	68 63 00 00 00 	pushq	$99
100000c27:	e9 a0 ff ff ff 	jmp	-96 <__stub_helper>
100000c2c:	68 72 00 00 00 	pushq	$114
100000c31:	e9 96 ff ff ff 	jmp	-106 <__stub_helper>
100000c36:	68 81 00 00 00 	pushq	$129
100000c3b:	e9 8c ff ff ff 	jmp	-116 <__stub_helper>
100000c40:	68 8d 00 00 00 	pushq	$141
100000c45:	e9 82 ff ff ff 	jmp	-126 <__stub_helper>
100000c4a:	68 9b 00 00 00 	pushq	$155
100000c4f:	e9 78 ff ff ff 	jmp	-136 <__stub_helper>
100000c54:	68 af 00 00 00 	pushq	$175
100000c59:	e9 6e ff ff ff 	jmp	-146 <__stub_helper>
100000c5e:	68 bf 00 00 00 	pushq	$191
100000c63:	e9 64 ff ff ff 	jmp	-156 <__stub_helper>
100000c68:	68 ce 00 00 00 	pushq	$206
100000c6d:	e9 5a ff ff ff 	jmp	-166 <__stub_helper>
100000c72:	68 db 00 00 00 	pushq	$219
100000c77:	e9 50 ff ff ff 	jmp	-176 <__stub_helper>
100000c7c:	68 e9 00 00 00 	pushq	$233
100000c81:	e9 46 ff ff ff 	jmp	-186 <__stub_helper>
Disassembly of section __TEXT,__const:
_GREETING:
100000c90:	57 	pushq	%rdi
100000c91:	65 6c 	insb	%dx, %es:(%rdi)
100000c93:	63 6f 6d 	movslq	109(%rdi), %ebp
100000c96:	65 20 74 6f 20 	andb	%dh, %gs:32(%rdi,%rbp,2)
100000c9b:	74 68 	je	104 <_GREETING+0x75>
100000c9d:	65 20 4d 69 	andb	%cl, %gs:105(%rbp)
100000ca1:	6e 	outsb	(%rsi), %dx
100000ca2:	69 2d 42 6f 6d 62 20 4d 6b 31 	imull	$829115680, 1651339074(%rip), %ebp
100000cac:	20 50 72 	andb	%dl, 114(%rax)
100000caf:	65 6c 	insb	%dx, %es:(%rdi)
100000cb1:	69 6e 69 6d 61 72 79 	imull	$2037539181, 105(%rsi), %ebp
100000cb8:	20 74 65 73 	andb	%dh, 115(%rbp,%riz,2)
100000cbc:	74 2e 	je	46 <_GREETING+0x5c>
100000cbe:	0a 23 	orb	(%rbx), %ah
100000cc0:	23 20 	andl	(%rax), %esp
100000cc2:	53 	pushq	%rbx
100000cc3:	61  <unknown>
100000cc4:	66 65 74 79 	je	121 <_GREETING+0xb1>
100000cc8:	20 45 71 	andb	%al, 113(%rbp)
100000ccb:	75 69 	jne	105 <_GREETING+0xa6>
100000ccd:	70 6d 	jo	109 <_GREETING+0xac>
100000ccf:	65 6e 	outsb	%gs:(%rsi), %dx
100000cd1:	74 20 	je	32 <_GREETING+0x63>
100000cd3:	6d 	insl	%dx, %es:(%rdi)
100000cd4:	75 73 	jne	115 <_GREETING+0xb9>
100000cd6:	74 20 	je	32 <_GREETING+0x68>
100000cd8:	62  <unknown>
100000cd9:	65 20 77 6f 	andb	%dh, %gs:111(%rdi)
100000cdd:	72 6e 	jb	110 <_GREETING+0xbd>
100000cdf:	20 61 74 	andb	%ah, 116(%rcx)
100000ce2:	20 61 6c 	andb	%ah, 108(%rcx)
100000ce5:	6c 	insb	%dx, %es:(%rdi)
100000ce6:	20 74 69 6d 	andb	%dh, 109(%rcx,%rbp,2)
100000cea:	65 73 2e 	jae	46 <_GREETING+0x8b>
100000ced:	20 23 	andb	%ah, (%rbx)
100000cef:	23 0a 	andl	(%rdx), %ecx
100000cf1:	0a 00 	orb	(%rax), %al
100000cf3:	00 00 	addb	%al, (%rax)
100000cf5:	00 00 	addb	%al, (%rax)
100000cf7:	00 00 	addb	%al, (%rax)
100000cf9:	00 00 	addb	%al, (%rax)
100000cfb:	00 00 	addb	%al, (%rax)
100000cfd:	00 00 	addb	%al, (%rax)
100000cff:	00 00 	addb	%al, (%rax)
100000d01:	00 00 	addb	%al, (%rax)
100000d03:	00 00 	addb	%al, (%rax)
100000d05:	00 00 	addb	%al, (%rax)
100000d07:	00 00 	addb	%al, (%rax)
100000d09:	00 00 	addb	%al, (%rax)
100000d0b:	00 00 	addb	%al, (%rax)
100000d0d:	00 00 	addb	%al, (%rax)
100000d0f:	00 00 	addb	%al, (%rax)
100000d11:	00 00 	addb	%al, (%rax)
100000d13:	00 00 	addb	%al, (%rax)
100000d15:	00 00 	addb	%al, (%rax)
100000d17:	00 00 	addb	%al, (%rax)
100000d19:	00 00 	addb	%al, (%rax)
100000d1b:	00 00 	addb	%al, (%rax)
100000d1d:	00 00 	addb	%al, (%rax)
100000d1f:	00 00 	addb	%al, (%rax)
100000d21:	00 00 	addb	%al, (%rax)
100000d23:	00 00 	addb	%al, (%rax)
100000d25:	00 00 	addb	%al, (%rax)
100000d27:	00 00 	addb	%al, (%rax)
100000d29:	00 00 	addb	%al, (%rax)
100000d2b:	00 00 	addb	%al, (%rax)
100000d2d:	00 00 	addb	%al, (%rax)
100000d2f:	00 00 	addb	%al, (%rax)
100000d31:	00 00 	addb	%al, (%rax)
100000d33:	00 00 	addb	%al, (%rax)
100000d35:	00 00 	addb	%al, (%rax)
100000d37:	00 00 	addb	%al, (%rax)
100000d39:	00 00 	addb	%al, (%rax)
100000d3b:	00 00 	addb	%al, (%rax)
100000d3d:	00 00 	addb	%al, (%rax)
100000d3f:	00 00 	addb	%al, (%rax)
100000d41:	00 00 	addb	%al, (%rax)
100000d43:	00 00 	addb	%al, (%rax)
100000d45:	00 00 	addb	%al, (%rax)
100000d47:	00 00 	addb	%al, (%rax)
100000d49:	00 00 	addb	%al, (%rax)
100000d4b:	00 00 	addb	%al, (%rax)
100000d4d:	00 00 	addb	%al, (%rax)
100000d4f:	00 00 	addb	%al, (%rax)
100000d51:	00 00 	addb	%al, (%rax)
100000d53:	00 00 	addb	%al, (%rax)
100000d55:	00 00 	addb	%al, (%rax)
100000d57:	00 00 	addb	%al, (%rax)
100000d59:	00 00 	addb	%al, (%rax)
100000d5b:	00 00 	addb	%al, (%rax)
100000d5d:	00 00 	addb	%al, (%rax)
100000d5f:	00 00 	addb	%al, (%rax)
100000d61:	00 00 	addb	%al, (%rax)
100000d63:	00 00 	addb	%al, (%rax)
100000d65:	00 00 	addb	%al, (%rax)
100000d67:	00 00 	addb	%al, (%rax)
100000d69:	00 00 	addb	%al, (%rax)
100000d6b:	00 00 	addb	%al, (%rax)
100000d6d:	00 00 	addb	%al, (%rax)
100000d6f:	00 00 	addb	%al, (%rax)
100000d71:	00 00 	addb	%al, (%rax)
100000d73:	00 00 	addb	%al, (%rax)
100000d75:	00 00 	addb	%al, (%rax)
100000d77:	00 00 	addb	%al, (%rax)
100000d79:	00 00 	addb	%al, (%rax)
100000d7b:	00 00 	addb	%al, (%rax)
100000d7d:	00 00 	addb	%al, (%rax)
100000d7f:	00 00 	addb	%al, (%rax)
100000d81:	00 00 	addb	%al, (%rax)
100000d83:	00 00 	addb	%al, (%rax)
100000d85:	00 00 	addb	%al, (%rax)
100000d87:	00 00 	addb	%al, (%rax)
100000d89:	00 00 	addb	%al, (%rax)
100000d8b:	00 00 	addb	%al, (%rax)
100000d8d:	00 00 	addb	%al, (%rax)
100000d8f:	00 42 6f 	addb	%al, 111(%rdx)

_FNAME:
100000d90:	42 6f 	outsl	(%rsi), %dx
100000d92:	6d 	insl	%dx, %es:(%rdi)
100000d93:	62 52 65 63 6f  <unknown>
100000d98:	72 64 	jb	100 <_FNAME+0x6e>
100000d9a:	2e 74 78 	je	120 <_FNAME+0x85>
100000d9d:	74 00 	je	0 <_FNAME+0xf>
100000d9f:	00 00 	addb	%al, (%rax)
100000da1:	00 00 	addb	%al, (%rax)
100000da3:	00 00 	addb	%al, (%rax)
100000da5:	00 00 	addb	%al, (%rax)
100000da7:	00 00 	addb	%al, (%rax)
100000da9:	00 00 	addb	%al, (%rax)
100000dab:	00 00 	addb	%al, (%rax)
100000dad:	00 00 	addb	%al, (%rax)
100000daf:	00 00 	addb	%al, (%rax)
100000db1:	00 00 	addb	%al, (%rax)
100000db3:	00 00 	addb	%al, (%rax)
100000db5:	00 00 	addb	%al, (%rax)
100000db7:	00 00 	addb	%al, (%rax)
100000db9:	00 00 	addb	%al, (%rax)
100000dbb:	00 00 	addb	%al, (%rax)
100000dbd:	00 00 	addb	%al, (%rax)
100000dbf:	00 00 	addb	%al, (%rax)
100000dc1:	00 00 	addb	%al, (%rax)
100000dc3:	00 00 	addb	%al, (%rax)
100000dc5:	00 00 	addb	%al, (%rax)
100000dc7:	00 00 	addb	%al, (%rax)
100000dc9:	00 00 	addb	%al, (%rax)
100000dcb:	00 00 	addb	%al, (%rax)
100000dcd:	00 00 	addb	%al, (%rax)
100000dcf:	00 00 	addb	%al, (%rax)
100000dd1:	00 00 	addb	%al, (%rax)
100000dd3:	00 00 	addb	%al, (%rax)
100000dd5:	00 00 	addb	%al, (%rax)
100000dd7:	00 00 	addb	%al, (%rax)
100000dd9:	00 00 	addb	%al, (%rax)
100000ddb:	00 00 	addb	%al, (%rax)
100000ddd:	00 00 	addb	%al, (%rax)
100000ddf:	00 00 	addb	%al, (%rax)
100000de1:	00 00 	addb	%al, (%rax)
100000de3:	00 00 	addb	%al, (%rax)
100000de5:	00 00 	addb	%al, (%rax)
100000de7:	00 00 	addb	%al, (%rax)
100000de9:	00 00 	addb	%al, (%rax)
100000deb:	00 00 	addb	%al, (%rax)
100000ded:	00 00 	addb	%al, (%rax)
100000def:	00 00 	addb	%al, (%rax)
100000df1:	00 00 	addb	%al, (%rax)
100000df3:	00 00 	addb	%al, (%rax)
100000df5:	00 00 	addb	%al, (%rax)
100000df7:	00 00 	addb	%al, (%rax)
100000df9:	00 00 	addb	%al, (%rax)
100000dfb:	00 00 	addb	%al, (%rax)
100000dfd:	00 00 	addb	%al, (%rax)
100000dff:	00 00 	addb	%al, (%rax)
100000e01:	00 00 	addb	%al, (%rax)
100000e03:	00 00 	addb	%al, (%rax)
100000e05:	00 00 	addb	%al, (%rax)
100000e07:	00 00 	addb	%al, (%rax)
100000e09:	00 00 	addb	%al, (%rax)
100000e0b:	00 00 	addb	%al, (%rax)
100000e0d:	00 00 	addb	%al, (%rax)
100000e0f:	00 00 	addb	%al, (%rax)
100000e11:	00 00 	addb	%al, (%rax)
100000e13:	00 00 	addb	%al, (%rax)
100000e15:	00 00 	addb	%al, (%rax)
100000e17:	00 00 	addb	%al, (%rax)
100000e19:	00 00 	addb	%al, (%rax)
100000e1b:	00 00 	addb	%al, (%rax)
100000e1d:	00 00 	addb	%al, (%rax)
100000e1f:	00 00 	addb	%al, (%rax)
100000e21:	00 00 	addb	%al, (%rax)
100000e23:	00 00 	addb	%al, (%rax)
100000e25:	00 00 	addb	%al, (%rax)
100000e27:	00 00 	addb	%al, (%rax)
100000e29:	00 00 	addb	%al, (%rax)
100000e2b:	00 00 	addb	%al, (%rax)
100000e2d:	00 00 	addb	%al, (%rax)
100000e2f:	00 00 	addb	%al, (%rax)
100000e31:	00 00 	addb	%al, (%rax)
100000e33:	00 00 	addb	%al, (%rax)
100000e35:	00 00 	addb	%al, (%rax)
100000e37:	00 00 	addb	%al, (%rax)
100000e39:	00 00 	addb	%al, (%rax)
100000e3b:	00 00 	addb	%al, (%rax)
100000e3d:	00 00 	addb	%al, (%rax)
100000e3f:	00 00 	addb	%al, (%rax)
100000e41:	00 00 	addb	%al, (%rax)
100000e43:	00 00 	addb	%al, (%rax)
100000e45:	00 00 	addb	%al, (%rax)
100000e47:	00 00 	addb	%al, (%rax)
100000e49:	00 00 	addb	%al, (%rax)
100000e4b:	00 00 	addb	%al, (%rax)
100000e4d:	00 00 	addb	%al, (%rax)
100000e4f:	00 00 	addb	%al, (%rax)
100000e51:	00 00 	addb	%al, (%rax)
100000e53:	00 00 	addb	%al, (%rax)
100000e55:	00 00 	addb	%al, (%rax)
100000e57:	00 00 	addb	%al, (%rax)
100000e59:	00 00 	addb	%al, (%rax)
100000e5b:	00 00 	addb	%al, (%rax)
100000e5d:	00 00 	addb	%al, (%rax)
100000e5f:	00 00 	addb	%al, (%rax)
100000e61:	00 00 	addb	%al, (%rax)
100000e63:	00 00 	addb	%al, (%rax)
100000e65:	00 00 	addb	%al, (%rax)
100000e67:	00 00 	addb	%al, (%rax)
100000e69:	00 00 	addb	%al, (%rax)
100000e6b:	00 00 	addb	%al, (%rax)
100000e6d:	00 00 	addb	%al, (%rax)
100000e6f:	00 00 	addb	%al, (%rax)
100000e71:	00 00 	addb	%al, (%rax)
100000e73:	00 00 	addb	%al, (%rax)
100000e75:	00 00 	addb	%al, (%rax)
100000e77:	00 00 	addb	%al, (%rax)
100000e79:	00 00 	addb	%al, (%rax)
100000e7b:	00 00 	addb	%al, (%rax)
100000e7d:	00 00 	addb	%al, (%rax)
100000e7f:	00 00 	addb	%al, (%rax)
100000e81:	00 00 	addb	%al, (%rax)
100000e83:	00 00 	addb	%al, (%rax)
100000e85:	00 00 	addb	%al, (%rax)
100000e87:	00 00 	addb	%al, (%rax)
100000e89:	00 00 	addb	%al, (%rax)
100000e8b:	00 00 	addb	%al, (%rax)
100000e8d:	00 00 	addb	%al, (%rax)
100000e8f:	00  <unknown>
Disassembly of section __TEXT,__cstring:
__cstring:
100000e90:	25 73 3a 20 25 	andl	$622869107, %eax
100000e95:	73 0a 	jae	10 <__cstring+0x11>
100000e97:	00 4f 70 	addb	%cl, 112(%rdi)
100000e9a:	65 6e 	outsb	%gs:(%rsi), %dx
100000e9c:	20 65 72 	andb	%ah, 114(%rbp)
100000e9f:	72 6f 	jb	111 <__cstring+0x80>
100000ea1:	72 00 	jb	0 <__cstring+0x13>
100000ea3:	43 6c 	insb	%dx, %es:(%rdi)
100000ea5:	6f 	outsl	(%rsi), %dx
100000ea6:	73 65 	jae	101 <__cstring+0x7d>
100000ea8:	20 65 72 	andb	%ah, 114(%rbp)
100000eab:	72 6f 	jb	111 <__cstring+0x8c>
100000ead:	72 00 	jb	0 <__cstring+0x1f>
100000eaf:	57 	pushq	%rdi
100000eb0:	72 69 	jb	105 <__cstring+0x8b>
100000eb2:	74 65 	je	101 <__cstring+0x89>
100000eb4:	20 65 72 	andb	%ah, 114(%rbp)
100000eb7:	72 6f 	jb	111 <__cstring+0x98>
100000eb9:	72 00 	jb	0 <__cstring+0x2b>
100000ebb:	46 61  <unknown>
100000ebd:	69 6c 75 72 65 20 74 6f 	imull	$1869881445, 114(%rbp,%rsi,2), %ebp
100000ec5:	20 6f 62 	andb	%ch, 98(%rdi)
100000ec8:	74 61 	je	97 <__cstring+0x9b>
100000eca:	69 6e 20 74 68 65 20 	imull	$543516788, 32(%rsi), %ebp
100000ed1:	63 75 72 	movslq	114(%rbp), %esi
100000ed4:	72 65 	jb	101 <__cstring+0xab>
100000ed6:	6e 	outsb	(%rsi), %dx
100000ed7:	74 20 	je	32 <__cstring+0x69>
100000ed9:	74 69 	je	105 <__cstring+0xb4>
100000edb:	6d 	insl	%dx, %es:(%rdi)
100000edc:	65 2e 0a 00 	orb	%cs:(%rax), %al
100000ee0:	46 61  <unknown>
100000ee2:	69 6c 75 72 65 20 74 6f 	imull	$1869881445, 114(%rbp,%rsi,2), %ebp
100000eea:	20 63 6f 	andb	%ah, 111(%rbx)
100000eed:	6e 	outsb	(%rsi), %dx
100000eee:	76 65 	jbe	101 <__cstring+0xc5>
100000ef0:	72 74 	jb	116 <__cstring+0xd6>
100000ef2:	20 74 68 65 	andb	%dh, 101(%rax,%rbp,2)
100000ef6:	20 63 75 	andb	%ah, 117(%rbx)
100000ef9:	72 72 	jb	114 <__cstring+0xdd>
100000efb:	65 6e 	outsb	%gs:(%rsi), %dx
100000efd:	74 20 	je	32 <__cstring+0x8f>
100000eff:	74 69 	je	105 <__cstring+0xda>
100000f01:	6d 	insl	%dx, %es:(%rdi)
100000f02:	65 2e 0a 00 	orb	%cs:(%rax), %al
100000f06:	52 	pushq	%rdx
100000f07:	65 63 6f 72 	movslq	%gs:114(%rdi), %ebp
100000f0b:	64 65 64 20 61 6e 	andb	%ah, %fs:110(%rcx)
100000f11:	20 65 78 	andb	%ah, 120(%rbp)
100000f14:	70 6c 	jo	108 <__cstring+0xf2>
100000f16:	6f 	outsl	(%rsi), %dx
100000f17:	73 69 	jae	105 <__cstring+0xf2>
100000f19:	6f 	outsl	(%rsi), %dx
100000f1a:	6e 	outsb	(%rsi), %dx
100000f1b:	20 61 74 	andb	%ah, 116(%rcx)
100000f1e:	20 25 73 00 42 6f 	andb	%ah, 1866596467(%rip)
100000f24:	6d 	insl	%dx, %es:(%rdi)
100000f25:	62 20 45 58  <unknown>
100000f29:	50 	pushq	%rax
100000f2a:	4c 4f  <unknown>
100000f2c:	44 45  <unknown>
100000f2e:	44 21 20 	andl	%r12d, (%rax)
100000f31:	2e 2e 2e 20 50 6c 	andb	%dl, %cs:108(%rax)
100000f37:	65 61  <unknown>
100000f39:	73 65 	jae	101 <__cstring+0x110>
100000f3b:	20 74 72 79 	andb	%dh, 121(%rdx,%rsi,2)
100000f3f:	20 61 67 	andb	%ah, 103(%rcx)
100000f42:	61  <unknown>
100000f43:	69 6e 2e 0a 00 69 6e 	imull	$1852375050, 46(%rsi), %ebp
100000f4a:	70 75 	jo	117 <dyld_stub_binder+0x100000fc1>
100000f4c:	74 2e 	je	46 <__cstring+0xec>
100000f4e:	74 78 	je	120 <dyld_stub_binder+0x100000fc8>
100000f50:	74 00 	je	0 <__cstring+0xc2>
100000f52:	72 00 	jb	0 <__cstring+0xc4>
100000f54:	43 6f 	outsl	(%rsi), %dx
100000f56:	75 6c 	jne	108 <dyld_stub_binder+0x100000fc4>
100000f58:	64 20 6e 6f 	andb	%ch, %fs:111(%rsi)
100000f5c:	74 20 	je	32 <__cstring+0xee>
100000f5e:	6f 	outsl	(%rsi), %dx
100000f5f:	70 65 	jo	101 <dyld_stub_binder+0x100000fc6>
100000f61:	6e 	outsb	(%rsi), %dx
100000f62:	20 70 61 	andb	%dh, 97(%rax)
100000f65:	74 68 	je	104 <dyld_stub_binder+0x100000fcf>
100000f67:	3a 20 	cmpb	(%rax), %ah
100000f69:	25 73 21 00 50 	andl	$1342185843, %eax
100000f6e:	68 61 73 65 20 	pushq	$543519585
100000f73:	31 20 	xorl	%esp, (%rax)
100000f75:	52 	pushq	%rdx
100000f76:	65 73 70 	jae	112 <dyld_stub_binder+0x100000fe9>
100000f79:	6f 	outsl	(%rsi), %dx
100000f7a:	6e 	outsb	(%rsi), %dx
100000f7b:	73 65 	jae	101 <dyld_stub_binder+0x100000fe2>
100000f7d:	3a 20 	cmpb	(%rax), %ah
100000f7f:	00 25 69 0a 00 50 	addb	%ah, 1342179945(%rip)
100000f85:	68 61 73 65 20 	pushq	$543519585
100000f8a:	31 20 	xorl	%esp, (%rax)
100000f8c:	53 	pushq	%rbx
100000f8d:	4f 4c  <unknown>
100000f8f:	56 	pushq	%rsi
100000f90:	45 44  <unknown>
100000f92:	21 0a 	andl	%ecx, (%rdx)
100000f94:	00 50 68 	addb	%dl, 104(%rax)
100000f97:	61  <unknown>
100000f98:	73 65 	jae	101 <dyld_stub_binder+0x100000fff>
100000f9a:	20 31 	andb	%dh, (%rcx)
100000f9c:	20 72 65 	andb	%dh, 101(%rdx)
100000f9f:	73 75 	jae	117 <dyld_stub_binder+0x100001016>
100000fa1:	6c 	insb	%dx, %es:(%rdi)
100000fa2:	74 3a 	je	58 <dyld_stub_binder+0x100000fde>
100000fa4:	20 25  <unknown>
100000fa6:	69 0a  <unknown>
100000fa8:	00  <unknown>
Disassembly of section __TEXT,__unwind_info:
__unwind_info:
100000fac:	01 00 	addl	%eax, (%rax)
100000fae:	00 00 	addb	%al, (%rax)
100000fb0:	1c 00 	sbbb	$0, %al
100000fb2:	00 00 	addb	%al, (%rax)
100000fb4:	00 00 	addb	%al, (%rax)
100000fb6:	00 00 	addb	%al, (%rax)
100000fb8:	1c 00 	sbbb	$0, %al
100000fba:	00 00 	addb	%al, (%rax)
100000fbc:	00 00 	addb	%al, (%rax)
100000fbe:	00 00 	addb	%al, (%rax)
100000fc0:	1c 00 	sbbb	$0, %al
100000fc2:	00 00 	addb	%al, (%rax)
100000fc4:	02 00 	addb	(%rax), %al
100000fc6:	00 00 	addb	%al, (%rax)
100000fc8:	b0 06 	movb	$6, %al
100000fca:	00 00 	addb	%al, (%rax)
100000fcc:	34 00 	xorb	$0, %al
100000fce:	00 00 	addb	%al, (%rax)
100000fd0:	34 00 	xorb	$0, %al
100000fd2:	00 00 	addb	%al, (%rax)
100000fd4:	67 0b 00 	orl	(%eax), %eax
100000fd7:	00 00 	addb	%al, (%rax)
100000fd9:	00 00 	addb	%al, (%rax)
100000fdb:	00 34 00 	addb	%dh, (%rax,%rax)
100000fde:	00 00 	addb	%al, (%rax)
100000fe0:	03 00 	addl	(%rax), %eax
100000fe2:	00 00 	addb	%al, (%rax)
100000fe4:	0c 00 	orb	$0, %al
100000fe6:	01 00 	addl	%eax, (%rax)
100000fe8:	10 00 	adcb	%al, (%rax)
100000fea:	01 00 	addl	%eax, (%rax)
100000fec:	00 00 	addb	%al, (%rax)
100000fee:	00 00 	addb	%al, (%rax)
100000ff0:	00 00 	addb	%al, (%rax)
100000ff2:	00 01 	addb	%al, (%rcx)
Disassembly of section __DATA,__nl_symbol_ptr:
__nl_symbol_ptr:
100001000:	00 00 	addb	%al, (%rax)
100001002:	00 00 	addb	%al, (%rax)
100001004:	00 00 	addb	%al, (%rax)
100001006:	00 00 	addb	%al, (%rax)
Disassembly of section __DATA,__got:
__got:
100001008:	00 00 	addb	%al, (%rax)
10000100a:	00 00 	addb	%al, (%rax)
10000100c:	00 00 	addb	%al, (%rax)
10000100e:	00 00 	addb	%al, (%rax)
100001010:	00 00 	addb	%al, (%rax)
100001012:	00 00 	addb	%al, (%rax)
100001014:	00 00 	addb	%al, (%rax)
100001016:	00 00 	addb	%al, (%rax)
Disassembly of section __DATA,__la_symbol_ptr:
__la_symbol_ptr:
100001018:	dc 0b 	fmull	(%rbx)
10000101a:	00 00 	addb	%al, (%rax)
10000101c:	01 00 	addl	%eax, (%rax)
10000101e:	00 00 	addb	%al, (%rax)
100001020:	e6 0b 	outb	%al, $11
100001022:	00 00 	addb	%al, (%rax)
100001024:	01 00 	addl	%eax, (%rax)
100001026:	00 00 	addb	%al, (%rax)
100001028:	f0 	lock
100001029:	0b 00 	orl	(%rax), %eax
10000102b:	00 01 	addb	%al, (%rcx)
10000102d:	00 00 	addb	%al, (%rax)
10000102f:	00 fa 	addb	%bh, %dl
100001031:	0b 00 	orl	(%rax), %eax
100001033:	00 01 	addb	%al, (%rcx)
100001035:	00 00 	addb	%al, (%rax)
100001037:	00 04 0c 	addb	%al, (%rsp,%rcx)
10000103a:	00 00 	addb	%al, (%rax)
10000103c:	01 00 	addl	%eax, (%rax)
10000103e:	00 00 	addb	%al, (%rax)
100001040:	0e  <unknown>
100001041:	0c 00 	orb	$0, %al
100001043:	00 01 	addb	%al, (%rcx)
100001045:	00 00 	addb	%al, (%rax)
100001047:	00 18 	addb	%bl, (%rax)
100001049:	0c 00 	orb	$0, %al
10000104b:	00 01 	addb	%al, (%rcx)
10000104d:	00 00 	addb	%al, (%rax)
10000104f:	00 22 	addb	%ah, (%rdx)
100001051:	0c 00 	orb	$0, %al
100001053:	00 01 	addb	%al, (%rcx)
100001055:	00 00 	addb	%al, (%rax)
100001057:	00 2c 0c 	addb	%ch, (%rsp,%rcx)
10000105a:	00 00 	addb	%al, (%rax)
10000105c:	01 00 	addl	%eax, (%rax)
10000105e:	00 00 	addb	%al, (%rax)
100001060:	36 0c 00 	orb	$0, %al
100001063:	00 01 	addb	%al, (%rcx)
100001065:	00 00 	addb	%al, (%rax)
100001067:	00 40 0c 	addb	%al, 12(%rax)
10000106a:	00 00 	addb	%al, (%rax)
10000106c:	01 00 	addl	%eax, (%rax)
10000106e:	00 00 	addb	%al, (%rax)
100001070:	4a 0c 00 	orb	$0, %al
100001073:	00 01 	addb	%al, (%rcx)
100001075:	00 00 	addb	%al, (%rax)
100001077:	00 54 0c 00 	addb	%dl, (%rsp,%rcx)
10000107b:	00 01 	addb	%al, (%rcx)
10000107d:	00 00 	addb	%al, (%rax)
10000107f:	00 5e 0c 	addb	%bl, 12(%rsi)
100001082:	00 00 	addb	%al, (%rax)
100001084:	01 00 	addl	%eax, (%rax)
100001086:	00 00 	addb	%al, (%rax)
100001088:	68 0c 00 00 01 	pushq	$16777228
10000108d:	00 00 	addb	%al, (%rax)
10000108f:	00 72 0c 	addb	%dh, 12(%rdx)
100001092:	00 00 	addb	%al, (%rax)
100001094:	01 00 	addl	%eax, (%rax)
100001096:	00 00 	addb	%al, (%rax)
100001098:	7c 0c 	jl	12 <_line+0x6>
10000109a:	00 00 	addb	%al, (%rax)
10000109c:	01 00 	addl	%eax, (%rax)
10000109e:	00 00 	addb	%al, (%rax)
Disassembly of section __DATA,__common:
_line:
...

_len:
...

_c_time_string:
...

_current_time:
...

_outMsg:
...
