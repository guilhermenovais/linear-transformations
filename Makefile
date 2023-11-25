#---------------------------------------------------------------------
# Arquivo	: Makefile
# Conteúdo	: compilar o calculador de tranformações lineares
# Autor		: Guilherme Novais de Souza
# Histórico	: 2023-11-25 arquivo criado
#---------------------------------------------------------------------
# Opções	: make all - compila tudo e executa o exemplo
#			: make clean - remove objetos e executável
#			: make test - compila tudo e executa o teste com o
#			  valgrind e o gdb
#---------------------------------------------------------------------

CC = g++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/matriz.o $(OBJ)/jogo.o $(OBJ)/seg_tree.o $(OBJ)/vetor.o $(OBJ)/main.o
HDRS = $(INC)/matriz.hpp $(INC)/jogo.hpp $(INC)/seg_tree.hpp $(INC)/vetor.hpp
CFLAGS = -c -g -I $(INC)

EXE = $(BIN)/tp3.out

mkdir:
	[ -d obj ] || mkdir obj
	[ -d bin ] || mkdir bin

all: mkdir $(EXE)

$(EXE): $(OBJS)
	$(CC) -o $(EXE) $(OBJS) $(LIBS)

$(OBJ)/matriz.o: $(HDRS) $(SRC)/matriz.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/matriz.o $(SRC)/matriz.cpp

$(OBJ)/jogo.o: $(HDRS) $(SRC)/jogo.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/jogo.o $(SRC)/jogo.cpp

$(OBJ)/seg_tree.o: $(HDRS) $(SRC)/seg_tree.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/seg_tree.o $(SRC)/seg_tree.cpp

$(OBJ)/vetor.o: $(HDRS) $(SRC)/vetor.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/vetor.o $(SRC)/vetor.cpp

$(OBJ)/main.o: $(HDRS) $(SRC)/main.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.cpp 
	
clean:
	rm -f $(EXE) $(OBJS) gmon.out

run: all
	./bin/tp3.out

test: all
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./bin/tp3.out < teste.txt
	gdb ./bin/tp3.out
