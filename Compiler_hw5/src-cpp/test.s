    .file "test.p"
    .option nopic
.bss
a:
    .word 0
.text
d:
    .word 4
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
    lw t0, -20(s0)
    lw t1, -24(s0)
    addw t0, t0, t1
    sw t0, -28(s0)
    lw t0, -28(s0)
    muli t0, t0, -1
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
    la t1, a
    lw t0, 0(t1)
    li t1, 40
    bgt t0, t1, L2
L1:
    la t1, a
    lw t0, 0(t1)
    li t1, 30
    bne t0, t1, L5
L4:
    la t0, a
    lw a0, 0(t0)
    jal ra, print
    j L6
L5:
    la t0, d
    lw a0, 0(t0)
    jal ra, print
L6:
    j L3
L2:
    j L8
L7:
    la t0, d
    lw a0, 0(t0)
    jal ra, print
    la t1, d
    lw t0, 0(t1)
    li t1, 1
    addw t0, t0, t1
    la t1, a
    sw t0, 0(t1)
L8:
    la t1, d
    lw t0, 0(t1)
    li t1, 8
    blt t0, t1, L7
L3:
    ld ra, 56(sp)
    ld s0, 48(sp)
    addi sp, sp, 64
    jr ra
    .size main, .-main
