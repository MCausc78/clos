%define TAB 2
bits 32
section .text
	align 4
	dd 0x1BADB002
	dd 0x00
	dd - (0x1BADB002 + 0x00)

global _start

extern clear
extern main
extern set_default_color

_start:
	cli
	; register ^ register = 0
	xor ax, ax
	xor eax, eax
	xor ecx, ecx
	call clear
	call set_default_color
	call main
	jmp $
	; hlt