#include <stdio.h>
#include <stdlib.h>

void printBoard(int board[][][]) {
    for (int d=0;d<x;d++) {
        printf("\n");
        for (int e=0;e<y;e++) {
            printf(" ");
            for (int f=0;f<3;f++) {
                printf("%d", board[d][e][f]);
            }
        }
    }
}
