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

void moveAmazon(int player_id, int x, int y, int numOfTiles, char direction[], Tile **board, int size);
void usingArtifact(int player_id, int x, int y, Tile **board, int size);
void shoot(int id, int x, int y, int numOfTiles, char direction[], Tile **board, int size);

void randomizeBoard (Tile **board, int x)
{
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < x; j++)
        {
            board[i][j].score = rand() % 6;
            board[i][j].artefact = rand() % 4;
            board[i][j].occupation = 0;
            board[i][j].moved = 0;
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
            board[y][x].artefact = 0;
            board[y][x].score = 0;
            break;
        }

        else printf("\nInvalid placement. Try again.\n");
    }    
}

int isAmazonAvaiable(int x, int y, Tile **board, int size)
{   
    size--;

    if(board[y][x].moved == 1)
        return 0;

    if(x == 0) {
        if(y == 0) {
            if (board[y+1][x+1].occupation != 0 && board[y+1][x].occupation != 0 && board[y][x+1].occupation != 0) {
                return 0;
            }
            return 1;
        }
        else if (y == size) {
            if (board[y-1][x+1].occupation != 0 && board[y-1][x].occupation != 0 && board[y][x+1].occupation != 0) {
                return 0;
            }
            return 1;
        }
        else if (board[y+1][x+1].occupation != 0 && board[y][x+1].occupation != 0 && board[y-1][x+1].occupation != 0 && board[y+1][x].occupation != 0 && board[y-1][x].occupation != 0) {
                return 0;
            }
            return 1;
    }
    if(x == size) {
        if(y == 0) {
            if (board[y+1][x-1].occupation != 0 && board[y+1][x].occupation != 0 && board[y][x-1].occupation != 0) {
                return 0;
            }
            return 1;
        }
        else if (y == size) {
             if (board[y-1][x-1].occupation != 0 && board[y-1][x].occupation != 0 && board[y][x-1].occupation != 0) {
                return 0;
            }
            return 1;
        }
        else if (board[y+1][x-1].occupation != 0 && board[y+1][x].occupation != 0 && board[y][x-1].occupation != 0 && board[y-1][x-1].occupation != 0 && board[y-1][x].occupation != 0) {
                return 0;
            }
            return 1;
    }
    if(y == 0) {
        if(x != 0 && x != size) {
            if (board[y][x-1].occupation != 0 && board[y+1][x-1].occupation != 0 && board[y][x+1].occupation != 0 && board[y+1][x+1].occupation != 0 && board[y][x+1].occupation != 0) {
                return 0;
            }
            return 1;
        }
        
    }
    if(y == size) {
        if(x != 0 && x != size) {
            if (board[y][x-1].occupation != 0 && board[y-1][x-1].occupation != 0 && board[y-1][x].occupation != 0 && board[y-1][x+1].occupation != 0 && board[y][x+1].occupation != 0) {
                return 0;
            }
            return 1;
        } 
    }
    else if (board[y+1][x-1].occupation != 0 && board[y+1][x].occupation != 0 && board[y+1][x+1].occupation != 0 && board[y][x+1].occupation != 0 && board[y-1][x+1].occupation != 0 && board[y-1][x].occupation != 0 && board[y-1][x-1].occupation != 0 && board[y][x-1].occupation != 0) {
                return 0;
            }
            return 1;
   
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

void shoot(int id, int x, int y, int numOfTiles, char direction[], Tile **board, int size)
{
    //id = 1    arrow
    //id = 2    spear

    int valid = 1;
    int inBoundaries = 1;
    int x_axis;
    int y_axis;
    
    //checking if shot is possible
    if(strcmp(direction, "LEFT")==0)
    {
        x_axis = 0;
        y_axis = -numOfTiles;

        if (y - numOfTiles < 0)
        {
            inBoundaries = 0;
            valid = 0;
        }
        else
        {
            for(int i = 1; i <= numOfTiles; i++)
            {
                if(isMovementPossible(x, y - i, board) == 0)
                {
                    valid = 0;
                }
            }
        }
        
        
    }
    else if(strcmp(direction, "RIGHT")==0)
    {
        x_axis = 0;
        y_axis = numOfTiles;

        if (y + numOfTiles > size)
        {
            inBoundaries = 0;
            valid = 0;
        }
        else
        {
            for(int i = 1; i <= numOfTiles; i++)
            {
                if(isMovementPossible(x, y + i, board) == 0)
                {
                    valid = 0;
                }
            }
        }
    }
    else if(strcmp(direction, "UP")==0)
    {
        x_axis = -numOfTiles;
        y_axis = 0;
        
        if (x - numOfTiles < 0)
        {
            inBoundaries = 0;
            valid = 0;
        }
        else
        {
            for(int i = 1; i <= numOfTiles; i++)
            {
                if(isMovementPossible(x - i, y, board) == 0)
                {
                    valid = 0;
                }
            }
        }
    }
    else if(strcmp(direction, "DOWN")==0)
    {
        x_axis = numOfTiles;
        y_axis = 0;

        if (x + numOfTiles > size)
        {
            inBoundaries = 0;
            valid = 0;
        }
        else
        {
            for(int i = 1; i <= numOfTiles; i++)
            {
                if(isMovementPossible(x + i, y, board) == 0)
                {
                    valid = 0;
                }
            }
        }
    }
    else if(strcmp(direction, "UPLEFT")==0)
    {
        x_axis = -numOfTiles;
        y_axis = -numOfTiles;

        if (x - numOfTiles < 0 || y - numOfTiles < 0)
        {
            inBoundaries = 0;
            valid = 0;
        }
        else
        {
            for(int i = 1; i <= numOfTiles; i++)
            {
                if(isMovementPossible(x - i, y - i, board) == 0)
                {
                    valid = 0;
                }
            }
        }
    }
    else if(strcmp(direction, "DOWNLEFT")==0)
    {
        x_axis = numOfTiles;
        y_axis = -numOfTiles;

        if (x + numOfTiles > size || y - numOfTiles < 0)
        {
            inBoundaries = 0;
            valid = 0;
        }
        else
        {
            for(int i = 1; i <= numOfTiles; i++)
            {
                if(isMovementPossible(x + i, y - i, board) == 0)
                {
                    valid = 0;
                }
            }
        }
    }
    else if(strcmp(direction, "UPRIGHT")==0)
    {
        x_axis = -numOfTiles;
        y_axis = numOfTiles;

        if (x - numOfTiles < 0 || y + numOfTiles > size)
        {
            inBoundaries = 0;
            valid = 0;
        }
        else
        {
            for(int i = 1; i <= numOfTiles; i++)
            {
                if(isMovementPossible(x - i, y + i, board) == 0)
                {
                    valid = 0;
                }
            }
        }
    }
    else if(strcmp(direction, "DOWNRIGHT")==0)
    {
        x_axis = numOfTiles;
        y_axis = numOfTiles;

        if (x + numOfTiles > size || y + numOfTiles > size)
        {
            inBoundaries = 0;
            valid = 0;
        }
        else
        {
            for(int i = 1; i <= numOfTiles; i++)
            {
                if(isMovementPossible(x + i, y + i, board) == 0)
                {
                    valid = 0;
                }
            }
        }
    }
    else
    {
        valid = 0;
    }
    
    if(id == 2 && board[x + x_axis][y + y_axis].occupation == 0 && inBoundaries)
    {
        board[x + x_axis][y + y_axis].occupation = 9;
        printf("Amazon shot a spear.\n");
    }
    else if(valid)
    {
        board[x + x_axis][y + y_axis].occupation = 9;
        printf("Amazon shot an arrow.\n");
    }
    else
    {
        printf("Shot is invalid. Make the shot again.\n");
        printBoard(board , size);
        int num;
        char direction[15];

        printf("Number of tiles you want to shoot a spear or an arrow: ");
        scanf("%d", &num);
        printf("Enter the direction: ");
        scanf("%s", &direction);

        shoot(id, x, y, num, direction, board, size);
    }
}

void usingArtifact(int player_id, int x, int y, Tile **board, int size)
{
    if(board[x][y].artefact == 0)
    {
        printf("There is no artifact. Shoot an arrow now.\n");
        
        //shooting an arrow
        if (isAmazonAvaiable(x, y, board, size))
        {
            int num;
            char direction[15];

            printf("Number of tiles you want to shoot an arrow: ");
            scanf("%d", &num);
            printf("Enter the direction: ");
            scanf("%s", &direction);

            shoot(1, x, y, num, direction, board, size);
        }
        
        else
        {
            printf("The amazon is blocked. It cannot shoot an arrow.\n");
        }
        
    }
    else if(board[x][y].artefact == 1)
    {
        //horse
        printf("Amazon found a horse, shoot an arrow and make a move.\n");

        int num;
        char direction[15];

        printf("Number of tiles you want to shoot an arrow: ");
        scanf("%d", &num);
        printf("Enter the direction: ");
        scanf("%s", &direction);

        shoot(1, x, y, num, direction, board, size);

        printBoard(board, size);

        printf("Time for another move\n");
        printf("Number of tiles the amazon will move: ");
        scanf("%d", &num);
        printf("Enter the direction: ");
        scanf("%s", &direction);

        moveAmazon(player_id, x, y, num, direction, board, size);
        board[x][y].artefact = 0;
    }
    else if(board[x][y].artefact == 2)
    {
        //broken arrow
        printf("Amazon found a broken arrow and it cannot shoot.\n");
        board[x][y].artefact = 0;
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

        shoot(2, x, y, num, direction, board, size);
        board[x][y].artefact = 0;
    }
    
}

void moveAmazon(int player_id, int x, int y, int numOfTiles, char direction[], Tile **board, int size) 
{

    int valid = 1;
    int x_axis;
    int y_axis;
    
    //checking if movement is possible
    if(strcmp(direction, "LEFT")==0)
    {
        x_axis = 0;
        y_axis = -numOfTiles;

        if (y - numOfTiles < 0)
        {
            valid = 0;
        }
        else
        {
            for(int i = 1; i <= numOfTiles; i++)
            {
                if(isMovementPossible(x, y - i, board) == 0)
                {
                    valid = 0;
                }
            }
        }
    }
    else if(strcmp(direction, "RIGHT")==0)
    {
        x_axis = 0;
        y_axis = numOfTiles;

        if (y + numOfTiles > size)
        {
            valid = 0;
        }
        else
        {
            for(int i = 1; i <= numOfTiles; i++)
            {
                if(isMovementPossible(x, y + i, board) == 0)
                {
                    valid = 0;
                }
            }
        }
    }
    else if(strcmp(direction, "UP")==0)
    {
        x_axis = -numOfTiles;
        y_axis = 0;
        
        if (x - numOfTiles < 0)
        {
            valid = 0;
        }
        else
        {
            for(int i = 1; i <= numOfTiles; i++)
            {
                if(isMovementPossible(x - i, y, board) == 0)
                {
                    valid = 0;
                }
            }
        }
    }
    else if(strcmp(direction, "DOWN")==0)
    {
        x_axis = numOfTiles;
        y_axis = 0;

        if (x + numOfTiles > size)
        {
            valid = 0;
        }
        else
        {
            for(int i = 1; i <= numOfTiles; i++)
            {
                if(isMovementPossible(x + i, y, board) == 0)
                {
                    valid = 0;
                }
            }
        }
    }
    else if(strcmp(direction, "UPLEFT")==0)
    {
        x_axis = -numOfTiles;
        y_axis = -numOfTiles;

        if (x - numOfTiles < 0 || y - numOfTiles < 0)
        {
            valid = 0;
        }
        else
        {
            for(int i = 1; i <= numOfTiles; i++)
            {
                if(isMovementPossible(x - i, y - i, board) == 0)
                {
                    valid = 0;
                }
            }
        }
    }
    else if(strcmp(direction, "DOWNLEFT")==0)
    {
        x_axis = numOfTiles;
        y_axis = -numOfTiles;

        if (x + numOfTiles > size || y - numOfTiles < 0)
        {
            valid = 0;
        }
        else
        {
            for(int i = 1; i <= numOfTiles; i++)
            {
                if(isMovementPossible(x + i, y - i, board) == 0)
                {
                    valid = 0;
                }
            }
        }
    }
    else if(strcmp(direction, "UPRIGHT")==0)
    {
        x_axis = -numOfTiles;
        y_axis = numOfTiles;

        if (x - numOfTiles < 0 || y + numOfTiles > size)
        {
            valid = 0;
        }
        else
        {
            for(int i = 1; i <= numOfTiles; i++)
            {
                if(isMovementPossible(x - i, y + i, board) == 0)
                {
                    valid = 0;
                }
            }
        }
    }
    else if(strcmp(direction, "DOWNRIGHT")==0)
    {
        x_axis = numOfTiles;
        y_axis = numOfTiles;

        if (x + numOfTiles > size || y + numOfTiles > size)
        {
            valid = 0;
        }
        else
        {
            for(int i = 1; i <= numOfTiles; i++)
            {
                if(isMovementPossible(x + i, y + i, board) == 0)
                {
                    valid = 0;
                }
            }
        }
    }
    else
    {
        valid = 0;
    }

    if(valid == 1)
    {
        board[x][y].occupation = 0;
        board[x + x_axis][y + y_axis].occupation = player_id;
        board[x + x_axis][y + y_axis].moved = 1;
        board[x][y].moved = 0;
        printBoard(board , size);
        //using artefact
        usingArtifact(player_id, x + x_axis, y + y_axis, board, size);
    }
    else
    {
        printf("Move is invalid. Make the move again.\n");
        printBoard(board , size);
        int num;
        char direction[15];
        printf("Number of tiles the amazon will move: ");
        scanf("%d", &num);
        printf("Enter the direction: ");
        scanf("%s", &direction);

        moveAmazon(player_id, x, y, num, direction, board, size);
    }

}

int availableAmazons(int player_id, Tile **board, int size)
{
    int freeAmazons = 0;

    for (int y = 0; y < size; y++)
        for (int x = 0; x < size; x++)
            if (board[y][x].occupation == player_id)
                if (isAmazonAvaiable(x, y, board, size))
                    freeAmazons++;
    
    return freeAmazons;
}

int endGameCheck(int playerCanMove[], int players)
{
    for (int id = 0; id < players; id++)
        if (playerCanMove[id] > 0)
            return 1;
    
    return 0;
}

void printScore(int numOfPlayers, char **name[numOfPlayers][11], Score *scoreBoard[numOfPlayers]) {
    for (int i = 0; i < numOfPlayers; i++) {
        printf("%s : %d points\n", name[i], scoreBoard[i]);
    }
}

void newMove(Tile **board, int size)
{
    for (int x = 0; x < size; x++)
        for (int y = 0; y < size; y++)
            board[x][y].moved = 0;
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
        board[i] = (Tile*) malloc(size * sizeof(Tile));

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

    int playersAvailableAmazons[numOfPlayers];

    for (int id = 0; id < numOfPlayers; id++)
        playersAvailableAmazons[id] = availableAmazons(id+1, board, size);

    while (endGameCheck(playersAvailableAmazons, numOfPlayers))
    {
        for (int i = 0; i < numOfPlayers; i++) 
        {
            newMove(board, size);
            while (playersAvailableAmazons[i])
            {
                printf("Turn of %s\n" , name[i]);
                
                printf("Enter the coordinates of the amazon you want to move\n");
                printf("x: ");
                scanf("%d", &x);
                printf("y: ");
                scanf("%d", &y);
                
                int canMove = isAmazonAvaiable(x, y, board, size);

                while (board[y][x].occupation != i+1 || !canMove) //error check
                {
                    printf("Your amazon is not on given tile or cannot move. Input the coordinates again\n");
                    printf("x: ");
                    scanf("%d", &x);
                    printf("y: ");
                    scanf("%d", &y);

                    canMove = isAmazonAvaiable(x, y, board, size);
                }
            
                int num;
                char direction[15];
                printf("Number of tiles the amazon will move: ");
                scanf("%d", &num);
                printf("Enter the direction: ");
                scanf("%s", &direction);

                moveAmazon(i+1, y, x, num, direction, board, size);

                printBoard(board , size);

                for (int id = 0; id < numOfPlayers; id++)
                    playersAvailableAmazons[id] = availableAmazons(id+1, board, size);
                    
                printf("\n");
            }
        }
    }
    
    printf("---GAME OVER---\n");
    
    getchar();
    return 1;
}
