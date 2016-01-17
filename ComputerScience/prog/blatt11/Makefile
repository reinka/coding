CC=gcc
CFLAGS=-I. -Wall -Werror -g -std=c99
DEPS= address.h
OBJ= menu.o address.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

menu: $(OBJ)
	gcc -o $@ $^ $(CFLAGS)