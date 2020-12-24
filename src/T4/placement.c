#include <stdio.h>
// DIMENSIONS IS THE RANGE OF THE BOARD//
void placement(Tile **board, int j, int dimensions){
    int x,y,r;
    while (1) {
        r=0;
        while (r==0) {
        printf("\nx: ");
        r=scanf("%d" ,&x);
        if(r==0 || x <=0 || x > dimensions ) 
        {
            printf("Wrong input, give another positive number in the range: \n");
            r=0;
        }
        while(getchar()!='\n');
    }
    r=0;
    while (r==0) {
        printf("\ny: ");
        r=scanf("%d" ,&y);
        if(r==0 || y <=0 || y > dimensions ) 
        {
            printf("Wrong input, give another positive number in the range: \n");
            r=0;
        }
        while(getchar()!='\n');
    }
        
        if(board[x][y].occupation == 0) {
            board[x][y].occupation = j;
            break;
        }
        else   printf("\nInvalid placement. Try again.\n");
    }
    
    
}
