#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct {
    int score;
    int artefact;
    int occupation;
    } Tile;

typedef struct {
        int player;
        int points;
    } Score;

void moveAmazon(int player_id, int x, int y, int numOfTiles, char direction[], Tile **board);
void usingArtifact(int player_id, int x, int y, Tile **board);
void shoot(int id, int x, int y, int numOfTiles, char direction[], Tile **board);

void randomizeBoard (Tile **board, int x)
{
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < x; j++)
        {
            board[i][j].score = rand() % 6;
            board[i][j].artefact = rand() % 4;
            board[i][j].occupation = 0;
        }
    }
}

void placement(Tile **board, int j, int dimensions)
{
    int x,y,r;

    while (1) {
        r = 0;
        while (r == 0) {
            printf("\nx: ");
            r=scanf("%d" ,&x);
            if(r == 0 || x < 0 || x > dimensions ) {
                printf("Wrong input, give another positive number in the range: \n");
                r=0;
            }
            while(getchar() != '\n');
        }
        
        r = 0;
        while (r == 0) {
            printf("y: ");
            r=scanf("%d" ,&y);
            if(r==0 || y < 0 || y > dimensions ) {
                printf("Wrong input, give another positive number in the range: \n");
                r=0;
            }
            while(getchar()!='\n');
        }
        
        if(board[y][x].occupation == 0) {
            board[y][x].occupation = j;
            break;
        }

        else printf("\nInvalid placement. Try again.\n");
    }    
}

void printBoard(Tile **board, int x)
{
    printf("    ");

    for (int k = 0; k < x; k++) {
        printf("%d ", k);
    }

    printf("\n    ");

    for (int k = 0; k < x; k++) {
        printf("- ");
    }

    printf("\n");

    for (int i = 0; i < x; i++) {
        printf("%d | ", i);
        for (int j = 0; j < x; j++)
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
            printf(" ");
        }
        printf("\n");
    }
    printf("\n");
}

int isMovementPossible(int x, int y, Tile **board)
{
    if(board[x][y].occupation == 0)
    {
        return 1;
    }
    return 0;
}

void shoot(int id, int x, int y, int numOfTiles, char direction[], Tile **board)
{
    //id = 1    arrow
    //id = 2    spear

    int valid = 1;
    int x_axis;
    int y_axis;
    
    //checking if shot is possible
    if(strcmp(direction, "LEFT")==0)
    {
        x_axis = 0;
        y_axis = -numOfTiles;

        for(int i = 1; i <= numOfTiles; i++)
        {
            if(isMovementPossible(x, y - i, board) == 0)
            {
                valid = 0;
            }
        }
    }
    else if(strcmp(direction, "RIGHT")==0)
    {
        x_axis = 0;
        y_axis = numOfTiles;

        for(int i = 1; i <= numOfTiles; i++)
        {
            if(isMovementPossible(x, y + i, board) == 0)
            {
                valid = 0;
            }
        }
    }
    else if(strcmp(direction, "UP")==0)
    {
        x_axis = -numOfTiles;
        y_axis = 0;

        for(int i = 1; i <= numOfTiles; i++)
        {
            if(isMovementPossible(x - i, y, board) == 0)
            {
                valid = 0;
            }
        }
    }
    else if(strcmp(direction, "DOWN")==0)
    {
        x_axis = numOfTiles;
        y_axis = 0;

        for(int i = 1; i <= numOfTiles; i++)
        {
            if(isMovementPossible(x + i, y, board) == 0)
            {
                valid = 0;
            }
        }
    }
    else if(strcmp(direction, "UPLEFT")==0)
    {
        x_axis = -numOfTiles;
        y_axis = -numOfTiles;

        for(int i = 1; i <= numOfTiles; i++)
        {
            if(isMovementPossible(x - i, y - i, board) == 0)
            {
                valid = 0;
            }
        }
    }
    else if(strcmp(direction, "DOWNLEFT")==0)
    {
        x_axis = numOfTiles;
        y_axis = -numOfTiles;

        for(int i = 1; i <= numOfTiles; i++)
        {
            if(isMovementPossible(x + i, y - i, board) == 0)
            {
                valid = 0;
            }
        }
    }
    else if(strcmp(direction, "UPRIGHT")==0)
    {
        x_axis = -numOfTiles;
        y_axis = numOfTiles;

        for(int i = 1; i <= numOfTiles; i++)
        {
            if(isMovementPossible(x - i, y + i, board) == 0)
            {
                valid = 0;
            }
        }
    }
    else if(strcmp(direction, "DOWNRIGHT")==0)
    {
        x_axis = numOfTiles;
        y_axis = numOfTiles;

        for(int i = 1; i <= numOfTiles; i++)
        {
            if(isMovementPossible(x + i, y + i, board) == 0)
            {
                valid = 0;
            }
        }
    }

    if(id == 2 && board[x + x_axis][y + y_axis].occupation == 0)
    {
        board[x + x_axis][y + y_axis].occupation = 9;
        printf("Amazon shot a spear.\n");
    }
    else if(valid == 1)
    {
        board[x + x_axis][y + y_axis].occupation = 9;
        printf("Amazon shot an arrow.\n");
    }
    else
    {
        printf("Shot is invalid.\n");
    }
}

void usingArtifact(int player_id, int x, int y, Tile **board)
{
    if(board[x][y].artefact == 0)
    {
        printf("There is no artifact. Shoot an arrow now.\n");
        
        //shooting an arrow
        int num;
        char direction[15];

        printf("Number of tiles you want to shoot an arrow: ");
        scanf("%d", &num);
        printf("Enter the direction: ");
        scanf("%s", &direction);

        shoot(1, x, y, num, direction, board);
    }
    else if(board[x][y].artefact == 1)
    {
        //horse
        printf("Amazon found a horse, make a move.\n");

        int num;
        char direction[15];

        printf("Number of tiles the amazon will move: ");
        scanf("%d", &num);
        printf("Enter the direction: ");
        scanf("%s", &direction);

        moveAmazon(player_id, x, y, num, direction, board);
    }
    else if(board[x][y].artefact == 2)
    {
        //broken arrow
        printf("Amazon found a broken arrow and it cannot shoot.\n");
    }
    else
    {
        //spear
        printf("Amazon found a spear. Shoot a spear now.\n");

        int num;
        char direction[15];

        printf("Number of tiles you want to shoot a spear: ");
        scanf("%d", &num);
        printf("Enter the direction: ");
        scanf("%s", &direction);

        shoot(2, x, y, num, direction, board);
    }
    
}

void moveAmazon(int player_id, int x, int y, int numOfTiles, char direction[], Tile **board) 
{

    int valid = 1;
    int x_axis;
    int y_axis;
    
    //checking if movement is possible
    if(strcmp(direction, "LEFT")==0)
    {
        x_axis = 0;
        y_axis = -numOfTiles;

        for(int i = 1; i <= numOfTiles; i++)
        {
            if(isMovementPossible(x, y - i, board) == 0)
            {
                valid = 0;
            }
        }
    }
    else if(strcmp(direction, "RIGHT")==0)
    {
        x_axis = 0;
        y_axis = numOfTiles;

        for(int i = 1; i <= numOfTiles; i++)
        {
            if(isMovementPossible(x, y + i, board) == 0)
            {
                valid = 0;
            }
        }
    }
    else if(strcmp(direction, "UP")==0)
    {
        x_axis = -numOfTiles;
        y_axis = 0;

        for(int i = 1; i <= numOfTiles; i++)
        {
            if(isMovementPossible(x - i, y, board) == 0)
            {
                valid = 0;
            }
        }
    }
    else if(strcmp(direction, "DOWN")==0)
    {
        x_axis = numOfTiles;
        y_axis = 0;

        for(int i = 1; i <= numOfTiles; i++)
        {
            if(isMovementPossible(x + i, y, board) == 0)
            {
                valid = 0;
            }
        }
    }
    else if(strcmp(direction, "UPLEFT")==0)
    {
        x_axis = -numOfTiles;
        y_axis = -numOfTiles;

        for(int i = 1; i <= numOfTiles; i++)
        {
            if(isMovementPossible(x - i, y - i, board) == 0)
            {
                valid = 0;
            }
        }
    }
    else if(strcmp(direction, "DOWNLEFT")==0)
    {
        x_axis = numOfTiles;
        y_axis = -numOfTiles;

        for(int i = 1; i <= numOfTiles; i++)
        {
            if(isMovementPossible(x + i, y - i, board) == 0)
            {
                valid = 0;
            }
        }
    }
    else if(strcmp(direction, "UPRIGHT")==0)
    {
        x_axis = -numOfTiles;
        y_axis = numOfTiles;

        for(int i = 1; i <= numOfTiles; i++)
        {
            if(isMovementPossible(x - i, y + i, board) == 0)
            {
                valid = 0;
            }
        }
    }
    else if(strcmp(direction, "DOWNRIGHT")==0)
    {
        x_axis = numOfTiles;
        y_axis = numOfTiles;

        for(int i = 1; i <= numOfTiles; i++)
        {
            if(isMovementPossible(x + i, y + i, board) == 0)
            {
                valid = 0;
            }
        }
    }

    if(valid == 1)
    {
        board[x][y].occupation = 0;
        board[x + x_axis][y + y_axis].occupation = player_id;

        //using artefact
        usingArtifact(player_id, x + x_axis, y + y_axis, board);
    }
    else
    {
        printf("Move is invalid.\n");
    }

}

void printScore(int numOfPlayers, char **name[numOfPlayers][11], Score *scoreBoard[numOfPlayers]) {
    for (int i = 0; i < numOfPlayers; i++) {
        printf("%s : %d points\n", name[i], scoreBoard[i]);
    }
}

int main() 
{
    //Declaration of all variables
    int numOfPlayers, numOfAmazons, size, x, y, numOfTiles;
    char direction[6];

    //Title
    printf("\n-WELCOME TO THE GAME OF AMAZONS-\n\n");

    //Inputing the number of players
    printf("Input the number of players\n");
    scanf("%d", &numOfPlayers);

    //Inputing the Player names
    char name[numOfPlayers][11];
    for(int i = 0; i < numOfPlayers; i++)
    {
        printf("Enter Player %d's name (max. 12 characters)\n", i+1);
        scanf("%s", name[i]);
    }

    //Inputting the number of Amazons per player
    printf("Input the number of amazons for each player\n");
    scanf("%d", &numOfAmazons);

    //Inputing the board dimensions
    printf("Input the board size\n");
    scanf ("%d", &size);
    printf("\n");

    //Initializing the board array
    Tile **board;
    board = (Tile**) malloc(size  * sizeof(Tile));
    for (int i = 0; i < size; i++) 
    {
        board[i] = (Tile*) malloc(size * sizeof(Tile));
    }

    //Randomizing the board array
    srand(time(NULL));
    randomizeBoard(board, size);

    //Initializing the Scoreboard
    Score *scoreBoard;
    scoreBoard = (Score*) malloc(numOfPlayers * sizeof(Score));

    printBoard(board, size);

    //Placement Phase
    for (int i = 0; i < numOfAmazons; i++) 
    {
        for (int j = 0; j < numOfPlayers; j++) 
        {
            printf("Turn of %s" , name[j]);
            placement(board , j+1, size);
            printBoard(board , size);
        }
    }

    printf("\n\n");

    //Movement Phase

    int movesAvailable = 1;

    while (movesAvailable)
    {
        for (int i = 0; i < numOfPlayers; i++) 
        {
            printf("Turn of %s\n" , name[i]);
            printf("Enter the coordinates of the amazon you want to move\n");
            printf("x: ");
            scanf("%d", &x);
            printf("y: ");
            scanf("%d", &y);

            while (board[y][x].occupation != i+1) //error check
            {
                printf("Your amazon is not on given tile. Input the coordinates again\n");
                printf("x: ");
                scanf("%d", &x);
                printf("y: ");
                scanf("%d", &y);
            }
            
            int num;
            char direction[15];
            printf("Number of tiles the amazon will move: ");
            scanf("%d", &num);
            printf("Enter the direction: ");
            scanf("%s", &direction);

            moveAmazon(i+1, y, x, num, direction, board);

            printBoard(board , size);

            printf("\n");
        }
    }
    
    
    getchar();
    return 0;
}
