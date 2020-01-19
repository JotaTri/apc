#include <stdio.h>

float Exponencial(float a, float b){
    int i;
    float resultado = 1;

    for (i = 0; i < b; i++){
        resultado *= a;
    }
    return resultado;
}

int main(){
    float base, expoente;

    printf("Indique a base da exponencial em questao: ");
    scanf("%f", &base);
    printf("Indique o expoente da exponencial em questao: ");
    scanf("%f", &expoente);

    printf("\n\n%.1f^%.1f = %.2f \n\n", base, expoente,Exponencial(base, expoente));

    return 0;
}
