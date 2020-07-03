BITS 64

SECTION .text

GLOBAL strlen

strlen:
    xor rcx, rcx
    jmp loop

more_one:
    inc rcx

loop:
    mov sil, BYTE [rdi+rcx]
    cmp sil, 0
    jne more_one
    mov rax, rcx
    ret