#include <stdio.h>

int Ler(int vetor[]){
    int i;
    for(i = 0; i < 12; i++){
        printf("Indique a Temperatura do %d* mes do ano em questao: ", i + 1);
        scanf("%d", &vetor[i]);
    }
    return (0);
}

int MenMaiTemp(int vetor[], int *maior, int *menor, int *Mmaior, int *Mmenor){
    int i;
    *maior = -100;
    *menor = 100;

    for(i = 0; i < 12; i++){
        if(*maior < vetor[i]){
            *maior = vetor[i];
            *Mmaior = i + 1;
        }
        if(*menor > vetor[i]){
            *menor = vetor[i];
            *Mmenor = i + 1;
        }
    }
    return 0;
}

int main(){
    int maior, menor, mesMenor, mesMaior, temps[12];

    Ler(temps);
    MenMaiTemp(temps, &maior, &menor, &mesMaior, &mesMenor);
    printf("Menor temperatura do ano: %d \n\tMes: %d",menor, mesMenor);
    printf(" \nMaior temperatura do ano: %d \n\tMes: %d",maior, mesMaior);

    return 0;

}
