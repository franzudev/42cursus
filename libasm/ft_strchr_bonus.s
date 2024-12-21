				global _ft_strchr

				section .text
_ft_strchr:
				cmp		BYTE [rdi], sil
				je		success
				cmp		BYTE [rdi], 0
				je		error
				inc		rdi
				jmp		_ft_strchr

error:
				mov		rax, 0
				ret

success:
				mov		rax, 10
				ret