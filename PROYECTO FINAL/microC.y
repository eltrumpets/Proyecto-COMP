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

program : "void" IDE "(" ")"  { printf("program->void %s(){body}\n", $2); }"{"body"}"
                              { printf("Programa %s procesado\n", $2); }
        ;

body : body declaration
     | body statement
     | %empty
     ; 

declaration : "var" { printf("var "); } tipo id_list ";" { printf("\n"); }
            | "const" { printf("const "); } tipo id_list ";" { printf("\n"); }
            ;

tipo : "int"    { printf("int "); }
     ;

id_list : id_decl 
        | id_list "," id_decl 
        ;

id_decl : IDE { printf("%s ", $1); }
        | IDE "=" expression { printf("%s=%d ", $1, $3); }
        ;

statement : IDE "=" expression ";"
          | "{" statement_list "}"
          | "if" "(" expression ")" statement "else" statement { printf("if (%d) statement else statement\n", $3); }
          | "if" "(" expression ")" statement %prec NOELSE     { printf("if (%d) statement\n", $3); }
          | "while" "(" expression ")" statement    { printf("while (%d) statement\n", $3); }
          | "print" "(" print_list ")" ";" { printf("\n"); }
          | "read" "(" read_list ")" ";"        { printf("read ();\n"); }
          | error
          ;

statement_list : statement_list statement
               | %empty
               ;

print_list : print_item         
           | print_list "," print_item
           ;

print_item : expression { printf("%d ", $1); }
           | CAD        { printf("%s ", $1); }
           ;

read_list : IDE
          | read_list "," IDE
          ;

expression : expression "+" expression { printf("Expresion->%d+%d\n", $1, $3); $$ = $1+$3; }
     | expression "-" expression { printf("Expresion->%d-%d\n", $1, $3); $$ = $1-$3; }
     | expression "*" expression { printf("Expresion->%d*%d\n", $1, $3); $$ = $1 * $3; } 
     | expression "/" expression { printf("Expresion->%d/%d\n", $1, $3); 
                       if ($3 == 0){
                         printf("División por 0 en línea %d\n",
                                yylineno);
                         exit(1);
                       }
                       $$ = $1 / $3;
                     }
     | NUM { $$ = $1; }
     | IDE { printf("Variable %s\n", $1); $$ = 0; }       
     | "(" expression ")"  { printf("(%d)\n", $2); $$ = $2; }
     | "-" expression %prec SIGNO   { printf("-%d\n", $2); $$ = -$2; }
     | "(" error ")"  { }
     ;

%%

void yyerror(const char *msg){
    printf("Error sintáctico en línea %d: %s\n", yylineno, msg);
    errores++;
}
