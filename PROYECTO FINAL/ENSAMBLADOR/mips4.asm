##################
# Seccion de datos
    .data

$str1:
    .asciiz "Numero no valido \n"
$str2:
    .asciiz "Numero demasiado grande \n"
$str3:
    .asciiz "Factorial: \n"
$str4:
    .asciiz "\n"
$str5:
    .asciiz "Suma especial: \n"
_TOPE:
    .word 0
_n:
    .word 0
_i:
    .word 0
_fact:
    .word 0
_res:
    .word 0

##################
# Seccion de codigo
    .text
    .global main
main:
    li $t0,100
    sw $t0,_TOPE
    li $v0,5
    syscall
    sw $v0,_n
    lw $t0,_n
    li $t1,0
    sle $t0,$t0,$t1
    beqz $t0,$l8
    li $v0,4
    la $a0,$str1
    syscall
    b $l9
$l8:
    lw $t1,_n
    lw $t2,_TOPE
    sgt $t1,$t1,$t2
    beqz $t1,$l6
    li $v0,4
    la $a0,$str2
    syscall
    b $l7
$l6:
    li $t2,1
    sw $t2,_fact
    li $t2,1
    sw $t2,_i
$l1:
    lw $t2,_i
    lw $t3,_n
    sle $t2,$t2,$t3
    beqz $t2,$l2
    lw $t3,_fact
    lw $t4,_i
    mul $t3,$t3,$t4
    sw $t3,_fact
    lw $t3,_i
    li $t4,1
    add $t3,$t3,$t4
    sw $t3,_i
    b $l1
$l2:
    li $t2,0
    sw $t2,_res
    li $t2,1
    sw $t2,_i
$l5:
    lw $t2,_i
    lw $t3,_n
    sne $t2,$t2,$t3
    beqz $t2,$l3
    lw $t3,_res
    lw $t4,_i
    add $t3,$t3,$t4
    sw $t3,_res
    b $l4
$l3:
    lw $t3,_res
    lw $t4,_fact
    add $t3,$t3,$t4
    sw $t3,_res
$l4:
    lw $t2,_i
    li $t3,1
    add $t2,$t2,$t3
    sw $t2,_i
    lw $t2,_i
    lw $t3,_n
    sle $t2,$t2,$t3
    bnez $t2,$l5
    li $v0,4
    la $a0,$str3
    syscall
    lw $t2,_fact
    li $v0,1
    move $a0,$t2
    syscall
    li $v0,4
    la $a0,$str4
    syscall
    li $v0,4
    la $a0,$str5
    syscall
    lw $t2,_res
    li $v0,1
    move $a0,$t2
    syscall
    li $v0,4
    la $a0,$str4
    syscall
$l7:
$l9:
    li $v0, 10
    syscall