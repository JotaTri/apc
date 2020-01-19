#include <stdio.h>

int Ler(int vetor[]){
    int i;
    for(i = 0; i < 9; i++){
        printf("Indique o %d* numero do vetor em questao: ", i + 1);
        scanf("%d", &vetor[i]);
    }
    return (0);
}

int Negs(int vetor[]){
    int i;
    for(i = 0; i < 9; i++){
        if(vetor[i] < 0)
            printf("Numero: %d - Posicao: %d \n", vetor[i], i + 1);

    }
    return 0;
}

int main(){
    int vetor[9];

    Ler(vetor);
    printf(" \n\n");
    Negs(vetor);

    return 0;
}
