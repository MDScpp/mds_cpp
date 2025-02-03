	.text
	.def	@feat.00;
	.scl	3;
	.type	0;
	.endef
	.globl	@feat.00
.set @feat.00, 0
	.intel_syntax noprefix
	.file	"internal.cpp"
	.def	"?foo2@@YAHXZ";
	.scl	2;
	.type	32;
	.endef
	.globl	"?foo2@@YAHXZ"                  # -- Begin function ?foo2@@YAHXZ
	.p2align	4, 0x90
"?foo2@@YAHXZ":                         # @"?foo2@@YAHXZ"
.seh_proc "?foo2@@YAHXZ"
# %bb.0:
	sub	rsp, 40
	.seh_stackalloc 40
	.seh_endprologue
	call	"?func@@YAHXZ"
	mov	dword ptr [rsp + 36], eax       # 4-byte Spill
	call	"?foo@?A0x6479AED9@@YAHXZ"
	mov	ecx, eax
	mov	eax, dword ptr [rsp + 36]       # 4-byte Reload
	add	eax, ecx
	add	rsp, 40
	ret
	.seh_endproc
                                        # -- End function
	.def	"?func@@YAHXZ";
	.scl	3;
	.type	32;
	.endef
	.p2align	4, 0x90                         # -- Begin function ?func@@YAHXZ
"?func@@YAHXZ":                         # @"?func@@YAHXZ"
# %bb.0:
	mov	eax, 3
	ret
                                        # -- End function
	.def	"?foo@?A0x6479AED9@@YAHXZ";
	.scl	3;
	.type	32;
	.endef
	.p2align	4, 0x90                         # -- Begin function ?foo@?A0x6479AED9@@YAHXZ
"?foo@?A0x6479AED9@@YAHXZ":             # @"?foo@?A0x6479AED9@@YAHXZ"
# %bb.0:
	mov	eax, 42
	ret
                                        # -- End function
	.addrsig
	.addrsig_sym "?func@@YAHXZ"
	.addrsig_sym "?foo@?A0x6479AED9@@YAHXZ"
