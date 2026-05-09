##################
# Seccion de datos
    .data

$str1:
    .asciiz "Suma pares: \n"
$str2:
    .asciiz "\n"
$str3:
    .asciiz "Suma impares: \n"
_LIMITE:
    .word 0
_i:
    .word 0
_par:
    .word 0
_impar:
    .word 0

##################
# Seccion de codigo
    .text
    .global main
main:
    li $t0,5
    sw $t0,_LIMITE
    li $t0,0
    sw $t0,_par
    li $t0,0
    sw $t0,_impar
    li $t0,1
    sw $t0,_i
$l9:
    lw $t0,_i
    lw $t1,_LIMITE
    sle $t0,$t0,$t1
    beqz $t0,$l10
    lw $t1,_i
    li $t2,1
    seq $t1,$t1,$t2
    beqz $t1,$l7
    lw $t2,_impar
    lw $t3,_i
    add $t2,$t2,$t3
    sw $t2,_impar
    b $l8
$l7:
    lw $t2,_i
    li $t3,2
    seq $t2,$t2,$t3
    beqz $t2,$l5
    lw $t3,_par
    lw $t4,_i
    add $t3,$t3,$t4
    sw $t3,_par
    b $l6
$l5:
    lw $t3,_i
    li $t4,3
    seq $t3,$t3,$t4
    beqz $t3,$l3
    lw $t4,_impar
    lw $t5,_i
    add $t4,$t4,$t5
    sw $t4,_impar
    b $l4
$l3:
    lw $t4,_i
    li $t5,4
    seq $t4,$t4,$t5
    beqz $t4,$l1
    lw $t5,_par
    lw $t6,_i
    add $t5,$t5,$t6
    sw $t5,_par
    b $l2
$l1:
    lw $t5,_impar
    lw $t6,_i
    add $t5,$t5,$t6
    sw $t5,_impar
$l2:
$l4:
$l6:
$l8:
    lw $t1,_i
    li $t2,1
    add $t1,$t1,$t2
    sw $t1,_i
    b $l9
$l10:
    li $v0,4
    la $a0,$str1
    syscall
    lw $t0,_par
    li $v0,1
    move $a0,$t0
    syscall
    li $v0,4
    la $a0,$str2
    syscall
    li $v0,4
    la $a0,$str3
    syscall
    lw $t0,_impar
    li $v0,1
    move $a0,$t0
    syscall
    li $v0,4
    la $a0,$str2
    syscall
    li $v0, 10
    syscall