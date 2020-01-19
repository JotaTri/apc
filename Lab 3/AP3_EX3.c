#include <stdio.h>

int main(){

    int n, i;
    float idade, media;

    media = 0;

    printf("Idique o numero de pessoas do grupo em questao: ");
    scanf("%d", &n);

    for(i = 1; i <= n; i++){
        printf("Indique a idade do %d* participante do grupo: ", i);
        scanf("%f", &idade);
        media += idade;
    }


    printf("A media da idade dos %d integrantes do grupo e' %.2f", n, (float)(media/n));

    return (0);
}
