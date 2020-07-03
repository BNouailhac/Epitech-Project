BITS 64

SECTION .text

GLOBAL strchr

strchr:
    xor rcx, rcx
    jmp loop

more_one:
    inc rcx
    inc rdi

loop:
    mov r11b, BYTE [rdi]
    cmp r11b, sil
    je good_end
    cmp r11b, 0
    je bad_end
    jmp more_one

good_end:
    mov rax, rdi
    add rax, rcx
    jmp end

bad_end:
    xor rax, rax

end:
	ret	