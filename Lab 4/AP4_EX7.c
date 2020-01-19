#include <stdio.h>

int main(){

    float antigo, novo, maior;
    antigo = 0;
    maior = -999999;
    novo = 1;
    while (novo != 0){
        printf("\nIndique o novo numero da sequencia: ");
        scanf("%f", &novo);
        antigo += novo;
        if(antigo > maior)
            maior = antigo;
        antigo = novo;

    }
    printf("\n\n\n A maior soma de numeros consecutivos inseridos e' %.2f \n\n\n", maior);
    return (0);
}
