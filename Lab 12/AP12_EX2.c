#include <stdio.h>

int fat(int n)
{
 if (n==0)
    return 1;
 else
    return n*fat(n-1);
}

int main(){
    int n;

    printf("Indique um numero maior ou igual a zero: ");
    scanf("%d", &n);

    printf("\n\n%d! e' igual a %d", n, fat(n));

    return 0;
}
