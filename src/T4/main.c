#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Board.h"
#include "placement.h"


int numOfPlayers, numOfAmazons, size_x, size_y, x, y, numOfTiles;
char direction[15];


int main()
{
    printf("\n");
    printf("-WELCOME TO THE GAME OF AMAZONS-\n\n");
    //Input of the number of amazons and players

    /*
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
    */

    printf("Input the board dimensions\n");
    printf ("x: ");
    scanf ("%d", &size_x);
    printf ("y: ");
    scanf ("%d", &size_y);
    printf("\n");

    //Initializing the board array
    Tile **board;
    board = (Tile**) malloc(size_x  * sizeof(Tile));
    for (int i = 0; i < size_x; i++)
    {
        board[i] = (Tile*) malloc(size_y * sizeof(Tile));
    }

    srand(time(NULL));

    randomizeBoard(board, size_x, size_y);

    typedef struct {
        int player = 0;
        int points = 0;
    } Score;

    //Initializing the Scoreboard
    Score *scoreBoard;
    scoreBoard = (Score*) malloc(/*numOfPlayers*/ 2 * sizeof(Score));

    printBoard(board, size_x, size_y);

    /* PLACEMENT PHASE */
    for(int i = 0; i < numOfAmazons; i++) {
        printf("%d amazons left");
        for(int j = 0; j < numOfPlayers; j++) {
            printf("Turn of player number %d" , (j+1));
            placement(board , j);
            printBoard(board , size_x, size_y);
        }
    }

    return 0;
}