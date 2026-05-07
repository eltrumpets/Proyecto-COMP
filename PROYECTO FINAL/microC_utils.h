#ifndef MICROC_UTILS_H
#define MICROC_UTILS_H

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

extern Lista l;
extern int numCadena;
extern int contador_etiq;
extern Tipo t;
extern ListaC codigoTotal;
extern bool registros[10];

void yyerror(const char *msg);
void comprobar_division(ListaC expre);
void declarar_id(char *id, Tipo t);
void imprimirLS(Lista l);
void declarar_cadena(char *cadena, Tipo t);
void verificar_id(char *id, int esLectura);
void inicializarRegs();
char *obtenerReg();
void liberarReg(char *reg);
ListaC expresion_num(char *num);
ListaC expresion_id(char *id);
ListaC expresion_bin(char *op, ListaC expr1, ListaC expr2);
ListaC expresion_rel(char *op, ListaC expr1, ListaC expr2);
char *nuevaEtiqueta();
void imprimirLC(ListaC codigo);
ListaC statement_while(ListaC expr, ListaC stat);
ListaC statement_if(ListaC expr, ListaC stat);
ListaC statement_if_else(ListaC expr, ListaC stat_if, ListaC stat_else);
ListaC statement_do_while(ListaC stat, ListaC expr);
ListaC genCodigo_sw(ListaC expr, char *ide);
ListaC genCodigo_print(ListaC expr);
ListaC genCodigo_printCAD(char* cad);
ListaC genCodigo_read(ListaC lista_leida, char* ide);

#endif // MICROC_UTILS_H
