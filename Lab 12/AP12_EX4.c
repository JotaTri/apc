#include <stdio.h>

int MDC(int x, int y){
    if(x < y)
        return MDC(y, x);
    if(x%y == 0)
        return(y);
    else
        return MDC(y, x%y);
}

int main(){
    int x, y;

    printf("Indique o numerador da fracao a ser analisada: ");
    scanf("%d", &x);
    printf("Indique o denominador da fracao a ser analisada: ");
    scanf("%d", &y);

    printf("O Minimo divisor comum da fraaco %d/%d e' %d",x, y, MDC(x,y));

    return 0;
}
