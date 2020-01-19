#include <stdio.h>

int main(){

    int codigo, atletamenor, atletamaior, i;
    float altura, menor, maior;
    menor = 500;
    maior = 0;

    for(i = 1; i <= 10; i++){
        printf("Indique o codigo do %d* atleta em questao: ", i);
        scanf("%d", &codigo);

        printf("Indique a altura em centimetros do atleta '%d':", codigo);
        scanf("%f", &altura);

        if(altura < menor){
            menor = altura;
            atletamenor = codigo;
        }
        if(altura > maior){
            maior = altura;
            atletamaior = codigo;
        }
    }
    printf("O menor atleta entre os %d comparados e' o %d com %.2fcm\n", i-1, atletamenor, menor);
    printf("O maior atleta entre os %d comparados e' o %d com %.2fcm\n", i-1, atletamaior, maior);

    return (0);

}
