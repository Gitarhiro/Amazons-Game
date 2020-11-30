#include <stdio.h>

void placement(int j , int *board)
{
    int x,y;
    while(1)
    {
        printf ("x: ");
        scanf ("%d", &x);
        printf("\n");
        printf ("y: ");
        scanf ("%d", &y);
        printf("\n");

      if(*(((board+x)+y)+2)==0)
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
