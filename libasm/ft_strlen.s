			global _ft_strlen

			section .text
_ft_strlen:
			mov		rax, -1

start:
			inc 	rax
			cmp		BYTE [rax + rdi], 0
			jne		start
			ret
