; /usr/local/bin/nasm -f macho64 64.asm && ld -macosx_version_min 10.7.0 -lSystem -o 64 64.o && ./64

global _start

section .data

msg:    db      "Hello, world!", 10
.len:   equ     $ - msg

section .text

_start:
    mov     rax, 4 ; write
    mov     rdi, 1 ; stdout
    mov     rsi, msg
    mov     rdx, msg.len
    syscall

    mov     rax, 1 ; exit
    mov     rdi, 0
    syscall