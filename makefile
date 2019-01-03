############################################################
#         Makefile para el proyecto scrabble jugador
#
# author: Blanca Cano Camarero
# date: enero 2019
# 
# instrucciones básicas:
#  make           para construir todo el proyecto
#  make clear     limpiar archivos no necesarios
#  make exe       ejecutar juego
#  make doxy      genera la documentación
#  make test      ejecuta todos los test 
#
############################################################



########## construcción programa y test de prueba ########

OBJ=./obj/
INCLUDE=./include/
FLAGS=-g -I$(INCLUDE)
DATA=./data/
BIN=./bin/
SRC=./src/

all:  $(BIN)testdiccionario.out $(BIN)testletras.out $(BIN)testia.out $(BIN)testcombinaciones.out 

## ~~~~~~~~~~ binarios de los test ~~~~~~~~~~
$(BIN)testdiccionario.out: $(OBJ)testdiccionario.o $(OBJ)diccionario.o
	g++ $^ -o $@

$(BIN)testletras.out: $(OBJ)testletras.o $(OBJ)letras.o $(OBJ)diccionario.o
	g++ $^ -o $@

$(BIN)testia.out: $(OBJ)testia.o $(OBJ)ia.o  $(OBJ)letras.o $(OBJ)diccionario.o
	g++ -g $^ -o $@

$(BIN)testcombinaciones.out: $(OBJ)testcombinaciones.o $(OBJ)combinaciones.o 
	g++ -g $^ -o $@


## ~~~~~~~~ objetos de los test ~~~~~~~~~~
$(OBJ)testdiccionario.o: $(SRC)testdiccionario.cpp 
	g++ -c $< -o $@ -I$(INCLUDE)

$(OBJ)testletras.o: $(SRC)testletras.cpp
	g++ -c $< -o $@ -I$(INCLUDE)

$(OBJ)testia.o: $(SRC)testia.cpp $(OBJ)ia.o
	g++ -c $< -o $@ -I$(INCLUDE)

$(OBJ)testcombinaciones.o: $(SRC)testcombinaciones.cpp $(OBJ)combinaciones.o
	g++ -c $< -o $@ -I$(INCLUDE)


## ~~~~~~~~~~ objetos esenciales ~~~~~~~~~~ 
$(OBJ)diccionario.o: $(SRC)diccionario.cpp $(INCLUDE)diccionario.h
	g++ -c $< -o $@ -I$(INCLUDE)

$(OBJ)letras.o: $(SRC)letras.cpp $(INCLUDE)letras.h
	g++ -c $< -o $@ -I$(INCLUDE)

$(OBJ)ia.o: $(SRC)ia.cpp $(INCLUDE)ia.h
	g++ -c $< -o $@ -I$(INCLUDE)

$(OBJ)combinaciones.o: $(SRC)combinaciones.cpp $(INCLUDE)combinaciones.h
	g++ -c $< -o $@ -I$(INCLUDE)


################### utilidades ##################
doxygen:
	doxygen configure.doxy 
	firefox ./doc/html/annotated.html &
clear:
	find . -name "*~" -delete
	@rm -r $(OBJ)* $(BIN)* ./doc/html ./doc/latex ./doc/man ./doc/xml

#########    comando para ejecutar test    ##########

valgrind:
	valgrind --leak-check=yes $(BIN)testia.out  < $(DATA)diccionario2.txt

testdiccionario:
	$(BIN)$(MAIN).out < $(DATA)diccionario1000.txt

testletras:
	$(BIN)$@.out ./data/estadisticas.txt ./data/letras.txt < $(DATA)diccionario1000.txt

testia:
	$(BIN)$@.out <  $(DATA)diccionario1000.txt

testcombinaciones:
	$(BIN)$@.out




