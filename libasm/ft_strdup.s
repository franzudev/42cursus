					global _ft_strdup
					extern	_malloc
					extern	_ft_strlen
					extern	_ft_strcpy

	section .text
_ft_strdup:
					xor		rax, rax
					call	_ft_strlen
					inc		rax
					mov		rsi, rdi
					mov		rdi, rax
					push	rsi
					call	_malloc
					pop		rsi
					mov		rdi, rax
					call	_ft_strcpy
					ret

