/* Programa que calcula a hipotenusa de um triangulo retângulo cujos catetos
*  foram informados pelo usuário.
*  Aluno João Tribouillet Marcial de Menezes
*  Matricula - 14/0043209
*/

/* Bibliotecas a serem utilizadas no programa*/
#include <stdio.h>
#include <math.h>

int main(){
    /*declaração de variaveis*/
    float cat1, cat2, hip;


    /* É requerido do usuário que ele digite dois numeros reais que em seguida
    *  são alocados as suas respectivas variaveis
    */
    printf("Indique o valor do primeiro cateto do triangulo retangulo em questao: ");
    scanf("%f", &cat1);

    printf("Indique o valor do segundo cateto do triangulo retangulo em questao: ");
    scanf("%f", &cat2);

    /* É então feito o cálculo do valor da hipotenusa que então é impresso para o usuário*/
    hip = sqrt(cat1*cat1 + cat2*cat2);

    printf("O valor da hipotenusa do triangulo com catetos de valor %.2f e %.2f e' %.2f \n\n\n", cat1, cat2, hip);

    /*retorno da função main()*/
    return(0);

}
