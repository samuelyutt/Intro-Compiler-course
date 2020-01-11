    .file "function.p"
    .option nopic
.bss
gv:
    .word 0
.text
gc:
    .word 2
.text
    .align 2
    .global product
    .type product, @function
product:
    addi sp, sp, -64
    sd ra, 56(sp)
    sd s0, 48(sp)
    addi s0, sp, 64
    sw a0, -20(s0)
    sw a1, -24(s0)
    li t0, 0
    sw t0, -28(s0)
    lw t0, -20(s0)
    lw t1, -24(s0)
    mulw t0, t0, t1
    sw t0, -28(s0)
    lw t0, -28(s0)
    mv a0, t0
    ld ra, 56(sp)
    ld s0, 48(sp)
    addi sp, sp, 64
    jr ra
    .size product, .-product
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
    li t0, 0
    sw t0, -28(s0)
    lw t0, -20(s0)
    lw t1, -24(s0)
    addw t0, t0, t1
    sw t0, -28(s0)
    lw t0, -28(s0)
    mv a0, t0
    ld ra, 56(sp)
    ld s0, 48(sp)
    addi sp, sp, 64
    jr ra
    .size sum, .-sum
.text
    .align 2
    .global dot
    .type dot, @function
dot:
    addi sp, sp, -64
    sd ra, 56(sp)
    sd s0, 48(sp)
    addi s0, sp, 64
    sw a0, -20(s0)
    sw a1, -24(s0)
    sw a2, -28(s0)
    sw a3, -32(s0)
    li t0, 0
    sw t0, -36(s0)
    lw t0, -32(s0)
    lw t1, -28(s0)
    mv a0, t1
    mv a1, t0
    jal ra, product
    mv t0, a0
    lw t1, -24(s0)
    lw t2, -20(s0)
    mv a0, t2
    mv a1, t1
    sw t0, -40(s0)
    jal ra, product
    lw t0, -40(s0)
    mv t1, a0
    mv a0, t1
    mv a1, t0
    jal ra, sum
    mv t0, a0
    sw t0, -36(s0)
    lw t0, -36(s0)
    mv a0, t0
    ld ra, 56(sp)
    ld s0, 48(sp)
    addi sp, sp, 64
    jr ra
    .size dot, .-dot
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
    la t1, gc
    lw t0, 0(t1)
    la t2, gv
    lw t1, 0(t2)
    mv a0, t1
    mv a1, t0
    jal ra, product
    mv t0, a0
    la t1, gv
    sw t0, 0(t1)
    la t1, gv
    lw t0, 0(t1)
    lw t1, -24(s0)
    lw t2, -20(s0)
    mv a0, t2
    mv a1, t1
    sw t0, -28(s0)
    jal ra, product
    lw t0, -28(s0)
    mv t1, a0
    addw t0, t0, t1
    sw t0, -20(s0)
    la t1, gv
    lw a0, 0(t1)
    jal ra, print
    lw a0, -20(s0)
    jal ra, print
    lw t0, -24(s0)
    lw t1, -20(s0)
    la t3, gc
    lw t2, 0(t3)
    la t4, gv
    lw t3, 0(t4)
    mv a0, t3
    mv a1, t2
    mv a2, t1
    mv a3, t0
    jal ra, dot
    mv t0, a0
    la t1, gv
    sw t0, 0(t1)
    la t1, gv
    lw a0, 0(t1)
    jal ra, print
    ld ra, 56(sp)
    ld s0, 48(sp)
    addi sp, sp, 64
    jr ra
    .size main, .-main
