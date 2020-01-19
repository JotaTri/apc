#include <stdio.h>

void Ler(int vetor[], int tamanho){
    int i;
    for (i = 0; i < tamanho; i++){
        printf("Indique o %d* numerdo inteiro positivo do vetor em questao:", i+1);
        scanf("%d", &vetor[i]);
    }
    vetor[i] = -1;
}
void Par_Impar(int vetor[], int *par, int *impar){
    int i;
    for(i = 0; vetor[i] >= 0; i++){
        if(vetor[i]%2 == 0)
            *par = *par + 1;
        else
            *impar = *impar + 1;
    }
    return 0;
}

int main(){
    int vetor[21];
    int par, impar, tamanho;

    printf("Indique o tamanho do vetor a ser verificado (valor menor ou iguais a 20)");
    scanf("%d", &tamanho);

    par = 0;
    impar = 0;

    Ler(vetor, tamanho);
    Par_Impar(vetor, &par, &impar);
    printf("Ha %d numero(s) pare(s) e %d numero(s) impare(s) no vetor inserido", par, impar);

    return 0;
}

