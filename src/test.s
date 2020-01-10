    .file "variableConstant.p"
    .option nopic
.bss
gv:
    .word 0
.text
gc:
    .word 2
.text
    .align 2
    .global main
    .type main, @function
main:
    addi sp, sp, -64
    sd ra, 56(sp)
    sd s0, 48(sp)
    addi s0, sp, 64
    li t0, 1
    la t1, gv
    sw t0, 0(t1)
    li t0, 3
    sw t0, -20(s0)
    la t1, gv
    lw a0, 0(t1)
    jal ra, print
    la t1, gc
    lw a0, 0(t1)
    jal ra, print
    lw a0, -20(s0)
    jal ra, print
    lw a0, -24(s0)
    jal ra, print
    ld ra, 56(sp)
    ld s0, 48(sp)
    addi sp, sp, 64
    jr ra
    .size main, .-main
