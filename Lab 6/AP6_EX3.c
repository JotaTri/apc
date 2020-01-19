#include <stdio.h>
#include <math.h>

typedef int bool;
#define true 1
#define false 0

void Raizes(float a, float b, float c, float *x1, float *x2, int *raizes){
    int delta = -1;

    delta = (b*b) - (4*a*c);
    if(delta < 0){
        *raizes = 0;
    }
    if (delta == 0){
        *raizes = 1;
    }
    if (delta > 0){
        *raizes = 2;
    }

    if (*raizes == 0)
        delta = (-1) * delta;

    *x1 = ((sqrt(delta) - b)/(2*a));
    *x2 = ((-sqrt(delta) - b)/(2*a));


    return 0;
}



int main(){
    float a, b, c, x1, x2;
    int QtdRaizes;
    bool signB, signC;
    x1 = 666;
    x2 = 666;


    printf("Indique o valor do coeficiente 'a' da equacao: ");
    scanf("%f", &a);

    printf("\nIndique o valor do coeficiente 'b' da questao: ");
    scanf("%f", &b);


    printf("\nIndique o valor do coeficiente 'c' da questao: ");
    scanf("%f", &c);

    if(b >= 0)
        signB = true;
    else
        signB = false;

        if(c >= 0)
        signC = true;
    else
        signC = false;


    Raizes( a, b, c, &x1, &x2, &QtdRaizes);


    printf("\n\nAs solucoes da equacao '%.2fx^2", a);
    if(signB)
        printf(" + %.2f", b);
    else
        printf(" %.2f", b);
    printf("x");
    if(signC)
        printf(" + %.2f", c);
    else
        printf(" %.2f");
    if(QtdRaizes == 2)
        printf(" sao: \nx1 = %.2f \nx2 = %.2f \n\n\n\n",x1, x2);
    if(QtdRaizes == 1)
        printf(" sao: \nx1 = x2 = %.2f \n\n\n\n", x1);
    if(QtdRaizes == 0)
        printf("sao imaginarias e iguais a: \nx1 = %.2fi \nx2 = %.2fi \n\n\n\n", x1, x2);

    return 0;
}
