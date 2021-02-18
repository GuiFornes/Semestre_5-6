    section .text
    global multiplie
multiplie:
    mov r8, 3
    mov r9, 5
    mov r10, 4
    mov r11, 1
    mov r13, 8
    mov r14, 7
    mov r15, 6
    mov rcx, 0
    mov r12, 0
while:
    rdtsc
    mov r11, rax
    imul r8, r9
    add r14, 1
    imul r10, r11
    add r15, 2
    imul r13, r14
    add r9, 1
    imul r15, rcx
    add r8, 2
    rdtsc
    sub rax, r11
    add r12, rax
    add rcx, 4
    cmp rcx, rdi
    jl while
    mov rax, r12
    ret
