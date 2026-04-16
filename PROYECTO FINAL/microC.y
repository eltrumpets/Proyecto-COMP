%{
    #define _GNU_SOURCE
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <stdbool.h>
    #include <assert.h>
    #include "listaSimbolos.h"
    #include "listaCodigo.h"

    extern int yylex();
    extern int yylineno;
    extern int errores;
    int numCadena = 1;
    int contador_etiq = 1;
    void yyerror(const char *msg);
    void comprobar_division(ListaC expre);
    // Lista de simbolos
    Lista l;
    void declarar_id(char *id, Tipo t);
    void imprimirLS(Lista l);
    void declarar_cadena(char *cadena, Tipo t);
    void verificar_id(char *id);
    // Variable para determinar si el id es VAR o CONST
    Tipo t;
    // Lista de codigo
    ListaC codigoTotal;
    bool registros[10];
    void inicializarRegs();
    char *obtenerReg();
    void liberarReg(char *reg);
    ListaC expresion_num(char *num);
    ListaC expresion_id(char *id);
    ListaC expresion_bin(char *op, ListaC expr1, ListaC expr2);
    ListaC expresion_neg(ListaC expr);
    char *nuevaEtiqueta();
    void imprimirLC(ListaC codigo);
    ListaC statement_while(ListaC expr, ListaC stat);
    

%}

%code requires{
    #include "listaCodigo.h"
}

%union{
  ListaC codigo;
  char *str;
}

%token PYC ";"
%token <str> IDE "identifier"
%token IGU "="
%token SUM "+"
%token RES "-"
%token COI "{"
%token COD "}"
%token PAI "("
%token PAD ")"
%token PRI "print"
%token COM ","
%token <str> CAD "cadena"
%token MUL "*"
%token VOI "void"
%token VAR "var"
%token CON "const"
%token INT "int"
%token IFF "if"
%token ELS "else"
%token DO  "do"
%token WHI "while"
%token REA "read"
%token DIV "/"
%token MNR "<"
%token MYR ">"
%token MNI "<="
%token MYI ">="
%token IG2 "=="
%token DES "!="
%token <str> NUM "number"


// Tipo de dato de los no terinales de la gramática
%type <codigo> expression statement statement_list print_item print_list read_list declaration id_list id_decl body
%type <str> tipo

%expect 0

/* Asociatividad y precedencia de los operadores 
   %left : asociatividad a la izquierda (2+2)+2
   %right: asociatividad a la derecha 2+(2+2)
   %nonassoc: no debe tener asociativividad 2+2+2 (error sintactico)
   Misma precedencia y asociatividad en la misma línea
   Mayor precedencia en lineas sucesivas

   %precedence solo define precedencia, no asociatividad
*/

%nonassoc "<" ">" "<=" ">=" "==" "!="
%left "+" "-"
%left "*" "/"
%precedence SIGNO /* operador unario, para el caso de -E, tiene mayor precedencia que los operadores binarios */

/*Resolucion de conflicto if if/else */
%precedence NOELSE
%precedence ELS

%define parse.error verbose

%%

program : { l = creaLS();
            codigoTotal = creaLC(); }
          VOI IDE { if(strcmp($3, "main") != 0){
                printf("Error en línea %d: %s es un id de programa incorrecto\n", yylineno, $3);
                errores++;
                    }
                  }
          "(" ")" "{"body"}" 
          {
            if (errores == 0){
               imprimirLS(l);
               imprimirLC(codigoTotal);
               
            }else{
                printf("\nErrores semanticos: %d\n", errores);
            }
            liberaLS(l); 
          }
        ;

body : body declaration { concatenaLC(codigoTotal, $2); }
     | body statement   { concatenaLC(codigoTotal, $2); }
     | %empty           { $$ = creaLC(); }
     ; 

declaration : VAR { t = VARIABLE; }tipo id_list ";" { $$ = $4; }
            | CON { t = CONSTANTE; } tipo id_list ";" { $$ = $4; }
            ;

tipo : INT    { $$ = "int"; }
     ;

id_list : id_decl { $$ = $1; }
        | id_list "," id_decl { $$ = $1;
                            concatenaLC($$, $3);
                            liberaLC($3); }
        ;

id_decl : IDE {
            declarar_id($1, t);
            $$ = creaLC(); }
        | IDE "=" expression {
            declarar_id($1,t);
            $$ = creaLC();
            if(errores == 0){
                // Generar codigo para la asignacion
                $$ = $3;
                Operacion o;
                o.op = "sw";
                o.res = recuperaResLC($3);
                asprintf(&(o.arg1), "_%s", $1);
                o.arg2 = NULL;
                insertaLC($$, finalLC($$), o);
                liberarReg(o.res);
            }
        }
        ;

statement : IDE "=" expression ";" { verificar_id($1);
                                     // Verificacion temporal
                                     if (errores == 0){
                                        $$ = $3;
                                        Operacion o;
                                        o.op = "sw";
                                        o.res = recuperaResLC($3);
                                        asprintf(&(o.arg1), "_%s", $1);
                                        o.arg2 = NULL;
                                        insertaLC($$, finalLC($$), o);
                                        liberarReg(o.res);
                                     }
                                     concatenaLC(codigoTotal,$3);   }
          | "{" statement_list "}" { if(errores == 0){
                                        $$ = $2; 
                                     } }
          | "if" "(" expression ")" statement "else" statement { }
          | "if" "(" expression ")" statement %prec NOELSE { }
          | "while" "(" expression ")" statement { $$ = statement_while($3,$5); 
                                        /*concatenaLC(codigoTotal, $$);*/ }
          | "print" "(" print_list ")" ";" { $$ = $3; }    
          | "read" "(" read_list ")" ";" { $$ = $3; }
          | "do" statement "while" "(" expression ")" ";" { }
          ;

statement_list : statement_list statement { $$ = $1;
                                            concatenaLC($$, $2);
                                            liberaLC($2); }
               | %empty { $$ = creaLC(); }
               ;

print_list : print_item { $$ = $1; }
           | print_list "," print_item { $$ = $1;
               concatenaLC($$, $3);
               liberaLC($3); }
           ;

print_item : expression { if(errores == 0){
                                $$ = $1;
                                Operacion o;
                                o.op = "li";
                                o.res = "$v0";
                                o.arg1 = "1";
                                o.arg2 = NULL;
                                insertaLC($$, finalLC($$), o);
                                o.op = "move";
                                o.res = "$a0";
                                o.arg1 = recuperaResLC($1);
                                o.arg2 = NULL;
                                insertaLC($$, finalLC($$), o);
                                o.op = "syscall";
                                o.res = o.arg1 = o.arg2 = NULL;
                                insertaLC($$, finalLC($$), o);
                                liberarReg(recuperaResLC($1));
                            }
              }
           | CAD { declarar_cadena($1,CADENA); 
                    if(errores == 0){
                        $$ = creaLC();
                        Operacion o;
                        o.op = "li";
                        o.res = "$v0";
                        o.arg1 = "4";
                        o.arg2 = NULL;
                        insertaLC($$, finalLC($$), o);
                        o.op = "la";
                        o.res = "$a0";
                        asprintf(&(o.arg1), "$str%d", numCadena-1);
                        o.arg2 = NULL;
                        insertaLC($$, finalLC($$), o);
                        o.op = "syscall";
                        o.res = o.arg1 = o.arg2 = NULL;
                        insertaLC($$, finalLC($$), o);
                    }
                 }
           ;

read_list : IDE { verificar_id($1); 
                    if(errores == 0){
                        $$ = creaLC();
                        Operacion o;
                        o.op = "li";
                        o.res = "$v0";
                        o.arg1 = "5";
                        o.arg2 = NULL;
                        insertaLC($$, finalLC($$), o);
                        o.op = "syscall";
                        o.res = o.arg1 = o.arg2 = NULL;
                        insertaLC($$, finalLC($$), o);
                        o.op = "sw";
                        asprintf(&(o.res), "_%s", $1);
                        o.arg1 = "$v0";
                        o.arg2 = NULL;
                        insertaLC($$, finalLC($$), o);
                        concatenaLC(codigoTotal, $$);
                    }
                 }
          | read_list "," IDE { verificar_id($3); }

expression : expression "+" expression { $$ = expresion_bin("add", $1, $3);
                                        
                                        
                                        }
     | expression "-" expression { $$ = expresion_bin("sub", $1, $3); }
     | expression "*" expression { $$ = expresion_bin("mul", $1, $3); } 
     | expression "/" expression { comprobar_division($3);
                                   $$ = expresion_bin("div", $1, $3); }
     | NUM { $$ = expresion_num($1); }
     | IDE { verificar_id($1);
             $$ = expresion_id($1); }              
     | "(" expression ")"  { $$ = $2; }
     | "-" expression %prec SIGNO   { $$ = expresion_bin("neg", $2, NULL); }
     | expression "<" expression    { }
     | expression ">" expression    { }
     | expression "<=" expression   { }
     | expression ">=" expression   { }
     | expression "==" expression   { }
     | expression "!=" expression   { }
     | "(" error ")"  { }
     ;

%%

// Accion que se ejecuta al detectar un error sintáctico y suma el contador de errores
void yyerror(const char *msg){
    printf("Error sintáctico en línea %d: %s\n", yylineno, msg);
    errores++;
}

// Accion que comprueba si la division tiene como denominador un 0 y suma el contador de errores
void comprobar_division(ListaC expre){
    if (expre == 0){
        printf("División por 0 en línea %d\n", yylineno);
        errores++;
    }
}

// Accion que declara un id en la tabla de simbolos, comprobando que no haya sido declarado previamente
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

         // cadenas
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

void verificar_id(char *id){
    PosicionLista p = buscaLS(l, id);
    if(p == finalLS(l)){
        printf("Error en línea %d: variable '%s' no declarada\n", yylineno, id);
        errores++;
    } else {
        Simbolo s = recuperaLS(l, p);
        if(s.tipo == CONSTANTE){
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
    // Buscar registro $tX libre
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
    // reg == $tX
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
    //liberaLC(expr);
    //liberaLC(stat);
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
        if(oper.op[0] == '$'){
            // Etiqueta de salto
            printf("%s:\n", oper.op);   // ✅ Usa el nombre real de la etiqueta
            p = siguienteLC(codigo, p); // ✅ Avanza el puntero
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