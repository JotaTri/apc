#include <stdio.h>
#include <strings.h>

typedef int bool;
#define true 1
#define false 0

void imprimirIguais(char str1[], char str2[]){
    bool imprimir;
    int i, j, k, ini, fim, aux;

    fim = 0;
    i = 0;
    ini = 0;
    while(str1[i] != '\0'){
        imprimir = true;

        while(str1[fim] != ' ' && str1[fim] != '\0'){
            fim++;
        }
        for(j = 0; j < 20; j++){
            if (str1[ini] == str2[j]){
                    /*printf("%c(%d-%d)", str2[j], ini,j);*/
                for(k = 0; k < fim - ini; k++){
                    if(str1[ini + k] != str2[j + k]){
                        imprimir = false;
                       /* printf(" %c-%c ", str1[ini + k], str2[j + k]);*/
                    }
                }

                if (imprimir){
                    for(k = ini; k < fim; k++)      printf("%c", str1[k]);
                    printf(" ");
                }
            }
            imprimir = true;
        }
    fim++;
    i = fim;
    ini = fim;
    }

}

int main(){
    char str1[20], str2[20];
    int i;

    printf("Indique a primeira string: ");
    scanf("%[^\n]s%*c", &str1);
    getchar();
    printf("\nIndique a segunda string: ");
    scanf("%[^\n]s%*c", &str2);
    getchar();
    int tam = strlen(str2);
    str2[tam] = ' ';
    str2[tam + 1] = '\0';

    imprimirIguais(str1, str2);

    return 0;
}
