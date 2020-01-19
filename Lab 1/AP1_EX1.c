/* Programa que troca o valor de duas variaveis com o uso de uma variavel auxiliar
*  Aluno João Tribouillet Marcial de Menezes
*  Matricula - 14/0043209
*/

/* Bibliotecas a serem utilizadas no programa*/
#include <stdio.h>

int main(){
    /*declaração de variaveis*/
    int a, b, aux;
    /* É impresso na tela o requerimento dos dois numeros a serem trocados e em seguidas alocadas
    *  a sua respectiva variavel
    */
    printf("Escreva o primeiro numero inteiro: ");
    scanf("%d", &a);

    printf("Escreva o segundo numero inteiro: ");
    scanf("%d", &b);

    /* é usada a variavel aux para guardar o valor de uma das variaveis temporariamente*/
    aux = a;
    a = b;
    b = aux;

    /* As variaveis agora são impressas com os seus valores trocados aos inseridos pelo usuário*/
    printf("O primeiro numero agora tem o valor: %d", a);
    printf("\nO segundo numero agora tem o valor: %d \n\n\n\n", b);

    /*retorno da função main()*/
    return(0);

}

