#ifndef TAUCS_H
#define TAUCS_H
#include "assets.h"
#endif

void moveAmazon(int player_id, Tile **board, int size, int numOfPlayers, char name[numOfPlayers][11], Score scoreBoard[numOfPlayers], int horse , int hx , int hy);
//moveAmzon                     function that is responsible for movement of an amazon
//player id                 -   id of a moving player
//tile board                -   structure of the board
//int size                  -   dimension of the board, size x size
//numOfPlayers              -   number of players in the game
//name[numOfPlayers][11]    -   char array storing names of the players
//scoreBoard[numOfPlayers]  -   Score array storing number of points which each player has
//horse                     -   is the movement caused by picking up a horse in previous movement   1 - yes  other - no
//hx                        -   coordinates in x axis of the next amazon
//hy                        -   coordinates in y axis of the next amazon

void usingArtifact(int player_id, int x, int y, Tile **board, int size, int numOfPlayers, char name[numOfPlayers][11], Score scoreBoard[numOfPlayers]);
//usingArtifact                 function that is responsible for using the founded artifact
//player id                 -   id of a moving player
//x                         -   coordinates in x axis of the amazon
//y                         -   coordinates in y axis of the amazon
//tile board                -   structure of the board
//int size                  -   dimension of the board, size x size
//numOfPlayers              -   number of players in the game
//name[numOfPlayers][11]    -   char array storing names of the players
//scoreBoard[numOfPlayers]  -   Score array storing number of points which each player has

void shoot(int id, int x, int y, Tile **board, int size, int numOfPlayers, char name[numOfPlayers][11], Score scoreBoard[numOfPlayers]);
//shoot                         funcion that is responsible for shooting (an arrow or a spear)
//id                        -   id of a moving player
//x                         -   coordinates in x axis of the amazon
//y                         -   coordinates in y axis of the amazon
//tile board                -   structure of the board
//int size                  -   dimension of the board, size x size
//numOfPlayers              -   number of players in the game
//name[numOfPlayers][11]    -   char array storing names of the players
//scoreBoard[numOfPlayers]  -   Score array storing number of points which each player has

int isAmazonAvaiable(int x, int y, Tile **board, int size);
//isAmazonAvaiable              function that cheks if the amazon is available
//x                         -   coordinates in x axis of the amazon
//y                         -   coordinates in y axis of the amazon
//tile board                -   structure of the board
//int size                  -   dimension of the board, size x size

int isMovementPossible(int x, int y, Tile **board);
//isMovementPossible            function that cheks if the amazon can make a move in any direction
//x                         -   coordinates in x axis of the amazon
//y                         -   coordinates in y axis of the amazon
//tile board                -   structure of the board

int availableAmazons(int player_id, Tile **board, int size);
//availableAmazons              function that checks how many available amazons does a player have
//player id                 -   id of a moving player
//tile board                -   structure of the board
//int size                  -   dimension of the board, size x size

int endGameCheck(int playerCanMove[], int players);
//endGameCheck                  function that checks if the game should end
//players                   -   number of players

void newMove(Tile **board, int size);

void InputCoordinate(int *a , int range);


