#include <stdio.h>

int main(){


    int a, b;
    printf("Informe o 1o valor: ");
    scanf("%d",&a);

    printf("Informe o 2o valor: ");
    scanf("%d",&b);

    if (a==b)
        printf("numeros iguais a %d",a);
    else
        if(a>b)
            printf("numeros diferentes, sendo o maior '%d'",a);
        else
            printf("numeros diferentes, sendo o maior '%d'",b);

    return(0);
}

