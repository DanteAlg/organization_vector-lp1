# Compiler
CC = g++

INC = ./include
SRC = ./src
OBJ = ./build
BIN = ./bin

CPPFLAGS = -O0 -Wall -pedantic -std=c++11 -I$(INC)
OBJECTS = $(OBJ)/date.o $(OBJ)/employer.o $(OBJ)/organization.o $(OBJ)/main.o

PROG = $(BIN)/organization

all: $(OBJECTS)
	$(CC) $(CPPFLAGS) -o $(PROG) $(OBJECTS)

$(OBJ)/date.o: $(INC)/date.h
	$(CC) $(CPPFLAGS) -c $(SRC)/date.cpp -o $@

$(OBJ)/employer.o: $(INC)/employer.h $(OBJ)/date.o
	$(CC) $(CPPFLAGS) -c $(SRC)/employer.cpp -o $@

$(OBJ)/organization.o: $(INC)/organization.h $(OBJ)/employer.o $(OBJ)/date.o
	$(CC) $(CPPFLAGS) -c $(SRC)/organization.cpp -o $@

$(OBJ)/main.o: $(OBJ)/organization.o
	$(CC) $(CPPFLAGS) -c $(SRC)/main.cpp -o $@

clean:
	rm -f $(PROG) $(OBJECTS)
