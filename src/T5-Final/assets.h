#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

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

void printBoard(Tile **board, int x, int numOfPlayers, char name[numOfPlayers][11], Score scoreBoard[numOfPlayers]);