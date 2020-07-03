BITS 64

SECTION .text

GLOBAL strcmp

strcmp:
    xor rcx, rcx
    jmp loop

bad_end:
    xor eax, eax
    jmp end

more_one:
    inc rcx

loop:
    mov dl, BYTE [rdi + rcx]
    mov bl, BYTE [rsi + rcx]
    cmp dl, 0
    je end
    cmp bl, dl
    je more_one
    movsx eax, bl
    movsx ebx, dl
    sub eax, ebx

end:
    ret