BITS 64

SECTION .text

GLOBAL memset

memset:
    xor rcx, rcx
    jmp loop

more_one:
    inc rdi
    inc rcx

loop:
    mov BYTE [rdi], sil
    cmp rdx, rcx
    jle loop2
    jmp more_one

less_one:
    dec rdi
    dec rcx

loop2:
    cmp rcx, 0
    jle end
    jmp less_one

end:
	mov rax, rdi
	ret	