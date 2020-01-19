/* Programa que calcula a hipotenusa de um triangulo ret�ngulo cujos catetos
*  foram informados pelo usu�rio.
*  Aluno Jo�o Tribouillet Marcial de Menezes
*  Matricula - 14/0043209
*/

/* Bibliotecas a serem utilizadas no programa*/
#include <stdio.h>
#include <math.h>

int main(){
    /*declara��o de variaveis*/
    float cat1, cat2, hip;


    /* � requerido do usu�rio que ele digite dois numeros reais que em seguida
    *  s�o alocados as suas respectivas variaveis
    */
    printf("Indique o valor do primeiro cateto do triangulo retangulo em questao: ");
    scanf("%f", &cat1);

    printf("Indique o valor do segundo cateto do triangulo retangulo em questao: ");
    scanf("%f", &cat2);

    /* � ent�o feito o c�lculo do valor da hipotenusa que ent�o � impresso para o usu�rio*/
    hip = sqrt(cat1*cat1 + cat2*cat2);

    printf("O valor da hipotenusa do triangulo com catetos de valor %.2f e %.2f e' %.2f \n\n\n", cat1, cat2, hip);

    /*retorno da fun��o main()*/
    return(0);

}
