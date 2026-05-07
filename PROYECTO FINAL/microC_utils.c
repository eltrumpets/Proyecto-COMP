#include "microC_utils.h"

Lista l;
int numCadena = 1;
int contador_etiq = 1;
Tipo t;
ListaC codigoTotal;
bool registros[10];

void yyerror(const char *msg){
    printf("Error sintáctico en línea %d: %s\n", yylineno, msg);
    errores++;
}

void comprobar_division(ListaC expre){
    if (expre == 0){
        printf("División por 0 en línea %d\n", yylineno);
        errores++;
    }
}

void declarar_id(char *id, Tipo t){
     PosicionLista p = buscaLS(l, id);
     if(p != finalLS(l)){
          printf("Error en linea %d: variable %s redeclarada\n", yylineno, id);
          errores++;
     }else{
          Simbolo s;
          s.nombre = id;
          s.valor = 0;
          s.tipo = t;
          insertaLS(l, finalLS(l),s);
     }
}

void declarar_cadena(char *cadena, Tipo t){
    PosicionLista p = buscaLS(l, cadena);
    if(p != finalLS(l)){
    }else{
        PosicionLista p = buscaLS(l, cadena);
        Simbolo s;
        s.nombre = cadena;
        s.valor = numCadena++;
        s.tipo = t;
        insertaLS(l, finalLS(l),s);
    }
}

char *nuevaEtiqueta(){
    char *aux;
    asprintf(&aux, "$l%d", contador_etiq++);
    return aux;
}

void imprimirLS(Lista l){
     printf("##################\n");
     printf("# Seccion de datos\n");
     printf("    .data\n\n");
     PosicionLista p = inicioLS(l);

     p = inicioLS(l);
     while (p != finalLS(l)) {
         Simbolo aux = recuperaLS(l, p);
         if(aux.tipo == CADENA){
             printf("$str%d:\n    .asciiz %s\n", aux.valor, aux.nombre);
         }
         p = siguienteLS(l, p);
     }
     p = inicioLS(l);
     while (p != finalLS(l)) {
         Simbolo aux = recuperaLS(l, p);
         if(aux.tipo == VARIABLE || aux.tipo == CONSTANTE){
             printf("_%s:\n    .word %d\n", aux.nombre, aux.valor);
         }
         p = siguienteLS(l, p);
     }
     printf("\n");
}

void verificar_id(char *id, int esLectura){
    PosicionLista p = buscaLS(l, id);
    if(p == finalLS(l)){
        printf("Error en línea %d: variable '%s' no declarada\n", yylineno, id);
        errores++;
    } else {
        Simbolo s = recuperaLS(l, p);
        if(s.tipo == CONSTANTE && esLectura == 0){
            printf("Error en línea %d: '%s' es una constante\n", yylineno, id);
            errores++;
        }
    }
}

void inicializarRegs(){
    for(int i = 0; i < 10; i++){
        registros[i] = false;
    }
}

char *obtenerReg(){
    for(int i = 0; i < 10; i++){
        if(registros[i] == false){
            registros[i] = true;
            char *reg;
            asprintf(&reg, "$t%d", i);
            return reg;
        }
    }
    printf("Error: registros agotados!\n");
    exit(1);
}

void liberarReg(char *reg){
    assert(reg[0] == '$');
    assert(reg[1] == 't');
    int index = (reg[2]) - '0';
    assert(index >= 0);
    assert(index <= 9);
    registros[index] = false;
}

ListaC expresion_num(char *num){
    ListaC codigo = creaLC();
    Operacion o;
    o.op = "li";
    o.res = obtenerReg();
    o.arg1 = num;
    o.arg2 = NULL;
    insertaLC(codigo, finalLC(codigo), o);
    guardaResLC(codigo, o.res);
    return codigo;
}

ListaC expresion_id(char *id){
    ListaC codigo = creaLC();
    Operacion o;
    o.op = "lw";
    o.res = obtenerReg();
    asprintf(&(o.arg1), "_%s", id);
    o.arg2 = NULL;
    insertaLC(codigo, finalLC(codigo), o);
    guardaResLC(codigo, o.res);
    return codigo;
}

ListaC expresion_bin(char *op, ListaC expr1, ListaC expr2){
    ListaC codigo = expr1;
    Operacion o;
    o.op = op;
    o.res = recuperaResLC(expr1);
    o.arg1 = recuperaResLC(expr1);
    if(expr2 != NULL){
        concatenaLC(codigo, expr2);
        o.arg2 = recuperaResLC(expr2);
        liberarReg(o.arg2);
        liberaLC(expr2);
    } else {
        o.arg2 = NULL;
    }
    insertaLC(codigo, finalLC(codigo), o);
    return codigo;
}

//MEJORA OPERADORES RACIONALES
ListaC expresion_rel(char *op, ListaC expr1, ListaC expr2){
    ListaC codigo = expr1;
    Operacion o;
    concatenaLC(codigo, expr2);
    o.op = op;
    o.res = recuperaResLC(expr1);
    o.arg1 = recuperaResLC(expr1);
    o.arg2 = recuperaResLC(expr2);
    liberarReg(o.arg2);
    insertaLC(codigo, finalLC(codigo), o);
    liberaLC(expr2);
    guardaResLC(codigo, o.res);
    return codigo;
}

ListaC statement_while(ListaC expr, ListaC stat){
    char *etiq_inicio = nuevaEtiqueta();
    char *etiq_fin = nuevaEtiqueta();
    Operacion o;
    o.op = etiq_inicio;
    o.res = o.arg1 = o.arg2 = NULL;
    ListaC codigo = creaLC();
    insertaLC(codigo, finalLC(codigo), o);
    concatenaLC(codigo, expr);
    o.op = "beqz";
    o.res = recuperaResLC(expr);
    o.arg1 = etiq_fin;
    o.arg2 = NULL;
    insertaLC(codigo, finalLC(codigo), o);
    concatenaLC(codigo, stat);
    o.op = "b";
    o.res = etiq_inicio;
    o.arg1 = NULL;
    o.arg2 = NULL;
    insertaLC(codigo, finalLC(codigo), o);
    o.op = etiq_fin;
    o.res = o.arg1 = o.arg2 = NULL;
    insertaLC(codigo, finalLC(codigo), o);
    liberarReg(recuperaResLC(expr));
    return codigo;
}

ListaC statement_if(ListaC expr, ListaC stat){
    char *etiq_fin = nuevaEtiqueta();
    Operacion o;
    ListaC codigo = creaLC();

    concatenaLC(codigo, expr);
    o.op = "beqz";
    o.res = recuperaResLC(expr);
    o.arg1 = etiq_fin;
    o.arg2 = NULL;
    insertaLC(codigo, finalLC(codigo), o);
    liberarReg(recuperaResLC(expr));
    concatenaLC(codigo, stat);
    o.op = etiq_fin;
    o.res = o.arg1 = o.arg2 = NULL;
    insertaLC(codigo, finalLC(codigo), o);
    liberaLC(expr);
    liberaLC(stat);
    return codigo;
}

ListaC statement_if_else(ListaC expr, ListaC stat_if, ListaC stat_else){
    char *etiq_else = nuevaEtiqueta();
    char *etiq_fin = nuevaEtiqueta();
    Operacion o;
    ListaC codigo = creaLC();
    concatenaLC(codigo, expr);
    o.op = "beqz";
    o.res = recuperaResLC(expr);
    o.arg1 = etiq_else;
    o.arg2 = NULL;
    insertaLC(codigo, finalLC(codigo), o);
    concatenaLC(codigo, stat_if);
    o.op = "b";
    o.res = etiq_fin;
    o.arg1 = NULL;
    o.arg2 = NULL;
    insertaLC(codigo, finalLC(codigo), o);
    o.op = etiq_else;
    o.res = o.arg1 = o.arg2 = NULL;
    insertaLC(codigo, finalLC(codigo), o);
    concatenaLC(codigo, stat_else);
    o.op = etiq_fin;
    o.res = o.arg1 = o.arg2 = NULL;
    insertaLC(codigo, finalLC(codigo), o);
    liberarReg(recuperaResLC(expr));
    return codigo;
}

//MEJORA DO-WHILE
ListaC statement_do_while(ListaC stat, ListaC expr){
    char *etiq_inicio = nuevaEtiqueta();
    Operacion o;
    ListaC codigo = creaLC();
    o.op = etiq_inicio;
    o.res = o.arg1 = o.arg2 = NULL;
    insertaLC(codigo, finalLC(codigo), o);
    concatenaLC(codigo, stat);
    concatenaLC(codigo, expr);
    o.op = "bnez";
    o.res = recuperaResLC(expr);
    o.arg1 = etiq_inicio;
    o.arg2 = NULL;
    insertaLC(codigo, finalLC(codigo), o);
    liberarReg(recuperaResLC(expr));
    return codigo;
}

void imprimirLC(ListaC codigo){
    printf("##################\n");
    printf("# Seccion de codigo\n");
    printf("    .text\n");
    printf("    .global main\n");
    printf("main:\n");
    PosicionListaC p = inicioLC(codigo);
    while (p != finalLC(codigo)) {
        Operacion oper = recuperaLC(codigo,p);
        if(oper.op[0] == '$' && oper.op[1] == 'l'){
            printf("%s:\n", oper.op);
            p = siguienteLC(codigo, p);
        }else{
            printf("    %s",oper.op);
            if (oper.res) printf(" %s",oper.res);
            if (oper.arg1) printf(",%s",oper.arg1);
            if (oper.arg2) printf(",%s",oper.arg2);
            printf("\n");
            p = siguienteLC(codigo,p);
        }
    }
    printf("    li $v0, 10\n");
    printf("    syscall\n");
}

//Funciones para las generaciones de codigo
ListaC genCodigo_sw(ListaC expr, char *ide) {
    Operacion o;
    o.op = "sw";
    o.res = recuperaResLC(expr);
    asprintf(&(o.arg1), "_%s", ide);
    o.arg2 = NULL;
    insertaLC(expr, finalLC(expr), o);
    liberarReg(o.res);
    return expr;
}

ListaC genCodigo_print(ListaC expr) {
    Operacion o;
    o.op = "li";
    o.res = "$v0";
    o.arg1 = "1";
    o.arg2 = NULL;
    insertaLC(expr, finalLC(expr), o);
    o.op = "move";
    o.res = "$a0";
    o.arg1 = recuperaResLC(expr);
    o.arg2 = NULL;
    insertaLC(expr, finalLC(expr), o);
    o.op = "syscall";
    o.res = o.arg1 = o.arg2 = NULL;
    insertaLC(expr, finalLC(expr), o);
    liberarReg(recuperaResLC(expr));
    return expr;
}

ListaC genCodigo_printCAD(char* cad) {
    ListaC codigo = creaLC();
    Operacion o;
    o.op = "li";
    o.res = "$v0";
    o.arg1 = "4";
    o.arg2 = NULL;
    insertaLC(codigo, finalLC(codigo), o);
    o.op = "la";
    o.res = "$a0";
    PosicionLista p = buscaLS(l, cad);
    Simbolo s = recuperaLS(l, p);
    asprintf(&(o.arg1), "$str%d", s.valor);
    o.arg2 = NULL;
    insertaLC(codigo, finalLC(codigo), o);
    o.op = "syscall";
    o.res = o.arg1 = o.arg2 = NULL;
    insertaLC(codigo, finalLC(codigo), o);
    return codigo;
}

ListaC genCodigo_read(ListaC lista_leida, char* ide){
    if(lista_leida == NULL){
        ListaC codigo = creaLC();
        Operacion o;
        o.op = "li";
        o.res = "$v0";
        o.arg1 = "5";
        o.arg2 = NULL;
        insertaLC(codigo, finalLC(codigo), o);
        o.op = "syscall";
        o.res = o.arg1 = o.arg2 = NULL;
        insertaLC(codigo, finalLC(codigo), o);
        o.op = "sw";
        o.res = "$v0";
        asprintf(&(o.arg1), "_%s", ide);
        o.arg2 = NULL;
        insertaLC(codigo, finalLC(codigo), o);
        return codigo;
    }else{
        Operacion o;
        o.op = "li";
        o.res = "$v0";
        o.arg1 = "5";
        o.arg2 = NULL;
        insertaLC(lista_leida, finalLC(lista_leida), o);
        o.op = "syscall";
        o.res = o.arg1 = o.arg2 = NULL;
        insertaLC(lista_leida, finalLC(lista_leida), o);
        o.op = "sw";
        o.res = "$v0";
        asprintf(&(o.arg1), "_%s", ide);
        o.arg2 = NULL;
        insertaLC(lista_leida, finalLC(lista_leida), o);
        return lista_leida;
    }
}
