			section .text
				global _ft_read
				extern ___error

_ft_read:									; rdi = file descriptor, rsi = string, rdx = byte count
				mov			rax, 0x2000003		; BSD / MacOS calling convention unlike Linux
				syscall
				jc			error
				ret
error:
			push		r15
			mov			r15, rax
			call		___error
			mov			[rax], r15
			pop			r15
			mov			rax, -1
			ret