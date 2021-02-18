    section .text
    global calcule
calcule:
    push rsi
    push rdi
    pop r8
    pop r9
    add r8, r9
    push r8
    push rdi
    pop r8
    pop r9
    mul r8, r9
    push r8
    pop r8
    mv rax, r8
    ret
