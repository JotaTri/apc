#include <stdio.h>

void iguais(int *numero, int *vezes, int m, int n, int matriz[m][n]){
    int i, j, k;

    for(i = 0; i < m; i++){
        for(j = 0; j < m; j++){
            for(k = 0; k < n; k++){
                if((matriz[i][k] == matriz[j][k])&&(i != j)){
                    *numero = matriz[i][k];
                }
            }
        }
    }
     for(i = 0; i < m; i++){
        for(j = 0; j < m; j++){
                if(matriz[i][j] == *numero)
                    *vezes = *vezes + 1;
        }
     }
}

void pegarM(int linhas, int colunas, int matriz[linhas][colunas]){
    int i, j;

    printf("Indique os %d numeros da matriz em questao separados por espaco", linhas*colunas);

    for(i = 0; i < linhas; i++){
        for(j = 0; j < colunas; j++){
            scanf("%d", &matriz[i][j]);
        }
    }
}

int main(){
    int m, n, numero, nVezes;
    nVezes = 0;

    printf("Indique o numero de linhas da matriz: ");
    scanf("%d", &m);
    printf("Indique o numero de colunas da matriz: ");
    scanf("%d", &n);

    int A[m][n];

    pegarM(m, n, A);
    iguais(&numero, &nVezes, m, n, A);

    if(nVezes == 1)
        printf("Nao ha' numeros repetidos na matriz \n\n\n");
    else
        printf("O numero repetido e' %d e ele aparece %d vezes na matriz", numero, nVezes);

    return 0;
}
