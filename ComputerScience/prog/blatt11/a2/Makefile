CC=gcc
CFLAGS=-I. -Wall -Werror -g -std=c99
DEPS= address.h
OBJ= a2.o address.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

a2: $(OBJ)
	gcc -o $@ $^ $(CFLAGS)