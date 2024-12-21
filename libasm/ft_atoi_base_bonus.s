				global	_ft_atoi_base
				extern	_ft_strlen
				extern	_ft_strcmp
				extern	_ft_strchr
				extern 	_ft_strcpy

section		.data
	str: 	db "",10 ;

section	.text
_ft_atoi_base:
				xor		rax, rax
				mov		r9, str

check_base:
				push	rdi
				mov		rdi, rsi
				push	rsi
				call	_ft_strlen
				cmp		rax, 2
				jl		base_error
				pop 	rsi
				pop		rdi
				jmp		valid_chars

valid_chars:
				mov		r8, rsi
				cmp		BYTE [r8], 32
				je		base_error
				cmp		BYTE [r8], 9
				je		base_error
				cmp		BYTE [r8], 10
				je		base_error
				cmp		BYTE [r8], 11
				je		base_error
				cmp		BYTE [r8], 12
				je		base_error
				cmp		BYTE [r8], 13
				je		base_error
				cmp		BYTE [r8], 43
				je		base_error
				cmp		BYTE [r8], 45
				je		base_error
				cmp		BYTE [r8], 0
				je		next
				inc 	rsi
				push	rdi
				mov		rdi, rsi
				push	rsi
				mov		rsi, [r8]
				call	_ft_strchr
				pop		rsi
				pop		rdi
				cmp		rax, 1
				je		base_error
				jmp		valid_chars

next:
				mov		rax, 1
				ret

base_error:
				mov		rax, 0
				ret

