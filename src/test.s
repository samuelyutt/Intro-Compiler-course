    .file "loop.p"
    .option nopic
.bss
gv:
    .word 0
.text
gc:
    .word 2
.text
    .align 2
    .global sum
    .type sum, @function
sum:
    addi sp, sp, -64
    sd ra, 56(sp)
    sd s0, 48(sp)
    addi s0, sp, 64
    sw a0, -20(s0)
    sw a1, -24(s0)
    sw a2, -28(s0)
    sw a3, -32(s0)
    sw a4, -36(s0)
    sw a5, -40(s0)
    sw a6, -44(s0)
    sw a7, -48(s0)
    lw a0, -56(s0)
    jal ra, print
    lw a0, -52(s0)
    jal ra, print
    lw a0, -48(s0)
    jal ra, print
    lw a0, -44(s0)
    jal ra, print
    lw a0, -40(s0)
    jal ra, print
    lw a0, -36(s0)
    jal ra, print
    lw a0, -32(s0)
    jal ra, print
    lw a0, -28(s0)
    jal ra, print
    lw a0, -24(s0)
    jal ra, print
    lw a0, -20(s0)
    jal ra, print
    lw t0, -52(s0)
    mv a0, t0
    ld ra, 56(sp)
    ld s0, 48(sp)
    addi sp, sp, 64
    jr ra
    .size sum, .-sum
.text
    .align 2
    .global main
    .type main, @function
main:
    addi sp, sp, -64
    sd ra, 56(sp)
    sd s0, 48(sp)
    addi s0, sp, 64
    li t0, 10
    li t1, 9
    li t2, 8
    li t3, 7
    li t4, 6
    li t5, 5
    li t6, 4
    sw t0, -20(s0)
    li t0, 3
    sw t1, -24(s0)
    li t1, 2
    sw t2, -28(s0)
    li t2, 1
    sw t3, -32(s0)
    mv a0, t2
    lw t3, -32(s0)
    mv a1, t1
    lw t2, -28(s0)
    mv a2, t0
    lw t1, -24(s0)
    mv a3, t6
    lw t0, -20(s0)
    mv a4, t5
    mv a5, t4
    mv a6, t3
    mv a7, t2
    sw t1, -116(s0)
    sw t0, -120(s0)
    jal ra, sum
    mv t0, a0
    la t1, gc
    lw t1, 0(t1)
    addw t0, t0, t1
    la t1, gv
    sw t0, 0(t1)
    la t0, gv
    lw a0, 0(t0)
    jal ra, print
    ld ra, 56(sp)
    ld s0, 48(sp)
    addi sp, sp, 64
    jr ra
    .size main, .-main
