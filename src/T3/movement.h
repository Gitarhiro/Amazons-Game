#include <stdio.h>
#include <stdlib.h>
/*
    function moveAmazon is responsible for moving an Amazon

    player_id   stores variable for player's id
    x           stores value of length of the board
    y           stores value of heigth of the board
    numOfTiles  stores value of how many tiles the player wants to move his amazon
    direction   stores name of direction in which the amazon will be moved
    score       an array which stores the values of each player's score
    board       a 3-dimentional array storing the board

*/
void moveAmazon(int player_id, int x, int y, int numOfTiles, char direction[], int *score, int *board)

