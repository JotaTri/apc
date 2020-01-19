#include <stdio.h>

void MM(int a, int b, int c, int *maior, int *menor){
    if((a > b)&&(a > c)){
       *maior = a;
       if(b < c)
            *menor = b;
        else
            *menor = c;
       }
    else if(b > c){
            *maior = b;
            if(a < c)
                *menor = a;
            else
                *menor = c;
        }
    else
        *maior = c;
        if(b < a)
            *menor = b;
        else
            *menor = a;
    return (0);
}

int main(){
    int num1, num2, num3, maior, menor;

    printf("Insira o valor do 1* numero:");
    scanf("%d", &num1);
    printf("Insira o valor do 2* numero:");
    scanf("%d", &num2);
    printf("Insira o valor do 3* numero:");
    scanf("%d", &num3);

    MM(num1, num2, num3, &maior, &menor);

    printf("\n\n\nO maior numero dentre (%d,%d,%d) e' %d. \nO menor numero dentre o mesmo conjunto e' %d. \n\n\n\n", num1, num2, num3, maior, menor);

    return 0;
}
