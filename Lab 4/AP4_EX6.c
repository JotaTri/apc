#include <stdio.h>

typedef int bool;
#define true 1
#define false 0

int main(){

    int i, j;
    float x, k, valor;
    bool neg;

    for(i = 0; i < 4; i++){
            valor = 1;
            printf("Indique o valor da base da exponencial: ");
            scanf("%f", &x);

            printf("Indique o valor do expoente da operacao: ");
            scanf("%f", &k);

            if(k < 0){
                neg = true;
                k *= -1;
            }
            else
                neg = false;

        for(j = k; j > 0; j--){
                valor = valor * x;
            }
        if (neg){
            printf("%.0f^%.0f = %.2f \n\n",x, -k, 1/valor);
        }
        else
            printf("%.0f^%.0f = %.2f \n\n",x, k, valor);
    }
    return (0);
}
