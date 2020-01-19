#include<stdio.h>

void Ler(int linhas, int colunas, int MAT[linhas][colunas]){
    int i, j;

    printf("Indique os %d numeros da matriz separados por espacos: ",linhas*colunas);
    for(i = 0; i < linhas; i++){
        for(j = 0; j < colunas; j++){
            scanf("%d", &MAT[i][j]);
        }
    }

}

void Negs(int linhas, int colunas, int MAT[linhas][colunas], int C[linhas]){
    int i, j, negs;

    negs = 0;

    for(i = 0; i < linhas; i++){
        for(j = 0; j < colunas; j++){
            if(MAT[i][j] < 0)
                negs++;
        }
        C[i] = negs;
        negs = 0;
    }

}

void ImpVet(int linhas, int C[linhas]){
    int i;

    for(i = 0; i < linhas; i++){
        printf("há %d numeros negativos na linhas %d \n", C[i], i+1);
    }

}

int main(){
    int C[5], MAT[5][5], linhas, colunas;

    printf("Indique o numero de linhas que a matriz em questao tem: ");
    scanf("%d", &linhas);
    printf("Indique o numero de colunas que a matriz em questao tem: ");
    scanf("%d", &colunas);

    Ler(linhas, colunas, MAT);
    Negs(linhas, colunas, MAT, C);
    ImpVet(linhas, C);

    return 0;


}
