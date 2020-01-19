/*
*Trabalho Prático 1 de Algorítmos e Programaçãoo de Computadores
*Aluno : João Tribouillet Marcial de Menezes (14/0043209)
*
*Implementaçãoo de uma versão do jogo Senha ("Mastermind"). Nessa implementação
*Cria-se uma senha composta de cinco numeros distintos entre 1 e 6 em uma ordem
*aleatória. O jogador deve deduzir esses numeros a partir de chutes e de dicas
*recebidas do programa, que informa quantos numeros estavam certos nas posições
*certas e nas posições trocadas. O programa também executa uma verificação do
*chute do jogador verificando se não há repetições nos números informados ou se
*há um número maior que 6.
**/


#include <stdio.h>
#include <time.h>
#include <stdlib.h>

typedef int bool;
#define true 1
#define false 0


/*Função que retorna o valor dos contadores de numeros em posição correta e em posição trocada*/
void Contadores(int inserida[], int verdadeira[], int *posicao, int *ordem){
    int i, j;
    for (i = 0; i < 5; i++){
        if(inserida[i] == verdadeira[i])     /*Verificação de numeros nas posições corretas*/
            *posicao = *posicao + 1;         /*Aumenta-se o valor do valor apontado pelo ponteiro*/
        for(j = 0; j < 5; j++){
            if(inserida[i] == verdadeira[j]) /*Verificação de numeros nas posições trocadas*/
                *ordem = *ordem + 1;         /*Aumenta-se o valor do valor apontado pelo ponteiro*/
        }
    }
}

/*Função responsável por montar o vetor da dedução inserida pelo usuário*/
void Pegar_deducao(int inserida[]){
    int i;
    for (i = 0; i < 5; i++){
            scanf("%d", &inserida[i]);  /*Adiciona-se o valor inserido a sua respoectiva posição no vetor*/
        }
            /*Fim a Função*/
}

/*Função responsável por criar uma senha aleatória válida a ser descoberta pelo usuário*/
void Criar_senha(int senha[]){
    int i, j;       /*variaveis de contagem*/

    srand ( time(NULL) );
       for(i = 0; i < 5; i++){
        senha[i] = (rand() %6) + 1;         /*Cria-se um numero aleatório entre 1 e 6 e o coloca na posição i do vetor*/
        if (i > 0){
            for(j = i - 1; j >= 0; j--){    /*Checagem de igualdade entre o número agora alocado e os alocados anteriormente*/
                if(senha[i] == senha[j])    /*Se houver igualdade com algum numero ja definido, deve-se recriar o numero na posição i*/
                    i--;                    /*Possibilita a recriação, pois ao final do loop i tera o valor da posição a ser recriada*/
            }
        }
    }
    /*
    for(i = 0; i < 5; i++) {                loop que imprime a senha correta para melhor teste do programa
        printf("%d", senha[i]);
    }
    printf("\n\n");*/
}

/*Função responsável por checar a validade do valor inserido e indicar ao usuário as informações do chute*/
bool Checar_senha(int inserida[], int verdadeira[]){
    int contador_tudocerto = 0;         /*Contador de numeros nas posições corretas*/
    int contador_numerocerto = 0;       /*Contador de numeros nas posições trocadas*/
    bool erro = false;                  /*Variavel que indica erro no chute do usuário iniciada como falsa*/
    int i, j;                           /*Contadores de loops*/

    /*Checagem de erros no chute do usuário chegando:
    *-Igualdade entre numeros em diferentes posições
    *-Valor fora do escopo definido (1 - 6)
    */
    for (i = 0; i < 5; i++){
        for(j = 0; j < 5; j++){
            if(((inserida[i] == inserida[j]) && (i != j)) || (inserida[i] > 6) || (inserida[i] < 1))
                erro = true;
        }
    }

    /*Enquanto houver erro, deve-se indicar que houve erro e pedir uma nova senha*/
    while(erro){
        printf("Deducao invalida!!! Informe novamente:");   /*Indicação de erro*/
        Pegar_deducao(inserida);                            /*Nova requisição de senha*/
        erro = false;                                       /*Coloca-se erro em false*/

        /*Checagem de erros no chute do usuários é feita novamente*/
        for (i = 0; i < 5; i++){
            for(j = 0; j < 5; j++){
                if(((inserida[i] == inserida[j]) && (i != j)) || (inserida[i] > 6) || (inserida[i] < 1))
                    erro = true;
            }

        }
    }

    /*Quando o chute do usuário for valido, contas-e o numero de acertos nas posições certas e nas posições erradas*/
    Contadores(inserida, verdadeira, &contador_tudocerto, &contador_numerocerto);
    if(contador_tudocerto == 5){    /*Se a contagem de tudo certo estiver em 5, deve-se retornar true e indicar que o usuário ganhou  o jogo*/
        printf("\n\n\n\n\nParabens! voce acertou!");
        return(true);
    }
    else                            /*Caso contrario, indica as informações do chute e retorna false*/
        printf("Numeros em posicoes certas: %d \nNumeros em posicoes trocadas: %d \n\n", contador_tudocerto, contador_numerocerto - contador_tudocerto);
        return (false);
}


/*Função principal*/
int main(){
    int senha[5], deducao[5];   /*Vetores de senha a ser descoberta e dedução do usiário*/
    int N_tentativas = 1;       /*Contador do número de tentativas*/

    Criar_senha(senha);         /*Cria-se a senha*/

            /*Requisita-se do usuário um chute e o aloca no vetor deducao*/
    printf("Informe os numeros da deducao separados por espacos:");
    Pegar_deducao(deducao);

    /*Enquanto Checar_senha retornar false (dedução nao igual a senha) a requisição é feita novamente*/
    while(!Checar_senha(deducao, senha)){
        printf("Informe os numeros da deducao separados por espacos:");
        Pegar_deducao(deducao);

        N_tentativas++;            /*A cada dedução valida, incrementa-se o contador de tentativas*/
    }
    printf("\nNumero de tentativas: %d", N_tentativas);     /*Ao final do programa, é informado o numero de tentativas*/
    return (0);         /*Retorno da Função Main()*/
}
