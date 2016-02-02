CC=gcc
CFLAGS=-I. -Wall -Werror -g -std=c99
DEPS= array.h
OBJ= main.o array.o
BIN= main

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	gcc -o $@ $^ $(CFLAGS)

.PHONY: clean
clean: 
	rm -rf $(BIN) $(OBJ)