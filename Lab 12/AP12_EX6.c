#include <stdio.h>
int contador = 0;

int Fib(int n){
    contador++;
    if(n == 0)
        return 0;
    if(n == 1)
        return 1;
    else
        return (Fib(n - 1) + Fib(n - 2));

}


int main(){
    int numero;

    printf("Indique o numero de Fibonacci a ser calculado: ");
    scanf("%d", &numero);

    printf("\n\nF%d = %d", numero, Fib(numero));

    printf("\nOcorreram %d chamadas da funcao recursiva", contador);

    return 0;
}
