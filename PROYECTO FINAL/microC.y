%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "listaSimbolos.h"

    extern int yylex();
    extern int yylineno;
    extern int errores;
    int numCadena = 1;
    void yyerror(const char *msg);
    // Lista de simbolos
    Lista l;
    void declarar_id(char *id, Tipo t);
    void imprimirLS(Lista l);
    void declarar_cadena(char *cadena, Tipo t);
    // Variable para determinar si el id es VAR o CONST
    Tipo t;
%}

%union{
  int num;
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
%token <num> NUM "number"
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
%token WHI "while"
%token REA "read"
%token DIV "/"

// Tipo de dato de los no terinales de la gramática
%type <num> expression 
%type <str> tipo


/* Asociatividad y precedencia de los operadores 
   %left : asociatividad a la izquierda (2+2)+2
   %right: asociatividad a la derecha 2+(2+2)
   %nonassoc: no debe tener asociativividad 2+2+2 (error sintactico)
   Misma precedencia y asociatividad en la misma línea
   Mayor precedencia en lineas sucesivas

   %precedence solo define precedencia, no asociatividad
*/
%left "+" "-"
%left "*" "/"
%precedence SIGNO /* operador unario, para el caso de -E, tiene mayor precedencia que los operadores binarios */

/*Resolucion de conflicto if if/else */
%precedence NOELSE
%precedence ELS

%define parse.error verbose

// Evitar el warning de if / if-else
//%expect 1

%%

program : { l = creaLS(); }
          VOI IDE "(" ")" "{"body"}" 
          {
           if (errores == 0){
               imprimirLS(l);
            }
            liberaLS(l); 
          }
        ;

body : body declaration
     | body statement
     | %empty
     ; 

declaration : VAR { t = VARIABLE; }tipo id_list ";" 
            | CON { t = CONSTANTE; } tipo id_list ";" 
            ;

tipo : INT    { $$ = "int"; }
     ;

id_list : id_decl 
        | id_list "," id_decl 
        ;

id_decl : IDE {
            declarar_id($1, t);
        }
        | IDE "=" expression {
            declarar_id($1,t);
        }
        ;

statement : IDE "=" expression ";" 
            { PosicionLista p = buscaLS(l, $1);
              if(p == finalLS(l)){
                printf("Error en línea %d: variable '%s' no declarada\n", yylineno, $1);
                errores++;
            } else {
                Simbolo s = recuperaLS(l, p);
                if(s.tipo == CONSTANTE){
                    printf("Error en línea %d: no se le puede asignar a la constante '%s'\n", yylineno, $1);
                    errores++;
                }
            }
            }
          | "{" statement_list "}"
          | "if" "(" expression ")" statement "else" statement 
          | "if" "(" expression ")" statement %prec NOELSE     
          | "while" "(" expression ")" statement   
          | "print" "(" print_list ")" ";"    
          | "read" "(" read_list ")" ";"        
          | error
          ;

statement_list : statement_list statement
               | %empty
               ;

print_list : print_item         
           | print_list "," print_item
           ;

print_item : expression 
           | CAD {
               declarar_cadena($1,CADENA);
           }
           ;

read_list : IDE
            {  
              PosicionLista p = buscaLS(l, $1);
              if(p == finalLS(l)){
                printf("Error en línea %d: variable '%s' no declarada\n", yylineno, $1);
                errores++;
            } else {
                Simbolo s = recuperaLS(l, p);
                if(s.tipo == CONSTANTE){
                    printf("Error en línea %d: no se le puede asignar a la constante '%s'\n", yylineno, $1);
                    errores++;
                }
            }
            }
          | read_list "," IDE
          {
              PosicionLista p = buscaLS(l, $3);
              if(p == finalLS(l)){
                printf("Error en línea %d: variable '%s' no declarada\n", yylineno, $3);
                errores++;
            } else {
                Simbolo s = recuperaLS(l, p);
                if(s.tipo == CONSTANTE){
                    printf("Error en línea %d: no se le puede asignar a la constante '%s'\n", yylineno, $3);
                    errores++;
                }
            }
          }
          ;

expression : expression "+" expression { $$ = $1+$3; }
     | expression "-" expression { $$ = $1-$3; }
     | expression "*" expression { $$ = $1 * $3; } 
     | expression "/" expression { if ($3 == 0){
                         printf("División por 0 en línea %d\n",
                                yylineno);
                         exit(1);
                       }
                       $$ = $1 / $3;
                     }
     | NUM { $$ = $1; }
     | IDE { PosicionLista p = buscaLS(l, $1);
         if(p == finalLS(l)){
             printf("Error en línea %d: variable '%s' no declarada\n", yylineno, $1);
             errores++;
             $$ = 0;
         } else {
             $$ = 0;
         }
     }              
     | "(" expression ")"  { $$ = $2; }
     | "-" expression %prec SIGNO   { $$ = -$2; }
     | "(" error ")"  { }
     ;

%%

void yyerror(const char *msg){
    printf("Error sintáctico en línea %d: %s\n", yylineno, msg);
    errores++;
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
     Simbolo s;
     s.nombre = cadena;
     s.valor = numCadena++;
     s.tipo = t;
     insertaLS(l, finalLS(l),s);
     
}



void imprimirLS(Lista l){
     printf("##################\n");
     printf("# Seccion de datos\n");
     printf(".data\n");
     PosicionLista p = inicioLS(l);
     p = inicioLS(l);
    while (p != finalLS(l)) {
        Simbolo aux = recuperaLS(l, p);
        if(aux.tipo == VARIABLE || aux.tipo == CONSTANTE){
            printf("_%s: .word %d\n", aux.nombre, aux.valor);
        }
        p = siguienteLS(l, p);
    }

    // cadenas
    p = inicioLS(l);
    while (p != finalLS(l)) {
        Simbolo aux = recuperaLS(l, p);
        if(aux.tipo == CADENA){
            printf("$str%d: .asciiz %s\n", aux.valor, aux.nombre);
        }
        p = siguienteLS(l, p);
    }
}