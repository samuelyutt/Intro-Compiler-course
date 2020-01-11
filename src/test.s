    .file "expression.p"
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
    li t0, 0
    sw t0, -20(s0)
    li t0, 2
    sw t0, -24(s0)
    li t0, 2
    la t1, gv
    sw t0, 0(t1)
    li t0, 2
    sw t0, -20(s0)
    lw t0, -24(s0)
    la t1, gv
    lw t1, 0(t1)
    addw t0, t0, t1
    la t1, gc
    lw t1, 0(t1)
    addw t0, t0, t1
    lw t1, -20(s0)
    addw t0, t0, t1
    la t1, gv
    sw t0, 0(t1)
    lw t0, -24(s0)
    la t1, gv
    lw t1, 0(t1)
    mulw t0, t0, t1
    la t1, gc
    lw t1, 0(t1)
    mulw t0, t0, t1
    lw t1, -20(s0)
    mulw t0, t0, t1
    sw t0, -20(s0)
    la t0, gv
    lw a0, 0(t0)
    jal ra, print
    lw a0, -20(s0)
    jal ra, print
    lw t0, -24(s0)
    la t1, gv
    lw t1, 0(t1)
    la t2, gc
    lw t2, 0(t2)
    addw t1, t1, t2
    lw t2, -20(s0)
    mulw t1, t1, t2
    addw t0, t0, t1
    la t1, gv
    sw t0, 0(t1)
    lw t0, -24(s0)
    la t1, gv
    lw t1, 0(t1)
    la t2, gc
    lw t2, 0(t2)
    lw t3, -20(s0)
    lw t4, -24(s0)
    la t5, gv
    lw t5, 0(t5)
    la t6, gc
    lw t6, 0(t6)
    sw t0, -28(s0)
    lw t0, -20(s0)
    sw t1, -32(s0)
    lw t1, -24(s0)
    sw t2, -36(s0)
    addw t0, t0, t1
    lw t2, -36(s0)
    addw t6, t6, t0
    lw t1, -32(s0)
    addw t5, t5, t6
    lw t0, -28(s0)
    addw t4, t4, t5
    addw t3, t3, t4
    addw t2, t2, t3
    addw t1, t1, t2
    addw t0, t0, t1
    sw t0, -20(s0)
    la t0, gv
    lw a0, 0(t0)
    jal ra, print
    lw a0, -20(s0)
    jal ra, print
    ld ra, 56(sp)
    ld s0, 48(sp)
    addi sp, sp, 64
    jr ra
    .size main, .-main
