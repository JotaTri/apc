#include <stdio.h>

int main(){

    float media, nota;
    int aluno, n, i, j;

    printf("Indique o numero de alunos cujas medias serao calculadas: ");
    scanf("%d", &n);

    for(i = 1; i <= n; i++){
        media = 0;
        printf("Indique o codigo do %d* aluno em questao: ", i);
        scanf("%d", &aluno);
        for(j = 1; j <= 3; j++){
            printf("Indique a nota da %d* prova do aluno '%d': ", i, aluno);
            scanf("%f", &nota);
            media += nota;
            if (j > 1)
                media += nota;
        }
        printf("A media ponderada do aluno '%d' e' %.2f \n\n", aluno, media/5);
    }
}
