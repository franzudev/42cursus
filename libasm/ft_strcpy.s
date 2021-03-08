					global _ft_strcpy

	section .text
_ft_strcpy:
					mov		r15, rdi
					xor		rax, rax

cpy:
					mov		al, [rsi]
					mov		[rdi], al
					cmp		al, 0
					je		return
					inc		rdi
					inc		rsi
					jmp		cpy
return:
					mov		rax, r15
					ret
