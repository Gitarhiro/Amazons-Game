#ifndef TAUCS_H
#define TAUCS_H
#include "assets.h"
#include "movement.h"
#include "placement.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#endif

int main()
{
    //Declaration of all variables
    int numOfPlayers, numOfAmazons, size, x, y, numOfTiles, r=0, canMove,num;
    char direction[15];

    //Title
    printf("\n-WELCOME TO THE GAME OF AMAZONS-\n\n");

    //Inputing the number of players
    while (r == 0)
    {
        printf("Input the number of players\n");
        r=scanf("%d",&numOfPlayers);
        if(r == 0 || numOfPlayers <= 0 )
        {
            printf("Wrong input, input a positive integer: \n");
            r=0;
        }
        while(getchar() != '\n');
    }

    //Inputing the Player names
    char name[numOfPlayers][11];
    for(int i = 0; i < numOfPlayers; i++)
    {
        printf("Enter Player %d's name (max. 12 characters)\n", i+1);
        scanf("%s", name[i]);
    }


    //Inputting the number of Amazons per player
    r=0;
    while (r == 0)
    {
        printf("Input the number of amazons for each player\n");
        r=scanf("%d",&numOfAmazons);
        if(r == 0 || numOfAmazons <= 0 )
        {
            printf("Wrong input, input a positive integer: \n");
            r=0;
        }
        while(getchar() != '\n');
    }

    //Inputing the board dimensions
    r=0;
    while (r == 0)
    {
        printf("Input the board size\n");
        r=scanf("%d",&size);
        if(r == 0 || size <=0 )
        {
            printf("Wrong input, input apositive integer: \n");
            r=0;
        }
        while(getchar() != '\n');
    }
    printf("\n");

    //Initializing the board array
    Tile **board;
    board = (Tile**) malloc(size  * sizeof(Tile));
    for (int i = 0; i < size; i++)
        board[i] = (Tile*) malloc(size * sizeof(Tile));

    //Randomizing the board array
    srand(time(NULL));
    randomizeBoard(board, size);

    //Initializing the Scoreboard
    Score *scoreBoard;
    scoreBoard = (Score*) malloc(numOfPlayers * sizeof(Score));

    //Resetting and first the Scoreboard
    for (int i = 0; i < numOfPlayers; i++)
    {
        scoreBoard[i].points = 0;
    }
    printBoardNoScore(board, size, numOfPlayers);

    //               //
    //PLACEMENT PHASE//
    //               //
    for (int i = 0; i < numOfAmazons; i++)
    {
        for (int j = 0; j < numOfPlayers; j++)
        {
            printf("Turn of %s", name[j]);
            placement(board, j+1, size);
            system("cls");
            printBoardNoScore(board, size, numOfPlayers);
        }
    }



    //              //
    //MOVEMENT PHASE//
    //              //

    system("cls");
    printf("\n\n-MOVEMENT PHASE-\n\n");
    instruction();
    printBoard(board, size, numOfPlayers, name, scoreBoard);
    newMove(board, size);

    int playersAvailableAmazons[numOfPlayers];

    for (int id = 0; id < numOfPlayers; id++)
        playersAvailableAmazons[id] = availableAmazons(id+1, board, size);

    while (endGameCheck(playersAvailableAmazons, numOfPlayers))
    {
        for (int i = 0; i < numOfPlayers; i++)
        {

            while (availableAmazons(i+1, board, size))
            {
                printf("Turn of %s\n", name[i]);
                moveAmazon(i+1, board, size, numOfPlayers, name, scoreBoard, 0, 0, 0);
            }
            newMove(board, size);
            for (int id = 0; id < numOfPlayers; id++)
                playersAvailableAmazons[id] = availableAmazons(id+1, board, size);

        }

    }

    printf("---GAME OVER---\n");

    getchar();
    return 1;
}
