#include <stdio.h>

void Compactar(char str[], char strC[]){
 char ant;
 int i, k, cont;

 i = 0;
    k = 0;
    cont = 1;
    while(str[i] != '\0'){
        ant = str[i];

        while(str[cont + i] == ant){
            cont++;
        }

        i += cont;
        if(cont > 1){
            strC[k] = cont + 0x30;
            k++;
        }
        strC[k] = str[i-1];
        k++;
        cont = 1;
    }
    strC[k] = '\0';
}
int main(){
    char str[25], strC[50];

    printf("Indique a string a ser compactada: ");
    scanf("%[^\n]s%*c", &str);

    Compactar(str, strC);
    printf("%s", strC);

    return 0;
}
