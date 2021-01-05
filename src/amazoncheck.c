#include <stdio.h>
#include <stdlib.h>
// TAKES THE COORDINATES OF THE AMAZON, THE BOARD ITSELF, AND THE SIZE OF THE BOARD TO CHECK WHETHER THE AMAZON STAYS ON THE BORDER OF THE BOARD
int isAmazonAvaiable(int x, int y, Tile **board, int size)
{   
    if(x == 1) {
        if(y == 1) {
            if (board[y+1][x+1].occupation != 0 && board[y+1][x].occupation != 0 && board[y][x+1].occupation != 0) {
                return 0;
            }
            return 1;
        }
        else if (y == size) {
            if (board[y-1][x+1].occupation != 0 && board[y-1][x].occupation != 0 && board[y][x+1].occupation != 0) {
                return 0;
            }
            return 1;
        }
        else if (board[y+1][x+1].occupation != 0 && board[y][x+1].occupation != 0 && board[y-1][x+1].occupation != 0 && board[y+1][x].occupation != 0 && board[y-1][x].occupation != 0) {
                return 0;
            }
            return 1;
    }
    if(x == size) {
        if(y == 1) {
            if (board[y+1][x-1].occupation != 0 && board[y+1][x].occupation != 0 && board[y][x-1].occupation != 0) {
                return 0;
            }
            return 1;
        }
        else if (y == size) {
             if (board[y-1][x-1].occupation != 0 && board[y-1][x].occupation != 0 && board[y][x-1].occupation != 0) {
                return 0;
            }
            return 1;
        }
        else if (board[y+1][x-1].occupation != 0 && board[y+1][x].occupation != 0 && board[y][x-1].occupation != 0 && board[y-1][x-1].occupation != 0 && board[y-1][x].occupation != 0) {
                return 0;
            }
            return 1;
    }
    if(y == 1) {
        if(x != 1 && x != size) {
            if (board[y][x-1].occupation != 0 && board[y+1][x-1].occupation != 0 && board[y][x+1].occupation != 0 && board[y+1][x+1].occupation != 0 && board[y][x+1].occupation != 0) {
                return 0;
            }
            return 1;
        }
        
    }
    if(y == size) {
        if(x != 1 && x != size) {
            if (board[y][x-1].occupation != 0 && board[y-1][x-1].occupation != 0 && board[y-1][x].occupation != 0 && board[y-1][x+1].occupation != 0 && board[y][x+1].occupation != 0) {
                return 0;
            }
            return 1;
        } 
    }
    else if (board[y+1][x-1].occupation != 0 && board[y+1][x].occupation != 0 && board[y+1][x+1].occupation != 0 && board[y][x+1].occupation != 0 && board[y-1][x+1].occupation != 0 && board[y-1][x].occupation != 0 && board[y-1][x-1].occupation != 0 && board[y][x-1].occupation != 0) {
                return 0;
            }
            return 1;
   
}



