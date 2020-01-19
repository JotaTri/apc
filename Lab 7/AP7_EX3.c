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

int main(){

    char nome_arq_l[20], nome_arq_e[30], carac;
    FILE *arq_l;
    FILE *arq_e;
    int i, id_aluno;
    float nota, media;

    printf("Indique o nome do arquivo que cotem as notas dos alunos: ");
    fgets(nome_arq_l, 20, stdin);
    for(i = 0; nome_arq_l[i] != '\0'; i++);
    nome_arq_l[i-1] = '\0';

    printf("Indique o nome do arquivo a ser criado com as medias dos alunos:");
    fgets(nome_arq_e, 20, stdin);
    for(i = 0; nome_arq_e[i] != '\0'; i++);
    nome_arq_e[i-1] = '\0';

    add_txt_nome(nome_arq_e);
    arq_e = fopen(nome_arq_e, "w");

    add_txt_nome(nome_arq_l);
    arq_l = fopen(nome_arq_l, "r+");


    while ((carac = fgetc(arq_l)) != EOF){
        media = 0;
        printf("%c", carac);
        while(carac = fgetc(arq_l) != '(');
        fscanf(arq_l, "%d", &id_aluno);
        while(carac = fgetc(arq_l) != ':');
        for(i = 0; i < 3; i++){
            fscanf(arq_l, "%f", &nota);
            media += nota;
        }
        media = media/3;
        while((carac = fgetc(arq_l) !='\n'));
        fprintf(arq_e, "%d : %.2f\n", id_aluno, media);
    }
    fclose(arq_e);
    fclose(arq_l);
    printf("\n\n\nAs identificacoes dos alunos e suas medias estao gaurdadas no arquivo '%s'", nome_arq_e);
    printf("na pasta em que esse programa foi executado. \n\n");
    return 0;

}
