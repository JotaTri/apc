#include <stdio.h>

void Leitura(float *nota1, float *nota2, float *nota3, int aluno){
    printf("Indique a nota da primeira prova feita pelo aluno %d: ", aluno);
    scanf("%f", &*nota1);
    printf("Indique a nota da segunda prova feita pelo aluno %d: ", aluno);
    scanf("%f", &*nota2);
    printf("Indique a nota da terceira prova feita pelo aluno %d: ", aluno);
    scanf("%f", &*nota3);

    return (0);
}

float Media(float nota1, float nota2, float nota3){
    return((3*nota1 + 3*nota2 + 4*nota3)/ 10);
}

int main(){
    float n1, n2, n3;
    int codigo, n, i;

    printf("Indique a quantidade de alunos a terem suas medias avaliadas:");
    scanf("%d",&n);
    for(i = 0; i < n; i++){
        printf("\nIndique o codigo do %d* aluno a ter sua media calculada:",i+1);
        scanf("%d", &codigo);
        Leitura(&n1,&n2,&n3,codigo);
        printf("\n\nA media do aluno %d e' %.2f \n\n",codigo, Media(n1,n2,n3));
    }
    return 0;
}
