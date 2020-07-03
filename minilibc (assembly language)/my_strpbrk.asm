BITS 64

SECTION .text

GLOBAL strpbrk

strpbrk:
    xor rax, rax
    xor rcx, rcx
    jmp loop

more_one:
    inc rcx

loop:
	xor rbx, rbx
    movzx r11d, BYTE [rdi+rcx]
    cmp r11d, 0
    je end
    jmp find_str

more_one_findstr:
	inc rbx

find_str:
    movzx r10d, BYTE [rsi + rbx]
    cmp r10d, 0
    je end_r10d
    cmp r10d, r11d
    je more_one_findstr
    jmp more_one

end_r10d:
	mov rax, rdi
	add rax, rbx	

end:
	ret	