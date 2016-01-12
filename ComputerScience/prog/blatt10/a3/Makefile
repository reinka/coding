CC=gcc
CFLAGS=-I. -Wall -Werror -g -std=c99
DEPS= a3.h
OBJ= a3.o func.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

a3: $(OBJ)
	gcc -o $@ $^ $(CFLAGS)