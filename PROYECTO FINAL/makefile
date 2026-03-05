lexico : lex.yy.c main.c
	gcc lex.yy.c main.c -lfl -o lexico

lex.yy.c : microC.l microC.h
	flex microC.l

clean : 
	rm -f lex.yy.c lexico

run : lexico entrada.txt
	./lexico entrada.txt
