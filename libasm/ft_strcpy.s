global ft_strcpy

section .text
ft_strcpy:
	xor rax, rax

loop:
	mov cl, byte [rsi + rax]
	cmp cl, 0
	je end
	mov byte [rdi + rax], cl
	inc rax
	jmp loop

end:
	mov byte [rdi + rax], 0
	mov rax, rdi
	ret
