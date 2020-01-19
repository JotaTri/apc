#include <stdio.h>

int main(){

    float indice;

    printf("Informe o Indice de Poluicao atual: ");
    scanf("%f", &indice);

    if(indice < 0.05)
        printf("Indice de Poluicao abaixo do normal");
    else if(indice < 0.25)
        printf("Indice de Poluicao normal");
    else if(indice < 0.3)
        printf("Indice de Poluicao acima do normal\nEstado de ALERTA");
    else if(indice < 0.4 )
         printf("Indice de Poluicao acima do normal\nSUSPENSAO DE ATIVIDADES DAS INDUSTRIAS DA LISTA 'A'");
    else if(indice < 0.5 )
        printf("Indice de Poluicao acima do normal\nSUSPENSAO DE ATIVIDADES DAS INDUSTRIAS DAS LISTAS 'A' e 'B'");
    else
        printf("Indice de Poluicao acima do normal\nSUSPENSAO DE ATIVIDADES DAS INDUSTRIAS DAS LISTAS 'A' e 'B' e 'C'");
    printf("\n\n");

    return (0);
}
