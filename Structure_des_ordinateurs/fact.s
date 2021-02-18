    section .text
    global fact
fact:
    mov rax, 1
thelabel:
    mul rdi
    sub rdi, 1
    cmp rdi, 1
    jg thelabel
    ret
