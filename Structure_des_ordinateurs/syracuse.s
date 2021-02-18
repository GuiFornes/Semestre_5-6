    section .text
    global syracuse
syracuse:

    mov r8, 3
    mov rax, rdi        ; valeur de la suite
    mov rcx, 0          ; temps de vol
while:
    mov rbx, rax
    and rbx, 1
    je paire
impaire:
    mul r8
    add rax, 1
    jmp fin
paire:
    shr rax, 1
fin:
    add rcx, 1
    cmp rax, 1
    jnz while
    mov rax, rcx
    ret
