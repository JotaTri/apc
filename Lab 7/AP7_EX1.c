#include <stdio.h>


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

    char nome_arq[20];
    int n_alunos, id_alunos, i, j;
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

    for(i = 0; i < n_alunos; i++){

        printf("Indique a identificacao do %d* aluno:", i+1);
        scanf("%d", &id_alunos);
        fprintf(arq, "%d : ", id_alunos);

        printf("Indique as tres notas do aluno:");
        for(j = 0; j < 3; j++){
            scanf("%f", &notas);
            fprintf(arq, "%.2f   ", notas);
        }
        fprintf(arq, "\n");
    }
    fclose(arq);
    printf("\n\n\nAs notas dos %d alunos estao gravadas no arquivo '%s' na pasta pasta em que esse programa foi executado.",n_alunos, nome_arq);
    return 0;
}
