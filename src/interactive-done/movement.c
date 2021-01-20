#ifndef TAUCS_H
#define TAUCS_H
#include "assets.h"
#endif



void moveAmazon(int player_id, Tile **board, int size, int numOfPlayers, char name[numOfPlayers][11], Score scoreBoard[numOfPlayers], int horse, int hx, int hy)
{
    char direction[15];
    int x, y, numOfTiles, valid = 1, x_axis, y_axis;
    if(!horse)
    {
        printf("Enter the coordinates of the amazon you want to move\n");
        while(1)
        {
            printf("x: ");
            InputCoordinate(&x, size);
            printf("y: ");
            InputCoordinate(&y, size);
            if(board[y][x].occupation == player_id && isAmazonAvaiable(x, y, board, size)==1 && board[y][x].moved == 0) break;
            else printf("Your amazon is not on given tile or cannot move. Input the coordinates again\n");
        }
    }
    if(horse)
    {
        x = hx;
        y = hy;
        if(board[y][x].occupation == player_id && isAmazonAvaiable(x, y, board, size)==1);
        else
        {
            printf("Your amazon cannot move\n");
            return;
        }
    }
    while (1)
    {
        valid = 1;
        printf("Number of tiles the amazon will move: ");
        scanf("%d", &numOfTiles);
        printf("Enter the direction: ");
        scanf("%s", &direction);


        //checking if movement is possible
        if(strcmp(direction, "UP")==0)
        {
            x_axis = 0;
            y_axis = -numOfTiles;

            if (y - numOfTiles < 0)
            {
                valid = 0;
            }
            else
            {
                for(int i = 1; i <= numOfTiles; i++)
                {
                    if(isMovementPossible(x, y - i, board) == 0)
                    {
                        valid = 0;
                    }
                }
            }
        }
        else if(strcmp(direction, "DOWN")==0)
        {
            x_axis = 0;
            y_axis = numOfTiles;

            if (y + numOfTiles > size)
            {
                valid = 0;
            }
            else
            {
                for(int i = 1; i <= numOfTiles; i++)
                {
                    if(isMovementPossible(x, y + i, board) == 0)
                    {
                        valid = 0;
                    }
                }
            }
        }
        else if(strcmp(direction, "LEFT")==0)
        {
            x_axis = -numOfTiles;
            y_axis = 0;

            if (x - numOfTiles < 0)
            {
                valid = 0;
            }
            else
            {
                for(int i = 1; i <= numOfTiles; i++)
                {
                    if(isMovementPossible(x - i, y, board) == 0)
                    {
                        valid = 0;
                    }
                }
            }
        }
        else if(strcmp(direction, "RIGHT")==0)
        {
            x_axis = numOfTiles;
            y_axis = 0;

            if (x + numOfTiles > size)
            {
                valid = 0;
            }
            else
            {
                for(int i = 1; i <= numOfTiles; i++)
                {
                    if(isMovementPossible(x + i, y, board) == 0)
                    {
                        valid = 0;
                    }
                }
            }
        }
        else if(strcmp(direction, "UPLEFT")==0)
        {
            x_axis = -numOfTiles;
            y_axis = -numOfTiles;

            if (x - numOfTiles < 0 || y - numOfTiles < 0)
            {
                valid = 0;
            }
            else
            {
                for(int i = 1; i <= numOfTiles; i++)
                {
                    if(isMovementPossible(x - i, y - i, board) == 0)
                    {
                        valid = 0;
                    }
                }
            }
        }
        else if(strcmp(direction, "UPRIGHT")==0)
        {
            x_axis = numOfTiles;
            y_axis = -numOfTiles;

            if (x + numOfTiles > size || y - numOfTiles < 0)
            {
                valid = 0;
            }
            else
            {
                for(int i = 1; i <= numOfTiles; i++)
                {
                    if(isMovementPossible(x + i, y - i, board) == 0)
                    {
                        valid = 0;
                    }
                }
            }
        }
        else if(strcmp(direction, "DOWNLEFT")==0)
        {
            x_axis = -numOfTiles;
            y_axis = numOfTiles;

            if (x - numOfTiles < 0 || y + numOfTiles > size)
            {
                valid = 0;
            }
            else
            {
                for(int i = 1; i <= numOfTiles; i++)
                {
                    if(isMovementPossible(x - i, y + i, board) == 0)
                    {
                        valid = 0;
                    }
                }
            }
        }
        else if(strcmp(direction, "DOWNRIGHT")==0)
        {
            x_axis = numOfTiles;
            y_axis = numOfTiles;

            if (x + numOfTiles > size || y + numOfTiles > size)
            {
                valid = 0;
            }
            else
            {
                for(int i = 1; i <= numOfTiles; i++)
                {
                    if(isMovementPossible(x + i, y + i, board) == 0)
                    {
                        valid = 0;
                    }
                }
            }
        }
        else
        {
            valid = 0;
        }
        if(valid == 1)
        {
            board[y + y_axis][x + x_axis].occupation = player_id;
            scoreBoard[player_id - 1].points += board[y + y_axis][x + x_axis].score;
            board[y + y_axis][x + x_axis].score = 0;
            board[y + y_axis][x + x_axis].moved = 1;
            board[y][x].moved = 0;
            board[y][x].occupation = 0;
            system("cls");
            printBoard(board, size, numOfPlayers, name, scoreBoard);
            usingArtifact(player_id, x + x_axis, y + y_axis, board, size, numOfPlayers, name, scoreBoard);
            break;
        }
        else
        {
            system("cls");
            printBoard(board, size, numOfPlayers, name, scoreBoard);
            printf("Move is invalid. Make the move again.\n");
            direction[0] = '\0';
        }
    }

}

void usingArtifact(int player_id, int x, int y, Tile **board, int size, int numOfPlayers, char name[numOfPlayers][11], Score scoreBoard[numOfPlayers])
{
    if(board[y][x].artefact == 0)
    {
        printf("There is no artifact. Shoot an arrow now.\n");

        //shooting an arrow
        if (isAmazonAvaiable(x, y, board, size))
        {

            shoot(1, x, y, board, size, numOfPlayers, name, scoreBoard);
        }

        else
        {
            printf("The amazon is blocked. It cannot shoot an arrow.\n");
        }

    }
    else if(board[y][x].artefact == 1)
    {
        //horse
        printf("Amazon found a horse, shoot an arrow and make a move.\n");
        board[y][x].artefact = 0;
        shoot(1, x, y, board, size, numOfPlayers, name, scoreBoard);
        system("cls");
        printBoard(board, size, numOfPlayers, name, scoreBoard);
        printf("Time for another move\n");
        moveAmazon(player_id, board, size, numOfPlayers, name, scoreBoard, 1, x, y);
    }
    else if(board[y][x].artefact == 2)
    {
        //broken arrow
        board[y][x].artefact = 0;
        printf("Amazon found a broken arrow and it cannot shoot.\n");

    }
    else
    {
        //spear
        board[y][x].artefact = 0;
        printf("Amazon found a spear. Shoot a spear now.\n");
        shoot(2, x, y, board, size, numOfPlayers, name, scoreBoard);

    }
}

void shoot(int id, int x, int y, Tile **board, int size, int numOfPlayers, char name[numOfPlayers][11], Score scoreBoard[numOfPlayers])
{
    //id = 1    arrow
    //id = 2    spear
    char direction[15];
    int  numOfTiles, valid = 1, x_axis, y_axis, inBoundaries = 1;
    while (1)
    {
        valid = 1;
        printf("Number of tiles you want to shoot a spear or an arrow: ");
        scanf("%d", &numOfTiles);
        printf("Enter the direction: ");
        scanf("%s", &direction);

        //checking if shot is possible
        if(strcmp(direction, "UP")==0)
        {
            x_axis = 0;
            y_axis = -numOfTiles;

            if (y - numOfTiles < 0)
            {
                inBoundaries = 0;
                valid = 0;
            }
            else
            {
                for(int i = 1; i <= numOfTiles; i++)
                {
                    if(isMovementPossible(x, y - i, board) == 0)
                    {
                        valid = 0;
                    }
                }
            }


        }
        else if(strcmp(direction, "DOWN")==0)
        {
            x_axis = 0;
            y_axis = numOfTiles;

            if (y + numOfTiles > size)
            {
                inBoundaries = 0;
                valid = 0;
            }
            else
            {
                for(int i = 1; i <= numOfTiles; i++)
                {
                    if(isMovementPossible(x, y + i, board) == 0)
                    {
                        valid = 0;
                    }
                }
            }
        }
        else if(strcmp(direction, "LEFT")==0)
        {
            x_axis = -numOfTiles;
            y_axis = 0;

            if (x - numOfTiles < 0)
            {
                inBoundaries = 0;
                valid = 0;
            }
            else
            {
                for(int i = 1; i <= numOfTiles; i++)
                {
                    if(isMovementPossible(x - i, y, board) == 0)
                    {
                        valid = 0;
                    }
                }
            }
        }
        else if(strcmp(direction, "RIGHT")==0)
        {
            x_axis = numOfTiles;
            y_axis = 0;

            if (x + numOfTiles > size)
            {
                inBoundaries = 0;
                valid = 0;
            }
            else
            {
                for(int i = 1; i <= numOfTiles; i++)
                {
                    if(isMovementPossible(x + i, y, board) == 0)
                    {
                        valid = 0;
                    }
                }
            }
        }
        else if(strcmp(direction, "UPLEFT")==0)
        {
            x_axis = -numOfTiles;
            y_axis = -numOfTiles;

            if (x - numOfTiles < 0 || y - numOfTiles < 0)
            {
                inBoundaries = 0;
                valid = 0;
            }
            else
            {
                for(int i = 1; i <= numOfTiles; i++)
                {
                    if(isMovementPossible(x - i, y - i, board) == 0)
                    {
                        valid = 0;
                    }
                }
            }
        }
        else if(strcmp(direction, "UPRIGHT")==0)
        {
            x_axis = numOfTiles;
            y_axis = -numOfTiles;

            if (x + numOfTiles > size || y - numOfTiles < 0)
            {
                inBoundaries = 0;
                valid = 0;
            }
            else
            {
                for(int i = 1; i <= numOfTiles; i++)
                {
                    if(isMovementPossible(x + i, y - i, board) == 0)
                    {
                        valid = 0;
                    }
                }
            }
        }
        else if(strcmp(direction, "DOWNLEFT")==0)
        {
            x_axis = -numOfTiles;
            y_axis = numOfTiles;

            if (x - numOfTiles < 0 || y + numOfTiles > size)
            {
                inBoundaries = 0;
                valid = 0;
            }
            else
            {
                for(int i = 1; i <= numOfTiles; i++)
                {
                    if(isMovementPossible(x - i, y + i, board) == 0)
                    {
                        valid = 0;
                    }
                }
            }
        }
        else if(strcmp(direction, "DOWNRIGHT")==0)
        {
            x_axis = numOfTiles;
            y_axis = numOfTiles;

            if (x + numOfTiles > size || y + numOfTiles > size)
            {
                inBoundaries = 0;
                valid = 0;
            }
            else
            {
                for(int i = 1; i <= numOfTiles; i++)
                {
                    if(isMovementPossible(x + i, y + i, board) == 0)
                    {
                        valid = 0;
                    }
                }
            }
        }
        else
        {
            valid = 0;
        }

        if(id == 2 && board[y + y_axis][x + x_axis].occupation == 0 && inBoundaries)
        {
            board[y + y_axis][x + x_axis].occupation = 9;
            system("cls");
            printBoard(board, size, numOfPlayers, name, scoreBoard);
            printf("Amazon shot a spear.\n");
            break;
        }
        else if(valid)
        {
            board[y + y_axis][x + x_axis].occupation = 9;
            system("cls");
            printBoard(board, size, numOfPlayers, name, scoreBoard);
            printf("Amazon shot an arrow.\n");
            break;
        }
        else
        {
            system("cls");
            printBoard(board, size, numOfPlayers, name, scoreBoard);
            printf("Shot is invalid. Make the shot again.\n");
            direction[0] = '\0';
        }
    }
}

int isAmazonAvaiable(int x, int y, Tile **board, int size)
{
    size--;

    if(x == 0)
    {
        if(y == 0)
        {
            if (board[y+1][x+1].occupation != 0 && board[y+1][x].occupation != 0 && board[y][x+1].occupation != 0)
            {
                return 0;
            }
            return 1;
        }
        else if (y == size)
        {
            if (board[y-1][x+1].occupation != 0 && board[y-1][x].occupation != 0 && board[y][x+1].occupation != 0)
            {
                return 0;
            }
            return 1;
        }
        else if (board[y+1][x+1].occupation != 0 && board[y][x+1].occupation != 0 && board[y-1][x+1].occupation != 0 && board[y+1][x].occupation != 0 && board[y-1][x].occupation != 0)
        {
            return 0;
        }
        return 1;
    }
    if(x == size)
    {
        if(y == 0)
        {
            if (board[y+1][x-1].occupation != 0 && board[y+1][x].occupation != 0 && board[y][x-1].occupation != 0)
            {
                return 0;
            }
            return 1;
        }
        else if (y == size)
        {
            if (board[y-1][x-1].occupation != 0 && board[y-1][x].occupation != 0 && board[y][x-1].occupation != 0)
            {
                return 0;
            }
            return 1;
        }
        else if (board[y+1][x-1].occupation != 0 && board[y+1][x].occupation != 0 && board[y][x-1].occupation != 0 && board[y-1][x-1].occupation != 0 && board[y-1][x].occupation != 0)
        {
            return 0;
        }
        return 1;
    }
    if(y == 0)
    {
        if(x != 0 && x != size)
        {
            if (board[y][x-1].occupation != 0 && board[y+1][x-1].occupation != 0 && board[y][x+1].occupation != 0 && board[y+1][x+1].occupation != 0 && board[y][x+1].occupation != 0)
            {
                return 0;
            }
            return 1;
        }

    }
    if(y == size)
    {
        if(x != 0 && x != size)
        {
            if (board[y][x-1].occupation != 0 && board[y-1][x-1].occupation != 0 && board[y-1][x].occupation != 0 && board[y-1][x+1].occupation != 0 && board[y][x+1].occupation != 0)
            {
                return 0;
            }
            return 1;
        }
    }
    else if (board[y+1][x-1].occupation != 0 && board[y+1][x].occupation != 0 && board[y+1][x+1].occupation != 0 && board[y][x+1].occupation != 0 && board[y-1][x+1].occupation != 0 && board[y-1][x].occupation != 0 && board[y-1][x-1].occupation != 0 && board[y][x-1].occupation != 0)
    {
        return 0;
    }
    return 1;
}

int isMovementPossible(int x, int y, Tile **board)
{
    if(board[y][x].occupation == 0)
    {
        return 1;
    }
    return 0;
}

int availableAmazons(int player_id, Tile **board, int size)
{
    int freeAmazons = 0;

    for (int y = 0; y < size; y++)
        for (int x = 0; x < size; x++)
            if (board[x][y].occupation == player_id)
                if (isAmazonAvaiable(x, y, board, size) && board[x][y].moved == 0)
                    freeAmazons++;

    return freeAmazons;
}

int endGameCheck(int playerCanMove[], int players)
{
    for (int id = 0; id < players; id++)
    {
        if (playerCanMove[id] > 0)
            return 1;
    }

    return 0;
}

void newMove(Tile **board, int size)
{
    for (int x = 0; x < size; x++)
        for (int y = 0; y < size; y++)
            board[x][y].moved = 0;
}

void InputCoordinate(int *a, int range)
{
    int r = 0;
    while (r == 0)
    {
        r=scanf("%d", a);
        if(r == 0 || (*a) < 0 || (*a) > range)
        {
            printf("Wrong input, input a positive integer in given range \n");
            r=0;
        }
        while(getchar() != '\n');
    }
    return ;
}

