SRC_DIR=src
INCLUDE_DIR=include
BUILD_DIR=build
TEST_DIR=tests

SRC=$(SRC_DIR)/main.c $(SRC_DIR)/listaSimbolos.c $(SRC_DIR)/listaCodigo.c $(SRC_DIR)/microC_utils.c
BISON_SRC=$(SRC_DIR)/microC.y
FLEX_SRC=$(SRC_DIR)/microC.l
BISON_OUT=$(BUILD_DIR)/microC.tab.c $(BUILD_DIR)/microC.tab.h
LEX_OUT=$(BUILD_DIR)/lex.yy.c

.PHONY: all clean run1 run2 run3 run4 run5 run6

all: microC

microC: $(LEX_OUT) $(BUILD_DIR)/microC.tab.c $(SRC)
	gcc -I$(INCLUDE_DIR) -I$(BUILD_DIR) $(LEX_OUT) $(BUILD_DIR)/microC.tab.c $(SRC) -lfl -o microC

$(LEX_OUT): $(FLEX_SRC) $(BUILD_DIR)/microC.tab.h
	flex -o $@ $<

$(BUILD_DIR)/microC.tab.h $(BUILD_DIR)/microC.tab.c: $(BISON_SRC)
	bison -d -v -o $(BUILD_DIR)/microC.tab.c $(BISON_SRC)

clean:
	rm -f $(LEX_OUT) microC $(BUILD_DIR)/microC.tab.* $(BUILD_DIR)/microC.output

run1: microC
	./microC $(TEST_DIR)/test1.txt

run2: microC
	./microC $(TEST_DIR)/test2.txt

run3: microC
	./microC $(TEST_DIR)/test3.txt

run4: microC
	./microC $(TEST_DIR)/test4.txt

run5: microC
	./microC $(TEST_DIR)/test5.txt

run6: microC
	./microC $(TEST_DIR)/test6.txt

run-while: microC
	./microC $(TEST_DIR)/test-while.txt

run-do-while: microC
	./microC $(TEST_DIR)/test-do-while.txt