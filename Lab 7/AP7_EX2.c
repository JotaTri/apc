#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void add_txt_nome( char *nome){
    int i, j;
    char *txt = ".txt";

    for(i = 0; nome[i] != '\0'; i++);
    for(j = 0; txt[j] != '\0'; j++){
        nome[i] = txt[j];
        i++;
    }
    nome[i] = '\0';
    return 0;
}
int main(void){

    char nome_arq[20], nome_aluno[30];
    int n_alunos, id_alunos, i, j, w;
    float notas;
    FILE *arq;

    printf("Indique o nome do arquivo a ser criado: ");
    /*fgets(nome_arq, sizeof(nome_arq), stdin);*/
    fgets(nome_arq, 20, stdin);
    for(i = 0; nome_arq[i] != '\0'; i++);
    nome_arq[i-1] = '\0';


    add_txt_nome(nome_arq);
    arq = fopen(nome_arq, "w");

    printf("Indique a quantidade de alunos a terem suas notas registradas: ");
    scanf("%d", &n_alunos);

    for(j = 0; j < n_alunos; j++){

        printf("Indique a identificacao do %d* aluno:", j+1);
        scanf("%d", &id_alunos);

        printf("Indique o nome do aluno:");
        getchar();
        fgets(nome_aluno, 30, stdin);

        for(i = 0; nome_aluno[i] != '\0'; i++);
        nome_aluno[i-1] = '\0';

        fprintf(arq, "%s ( %d ) : ",nome_aluno, id_alunos);

        printf("Indique as tres notas do aluno %s(%d):", nome_aluno, id_alunos);
        for(w = 0; w < 3; w++){
            scanf("%f", &notas);
            fprintf(arq, "%.2f   ", notas);
        }
        fprintf(arq, "\n");
    }
    fclose(arq);
    printf("\n\n\nAs notas dos %d alunos estao gravadas no arquivo '%s' na pasta pasta em que esse programa foi executado.",n_alunos, nome_arq);
    return 0;
}
