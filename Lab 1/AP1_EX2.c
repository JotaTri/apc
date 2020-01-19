/*  Programa que calcula a média de dois valores inseridos pelo usuário
*   Aluno João Tribouillet Marcial de Menezes
*   Matricula - 14/0043209
*/

/* Bibliotecas a serem utilizadas no programa*/
#include <stdio.h>

int main (){
    int num1, num2;
    float media;

    /* é requerido do usuário que ele digite dois numeros inteiros que em seguida
    *  são alocados as suas respectivas variaveis
    */
    printf("Digite o primeiro numero inteiro: ");
    scanf("%d", &num1);

    printf("\nDigite o segundo numero inteiro: ");
    scanf("%d", &num2);

    /* É feita o calculo da média dos numeros com um casting para permitimos resultados
    *  com valores decimais e, em seguida, é informado a media para o usuário
    */
    media = (float)(num1 + num2)/2;

    printf("\n\n\nA media de %d e %d e' %.2f",num1, num2, media);

    /*retorno da função main()*/
    return(0);

}
