				global _ft_strcmp

				section .text
_ft_strcmp:
				xor		rax, rax
				xor		r8, r8

start:
				mov		al, [rdi]
				mov		r8b, [rsi]
				cmp		al, r8b
				jne		return
				inc		rdi
				inc		rsi
				cmp		al, 0
				je		return
				jmp		start

return:
				sub		rax, r8
				ret
