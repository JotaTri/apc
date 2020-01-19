#include <stdio.h>

int main(){

    int soma, i;
    soma = 0;

    for(i = 1; i <= 10; i++){
        soma += i;
        printf("%d + ", i);
    }
    printf("\b\b= %d", soma);

    return (0);
}
