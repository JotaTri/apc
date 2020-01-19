#include <stdio.h>

int main () {
    int i, j;
    int MAT[3][3];

    for (i=0; i<3; i++) {     /* leitura da matriz */
        for (j=0; j<3; j++) {
            scanf("%d",&MAT[i][j]);
        }
    }
    for (i=0; i<3; i++) {    /* impressão da matriz */
        for (j=0; j<3; j++) {
            printf("%d\t",MAT[i][j]);
        }
        /*printf("\n");*/
    }
    getchar();
    getchar();

    return 0;
}
