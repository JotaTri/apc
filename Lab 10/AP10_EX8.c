#include <stdio.h>


int main(){
    char str1[25], str2[25];
    int i, j, aux, k;

    aux = -1;
    k = 0;
    i = 0;

    printf("Indique a String em questao: ");
    scanf("%[^\n]s%*c", str1);

    while(str1[i] != '\0'){
        i++;
        for(; (str1[i] != ' ') && (str1[i] != '\0'); i++);
        for(j = i - 1; j > aux; j--){
            str2[k] = str1[j];
            k++;
        }
        if(str1[i] == '\0'){
            str2[k] = '\0';
            break;
        }
        str2[k] = ' ';
        k++;
        aux = i;
    }
        str2[k] = '\0';

    printf(" \n\n%s", str2);
    return 0;
}
