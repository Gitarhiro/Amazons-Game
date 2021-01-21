#include <stdio.h>

typedef struct {
    int score;
    int artefact;
    int occupation;
    int moved;
    } Tile;

typedef struct {
        int player;
        int points;
    } Score;

void printBoard(Tile **board, int x, int numOfPlayers, char name[][11], Score scoreBoard[]);
//printBoard                function that prints the board and the scoreboard below it
//tile board            -   strucure of the board
//x                     -   dimensions of the square board
//numOfPlayers          -   number of players
//name[][11]            -   char array of players names
//scoreBoard[]          -   Score array that stores number of points for each player

void printBoardNoScore(Tile **board, int x, int numOfPlayers);
//printBoardNoScore         function that prints the board without the scoreboard
//tile board            -   strucure of the board
//x                     -   dimensions of the square board
//numOfPlayers          -   number of players

void instruction();
//instruction               function that prints the instructions for the game, if asked 
