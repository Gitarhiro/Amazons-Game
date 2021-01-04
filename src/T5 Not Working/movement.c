#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "movement.h"
#include "board.h"
    
    /*for (int i = 1; i <= numOfPlayers; i++) {
    
    //removing an amazon from his previous tile
    board[x][y].occupation = 0;

    //moving an amazon to a different tile
    if(strcmp(direction, "UP") == 0)
    {
        if(board[x][y - numOfTiles].occupation == 0) {
            board[x][y - numOfTiles].occupation = player_id;
        }

        else {
            printf("Move is invalid.");
        }

        //using artefact
        
    }

    else if(strcmp(direction, "DOWN")==0) {
        if(board[x][y + numOfTiles].occupation == 0) {
            board[x][y + numOfTiles].occupation = player_id;
        }
        
        else {
            printf("Move is invalid.");
        }
    }
    else if(strcmp(direction, "LEFT")==0) {
        if(board[x - numOfTiles][y].occupation == 0) {
            board[x - numOfTiles][y].occupation = player_id;
        }

        else {
            printf("Move is invalid.");
        }
    }
    else if(strcmp(direction, "RIGHT")==0) {
        if(board[x + numOfTiles][y].occupation == 0) {
            board[x + numOfTiles][y].occupation = player_id;
        }

        else {
            printf("Move is invalid.");
        }
    }
    else if(strcmp(direction, "UPLEFT")==0) {
        if(board[x - numOfTiles][y - numOfTiles].occupation == 0) {
            board[x - numOfTiles][y - numOfTiles].occupation = player_id;
        }

        else {
            printf("Move is invalid.");
        }
        
    }

    else if(strcmp(direction, "UPRIGHT")==0) {
        if(board[x + numOfTiles][y - numOfTiles].occupation == 0) {
            board[x + numOfTiles][y - numOfTiles].occupation = player_id;
        }
        else {
            printf("Move is invalid.");
        }
    }

    else if(strcmp(direction, "DOWNLEFT")==0) {
        if(board[x - numOfTiles][y + numOfTiles].occupation == 0) {
            board[x - numOfTiles][y + numOfTiles].occupation = player_id;
        }
        else {
            printf("Move is invalid.");
        }
    }

    else if(strcmp(direction, "DOWNRIGHT")==0) {
        if(board[x + numOfTiles][y + numOfTiles].occupation == 0) {
            board[x + numOfTiles][y + numOfTiles].occupation = player_id;
        }

        else {
                printf("Move is invalid.");
            }
        }
    }
}*/

/*void moveAmazon(int numOfPlayers, int numOfAmazons, int x, int y, int numOfTiles, char direction[], Tile **board) {

    for (int i = 1; i <= numOfPlayers; i++) {
        printf("Turn of player number %d\n" , i);

        for (int j = 0; j < numOfAmazons; j++) {
            printf("%d amazon(s) left to move\n\n", numOfAmazons - j);

            printf("Input Location of Amazon that you wish to move\n");

            int x1, y1, r;
            
            while (1) {
                r = 0;
                while (r == 0) {
                    printf("\nx: ");
                    r=scanf("%d" ,&x);
                    if(board[x1][y1].occupation != j) {
                        printf("Wrong input, enter a location where your Amazon is present: \n");
                        r=0;
                    }
                while(getchar() != '\n');
            }
        
            r = 0;
            while (r == 0) {
                printf("y: ");
                r=scanf("%d" ,&y);
                if(r==0 || y < 0 || y > numOfTiles ) {
                    printf("Wrong input, give another positive number in the range: \n");
                    r=0;
                }
                while(getchar()!='\n');
            }
        
            if(board[x1][y1].occupation != j) {
                printf("Wrong input, enter a location where your Amazon is present: \n");
            }
        }

        else printf("\nInvalid placement. Try again.\n");
    }
        }
    }*/

void moveAmazon(int numOfPlayers, int numOfTiles, int numOfAmazons, Tile **board, Score *scoreBoard) {

    

        for (int j = 0; j < numOfAmazons; j++) {

            printf("%d amazon(s) left to move\n\n", numOfAmazons - j);
            printf("Enter Coordinates of Amazon that you want to move\n");

            int x1, y1, distance;

            while (1) {
                printf("X: ");
                scanf("%d\n", &x1);

                printf("y: ");
                scanf("%d\n", &y1);

                if(board[x1][y1].occupation != j) {
                    printf("Wrong input, enter a location where your Amazon is present\n");
                    continue;
                }

                else {
                    break;
                }
            }

            char direction[3];

            while (1) {
            
                printf("Enter Direction to move\nNorth: N\nSouth: S\nEast: E\nWest: W\nNorthEast: NE\nNorthWest: NW\nSouthEast: SE\nSouthWest: SW\n\nDirection: ");
                scanf("%s", direction[3]);

                printf("Enter number of blocks to move in specified direction");
                scanf("%d", &distance);

                if(direction[3] != ("N\0" || "S\0" || "E\0" || "W\0" || "NE\0" || "NW\0" || "SE\0" || "SW\0")) {
                    printf("Invalid direction");
                    continue;
                }

                else {
                    break;
                }
            }

            board[x1][y1].occupation = 0;



            if (direction[3] == "N\0") {
                board[x1][y1 - distance].occupation = i;

                scoreBoard[i] += board[x1][y1 - distance].score;

                board[x1][y1 - distance].score = 0;
            }
            
        }
return 0;
}