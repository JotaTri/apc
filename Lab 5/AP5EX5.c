#include <stdio.h>

float Maior(float a, float b, float c){
    if (a > b ){
        if (a > c)
            return a;
        else
            return c;
    }
    else if(b > c)
            return b;
    else
        return c;
}

int main(){
    float num1, num2, num3;

    printf("Indique o primeiro numero:");
    scanf("%f", &num1);
    printf("Indique o segundo numero:");
    scanf("%f", &num2);
    printf("Indique o terceiro numero:");
    scanf("%f", &num3);

    printf("Dentre os numeros (%.2f,%.2f,%.2f) e' %.2f \n\n\n\n", num1, num2, num3, Maior(num1, num2, num3));

    return 0;
}
