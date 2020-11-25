#include <stdio.h>
#include <stdlib.h>

/* 
    -what if move is not possible?
    -what about using an artifact? is it a separate function?
*/
                                                                              
void moveAmazon(int player_id, int x, int y, int numOfTiles, char direction[], int *score, int *board)
{
    if(strcmp(direction, "UP")==0)
    {
        //removing amazon from his previous spot
        //tile on board[x][y][2] is now unoccupied
        *(((board + x) + y) + 2) = 0;

        //tile on board[x][y-h][2] is now occupied
        *(((board + x) + y - numOfTiles) + 2) = player_id;

        /*adding score from the tile*/
        *(score + player_id) = *(((board + x) + y - numOfTiles) + 0);//how to do it?
        
        /*using the artifact*/
    }
    else if(strcmp(direction, "DOWN")==0)
    {
        *(((board + x) + y) + 2) = 0;
        *(((board + x) + y + numOfTiles) + 2) = player_id;

        /*adding score from the tile*/

        /*using the artifact*/
    }
    else if(strcmp(direction, "LEFT")==0)
    {
        *(((board + x) + y) + 2) = 0;
        *(((board + x - numOfTiles) + y) + 2) = player_id;

        /*adding score from the tile*/

        /*using the artifact*/
    }
    else if(strcmp(direction, "RIGHT")==0)
    {
        *(((board + x) + y) + 2) = 0;
        *(((board + x + numOfTiles) + y) + 2) = player_id;

        /*adding score from the tile*/

        /*using the artifact*/
    }
    else if(strcmp(direction, "UPLEFT")==0)
    {
        *(((board + x) + y) + 2) = 0;
        *(((board + x - numOfTiles) + y - numOfTiles) + 2) = player_id;

        /*adding score from the tile*/

        /*using the artifact*/
    }
    else if(strcmp(direction, "UPRIGHT")==0)
    {
        *(((board + x) + y) + 2) = 0;
        *(((board + x + numOfTiles) + y - numOfTiles) + 2) = player_id;

        /*adding score from the tile*/

        /*using the artifact*/
    }
    else if(strcmp(direction, "DOWNLEFT")==0)
    {
        *(((board + x) + y) + 2) = 0;
        *(((board + x - numOfTiles) + y + numOfTiles) + 2) = player_id;

        /*adding score from the tile*/

        /*using the artifact*/ 
    }
    else if(strcmp(direction, "DOWNRIGHT")==0)
    {
        *(((board + x) + y) + 2) = 0;
        *(((board + x + numOfTiles) + y + numOfTiles) + 2) = player_id;

        /*adding score from the tile*/

        /*using the artifact*/
    }

}
