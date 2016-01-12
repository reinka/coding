//
//  main.c
//  a4.c
//
//  Created by Andrei Poehlmann on 06/01/16.
//  Copyright © 2016 Computer Science. All rights reserved.
//
#include "a4.h"


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
        
        usleep(50000);
    }
    
    return EXIT_SUCCESS;
}
