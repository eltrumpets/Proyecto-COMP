microC : lex.yy.c microC.tab.c main.c listaSimbolos.c listaCodigo.c
	gcc lex.yy.c microC.tab.c main.c listaSimbolos.c listaCodigo.c -lfl -o microC

lex.yy.c : microC.l microC.tab.h
	flex microC.l

microC.tab.h microC.tab.c : microC.y
	bison -d -v microC.y
	
clean : 
	rm -f lex.yy.c microC microC.tab.*

run1 : microC entrada.txt
	./microC entrada.txt

run2 : microC entrada2.txt
	./microC entrada2.txt

run3 : microC test1.txt
	./microC test1.txt

run4 : microC test4.txt
	./microC test4.txt