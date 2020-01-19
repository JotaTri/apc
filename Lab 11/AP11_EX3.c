#include <stdio.h>


void Ler(int MAT[4][4]){
    int i, j;

    printf("Indique os 16 numeros da matriz separados por espacos: ");
    for(i = 0; i < 4; i++){
        for(j = 0; j < 4; j++){
            scanf("%d", &MAT[i][j]);
        }
    }

}

void ImpMat(int MAT[4][4]){
    int i, j;

    for(i = 0; i < 4; i++){
        for(j = 0; j < 4; j++){
            printf("%d  ", MAT[i][j]);
        }
        printf("\n");
    }

}

void Nulas(int MAT[4][4], int *linhas, int *colunas){
    int i, j, zeros;

    zeros = 0;

    for(i = 0; i < 4; i++){
        for(j = 0; j < 4; j++){
            if(MAT[i][j] == 0)
                zeros++;
        }
        if(zeros == 4)
            *linhas = *linhas + 1;
        zeros = 0;
    }

    for(i = 0; i < 4; i++){
        for(j = 0; j < 4; j++){
            if(MAT[j][i] == 0)
                zeros++;
        }
        if(zeros == 4)
            *colunas = *colunas + 1;
        zeros = 0;
    }
}

int main(){
    int MAT[4][4];
    int linhas, colunas;

    linhas = 0;
    colunas = 0;

    Ler(MAT);
    Nulas(MAT, &linhas, &colunas);
    ImpMat(MAT);

    printf("Na matriz acima, ha' %d linhas nulas e %d colunas nulas \n\n\n", linhas, colunas);

    return 0;
}
