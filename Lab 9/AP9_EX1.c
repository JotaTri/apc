#include <stdio.h>

int Ler(int vetor[]){
    int i;

    for(i = 0; i < 10; i++){
        printf("Indique o %d* numero do vetor em questao: ", i+1);
        scanf("%d", &vetor[i]);
    }
    return 0;
}

int Imprimir(int vetor[]){
    int i;

    printf("O vetor ordenado é: \n");
    for(i = 0; i < 10; i++){
        printf("\t %d \n", vetor[i]);
    }
    return 0;
}

int bouble(int vetor[]){
    int i, aux;

    for(i = 0; i < 9; i++){
        if(vetor[i] > vetor[i+1]){
            aux = vetor[i];
            vetor[i] = vetor[i+1];
            vetor[i+1] = aux;
            i = -1;
        }
    }
    return 0;
}

int main(){
    int vetor[10];

    Ler(vetor);
    bouble(vetor);
    Imprimir(vetor);
    return 0;
}
