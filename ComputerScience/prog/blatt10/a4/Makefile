CC=gcc
CFLAGS=-I. -g -Wall -Werror -std=c99
DEPS = a4.h
OBJ = a4.o func.o 

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

a4: $(OBJ)
	gcc -o $@ $^ $(CFLAGS)