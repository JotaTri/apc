#include <stdio.h>
/* Descricao: programa para imprimir os numeros de 1 a 10.
Entrada: nao tem
Saida: 1,2,3,...,10 */
int main () {
int i;
printf("Os numeros de 1 a 10 sao: ");
for (i=1;i<11;i++) {
 printf("\n%d ",i);
 getchar();
}

return 0;
}
