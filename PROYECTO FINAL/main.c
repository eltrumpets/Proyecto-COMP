#include <stdio.h>
#include <stdlib.h>
extern char *yytext;
extern int yylex();
extern FILE *yyin;

int errores = 0;
int main(int argc, char * argv[]){
    int token;

    if (argc != 2){
        printf("Uso: %s fichero\n", argv[0]);
        exit(1);
    }
    yyin = fopen(argv[1],"r");
    if(yyin == NULL){
        printf("No se puede abrir %s\n", argv[1]);
        exit(2);
    }

    while((token = yylex()) != 0){
        printf("Token: <%d,%s>\n", token, yytext);
        /* yytext nos pone cual es el lexema de cada token */
    }

}