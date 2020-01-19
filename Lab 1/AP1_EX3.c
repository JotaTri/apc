/*  Programa que calcula o volume de um cilindro a partir de valores de raio da base
*   informados pelo usu�rio
*   Aluno Jo�o Tribouillet Marcial de Menezes
*   Matricula - 14/0043209
*/

/* Bibliotecas a serem utilizadas no programa*/
#include <stdio.h>

int main(){
    /*declara��o de variaveis*/
    float raio, altura, volume;
    const float pi = 3.14;

    /* � requerido do usu�rio que ele digite dois numeros reais que em seguida
    *  s�o alocados as suas respectivas variaveis
    */
    printf("Informe o valor do raio da base do cilindro em questao: ");
    scanf("%f", &raio);

    printf("\nInforme o valor da altura do cilindro em questao: ");
    scanf("%f", &altura);


    /* � ent�o feito o calculo do volume do cilindro com as suas dimens�es e ent�o seu valor � informado*/
    volume = pi*raio*raio*altura;

    printf("\n\n O volume do cilindro com raio %.2f e altura %.2f e' %.2f", raio, altura, volume);

    /*retorno da fun��o main()*/
    return(0);

}
