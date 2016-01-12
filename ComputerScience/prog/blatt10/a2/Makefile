CC=gcc
CFLAGS=-I. -Wall -Werror -g -std=c99
DEPS= a2.h
OBJ= a2.o func.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

a2: $(OBJ)
	gcc -o $@ $^ $(CFLAGS)