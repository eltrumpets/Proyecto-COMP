%{
    /* Código verbattim, es decir, codigo literal */
    #include <stdio.h>  
    #include <stdlib.h>
    #include "microC.tab.h"
    int inicio_comentario = 0;
    #define MAX_ENTERO 2147483648
    int contador_error = 0;
%}

/* Definiciones de macros de expresiones regulares */

L       [a-zA-Z_]
D       [0-9]
panico  [^a-zA-Z_0-9+\-*/ /; \t\n\r\"(){}]+

/* Opciones de flex */
%option yylineno

/* Condición de contexto para comentarios multilínea */
%x comentario

%%

 /* Expresiones regulares de espacios en blanco y comentarios */
[ \n\r\t]+          { }
"//".*              { }
"/*"                { BEGIN(comentario); 
                      inicio_comentario = yylineno;
                      yymore(); //Para que no borre la variable yytext
                    }
<comentario>.|\n    { yymore();}
<comentario>"*/"    { BEGIN(INITIAL); }
<comentario><<EOF>> { printf("Comentario desde %d sin cerrar al final\n", inicio_comentario); 
                      return 0;
                    }

 /* Expresiones regulares de tokens */

"print"         { return PRI; }
"void"          { return VOI; }
"var"           { return VAR; }
"const"         { return CON; }
"int"           { return INT; }
"if"            { return IFF; }
"else"          { return ELS; }
"while"         { return WHI; }
"read"          { return REA; }
 /* Entre llaves para poner macros*/
{L}({L}|{D})*   { 
                  if(yyleng > 32){
                    contador_error++;
                    printf("Identificador %s que excede el máximo de caracteres en la linea %d\n", yytext, yylineno);
                  }
                  yylval.str = strdup(yytext);
                  return IDE; 
                }
"="             { return IGU; }
"+"             { return SUM; }
"-"             { return RES; }
"*"             { return MUL; }
"/"             { return DIV; }
"{"             { return COI; }
"}"             { return COD; }
","             { return COM; }
";"             { return PYC; }
"("             { return PAI; }
")"             { return PAD; }

{D}+            { 
                  long long entero = strtoll(yytext, NULL, 10);
                  if(entero > MAX_ENTERO){
                    printf("Entero supera el máximo en línea %d: %s\n",
                            yylineno, yytext);
                    contador_error++;
                  }
                  yylval.num = entero;
                  return NUM; 
                              }
\"([^"\n\\]|\\["ntr\\])*\"   { int len = strlen(yytext);
    yylval.str = malloc(len - 1);
    strncpy(yylval.str, yytext + 1, len - 2);
    yylval.str[len - 2] = '\0';
    return CAD; }
\"([^"\n\\]|\\[\"ntr\\])*     { printf("Cadena de caracteres no cerrada en línea %d: %s\n", yylineno, yytext); }

 /* Expresion regular de errores */
{panico}               { printf("Error en linea %d: %s\n", yylineno, yytext);}

%%

