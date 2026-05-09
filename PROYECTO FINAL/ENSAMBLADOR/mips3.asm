##################
# Seccion de datos
    .data

$str1:
    .asciiz "Son iguales\n"
$str2:
    .asciiz "Diferencia pequeña: \n"
$str3:
    .asciiz "\n"
$str4:
    .asciiz "Diferencia grande: \n"
$str5:
    .asciiz "Mayor reducido: \n"
_MAX:
    .word 0
_a:
    .word 0
_b:
    .word 0
_mayor:
    .word 0
_menor:
    .word 0
_dif:
    .word 0

##################
# Seccion de codigo
    .text
    .global main
main:
    li $t0,5
    sw $t0,_MAX
    li $v0,5
    syscall
    sw $v0,_a
    li $v0,5
    syscall
    sw $v0,_b
    lw $t0,_a
    lw $t1,_b
    sge $t0,$t0,$t1
    beqz $t0,$l1
    lw $t1,_a
    sw $t1,_mayor
    lw $t1,_b
    sw $t1,_menor
    b $l2
$l1:
    lw $t1,_b
    sw $t1,_mayor
    lw $t1,_a
    sw $t1,_menor
$l2:
    lw $t0,_mayor
    lw $t1,_menor
    sub $t0,$t0,$t1
    sw $t0,_dif
    lw $t0,_dif
    li $t1,0
    seq $t0,$t0,$t1
    beqz $t0,$l5
    li $v0,4
    la $a0,$str1
    syscall
    b $l6
$l5:
    lw $t1,_dif
    lw $t2,_MAX
    sle $t1,$t1,$t2
    beqz $t1,$l3
    li $v0,4
    la $a0,$str2
    syscall
    lw $t2,_dif
    li $v0,1
    move $a0,$t2
    syscall
    li $v0,4
    la $a0,$str3
    syscall
    b $l4
$l3:
    li $v0,4
    la $a0,$str4
    syscall
    lw $t2,_dif
    li $v0,1
    move $a0,$t2
    syscall
    li $v0,4
    la $a0,$str3
    syscall
$l4:
$l6:
$l7:
    lw $t0,_mayor
    li $t1,1
    sub $t0,$t0,$t1
    sw $t0,_mayor
    lw $t0,_mayor
    lw $t1,_menor
    sgt $t0,$t0,$t1
    bnez $t0,$l7
    li $v0,4
    la $a0,$str5
    syscall
    lw $t0,_mayor
    li $v0,1
    move $a0,$t0
    syscall
    li $v0,4
    la $a0,$str3
    syscall
    li $v0, 10
    syscall