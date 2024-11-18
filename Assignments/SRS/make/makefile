CC = gcc
CFLAGS = -Wall -pthread -I../inc
TFLAGS = -pthread
SRC = ../src
INC = ../inc
OBJ = ../obj

TARGET = ../bin/student_import

all: $(TARGET)

$(TARGET):  $(OBJ)/main.o $(OBJ)/student.o

	$(CC)  $(OBJ)/main.o $(OBJ)/student.o  -o $(TARGET) $(TFLAGS)

$(OBJ)/main.o: $(SRC)/main.c $(INC)/student.h $(INC)/common.h
	$(CC) $(CFLAGS) -c $(SRC)/main.c -o $(OBJ)/main.o

$(OBJ)/student.o: $(SRC)/student.c $(INC)/student.h $(INC)/common.h
	$(CC) $(CFLAGS) -c $(SRC)/student.c -o $(OBJ)/student.o


clean:
	rm -rf $(OBJ) $(TARGET)



