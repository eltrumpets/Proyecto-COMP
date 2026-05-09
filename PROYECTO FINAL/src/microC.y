%{
#define _GNU_SOURCE
#include "microC_utils.h"
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

program :
        {
            l = creaLS();
            codigoTotal = creaLC();
        }
        VOI IDE
        {
            comprobar_main($3);
        }
        "(" ")" "{" body "}"
        {
            if (errores == 0){
                imprimirLS(l);
                imprimirLC(codigoTotal);
            } else {
                printf("Errores semanticos: %d\n", errores);
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
            if(errores == 0){
                $$ = genCodigo_sw($3, $1);
            }
        }
        ;

statement : IDE "=" expression ";" { verificar_id($1, 0);
                                     if (errores == 0){
                                        $$ = genCodigo_sw($3, $1);
                                     }else{
                                        $$ = creaLC();
                                     }
                                     /*concatenaLC(codigoTotal,$3);*/   }
          | "{" statement_list "}" { if(errores == 0){
                                        $$ = $2; 
                                     } }
          | "if" "(" expression ")" statement "else" statement { if(errores == 0){
                                                                    $$ = statement_if_else($3,$5,$7);               
                                                                } }
          | "if" "(" expression ")" statement %prec NOELSE { if(errores == 0){
                                                                $$ = statement_if($3,$5);
                                                              } }
          | "while" "(" expression ")" statement { if(errores == 0){
                                                    $$ = statement_while($3,$5);
                                                  } }
          | "print" "(" print_list ")" ";" { $$ = $3; }    
          | "read" "(" read_list ")" ";" { $$ = $3; }
          | "do" statement "while" "(" expression ")" ";" { if(errores == 0){
                                                                // MEJORA DEL DO_WHILE
                                                                $$ = statement_do_while($2, $5);
                                                    } }
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
                                $$ = genCodigo_print($1);
                            }
              }
           | CAD { declarar_cadena($1,CADENA); 
                    if(errores == 0){
                        $$ = genCodigo_printCAD($1);
                    }
                 }
           ;

read_list : IDE { verificar_id($1, 1);
                    if(errores == 0){
                        $$ = genCodigo_read(NULL, $1);
                    } else {
                        $$ = creaLC();
                    }
                 }
          | read_list "," IDE { verificar_id($3, 1);
                                if(errores == 0){
                                    $$ = genCodigo_read($1, $3);
                                } else {
                                    $$ = $1;
                                }
                              }

expression : expression "+" expression { if(errores == 0){
                                        $$ = expresion_bin("add", $1, $3);
                                        
                                          } 
                                        }
     | expression "-" expression { if(errores == 0){
                                    $$ = expresion_bin("sub", $1, $3);
                                  } }
     | expression "*" expression { if(errores == 0){
                                    $$ = expresion_bin("mul", $1, $3);
                                  } }
     | expression "/" expression { comprobar_division($3);
                                if(errores == 0){
                                   $$ = expresion_bin("div", $1, $3);
                                 } }
     | NUM { if(errores == 0){
                $$ = expresion_num($1);
             } }
     | IDE { verificar_id($1, 1);
            if(errores == 0){
             $$ = expresion_id($1); 
             } else {
                $$ = creaLC();
             }
            }            
     | "(" expression ")"  { $$ = $2; }
     | "-" expression %prec SIGNO   { if(errores == 0){
                                        $$ = expresion_bin("neg", $2, NULL);
                                      } }
     | expression "<" expression    { if(errores == 0){
                                        $$ = expresion_rel("slt", $1, $3);
                                      } }
     | expression ">" expression    { if(errores == 0){
                                        $$ = expresion_rel("sgt", $1, $3);
                                      } }
     | expression "<=" expression   { if(errores == 0){
                                        $$ = expresion_rel("sle", $1, $3);
                                      } }
     | expression ">=" expression   { if(errores == 0){
                                        $$ = expresion_rel("sge", $1, $3);
                                      } }
     | expression "==" expression   { if(errores == 0){
                                        $$ = expresion_rel("seq", $1, $3);
                                      } }
     | expression "!=" expression   { if(errores == 0){
                                        $$ = expresion_rel("sne", $1, $3);
                                      } }
     | "(" error ")"  { }
     ;

%%