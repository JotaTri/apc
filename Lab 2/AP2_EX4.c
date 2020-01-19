#include <stdio.h>

int main(){

    float a, b, x, y, altura, largura;


    printf("Informe o valor correspondente a abicissa do ponto inicial do retangulo");
    scanf("%f", &x);

    printf("Informe o valor correspondente a ordenada do ponto inicial do retangulo");
    scanf("%f", &y);


    printf("Informe o valor da largura do retangulo em questao (positivo): ");
    scanf("%f", &largura);

    printf("\nInforme o valor da altura do retangulo em questao (positivo): ");
    scanf("%f", &altura);

    printf("\n\n\nAgora informe o valor correspondente a abicissa do ponto que deve-se checar a posicao: ");
    scanf("%f", &a);

    printf("\nAgora informe o valor correspondente a ordenada do ponto que deve-se checar a posicao: ");
    scanf("%f", &b);


    if((a > x + largura )||(b > y + altura)||(a < x)||(b < y))
        printf("\n\n\n\nO ponto (%.2f;%.2f) nao se encontra dentro do retangulo com largura %.2f e altura %.2f \n\n\n\n", a, b, x, y);

    else if(((a == x)||(a == x + largura))&&(y < b + altura)   ||   ((b == y)||(b == y + altura))&& (x < a + largura))
        printf("\n\n\n\nO ponto (%.2f;%.2f) se encontra em uma das linhas que define o retangulo de largura %.2f e altura %.2f \n\n\n\n", a, b, x, y);

    else
        printf("\n\n\n\nO ponto (%.2f;%.2f) se encontra dentro do retangulo de largura %.2f e altura %.2f \n\n\n\n", a, b, x, y);

    return (0);


}
