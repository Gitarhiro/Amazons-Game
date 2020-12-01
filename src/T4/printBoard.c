#include <stdio.h>
#include <stdlib.h>

int printBoard(int board[2][2][3]) {
    for (int d=0;d<2;d++) {
        printf("\n");
        for (int e=0;e<2;e++) {
            printf(" ");
            if (board[d][e][3] == 0) {
                printf("☐");
            }
            else if (board[d][e][3] == 9) {
                printf("/");
            }
            else {
                printf("%d", board[d][e][3]);
            }
        }
    }

    return 0;
}

int main() {
    int a[2][2][3] = {{{3, 4, 2}, {0, -3, 9}}, {{13, 4, 0}, {3, 1, 9}}};
    printBoard(a[2][2][3]);

    return 0;
}