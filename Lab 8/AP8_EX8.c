#include <stdio.h>

typedef int bool;
#define true 1
#define false 0

int Ler(int vetor[]){
    int i;
    for(i = 0; i < 10; i++){
        printf("Indique o %d* numero do vetor em questao: ", i + 1);
        scanf("%d", &vetor[i]);
    }
    return (0);
}

int InterUni(int vetor1[], int vetor2[], int Inter[], int Uni[]){
    int i, j, k, in, un, sen;
    int sentinelas[10];
    in = 0;
    un = 0;
    sen = 0;
    bool inserir;
    inserir = true;
    for(i = 0; i < 10; i++){
        Uni[i] = vetor2[i];
        un++;
    }
    for(i = 0; i < 10; i++){
        for (j = 0; j < 10; j++){
            if(vetor1[i] == vetor2[j]){
                Inter[in] = vetor1[i];
                sentinelas[sen] = vetor1[i];
                in++;
                sen++;
            }

        }
        for(j = 0; j < 10; j++){
                if(vetor1[i] == sentinelas[j])
                    inserir = false;
        }
        if(inserir){
                Uni[un] = vetor1[i];
                un++;
        }
        inserir = true;
    }
    Uni[un] = -1;
    Inter[in] = -1;
    return 0;
}

int Imprimir(int vetor []){
    int i;
    i = 0;

    while(vetor[i] != -1){
        printf("\t\t%d* = %d \n",i + 1, vetor[i]);
        i++;
    }
}

int main(){
    int X[10], Y[10], Int[10], Uni[20];
    Ler(X);
    Ler(Y);
    InterUni(X,Y,Int,Uni);
    printf(" \n\nA interseccao corresponde a:\n");
    Imprimir(Int);
    printf("\n\n");
    printf(" \n\nA uniao corresponde a:\n");
    Imprimir(Uni);

    return 0;


}
