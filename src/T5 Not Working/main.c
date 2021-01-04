#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "board.h"
#include "movement.h"

int main() {
    //Declaration of all variables
    int numOfPlayers, numOfAmazons, size_x, x, y, numOfTiles;
    char direction[6];

    //Title
    printf("\n-WELCOME TO THE GAME OF AMAZONS-\n\n");

    //Inputing the number of players
    printf("Input the number of players\n");
    scanf("%d", &numOfPlayers);

    //Inputing the Player names
    char name[numOfPlayers][11];
    for(int i = 1; i <= numOfPlayers; i++)
    {
        printf("Enter Player %d's name (max. 12 characters)\n", i);
        scanf("%s", name[i]);
    }

    //Inputting the number of Amazons per player
    printf("Input the number of amazons for each player\n");
    scanf("%d", &numOfAmazons);

    //Inputing the board dimensions
    printf("Input the board size\n");
    scanf ("%d", &size_x);
    printf("\n");

    //Initializing the board array
    Tile **board;
    board = (Tile**) malloc(size_x  * sizeof(Tile));
    for (int i = 0; i < size_x; i++) {
        board[i] = (Tile*) malloc(size_x * sizeof(Tile));
    }

    //Randomizing the board array
    srand(time(NULL));
    randomizeBoard(board, size_x);

    //Initializing the Scoreboard
    Score *scoreBoard;
    scoreBoard = (Score*) malloc(numOfPlayers * sizeof(Score));

    printBoard(board, size_x);

    //Placement Phase
    for (int i = 0; i < numOfAmazons; i++) {
        printf("%d amazons left to deploy\n");
        for (int j = 0; j < numOfPlayers; j++) {
            printf("Turn of player number %d" , (j+1));
            placement(board , j+1, size_x);
            printBoard(board , size_x);
        }
    }

    printf("\n\n");
    
    //Movement Phase
        for (int i = 1; i <= numOfPlayers; i++) {
            printf("Turn of player number %d\n" , i+1);
            
            moveAmazon(numOfPlayers, size_x, numOfAmazons, board, scoreBoard);

            printBoard(board , size_x);

            printf("\n");

            if (i == numOfPlayers) {
                i = 1;
            }
        }

return 0;
}