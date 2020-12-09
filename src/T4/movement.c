#include <stdio.h>
#include <stdlib.h>
                                                                          
void moveAmazon(int player_id, int x, int y, int numOfTiles, char direction[], Tile **board)
{
    //removing an amazon from his previous tile
    board[x][y].occupation = 0;

    //moving an amazon to a different tile
    if(strcmp(direction, "UP")==0)
    {
        if(board[x][y - numOfTiles].occupation == 0)                                //checking if the tile an amazon want to move to is unoccupied
        {
            board[x][y - numOfTiles].occupation = player_id;
        }
        else
        {
            printf("Move is invalid.");
        }

        //using artefact
        
    }
    else if(strcmp(direction, "DOWN")==0)
    {
        if(board[x][y + numOfTiles].occupation == 0)                                
        {
            board[x][y + numOfTiles].occupation = player_id;
        }
        else
        {
            printf("Move is invalid.");
        }
    }
    else if(strcmp(direction, "LEFT")==0)
    {
        if(board[x - numOfTiles][y].occupation == 0)                                
        {
            board[x - numOfTiles][y].occupation = player_id;
        }
        else
        {
            printf("Move is invalid.");
        }
    }
    else if(strcmp(direction, "RIGHT")==0)
    {
        if(board[x + numOfTiles][y].occupation == 0)                                
        {
            board[x + numOfTiles][y].occupation = player_id;
        }
        else
        {
            printf("Move is invalid.");
        }
        
    }
    else if(strcmp(direction, "UPLEFT")==0)
    {
        if(board[x - numOfTiles][y - numOfTiles].occupation == 0)                                
        {
            board[x - numOfTiles][y - numOfTiles].occupation = player_id;
        }
        else
        {
            printf("Move is invalid.");
        }
        
    }
    else if(strcmp(direction, "UPRIGHT")==0)
    {
        if(board[x + numOfTiles][y - numOfTiles].occupation == 0)                                
        {
            board[x + numOfTiles][y - numOfTiles].occupation = player_id;
        }
        else
        {
            printf("Move is invalid.");
        }
    }
    else if(strcmp(direction, "DOWNLEFT")==0)
    {
        if(board[x - numOfTiles][y + numOfTiles].occupation == 0)                                
        {
            board[x - numOfTiles][y + numOfTiles].occupation = player_id;
        }
        else
        {
            printf("Move is invalid.");
        }
    }
    else if(strcmp(direction, "DOWNRIGHT")==0)
    {
        if(board[x + numOfTiles][y + numOfTiles].occupation == 0)                                
        {
            board[x + numOfTiles][y + numOfTiles].occupation = player_id;
        }
        else
        {
            printf("Move is invalid.");
        }
    }

}
