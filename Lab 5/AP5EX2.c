#include <stdio.h>

float PesoIdeal(float altura, char sexo){
    if(sexo == 'm' || sexo == 'M')
        return(72.7*altura - 58);
    else if(sexo == 'f' || sexo == 'F')
        return (62.1*altura - 44.7);
    return 666;
}

int main(){
    int n, i;
    float altura;
    char sexo;

    printf("Indique a quantidade de pessoas a serem analisadas:");
    scanf("%d", &n);

    for(i = 0; i < n; i++){
    printf("Indique  o sexo da pessoa em questao: ");
    scanf(" %c", &sexo);

    printf("Indique a altura da pessoa em questao: ");
    scanf("%f", &altura);

    printf("\nO peso ideal da pessoa em queestao e' %.2fKg.\n\n",PesoIdeal(altura, sexo));

    }
    return (0);
}
