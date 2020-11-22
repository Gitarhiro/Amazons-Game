#include <stdio.h>

/* this one should use the array from makeboard */

void placement(int j int *board)
{
    int x,y;
    while(true)
    {
        printf ("x: ");
        scanf ("%d", &x);
        printf("\n");
        printf ("y: ");
        scanf ("%d", &y);
        printf("\n");

      if(board[x][y][2]==0)
        {
            *(((board+x)+y)+2)=j;
            return;
        }
        else
        {
            printf("invalid placement, try again.\n");
        }
    }


}
