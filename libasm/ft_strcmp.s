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

less:
				mov		rax, -1
				ret

equal:
				mov		rax, 0
				ret

greater:
				mov		rax, 1
				ret

return:
				sub		rax, r8
				jl		less
				je		equal
				jg		greater
