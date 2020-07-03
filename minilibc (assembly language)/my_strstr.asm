BITS 64

SECTION .text

GLOBAL strstr

strstr:
    xor rax, rax
    xor rcx, rcx
    jmp loop

more_one:
    inc rcx

loop:
	xor rbx, rbx
    mov r8, rcx
    jmp find_str	

more_one_findstr:
	inc r8
	inc rbx	

find_str:
    mov dl, BYTE [rsi+rbx]
    cmp dl, 0
    je end_dl
    mov bl, BYTE [rdi+rcx]
    cmp bl, 0
    je end
    cmp dl, bl
    je more_one_findstr
    jmp more_one

end_dl:
	mov rax, rdi
	add rax, rbx	

end:
	ret	