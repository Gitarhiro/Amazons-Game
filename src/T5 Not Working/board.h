typedef struct {
    int score;
    int artefact;
    int occupation;
    } Tile;

typedef struct {
        int player;
        int points;
    } Score;

void randomizeBoard(Tile **board, int x);

void placement(Tile **board, int j, int dimensions);

void printBoard(Tile **board, int x);