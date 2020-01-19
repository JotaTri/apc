#include <stdio.h>

void Ler(int vetor[]){
    int i;
    for (i = 0; i < 6; i++){
        printf("Indique o %d* numerdo inteiro positivo do vetor em questao:", i+1);
        scanf("%d", &vetor[i]);
    }
}
void Par_Impar(int vetor[], int *par, int *impar){
    int i;
    for(i = 0; i < 6; i++){
        if(vetor[i]%2 == 0)
            *par = *par + 1;
        else
            *impar = *impar + 1;
    }
    return 0;
}

int main(){
    int vetor[6];
    int par, impar;

    par = 0;
    impar = 0;

    Ler(vetor);
    Par_Impar(vetor, &par, &impar);
    printf("Ha %d numero(s) pare(s) e %d numero(s) impare(s) no vetor inserido", par, impar);

    return 0;
}
