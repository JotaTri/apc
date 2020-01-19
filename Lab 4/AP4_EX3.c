#include <stdio.h>

int main(){

    int i;
    float soma, k;

    k = 0;
    soma = 0;
    while(k >=0){
        printf("Indique o valor máximo da soma dos naturais com seus naturais seguintes: ");
        scanf("%f", &k);

        for(i = 1; i <= k; i++){
            soma += i;
        }
        if (k < 0)
            printf("Valor menor que zero inserido.\n\n      Programa encerrado. \n\n");
        else
        printf("A soma dos naturais ate' %.0f e' %.0f. \n\n", k, soma);
        soma = 0;
    }
    return (0);
}
