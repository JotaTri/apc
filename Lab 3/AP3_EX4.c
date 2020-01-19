#include <stdio.h>

int main(){

    int i, j;

    for(i = 10; i <= 20; i++){
        for(j = 1; j <=10; j++){
            printf("%d x %d = %d , ",i,j,i*j);
        }
        printf(" \b\b\b \n");
    }

    return(0);
}
