#ifndef TAUCS_H
#define TAUCS_H
#include "assets.h"
#include <stdio.h>
#include <stdlib.h>
#endif

void inputBoard(FILE* f, Tile** board, int height, int width)
{
    int array[height][width];
    for(int jj=0; jj<height; jj++)
        for(int ii=0; ii<width; ii++)
        {
            fscanf(f, "%d", &array[jj][ii]);

            if (array[jj][ii] < 10)
            {
                board[jj][ii].score = 0;
                board[jj][ii].artefact = 0;
                board[jj][ii].occupation = array[jj][ii];
            }

            else if (array[jj][ii] < 100)
            {
                board[jj][ii].score = 0;
                board[jj][ii].artefact = array[jj][ii] / 10;
                board[jj][ii].occupation = array[jj][ii] % 10;
            }

            else if (array[jj][ii] < 999)
            {
                board[jj][ii].score = array[jj][ii] / 100;
                board[jj][ii].artefact = array[jj][ii] % 100 / 10;
                board[jj][ii].occupation = array[jj][ii] % 100 % 10;
            }
        }
}

void outputBoard(FILE* f, Tile** board, int height, int width)
{
    fprintf(f, "%d %d\n", height, width);
    for(int jj=0; jj<height; jj++)
    {
        for(int ii=0; ii<width; ii++)
            fprintf(f, "%d%d%d ", board[jj][ii].score, board[jj][ii].artefact, board[jj][ii].occupation);
        fprintf(f, "\n");
    }
}