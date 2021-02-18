    section .text
    global plusun
plusun:
    add rdi, 1
    mov rax, rdi
    ret
