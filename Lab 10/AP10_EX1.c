#include <stdio.h>

int main(){
    char gaba[10], resp[20];
    int nAlunos, i, j, nota, notaM;

    notaM = 0;
    nota = 0;
    printf("Indique o gabarito da prova em questao");
    scanf("%s", &gaba);

    printf("Indique a quantidade de alunos");
    scanf("%d", &nAlunos);

    for(i = 0; i < nAlunos; i++){
        printf("Indique a resposta do aluno %d:", i+1);
        scanf("%s", &resp);

        for(j = 0; j < 10; j++){
            if(gaba[j] == resp[j])
                nota++;
        }
        if(nota > notaM)
            notaM = nota;
        nota = 0;
    }
    printf("A maior nota foi %d", notaM);
}
