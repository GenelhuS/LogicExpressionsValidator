#---------------------------------------------------------------------
# Arquivo	: Makefile
# Conteúdo	: compilar o programa vetop
# Autor		: Wagner Meira Jr. (meira@dcc.ufmg.br)
# Histórico	: 2022-04-02 - arquivo criado
#---------------------------------------------------------------------
# Opções	: make all - compila tudo e executa exemplo
#		: make clean - remove objetos e executável
#---------------------------------------------------------------------

CC = gcc
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/main.o $(OBJ)/functions.o 
HDRS = $(INC)/functions.h 
CFLAGS = -Wall -c -I$(INC)

EXE = $(BIN)/main

all:  $(EXE)
	$(EXE) 1 5
	$(EXE) 2 5
	$(EXE) 3 5
	$(EXE) 4 5

$(BIN)/main: $(OBJS)
	$(CC) -pg -o $(BIN)/main $(OBJS) $(LIBS)

$(OBJ)/main.o: $(HDRS) $(SRC)/main.c
	$(CC) -pg $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.c 

$(OBJ)/functions.o: $(HDRS) $(SRC)/functions.c
	$(CC) -pg $(CFLAGS) -o $(OBJ)/functions.o $(SRC)/functions.c 
	
clean:
	rm -f $(EXE) $(OBJS) gmon.out
