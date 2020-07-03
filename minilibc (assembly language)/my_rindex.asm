BITS 64

SECTION .text

GLOBAL rindex

rindex:
    xor rcx, rcx
    xor rax, rax
    jmp to_end

to_end:
    mov dl, BYTE [rdi+rcx]
    inc rcx
    cmp dl, 0
    jne to_end

more_one:
    dec rcx

loop:
    movsx edx, BYTE [rdi+rcx]
    cmp edx, 0
    jne end
    cmp edx, esi
    jne more_one
    mov rax, rdi
    add rax, rcx
    jmp more_one

end:
	ret	