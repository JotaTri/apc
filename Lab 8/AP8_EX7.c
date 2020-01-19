#include <stdio.h>

int Ler(int vetor[]){
    int i;
    printf("*******Para os valores inseridos a seguir, insira qualquer valor diferente de -1!****** \n\n");
    for(i = 0; i < 15; i++){
        printf("Indique o %d* numero do vetor em questao: ", i + 1);
        scanf("%d", &vetor[i]);
    }
    return (0);
}

int Compactar(int vetor[]){
    int i, j;
    for(i = 0; i < 15; i++){
        if(vetor[i] == 0){
            for(j = i; j < 14; j++){
                vetor[j] = vetor[j+1];
            }
            vetor[j] = -1;
            i--;
        }
    }
    return 0;
}

int imprimirCompactada(int vetor[]){
    int i;
    i = 0;
    while(vetor[i] != -1){
        printf("vetor[%d] = %d \n",i, vetor[i]);
        i++;
    }
    return 0;
}

int main(){
    int vetor[15];

    Ler(vetor);
    Compactar(vetor);
    printf("\n\n");
    imprimirCompactada(vetor);
}
