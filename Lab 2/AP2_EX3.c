
/* Programa que calcula as raízes reais de uma equação do segundo grau cujos coeficientes
*  e as informa para o usuário juntamente com a equação formada.
*  Aluno João Tribouillet Marcial de Menezes
*  Matricula - 14/0043209
*/

/* Bibliotecas a serem utilizadas no programa*/
#include <stdio.h>
#include <math.h>

/*definição de um type bool para uso de logica booleana no código*/
typedef int bool;
#define true 1
#define false 0

int main(){
    /*declaração de variaveis*/
    float a, b, c, delta, x1, x2;
    bool signB, signC, signD;



    /* é requerido do usuário que ele digite tres numeros reais que correspondam
    *  aos coeficientes da equação de segundo grau*/
    printf("Indique o valor do coeficiente 'a' da equacao: ");
    scanf("%f", &a);

    printf("\nIndique o valor do coeficiente 'b' da questao: ");
    scanf("%f", &b);


    printf("\nIndique o valor do coeficiente 'c' da questao: ");
    scanf("%f", &c);

     /* Para os coeficientes 'b' e 'c' é analizado seus respectivos sinais para
     *  melhor imprimir a equação inteira formada */
        if(b >= 0)
        signB = true;
    else
        signB = false;

        if(c >= 0)
        signC = true;
    else
        signC = false;


    /* São então feitos os calculos para o delta e as raizes da equação em questão.
    *  Como a função sqrt() retorna a raiz positiva, para 'x2' foi usada '-sqrt(delta)'
    */
    delta = (b*b) - (4*a*c);
    if (delta > 0)
        signD = true;
    else
        signD = false;

    if(signD){
    x1 = ((sqrt(delta) - b)/(2*a));
    x2 = ((-sqrt(delta) - b)/(2*a));
    }


    /* É então impresso para o usuário a equação inteira com os coeficientes por ele
    *  informados e as raizes da mesma quando o discriminante for maior ou igual a zero.
    *  Para discriminante menor que zero, uma mensagem será informada
    *  Para a impressão da equação, deve-se considerar numeros negativos, que ja são
    *  impressos com o seu sinal, e numeros positivos, que quando impressos só mostram
    *  o numero. Portanto para o caso de numeros positivos, além do numero, deve-se
    *  imprimir ' + ' antes, para formar a equação de fato
    */

    printf("As solucoes da equacao '%.2fx^2", a);
    if(signB)
        printf(" + %.2f", b);
    else
        printf(" %.2f", b);
    printf("x");
    if(signC)
        printf(" + %.2f", c);
    else
        printf(" %.2f");
    if(signD)
        printf(" sao: \nx1 = %.2f \nx2 = %.2f \n\n\n\n",x1, x2);
    else
        printf(" nao puderam ser calculadas pois seu discriminante e' menor que zero");

    printf("\n\n\n\n\n");

    /*retorno da função main()*/
    return (0);



    }
