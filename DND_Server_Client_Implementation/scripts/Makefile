CC = gcc
CFLAGS = -Wall -g
INCLUDE_FLAGS = -I../inc

SRC_DIR = ../src
OBJ_DIR = ../obj
BIN_DIR = ../bin
EXC = $(BIN_DIR)/server $(BIN_DIR)/client

SERVER_SRC_FILES = $(SRC_DIR)/server.c
SERVER_OBJ_FILES = $(OBJ_DIR)/server.o

CLIENT_SRC_FILES = $(SRC_DIR)/client.c
CLIENT_OBJ_FILES = $(OBJ_DIR)/client.o
all: $(EXC)
$(BIN_DIR)/server: $(SERVER_OBJ_FILES)
	$(CC) $(SERVER_OBJ_FILES) -o $(BIN_DIR)/server -pthread

$(BIN_DIR)/client: $(CLIENT_OBJ_FILES)
	$(CC) $(CLIENT_OBJ_FILES) -o $(BIN_DIR)/client

$(OBJ_DIR)/server.o: $(SRC_DIR)/server.c
	$(CC) $(CFLAGS) $(INCLUDE_FLAGS) -c $(SRC_DIR)/server.c -o $(OBJ_DIR)/server.o

$(OBJ_DIR)/client.o: $(SRC_DIR)/client.c
	$(CC) $(CFLAGS) $(INCLUDE_FLAGS) -c $(SRC_DIR)/client.c -o $(OBJ_DIR)/client.o

clean:
	@echo "Cleaning..."
	rm -rf $(OBJ_DIR)/* $(BIN_DIR)/*

