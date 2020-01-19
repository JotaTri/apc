#include <stdio.h>


int main () {
    int conjunto[15], inicio, fim, meio, valor, achou;
    /* leitura do vetor foi omitida */
    printf("Informe o valor a ser procurado:\n");
    scanf("%d", &valor);
    inicio = 0;
    fim = 14;
    achou = 0;
    while ((inicio <= fim) && (!achou)) {
            meio = (inicio + fim) / 2;
            if (valor < conjunto[meio])
                fim = meio - 1;
            else {
                if (valor > conjunto[meio])
                    inicio = meio + 1;
                else
                    achou = 1;
            }
    }
    if (achou)
        printf("%d encontrado na posicao %d.\n", valor, meio + 1);
    else
        printf("%d nao encontrado.\n", valor);
    return 0;
}
