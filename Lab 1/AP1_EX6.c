/* Programa que calcula a média final de um Aluno a partir de notas e respectivos
*  pesos informados pelo usuário.
*  Aluno João Tribouillet Marcial de Menezes
*  Matricula - 14/0043209
*/

/* Bibliotecas a serem utilizadas no programa*/
#include <stdio.h>

int main(){

    /*declaração de variaveis*/
    float nota1, nota2, nota3;
    float peso1, peso2, peso3;
    float media;

    /* É requerido do usuário que ele digite seis numeros inteiros que em seguida
    *  são alocados as suas respectivas variaveis (3 notas e 3 pesos);
    */
    printf("Indique a nota da primeira prova do aluno em questao: ");
    scanf("%f", &nota1);

    printf("Indique o peso da primeira prova: ");
    scanf("%f", &peso1);


    printf("Indique a nota da segunda prova do aluno em questao: ");
    scanf("%f", &nota2);

    printf("Indique o peso da segunda prova: ");
    scanf("%f", &peso2);


    printf("Indique a nota da terceira prova do aluno em questao: ");
    scanf("%f", &nota3);

    printf("Indique o peso da terceira prova: ");
    scanf("%f", &peso3);

    /* É então feito o cálculo da média do aluno levando em conta os respectivos pesos que então
    *  é impresso em seguida*/
    media = (nota1*peso1 + nota2*peso2 + nota3*peso3)/(peso1 + peso2 + peso3);


    printf("\n\nA media do aluno que tirou as notas %.2f, %.2f e %.2f com respectivos pesos %.2f, %.2f e %.2f e': %.2f", nota1, nota2, nota3, peso1, peso2, peso3, media);

    /*retorno da função main()*/
    return (0);

}
