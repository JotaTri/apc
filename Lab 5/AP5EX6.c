#include <stdio.h>

int MultiplicacaoBizarra(int a, int b){
    int resultado = 0;
    if(a == 0 || b == 0){
        return 0;
    }

    while (a != 1){
        if(a%2 != 0){
            resultado += b;
        }
        a = a/2;
        b = b*2;

    }
    return (resultado + b);
}

int main(){
    int num1, num2, i;

    for(i = 0; i < 10; i++){
        printf("Indique o primeiro numero inteiro da multiplicacao:");
        scanf("%d", &num1);
        printf("Indique o segundo numero inteiro da multiplicacao:");
        scanf("%d", &num2);

        printf(" \n\n%d x %d = %d \n\n", num1, num2, MultiplicacaoBizarra(num1, num2));

    }
    return 0;
}
