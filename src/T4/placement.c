#include <stdio.h>

void placement(Tile **board, int j){
    int x,y;
    while (1) {
        printf("\nx: ");
        scanf("%d" , &x );
        printf("\ny: ");
        scanf("%d" , &y );
        if(board[x][y].occupation == 0) {
            board[x][y].occupation = j;
            break;
        }
        else   printf("\nInvalid placement. Try again.\n")
    }
    //THING TO BE MADE FOR THE NEXT TUTORIALS IS TO CHECK THE TYPE OF DATA IMPUT IN THE PLACEMENT//
    
}

