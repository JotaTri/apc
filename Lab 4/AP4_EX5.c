#include <stdio.h>

int main(){

    int i, j;
    float x, k, valor;

    for(i = 0; i < 3; i++){
        valor = 1;
        k = -1;
        x = -1;
        while( x < 0){
            printf("Indique o valor da base da exponencial: ");
            scanf("%f", &x);
        if(x < 0)
            printf("Valor inserido invalido!\nA base deve ser positiva! \n");
        }
        while (k < 0){
            printf("Indique o valor do expoente da operacao: ");
            scanf("%f", &k);
        if (k < 0)
            printf("Valor inserido invalido!\nO expoente deve ser positiva! \n");
        }
        for (j = k; j > 0; j--){
            valor = valor * x;
        }
        printf("%.0f^%.0f = %.0f \n\n",x, k, valor);

    }
    return (0);
}
