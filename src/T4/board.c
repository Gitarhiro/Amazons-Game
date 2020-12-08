typedef struct
{
    int score = 0;
    int artefact = 0;
    int occupation = 0;
} Tile;


void randomizeBoard (Tile **board, int x, int y)
{
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            board[i][j].score = rand() % 6;
            board[i][j].artefact = rand() % 4;
            board[i][j].occupation = 0;
        }
    }
}

void printBoard (Tile **board, int x, int y)
{
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            if (board[i][j].occupation == 0) {
                printf("%c", 254);
            }

            else if (board[i][j].occupation == 9) {
                printf("%c", 92);
            }

            else {
                printf("%d", board[i][j].occupation);
            }
        }
        printf("\n");
    }
}
