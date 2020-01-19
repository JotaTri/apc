#include <stdio.h>

int main(){

    float a, b, c, aux;

    printf("Informe a primeira dimensao do possível triangulo: ");
    scanf("%f", &a);

    printf("\nInforme a segunda dimensao do possível triangulo: ");
    scanf("%f", &b);
    if(b > a){
        aux = a;
        a = b;
        b = aux;
    }

    printf("\nInforme a terceira dimensao do possível triangulo: ");
    scanf("%f", &c);
     if(c > a){
        aux = a;
        a = c;
        c = aux;
    }

    if((a + b > c) && (a + c > b) && (b + c > a))
        printf("\n\n\n\n\nAs dimensões %.2f, %.2f e %.2f podem formar um triangulo", a, b, c);
        if(a*a == (b*b + c*c))
            printf(" retangulo");
        else
            printf("\n\n\n\n\nAs dimensões %.2f, %.2f e %.2f nao podem formar um triangulo", a, b, c);

    printf("\n\n\n");

    return(0);


}
