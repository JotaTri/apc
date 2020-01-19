#include <stdio.h>
int main () {
 int ano;
 char sexo;

 printf("Informe o sexo: ");
 scanf("%c",&sexo);
 while ((sexo != 'f') && (sexo != 'F') && (sexo != 'm') &&
(sexo != 'M')){
 printf("Erro! ");
 printf("Informe o sexo novamente: ");
 getchar();
 scanf("%c",&sexo);
 }
 printf("Informe o ano: ");
 scanf("%d",&ano);
 printf("Saida - Ano = %d e Sexo = %c", ano, sexo);
 getchar();
 return (0);
}
