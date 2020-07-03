BITS 64

SECTION .text

GLOBAL memcpy

memcpy:
    xor rcx, rcx
    jmp loop

more_one:
    inc rdi
    inc rsi
    inc rcx

loop:
    mov r10b, BYTE [rsi]
 	mov [rdi], r10b
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