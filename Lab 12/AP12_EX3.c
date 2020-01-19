#include <stdio.h>

float potencia(float base, float expoente){
    if (expoente == 1)
        return base;
    else
        return(base*potencia(base, expoente - 1));
}

int main(){
    float x,y;

    printf("Indique a base da potencia a ser calculada: ");
    scanf("%f", &x);
    printf("Indique o expoente da potencia a ser calculada: ");
    scanf("%f", &y);

    printf("%.1f^%.1f = %.2f", x, y, potencia(x,y));

    return 0;

}
