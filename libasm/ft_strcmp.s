global ft_strcmp

section .text
ft_strcmp:
	xor rdx, rdx

loop:
	mov al, byte [rdi + rdx]
	mov cl, byte [rsi + rdx]
	cmp al, cl
	jne diff
	cmp al, 0
	je end
	inc rdx
	jmp loop

diff:
	movzx eax, al
	movzx ecx, cl
	sub eax, ecx
	ret

end:
	xor eax, eax
	ret
