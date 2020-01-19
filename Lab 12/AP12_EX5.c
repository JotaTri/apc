#include <stdio.h>
int contador = 0;

int Soma(int numero){
    if(numero == 1)
        return 1;
    else
        return (numero + Soma(numero-1));
}

int main(){
    int n;

    printf("Indique o numero que se deseja saber o valor da soma dos inteiros positivos menores ou iguais a ele: ");
    scanf("%d", &n);

    printf("A soma dos valores inteiros positivos menores ou iguais a %d e' %d", n, Soma(n));

    return 0;
}
