//
//  main.c
//  a4.c
//
//  Created by Andrei Poehlmann on 06/01/16.
//  Copyright © 2016 Computer Science. All rights reserved.
//
#include <sys/ioctl.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#define ROW 40
#define COL 120
#define PROPORTION 0.4

/**
 * clears the current terminal
 */
void clear_terminal(){
    system ("clear");
}

/*
 * gets the number of rows of the current terminal
 */
int get_current_terminal_rows(){
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    return w.ws_row;
}

/*
 * gets the number of columns of the current terminal
 */
int get_current_terminal_columns(){
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    return w.ws_col;
}

/*
 *initializes game board
 */
void initialize_board(int board[][COL]){
    srand((unsigned int) time(NULL));
    int numberOfLivingCells = PROPORTION * COL * ROW;
    
    /*
     *fill board with 0 = dead cells
     */
    
    for (int i = 0; i < ROW; i++)
        for(int j = 0; j < COL; j++){
            board[i][j] = 0;
        }
    
    /*
     *get x and y coords for living cells = 1, randomly
     */
    
    for (int i = 0; i < numberOfLivingCells; i++) {
        int x_coord = rand() % ROW, y_coord = rand() % COL;
        board[x_coord][y_coord] = 1;
    }
}

/*
 *adjust width in case neighbour goes beyond the left/right margin
 */
int adjust_width(int celPos, int neighbourPos){
    
    neighbourPos += celPos;
    if (neighbourPos < 0) {
        neighbourPos += COL;
    }
    else if (neighbourPos > COL - 1) {
        neighbourPos -= COL;
    }
    
    return neighbourPos;
}

/*
 *adjust height in case neighbour goes beyond the top/bottom margin
 */
int adjust_height(int celPos, int neighbourPos) {
    
    neighbourPos += celPos;
    if (neighbourPos < 0) {
        neighbourPos += ROW;
    }
    else if (neighbourPos > ROW - 1) {
        neighbourPos -= ROW;
    }
    
    return neighbourPos;
}

/*
 *gets the number of neighbours given a specific cell
 */
int number_of_neighbours(int board[][COL], int rowCoord, int colCoord){
    int count = 0;
    
    /*circle around cell*/
    
    for (int row = -1; row <= 1; row++) {
        for (int col = -1; col <= 1; col++) {
            
            /*exclude case where row = col = 0 (-> position of the cell being circled)*/
            
            if (row || col) {
                
                /*count only living neighbours (value = 1)*/
                
                if (board[adjust_height(rowCoord, row)][adjust_width(colCoord, col)]) {
                    count++;
                }
            }
        }
    }
    
    return count;
}

/*
 *calculate next cell state
 */
void next_state(int board[][COL], int rowCoord, int colCoord){
    
    char neighbours = number_of_neighbours(board, rowCoord, colCoord);
    
    
    
    /*decide future state according to the rules*/
    
    switch (neighbours) {
        case 2:     //this state depends on the current one, though it's irrelevant with the current method
            if (board[rowCoord][colCoord]) {
                board[rowCoord][colCoord] = 1;
            }
            break;
        case 3:     //this state is independent of the current one, will always lead to 1
            board[rowCoord][colCoord] = 1;
            break;
        default:    //every other state ends with death
            board[rowCoord][colCoord] = 0;
            break;
    }
}

/*
 *update board cells
 */
void update_board(int board[][COL], int newBoard[][COL]){
    
    int updatedBoard[ROW][COL];
    
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL ; j++) {
            next_state(newBoard, i, j);
            updatedBoard[i][j] = newBoard[i][j];
            newBoard[i][j] = board[i][j];
        }
    }
    
    /*copy updated board into the old one*/
    
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            newBoard[i][j] = updatedBoard[i][j];
        }
    }
    
}

void print_board(int board[][COL]) {
    //int rows = get_current_terminal_rows();
    //int cols = get_current_terminal_columns();
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            printf("%c", board[i][j] ? '#' : ' ');
        }
        puts("");
    }
}

int main(int argc, char **argv){
    int board[ROW][COL], newBoard[ROW][COL];
    
    
    initialize_board(board);
    
    /*copy board into the new one*/
    
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            newBoard[i][j] = board[i][j];
        }
    }
    
    for (int i = 0; i < 100000; i++) {

        clear_terminal();
        
        if (i % 2) {
            update_board(newBoard, board);
            print_board(newBoard);
        }
        else{
            update_board(board, newBoard);
            print_board(board);
        }
        
        usleep(1000);
    }
    
    return EXIT_SUCCESS;
}
