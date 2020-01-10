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
    .global main
    .type main, @function
main:
    addi sp, sp, -64
    sd ra, 56(sp)
    sd s0, 48(sp)
    addi s0, sp, 64
    lw t0, -20(s0)
    lw t1, -24(s0)
    addw t0, t0, t1
    la t2, d
    lw t1, 0(t2)
    mulw t0, t0, t1
    sw t0, -20(s0)
    ld ra, 56(sp)
    ld s0, 48(sp)
    addi sp, sp, 64
    jr ra
    .size main, .-main
