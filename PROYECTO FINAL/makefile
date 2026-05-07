microC : lex.yy.c microC.tab.c main.c listaSimbolos.c listaCodigo.c microC_utils.c
	gcc lex.yy.c microC.tab.c main.c listaSimbolos.c listaCodigo.c microC_utils.c -lfl -o microC

lex.yy.c : microC.l microC.tab.h
	flex microC.l

microC.tab.h microC.tab.c : microC.y
	bison -d -v microC.y
	
clean : 
	rm -f lex.yy.c microC microC.tab.*

run1 : microC test1.txt
	./microC test1.txt

run2 : microC test2.txt
	./microC test2.txt

run3 : microC test3.txt
	./microC test3.txt

run4 : microC test4.txt
	./microC test4.txt

run5 : microC test5.txt
	./microC test5.txt