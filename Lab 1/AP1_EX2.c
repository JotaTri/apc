/*  Programa que calcula a m�dia de dois valores inseridos pelo usu�rio
*   Aluno Jo�o Tribouillet Marcial de Menezes
*   Matricula - 14/0043209
*/

/* Bibliotecas a serem utilizadas no programa*/
#include <stdio.h>

int main (){
    int num1, num2;
    float media;

    /* � requerido do usu�rio que ele digite dois numeros inteiros que em seguida
    *  s�o alocados as suas respectivas variaveis
    */
    printf("Digite o primeiro numero inteiro: ");
    scanf("%d", &num1);

    printf("\nDigite o segundo numero inteiro: ");
    scanf("%d", &num2);

    /* � feita o calculo da m�dia dos numeros com um casting para permitimos resultados
    *  com valores decimais e, em seguida, � informado a media para o usu�rio
    */
    media = (float)(num1 + num2)/2;

    printf("\n\n\nA media de %d e %d e' %.2f",num1, num2, media);

    /*retorno da fun��o main()*/
    return(0);

}
