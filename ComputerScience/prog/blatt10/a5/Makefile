CC=gcc
CFLAGS=-I. -Wall -Werror -g -std=c99
DEPS= a5.h
OBJ= a5.o func.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

a5: $(OBJ)
	gcc -o $@ $^ $(CFLAGS)