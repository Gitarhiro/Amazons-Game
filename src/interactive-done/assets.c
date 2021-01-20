#include "assets.h"

void printBoard(Tile **board, int x, int numOfPlayers, char name[numOfPlayers][11], Score scoreBoard[numOfPlayers])
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

    for (int i = 0; i < numOfPlayers; i++) {
        printf("%s : %d points\n", name[i], scoreBoard[i].points);
    }
    printf("\n");
}

void printBoardNoScore(Tile **board, int x, int numOfPlayers)
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

void instruction() {
    int a;
    printf("\nIS INSTRUCTION REQUIRED?\n TYPE 1 TO SEE INSTRUCTIONS\n TYPE ANY OTHER CHARACTER TO PROCEED WITH THE GAME\n");
    scanf("%d" , &a);
    if(a==1) {
        printf("to move, choose coordinates of amazon you want to move, the nubmer of tiles you\nwant to move, and direction you want the amazon to be move\n");
        printf("the movement directions are:\nLEFT\nRIGHT\nUP\nDOWN\nUPLEFT\nUPRIGHT\nDOWNLEFT\nDOWNRIGHT\n");
        return;
    }
    else system("cls");return;
}
