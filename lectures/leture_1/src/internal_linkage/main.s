	.text
	.def	@feat.00;
	.scl	3;
	.type	0;
	.endef
	.globl	@feat.00
.set @feat.00, 0
	.intel_syntax noprefix
	.file	"main.cpp"
	.def	"?func@@YAHXZ";
	.scl	2;
	.type	32;
	.endef
	.globl	"?func@@YAHXZ"                  # -- Begin function ?func@@YAHXZ
	.p2align	4, 0x90
"?func@@YAHXZ":                         # @"?func@@YAHXZ"
# %bb.0:
	mov	eax, 3
	ret
                                        # -- End function
	.def	"?foo@@YAHXZ";
	.scl	2;
	.type	32;
	.endef
	.globl	"?foo@@YAHXZ"                   # -- Begin function ?foo@@YAHXZ
	.p2align	4, 0x90
"?foo@@YAHXZ":                          # @"?foo@@YAHXZ"
# %bb.0:
	mov	eax, 42
	ret
                                        # -- End function
	.def	main;
	.scl	2;
	.type	32;
	.endef
	.globl	main                            # -- Begin function main
	.p2align	4, 0x90
main:                                   # @main
.seh_proc main
# %bb.0:
	sub	rsp, 40
	.seh_stackalloc 40
	.seh_endprologue
	mov	dword ptr [rsp + 36], 0
	call	"?func@@YAHXZ"
	mov	dword ptr [rsp + 32], eax       # 4-byte Spill
	call	"?foo@@YAHXZ"
	mov	ecx, eax
	mov	eax, dword ptr [rsp + 32]       # 4-byte Reload
	add	eax, ecx
	add	rsp, 40
	ret
	.seh_endproc
                                        # -- End function
	.data
	.globl	"?a@@3HA"                       # @"?a@@3HA"
	.p2align	2, 0x0
"?a@@3HA":
	.long	1                               # 0x1

	.globl	"?b@@3MA"                       # @"?b@@3MA"
	.p2align	2, 0x0
"?b@@3MA":
	.long	0x3f800000                      # float 1

	.addrsig
	.addrsig_sym "?func@@YAHXZ"
	.addrsig_sym "?foo@@YAHXZ"
