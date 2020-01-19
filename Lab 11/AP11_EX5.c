#include <stdio.h>


void LerM(int linhas, int colunas, int MAT[linhas][colunas]){
    int i, j;

    printf("Indique os %d numeros da matriz separados por espacos: ",linhas*colunas);
    for(i = 0; i < linhas; i++){
        for(j = 0; j < colunas; j++){
            scanf("%d", &MAT[i][j]);
        }
    }

}

void LerV(int tamanho, int VET[tamanho]){
    int i;

    printf("Indique os %d numeros do vetor separados por espacos: ", tamanho);
    for(i = 0; i < tamanho; i++){
        scanf("%d", &VET[i]);
    }

}

int Comparar(int linhas, int colunas, int MAT[linhas][colunas], int VET[colunas]){
    int i, j, iguais;

    for(i = 0; i < linhas; i++){
        iguais = 0;
        for(j = 0; j < colunas; j++){
            if(MAT[i][j] == VET[j])
                iguais++;
        }
        if(iguais == colunas)
            return i;
    }
    return -1;
}

int main(){
    int MAT[5][5], VET[5], caso, linhas, colunas;

    printf("Indique o numero de linhas que a matriz em questao tem: ");
    scanf("%d", &linhas);
    printf("Indique o numero de colunas que a matriz em questao tem: ");
    scanf("%d", &colunas);

    LerM(linhas, colunas, MAT);
    LerV(colunas, VET);

    caso = Comparar(linhas, colunas, MAT, VET);
    switch (caso){
        case -1:
            printf("Nao foi possivel identificar nenhuma linha da matriz igual ao vetor indicado");
            break;
        default:
            printf("A linha %d da matriz e' igual ao vetor indicado", caso + 1);
            break;
    }

    return 0;
}
