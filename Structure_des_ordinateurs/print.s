    section .text
    global print
    extern printf
print:
    mov rsi, rdi
    mov rdi, Fmt
    push rbp
    call printf
    pop rbp
    ret

    section .data
    Fmt db "valeur=%d", 10, 0
