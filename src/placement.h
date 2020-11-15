#include <stdio.h>
#include <stdlib.h>
#include <time.h>/*For Random seeding*/

int generateboard(int x, int y) {
    int board[x][y][3];
    srand(time(NULL));
    
    /*This generates the array*/
    for (int d=0;d<x;d++) {
        for (int e=0;e<y;e++) {
            board[d][e][0] = rand() % 6;
            board[d][e][1] = rand() % 4;
            board[d][e][2] = 0;
        }
    }
    
    /*This prints the Array
      It will be removed once I can figure out how to return the array via the function*/
    for (int d=0;d<x;d++) {
        printf("\n");
        for (int e=0;e<y;e++) {
            printf(" ");
            for (int f=0;f<3;f++) {
                printf("%d", board[d][e][f]);
            }
        }
    }
    
    return 0;
}