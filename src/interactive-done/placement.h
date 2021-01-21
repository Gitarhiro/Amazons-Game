#ifndef TAUCS_H
#define TAUCS_H
#include "assets.h"
#endif

void randomizeBoard (Tile **board, int x);
//randomizeBoard    function that randomizes the board, adds artefacts and score in random order and with random values specified in instructions
//tile board    -   structure for game's board
//int x         -   dimension of the square board

void placement(Tile **board, int j, int dimensions);
//tile board    -   structure for game's board
//int j         -   id of player which is placing an amazon
//dimensions    -   dimensions of the square board, dimensions x dimensions