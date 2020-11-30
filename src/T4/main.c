#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "placement.h"
#include "movement.h"

//These are dummy variables and functions for now, they will be properly implemented in the next stages

int numOfPlayers, numOfAmazons, x, y, numOfTiles;
int moveAvailable = 1;
int sumOfAvailableMoves = 1;
char direction[15];

//void generateBoard(int x, int y);
//void printBoard();
//void placeAmazon();
//void moveAmazon(int x, int y, int n, char direction [15]);

int main()
{
    printf("\n");
    printf("-WELCOME TO THE GAME OF AMAZONS-\n\n");
    //Input of the number of amazons and players
    printf("Input the number of players\n");
    scanf("%d", &numOfPlayers);

    char name[numOfPlayers][11];

    for (int i = 1; i <= numOfPlayers; i++) //asking for players' names
    {
        printf ("Enter Player %d's name (max. 12 characters)\n", i);
        scanf ("%s", name[i]);
    }

    printf("Input the number of amazons for each player\n");
    scanf("%d", &numOfAmazons);
    printf("Input the board dimensions\n");
    printf ("x: ");
    scanf ("%d", &x);
    printf ("y: ");
    scanf ("%d", &y);
    printf("\n");
    
    // Generate the array
    int board[x][y][3];
    srand(time(NULL));

    for (int d=0;d<x;d++) {
        for (int e=0;e<y;e++) {
            board[d][e][0] = rand() % 6;
            board[d][e][1] = rand() % 4;
            board[d][e][2] = 0;
        }
    }
    
    /* This prints the board*/
    for (int d=0;d<x;d++) {
        printf("\n");
        for (int e=0;e<y;e++) {
            printf(" ");
            for (int f=0;f<3;f++) {
                printf("%d", board[d][e][f]);
            }
        }
    }

    //Placement phase

    printf("-PLACEMENT PHASE-\n\n");

    for (int i = 1; i <= numOfAmazons; i++)
    {
        for (int j = 1; j <= numOfPlayers; j++)
        {
            //printBoard();
            printf ("===%s's turn===\n", name[j]);
            printf ("Enter the coordinates where your amazon %d should be placed\n", i);
            printf ("x: ");
            scanf ("%d", &x);
            printf ("y: ");
            scanf ("%d", &y);
            //placeAmazon();
        }
    }

    //Movement phase

    printf("\n");
    printf("-MOVEMENT PHASE-\n\n");

    printf("Direction options: 'UP', 'LEFT', 'DOWNLEFT', UPRIGHT, ...\n");
    
    while (sumOfAvailableMoves) //check if any player can move
    {
        for (int i = 1; i <= numOfPlayers; i++)
        {
            if (moveAvailable) //check if the player can move
            {
                //printBoard();
                printf("===%s's turn===\n", name[i]);
                printf ("Enter the coordinates of the amazon you want to move\n");
                printf ("x: ");
                scanf ("%d", &x);
                printf ("y: ");
                scanf ("%d", &y);
                printf("Enter the direction: ");
                scanf("%s", direction);
                printf("Enter the amount of tiles it will traverse: ");
                scanf ("%d", &numOfTiles);
                //moveAmazon(x, y, numOfTiles, direction);
            }
        }
    }

    
    return 0;
}
