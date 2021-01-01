#include <stdio.h>
#include <stdlib.h>
#include "board.h"

void randomizeBoard (Tile **board, int x)
{
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < x; j++)
        {
            board[i][j].score = rand() % 6;
            board[i][j].artefact = rand() % 4;
            board[i][j].occupation = 0;
        }
    }
}

void placement(Tile **board, int j, int dimensions){
    int x,y,r;
    while (1) {
        r=0;
        while (r==0) {
        printf("\nx: ");
        r=scanf("%d" ,&x);
        if(r==0 || x < 0 || x > dimensions ) 
        {
            printf("Wrong input, give another positive number in the range: \n");
            r=0;
        }
        while(getchar()!='\n');
    }
    r=0;
    while (r==0) {
        printf("\ny: ");
        r=scanf("%d" ,&y);
        if(r==0 || y < 0 || y > dimensions ) 
        {
            printf("Wrong input, give another positive number in the range: \n");
            r=0;
        }
        while(getchar()!='\n');
    }
        
        if(board[x][y].occupation == 0) {
            board[x][y].occupation = j;
            break;
        }
        else printf("\nInvalid placement. Try again.\n");
    }    
}

void printBoard(Tile **board, int x)
{
    printf("    ");

    for (int k = 0; k < x; k++) {
        printf("%d ", k);
    }

    printf("\n    ");

    for (int k = 0; k < x; k++) {
        printf("- ");
    }

    printf("\n");

    for (int i = 0; i < x; i++) {
        printf("%d | ", i);
        for (int j = 0; j < x; j++)
        {
            if (board[i][j].occupation == 0) {
                printf("%c", 254);
            }

            else if (board[i][j].occupation == 9) {
                printf("%c", 92);
            }

            else {
                printf("%d", board[i][j].occupation);
            }
            printf(" ");
        }
        printf("\n");
    }
}