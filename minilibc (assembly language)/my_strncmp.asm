BITS 64

SECTION .text

GLOBAL strncmp

strncmp:
    xor rcx, rcx
    xor rax, rax
    jmp loop

more_one:
    inc rcx
    inc rdi
    inc rsi

loop:
    cmp rcx, rdx
    je end
    mov r10b, BYTE [rdi]
    mov r11b, BYTE [rsi]
    cmp r10b, 0
    je end
    cmp r11b, r10b
    je more_one
    movsx rax, r11b
    movsx rbx, r10b
    sub rax, rbx

end:
    ret