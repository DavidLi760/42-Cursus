global ft_strdup
extern ft_strlen
extern ft_strcpy
extern malloc

section .text
ft_strdup:
    push rdi
    call ft_strlen
    mov rdi, rax
    inc rdi
    call malloc wrt ..plt

    test rax, rax
    je .error

    mov rdi, rax
    pop rsi
    call ft_strcpy
    
    mov rax, rdi
    ret

.error:
    pop rdi
    xor rax, rax
    ret
