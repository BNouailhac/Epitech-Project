BITS 64

SECTION .text

GLOBAL strcasecmp

strcasecmp:
    xor rcx, rcx
    xor eax, eax
    jmp loop

more_one:
    inc rcx

loop:
    mov dl, BYTE [rdi+rcx]
    mov bl, BYTE [rsi+rcx]
    cmp dl, 0
    je end
    cmp dl, 'A'
    jnge to_lowerdl
    cmp dl, 'Z'
    jnge to_lowerdl
    cmp bl, 'A'
    jnge to_lowerbl
    cmp bl, 'Z'
    jnge to_lowerbl
    cmp bl, dl
    je more_one
    movsx eax, bl
    movsx rbx, dl
    sub eax, ebx

to_lowerbl:
	add bl, 32

to_lowerdl:
	add dl, 32

end:
    ret