#include "funciones_gencodigo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "listaSimbolos.h"
#include "listaCodigo.h"

void genCodigo_sw(ListaC expr, ListaC ide) {
    $$ = expr;
    Operacion o;
    o.op = "sw";
    o.res = recuperaResLC(expr);
    asprintf(&(o.arg1), "_%s", ide);
    o.arg2 = NULL;
    insertaLC($$, finalLC($$), o);
    liberarReg(o.res);
}

void liberarReg(char *reg){
    // reg == $tX
    assert(reg[0] == '$');
    assert(reg[1] == 't');
    int index = (reg[2]) - '0';
    assert(index >= 0);
    assert(index <= 9);
    registros[index] = false;

}