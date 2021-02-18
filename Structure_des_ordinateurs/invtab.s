    section .text
    global invtab
invtab:

inv:
    mov r8, rdi
    lea r9, [rdi + rsi*8]

while:
    mov r10, [r8]
    mov r11, [r9]
    mov [r8], r11
    mov [r9], r10

    add r8,8
    sub r9,8

    cmp r8, r9

    jl while

    ret
