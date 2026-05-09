##################
# Seccion de datos
    .data

$str1:
    .asciiz "Resultado: \n"
$str2:
    .asciiz "\n"
_LIMITE:
    .word 0
_i:
    .word 0
_suma:
    .word 0
_num:
    .word 0

##################
# Seccion de codigo
    .text
    .global main
main:
    li $t0,10
    sw $t0,_LIMITE
    li $t0,1
    sw $t0,_i
    li $t0,0
    sw $t0,_suma
    li $v0,5
    syscall
    sw $v0,_num
$l3:
    lw $t0,_i
    lw $t1,_LIMITE
    sle $t0,$t0,$t1
    beqz $t0,$l4
    lw $t1,_num
    lw $t2,_i
    sge $t1,$t1,$t2
    beqz $t1,$l1
    lw $t2,_suma
    lw $t3,_i
    add $t2,$t2,$t3
    sw $t2,_suma
    lw $t2,_i
    li $t3,1
    add $t2,$t2,$t3
    sw $t2,_i
    b $l2
$l1:
    lw $t2,_LIMITE
    li $t3,1
    add $t2,$t2,$t3
    sw $t2,_i
$l2:
    b $l3
$l4:
$l5:
    li $v0,4
    la $a0,$str1
    syscall
    lw $t0,_suma
    li $v0,1
    move $a0,$t0
    syscall
    li $v0,4
    la $a0,$str2
    syscall
    lw $t0,_num
    li $t1,1
    sub $t0,$t0,$t1
    sw $t0,_num
    lw $t0,_num
    li $t1,0
    sgt $t0,$t0,$t1
    bnez $t0,$l5
    li $v0, 10
    syscall