#ifndef A4_H
#define A4_H
#include <sys/ioctl.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#define ROW 40
#define COL 160
#define PROPORTION 0.2
#endif

void clear_terminal();
int get_current_terminal_rows();
int get_current_terminal_columns();
void initialize_board(int board[][COL]);
int adjust_width(int celPos, int neighbourPos);
int adjust_height(int celPos, int neighbourPos);
int number_of_neighbours(int board[][COL], int rowCoord, int colCoord);
void next_state(int board[][COL], int rowCoord, int colCoord);
void update_board(int board[][COL], int newBoard[][COL]);
void print_board(int board[][COL]);

