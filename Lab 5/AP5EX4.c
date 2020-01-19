#include <stdio.h>

int SomaPares(int n){
    int somaPares = 0;

    for(n; n > 0; n--){
        if(n % 2 == 0)
            somaPares += n;
    }
    return somaPares;
}

int main(){
    int n;

    printf("Indique o numero cujos numeros pares entre 0 e ele serao somados: ");
    scanf("%d", &n);

    printf("A soma dos numeros pares entre 0 e %d e' %d \n\n\n\n\n", n, SomaPares(n));

    return 0;
}
