#include <stdio.h>

int main(){

    int t, i, j;
    float fatorial, valorIns;

    printf("Indique o numero cujo fatorial sera calculado: ");
    scanf("%f", &valorIns);

    printf("Indique quantas vezes eu devo fazer essa operacao: ");
    scanf("%d", &t);

    for(j = 1; j <= t; j++){
        fatorial = valorIns;
        printf("\n%.0f!", valorIns);
        for(i = fatorial - 1; i > 1; i--){
            fatorial = (float) fatorial * i;
        }
        printf(" = %.0f \n", fatorial);
    }
    return 0;
}
