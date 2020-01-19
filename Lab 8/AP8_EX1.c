#include <stdio.h>

int main(){
    int i, w[5];

    for (i = 0; i < 5; i++){
        printf("Digite o %d* numero:", i+1);
        scanf("%d", &w[i]);
    }
    for(i = 0; i < 5; i++){
        printf("O valor armazenado em w[%d] e' %d \n", i, w[i]);
    }
    getchar();
    return 0;

}
