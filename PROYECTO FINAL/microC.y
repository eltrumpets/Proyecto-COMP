%{
    #include <stdio.h>
    #include <stdlib.h>
    extern int yylex();
    extern int yylineno;
    extern int errores;
    void yyerror(const char *msg);
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

%%

program : "void" IDE "(" ")" "{" body "}"
        ;

body : body declaration
     | body statement
     | %empty
     ; 

declaration : "var" tipo id_list ";"
            | "const" tipo id_list ";"
            ;

tipo : "int"
     ;

id_list : id_decl
        | id_list "," id_decl
        ;

id_decl : IDE
        | IDE "=" expression
        ;

statement : IDE "=" expression ;
          | "{" statement_list "}"
          | "if" "(" expression ")" statement "else" statement
          | "if" "(" expression ")" statement
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
           | CAD
           ;

read_list : IDE
          | read_list "," IDE
          ;




expression : expression "+" expression { printf("E->E+E\n"); $$ = $1+$3; }
     | expression "-" expression { printf("E->E-E\n"); $$ = $1-$3; }
     | expression "*" expression { printf("E->E*E\n"); $$ = $1 * $3; } 
     | expression "/" expression { printf("E->E/E\n"); 
                       if ($3 == 0){
                         printf("División por 0 en línea %d\n",
                                yylineno);
                         exit(1);
                       }
                       $$ = $1 / $3;
                     }
     | NUM           { printf("E->num (%d)\n", $1); $$ = $1; }
     | IDE { $$ = 0; }       
     | "(" expression ")"  { printf("E->(E)\n"); $$ = $2; }
     | "-" expression %prec SIGNO   { printf("E->-E\n"); $$ = -$2; }
     | "(" error ")"  { }
     ;

%%

void yyerror(const char *msg){
    printf("Error sintáctico en línea %d: %s\n", yylineno, msg);
    errores++;
}
