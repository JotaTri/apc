/*Universidade de Brasilia
* Instituto de Cincias Exatas
* Departamento de Ciencia da Computacao
*
* Algoritmos e Programação de Computadores - 1/2016
*
* Aluno: João Tribouillet Marcial de Menezes
* Matricula: 140043209
* Turma H
*
* Descricao: Programa que cria relatorios de um campeonato de futebol
* a partir de escrita de registros de partidas em arquivos binarios.
* a qualquer momento o usuario poderá escolher opções de como proseguir
* com o uso do programa a partir de funçoes mostradas em um menu principal.
* Cada opção escolhida checara a viabilidade de sua propria execução e realizara
* uma ação apropriada ao obter uma resposta.
* O arquivo binario com todos os jogos incuidos pelo usuario e organizado a partir
* do numero da rodada e, apos isso, pelo numro do jogo a cada inclusão feita
* pelo usuario para melhor manuseio e organização do arquivo
* Um arquivo de texto pode ser criado a qualquer momento, onde, a partir de uma
* organização pre determinada, todos os jogos e seus conteudos são expressos em 
* ordem de rodada e de jogo. Esse arquivo termina com estatisticas finais de 
* todos os jogos que se encontravam no arquivo binario
*/

/*Bibliotecas utilizadas no projeto*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Definicao do Registro Jogo utilizado no projeto */
typedef struct
{
	int nJogo;
	char nTimeCasa[16];
	char nTimeVisitante[16];
	char estadio[21];
	char hora[6];
	char data[9];
	int rodada;
	int publico;
	float renda;
	int golsCasa;
	int golsVisitante;
} Jogo;

/*Definicao de um tipo booleano utilizado no projeto*/
typedef int bool;
#define true 1
#define false 0

Jogo pegarDados();
int menuPrincipal();
void criarCadastro(FILE *arquivo);
void incluirDados(FILE *arquivo);
bool testarArquivo(char *nome);
void escreverPartidaBin(FILE *arquivo, Jogo cadastro);
void truncarStruct(bool fim, int cont, FILE *arquivo, Jogo cadastro);
void consultarCadastroNJ(FILE *arquivo);
void imprimirPartidaTela(Jogo partida);
void consultarCadastroR(FILE *arquivo);
int contarNumeroUmaRodada(int rodada, FILE *arquivo, int *fim, Jogo partida);
void imprimirJogosRodada(FILE *arquivo, int cont, int flagFim);
void limparTela();
void naohaarquivo(FILE *arquivo);
void gerarTxt(FILE *arqBin);
void gerarTextoStruct(int tamanho, Jogo vetJogos[tamanho]);
void estatisticasFinais(FILE *arqBin);

/*******************************************************************************/
/*Funcao principal do programa.
* Ela consiste em um loop infinito com um switch-case que se refere aas
* opções escolhidas do menu principal.
* Em todos os casos, checa-se a existencia do arquivo binario e e feita
* a acao adequada para a resposta obtida.
*/
int main(){
	char in = 'y';
    FILE *arqBin;

    while(1){
        switch(menuPrincipal()){
        case 1:
        	if(testarArquivo("Jogos.bin")){
                getchar();
        		printf("Ja ha' um arquivo criado!\nDeseja-se substitui-lo por um novo? (Y/N)");
        		scanf("%c", &in);
        		if(in == 'y' || in == 'Y'){
            		criarCadastro(arqBin);
        		}
       		}
       		else
       			criarCadastro(arqBin);
            break;
        case 2:
        	if(testarArquivo("Jogos.bin"))
            	incluirDados(arqBin);
            else
            	naohaarquivo(arqBin);
            break;
        case 3:
        	if(testarArquivo("Jogos.bin"))
            	consultarCadastroNJ(arqBin);
            else
            	naohaarquivo(arqBin);
            break;
        case 4:
        	if(testarArquivo("Jogos.bin"))
            	consultarCadastroR(arqBin);
            else
            	naohaarquivo(arqBin);
            break;
        case 5:
            if(testarArquivo("Jogos.bin")){
                if(testarArquivo("Relatorio.txt")){
                    limparTela();
                    getchar();
                    printf("Ja' ha' um arquivo de relatorio criado!\nDeseja substitui-lo?(Y/N): ");
                    scanf("%c", &in);
                }
                if(in == 'y' || in == 'Y'){
                    limparTela();
                    gerarTxt(arqBin);
                    printf("Arquivo 'Relatorio.txt' gerado!\n Tecle 'ENTER' para continuar");
                    getchar();
                    getchar();
                }
            }
            else
                naohaarquivo(arqBin);
            break;
        case 6:
        	limparTela();
        	printf("Programa Encerrado\n\n");
        	getchar();
            return (0);
        default:
        	limparTela();
            printf("********OPCAO INVALIDA!!!********\n\n\tTecle 'ENTER' para continuar\n");
            getchar();
            break;
        }
    }
    return 0;
}
/********************************************************************************************/

/*Funcao responsavel por limpar a tela em que o programa esta rodadando*/
void limparTela(){
	system("cls");
}

/*Funcao responsavel por indicar que nao há nenhum arquivo binario criado
* e questiona o usuario se e de interesse criar um, chamando a Funcao apropriada*/
void naohaarquivo(FILE *arquivo){
	char c;
	printf("Nao ha' nenhum cadastro criado\nDeseja criar um novo cadastro? (Y/N)");
        scanf("%c", &c);
        if(c == 'y' || c == 'Y')
        	criarCadastro(arquivo);

}

/*Funcao que monta um registro do tipo Jogo, preenchendo todos os
* conteudos do registro, e o retorna
*/
Jogo pegarDados(){
    	Jogo partida;
    	bool valido = false;

	    limparTela();

	    while(!valido){
        	printf("Indique a rodada do campeonato: ");
    		scanf("%d", &partida.rodada);
    		getchar();
    		if (partida.rodada > 0)
    			valido = true;
    		else
    			printf("Numero da rodada informada invalida!\n");
    	}
    	valido = false;
    	while(!valido){
    		printf("Indique o numero do jogo: ");
    		scanf("%d", &partida.nJogo);
    		getchar();
    		if (partida.nJogo > 0)
    			valido = true;
    		else
    			printf("Numero do jogo informado invalido!\n");
    	}
    	valido = false;

    	printf("Indique o nome do time de casa: ");
    	scanf("%[^\n]s%*c", &partida.nTimeCasa);
    	getchar();
    	printf("Indique o nome do time visitante: ");
    	scanf("%[^\n]s%*c", &partida.nTimeVisitante);
    	getchar();
    	printf("Indique o estadio do jogo: ");
    	scanf("%[^\n]s%*c", &partida.estadio);
    	getchar();
    	printf("Indique a data em que o jogo ocorreu: ");
    	scanf("%[^\n]s%*c", &partida.data);
    	getchar();
    	printf("Indique a hora em que o jogo ocorreu: ");
    	scanf("%[^\n]s%*c", &partida.hora);
    	getchar();

    	while(!valido){
    		printf("Indique o numero de pagantes: ");
    		scanf("%d", &partida.publico);
    		getchar();
    		if(partida.publico > 0)
    			valido = true;
    		else
    			printf("Numero de pagantes informado invalido!\n");
    	}
    	valido = false;

    	while(!valido){
    		printf("Indique a renda do jogo: ");
    		scanf("%f", &partida.renda);
    		getchar();
    		if(partida.renda > 0)
    			valido = true;
    		else
    			printf("Renda informada invalida!\n");
    	}
    	valido = false;

    	while(!valido){
    		printf("Indique o numero de gols do time da casa: ");
    		scanf("%d", &partida.golsCasa);
    		getchar();
    		if(partida.golsCasa > 0)
    			valido = true;
    		else
    			printf("Numero de gols informado invalido!\n");
    	}
    	valido = false;

    	while(!valido){
    		printf("Indique o numero de gols do time visitante: ");
    		scanf("%d", &partida.golsVisitante);
    		getchar();
    		if(partida.golsVisitante > 0)
    			valido = true;
    		else
    			printf("Numero de gols informado invalido!\n");
    	}
    	return partida;
}

/*Funcao responsavel por montar o menu principal, mostrando todas as
* opções, esperando a escolha do usuario e retornando o valor da escolha
*/
int menuPrincipal(){
    int opcao;
    limparTela();

    printf("1. CRIAR E INICIAR CADASTRO NOVO \n");
    printf("2. INCLUIR DADOS NO CADASTRO EXISTENTE \n");
    printf("3. CONSULTAR O CADASTRO POR NUMERO DO JOGO\n");
    printf("4. CONSULTAR O CADASTRO POR RODADA \n");
    printf("5. GERAR RELATORIO EM ARQUIVO TXT\n");
    printf("6. SAIR\n");
    scanf("%d", &opcao);
    return opcao;
}

/*Funcao responsavel por criar o arquivo binario, escrever o primeiro
* registro e, se for de interesse do usuario, chamar a Funcao que adiciona
* novos registros*/
void criarCadastro(FILE *arquivo){
	Jogo cadastro;
	char c;

	/*arquivo e aberto em modo 'wb' que cria ou sobreescreve o arquivo binario*/
    arquivo = fopen("JOGOS.bin", "wb");

    /*um registro e montado e adicionado ao arquivo que, em seguida, e fechado*/
    cadastro = pegarDados();
    fwrite(&cadastro, sizeof(Jogo), 1, arquivo);
    fclose(arquivo);

    printf("Deseja-se adicionar outro cadastro? (Y/N)");
	scanf("%c", &c);
	if(c == 'y' || c == 'Y')
        incluirDados(arquivo);
}

/*Funcao responsavel por montar registros enquanto o usuario desejar
* e o incluir no arquivo*/
void incluirDados(FILE *arquivo){
	char in = 'y';
	Jogo cadastro;

	/*Enquanto o usuario escrever 'Y' como resposta, deve-se montar um registro,
	* o escrever no arquivo binario e limpar a tela*/
	while(in == 'y' || in == 'Y'){
		cadastro = pegarDados();
		escreverPartidaBin(arquivo, cadastro);
		limparTela();
		printf("Deseja-se adicionar outro cadastro? (Y/N)");
		scanf("%c", &in);
	}
}

/*Funcao responsavel por checar a existencia de um arquivo com o nome
* indicado pela referencia*/
bool testarArquivo(char *nome){
	FILE *arquivo = fopen(nome, "rb");
	if(arquivo == NULL){
		fclose(arquivo);
		return false;
	}
	else{
		fclose(arquivo);
		return true;
	}
}

/*Funcao responsavel por escrever o registro na posição correta
* do arquivo binario
*/
void escreverPartidaBin(FILE *arquivo, Jogo cadastro){
	Jogo partida;
	bool fim = false;
	int cont = 0;

	arquivo = fopen("JOGOS.bin", "r+b");
    partida.rodada = -1;

    /*Loops que posicionam o cursor no local onde deve-se escrever o novo
    * registro, primeiramente chegando o valor da rodada e, em seguida, o
    * valor do numero do jogo
    */
	while(partida.rodada < cadastro.rodada){
        cont++;
        if (fread(&partida, sizeof(Jogo), 1, arquivo) == 0){
            fim = true;
            break;
        }
       if (partida.rodada >= cadastro.rodada)
            break;

	}
	while((partida.rodada == cadastro.rodada) && (!fim)){
        cont++;
        if (fread(&partida, sizeof(Jogo), 1, arquivo) == 0){
            fim = true;
            break;
        }
        if(partida.nJogo > cadastro.nJogo)
            break;
	}
	/*Chama-se a Funcao que coloca o registro no local correto*/
    truncarStruct(fim, cont, arquivo, cadastro);

    fclose(arquivo);
}

/*Funcao responsavel por truncar um registro em seu local correto
* com o uso de arquivos temporários para nao se perder nenhum dado
* na efetiva escrita a partir da Funcao fwrite()
*/
void truncarStruct(bool fim, int cont, FILE *arquivo, Jogo cadastro){
    FILE *temp;
    Jogo aux;

    /*Se o fim do arquivo foi atingido, deve-se posicionar o cursor
    * no final do arquivo e escrever o registro
    */
	if(fim){
        fseek(arquivo, sizeof(Jogo)*(cont - 1), SEEK_SET);
        fwrite(&cadastro, sizeof(Jogo), 1, arquivo);
	}
	/*Se a posição a se adicionar estiver no meio do arquivo, deve-se
	* salvar o conteudo a frente do local da escrita em um arquivo
	* temporario, escrever o registro, e colocar os conteudos contidos
	* no arquivo temporario devolta ao arquivo binario principal
	*/
	else{
		/*Arquivo temporario criado e o cursor do arquivo binario e
		* alocado ao local correto
		*/
        temp = fopen("temp.bin", "w+b");
        fseek(arquivo, sizeof(Jogo)*(cont - 1), SEEK_SET);

        /*e copiado todos os registros a frente do local a ser escrito o
        * registro para o arquivo temporario
        */
        while(fread(&aux, sizeof(Jogo), 1, arquivo) != 0){
            fwrite(&aux, sizeof(Jogo), 1, temp);
        }

        /*e alocado o cursor de ambos os arquivos ao inicio dos arquivos*/
        rewind(arquivo);
        rewind(temp);

        /*e alocado o cursor do arquivo binario para o locar a ser escrito
        * o registro e o escreve*/
        fseek(arquivo, sizeof(Jogo)*(cont - 1), SEEK_SET);
        fwrite(&cadastro, sizeof(Jogo), 1, arquivo);
        /*Nesse momento, um registro (localizado onde o cursor estava) e
        * perdido e substituido pelo registro escrito
        */

        /*e copiado todo o conteúdo do arquivo temporario para o arquivo
        * binario a partir do registro recem escrito*/
        while(fread(&aux, sizeof(Jogo), 1, temp) != 0){
            fwrite(&aux, sizeof(Jogo), 1, arquivo);
        }

        /*fecha-se o arquivo temporário e o exclui*/
        fclose(temp);
        remove("temp.bin");
    }
}

/*Funcao responsavel por consultar um registro contido no arquivo binario
* a partir do numero do jogo e o mostrar na tela
*/
void consultarCadastroNJ(FILE *arquivo){
	Jogo partida;
	char c = 'y';
	int numero;

	/*Arquivo e aberto em modo de leitura*/
	arquivo = fopen("Jogos.bin", "rb");

	while(c == 'y' || c == 'Y'){
		limparTela();
		printf("Indique o numero do jogo que desejas consultar: ");
		scanf("%d", &numero);

		/*Com esse loop, alocamos oo registro 'partida' o registro de interesse ao
		* usuario, se ele realmente for achado.
		*/
		while((fread(&partida, sizeof(Jogo), 1, arquivo) != 0) && (partida.nJogo != numero));
		/*Se o jogo foi encontrado, o imprime na tela*/
		if (partida.nJogo == numero)
			imprimirPartidaTela(partida);
		/*Se o jogo nao foi encontrado, imprimi-se uma mensagem explicativa*/
		else
			printf("nao foi encontrado nenhum jogo com o numero %d", numero);
        getchar();
		printf("\n\n Deseja fazer outra busca?(Y/N)");
		scanf("%c", &c);
		rewind(arquivo);
	}
	fclose(arquivo);
}

/*Funcao responsavel por imprimir um registro na tela a partir de uma organização
* pre definida
*/
void imprimirPartidaTela(Jogo partida){
	printf("\nJogo numero %d:\n", partida.nJogo);
	printf("Time da Casa: %s X Time Visitante: %s\n",partida.nTimeCasa, partida.nTimeVisitante);
	printf("Data: %s \t Hora: %s\n", partida.data, partida.hora);
	printf("Publico: %d \t Renda: %.2f\n", partida.publico, partida.renda);
	printf("Resultado (Casa X Visitante): %d X %d \n\n\n", partida.golsCasa, partida.golsVisitante);
}

/*Funcao responsavel por consultar registros de mesma rodada contidos no
* arquivo binario e os mostrar na tela
*/
void consultarCadastroR(FILE *arquivo){
	char c = 'y';
	int rodada, contador = 0, flag;
	Jogo partida;

	arquivo = fopen("Jogos.bin", "rb");

	while (c == 'y' || c == 'Y'){
        flag = 1;
		limparTela();
		printf("Indique a rodada do jogo que desejas consultar: ");
		scanf("%d", &rodada);

        fread(&partida, sizeof(Jogo), 1, arquivo);

        /*Determina-se o numero de jogos que estão em uma rodada e, se esse numero
        * for maio do que zero, imprime os jogos encontrados na tela. Caso contrario
        * e apresentada uma mensagem explicativa
        */
		if((contador = contarNumeroUmaRodada(rodada, arquivo, &flag, partida)))
			imprimirJogosRodada(arquivo, contador, flag);
		else
			printf("Nao foi possivel encontrar nenhum jogo da rodada %d\n", rodada);

        getchar();
		printf("\n\n\n Deseja fazer outra busca? (Y/N)");
		scanf("%c", &c);
		rewind(arquivo);
	}
    fclose(arquivo);
}

/*Fução responsavel por retornar a quantidade de jogos que uma rodada tem*/
int contarNumeroUmaRodada(int rodada, FILE *arquivo, int *fim, Jogo partida){
    int cont = 0;

    /*Enquanto o cursor do aquivo nao estiver dentro da rodada de interesse,
    * deve-se procula-lo
    */
    while(partida.rodada != rodada){
    	/*Se cehgamos ao fim do arquivo, colocamos a 'flag' de fim do arquivo
    	* em zero
    	*/
        if (fread(&partida, sizeof(Jogo), 1, arquivo) == 0){
            *fim = 0;
            break;
        }
    }
    /*Se a rodada de interesse foi encontrada, devemos contar quantos jogos
    * essa rodada contem, incrementando o contador. Caso o fim do arquivo for
    * atingido, deve-se colocar a 'flag' de fim do arquivo em zero e interromper
    * a pesquisa
    */
		if((partida.rodada == rodada) && (*fim)){
			while(partida.rodada == rodada){
                cont++;
				if (fread(&partida, sizeof(Jogo), 1, arquivo) == 0){

				    *fim = 0;
                    break;
				}
			}
    }
    return cont;
}

/*Funcao responsavel por imprimir os jogos contidos em uma rodada*/
void imprimirJogosRodada(FILE *arquivo, int cont, int flagFim){
	int i;
	/*Com o numero de jogos contidos em uma rodada conhecido, aloca o cursor
	* para o local onde se inicia a rodada no arquivo, levando em conta o numero
	* de jogos presentes na rodada e se foi atingido o fim do arquivo ou nao, e,
	* então, coloca-se toda a rodada em um vetor de registros de tamanho igual a
	* quantidade de registros e os escreve a partir de uma organização pre definida
	*/
	Jogo partidas[cont];
	fseek(arquivo, sizeof(Jogo)*(cont+flagFim)*(-1), SEEK_CUR);
	fread(&partidas, sizeof(Jogo), cont, arquivo);
	printf("Rodada: %d \nNumero de jogos: %d \n\n", partidas[0].rodada, cont);
	printf("Numero \tTime Casa \t Time Visitante \tData\n");
	for(i = 0; i < cont; i++){
		printf("%d \t%s ", partidas[i].nJogo, partidas[i].nTimeCasa);
		printf("\t%s \t\t%s\n\n", partidas[i].nTimeVisitante, partidas[i].data);
	}
}

/*Funcao responsavel por criar um arquivo de texto contendo o conteudo de todos
* os jogos organizando-os a partir de um padrão pre definido*/
void gerarTxt(FILE *arqBin){
    Jogo partida;
    int cont, flag = 1;

    arqBin = fopen("Jogos.bin", "rb");
    fopen("Relatorio.txt", "wb");

    while(fread(&partida, sizeof(Jogo), 1, arqBin) != 0){
    flag = 1;

    /*as partidas são escritas a partir de rodadas, onde contamos o numero de
    * partidas em cada rodada, cria-se um vetor de registros, aloca-se todos
    * os jogos nesse vetor e os escreve apartir de uma Funcao*/
    cont = contarNumeroUmaRodada(partida.rodada, arqBin, &flag, partida);

	Jogo partidas[cont];

	fseek(arqBin, sizeof(Jogo)*(cont+flag)*(-1), SEEK_CUR);
	fread(&partidas, sizeof(Jogo), cont, arqBin);

	gerarTextoStruct(cont, partidas);
    }
    rewind(arqBin);
    estatisticasFinais(arqBin);
    fclose(arqBin);
}

/*Funcao responsavel por escrever em um arquivo txt todos os jogos de uma
* rodada que se encontram em um detor de registros a partir de uma organização
* pre definida
*/
void gerarTextoStruct(int tamanho, Jogo vetJogos[tamanho]){
     FILE *arqTxt;
     int i;
     float soma = 0;

     arqTxt = fopen("Relatorio.txt", "a");

     for(i = 0; i < 50; i++){
     	fprintf(arqTxt, "*");
     }
     fprintf(arqTxt, "\n\t\t\t\t*** Rodada: %d* ***\n", vetJogos[0].rodada);
     for(i = 0; i < 50; i++){
     	fprintf(arqTxt, "*");
     }
     fprintf(arqTxt,"\n\n");

     for(i = 0; i < tamanho; i++){
     	fprintf(arqTxt, "JOGO (CASA X VISITANTE) : %s X %s \n",vetJogos[i].nTimeCasa, vetJogos[i].nTimeVisitante);
     	fprintf(arqTxt, "DATA: %s \tHora: %s\n", vetJogos[i].data, vetJogos[i].hora);
     	fprintf(arqTxt, "PUBLICO: %d \tRENDA (R$): %.2f \n", vetJogos[i].publico, vetJogos[i].renda);
     	fprintf(arqTxt, "RESULTADO (CASA X VISITANTE): %d X %d \n", vetJogos[i].golsCasa, vetJogos[i].golsVisitante);
   		fprintf(arqTxt, "\n\n");
   		soma += vetJogos[i].golsVisitante + vetJogos[i].golsCasa;
     }
     fprintf(arqTxt, "NUMERO TOTAL DE JOGOS: %d \n", tamanho);
     fprintf(arqTxt, "MEDIA DE GOLS POR JOGO: %.2f \n\n\n", soma/tamanho);
     fclose(arqTxt);
 }

/*Funcao responsavel por determinar as estatisticas finais de todos os jogos
* e as escrever a partir de uma organização pre determinada no arquivo de
* de texto do relatorio
*/
 void estatisticasFinais(FILE *arqBin){
	FILE *arqtxt;
	int nJogos = 0, nVitoriasCasa = 0, nVitoriasVisitante = 0, nEmpates = 0, i;
	float mGols = 0, mPublico = 0, mRenda = 0;
	Jogo maiorRenda, partida;

	maiorRenda.renda = -1;

	/*Isso e feito com um loop que passa pelo arquivo binario por completo
	* checando certos aspectos de cada registro e somando as informações
	* especificas de acordo com a informação contida no registro
	*/
	while(fread(&partida, sizeof(Jogo), 1, arqBin) != 0){
		nJogos++;
		if(partida.golsCasa > partida.golsVisitante)
			nVitoriasCasa++;
		else if (partida.golsCasa < partida.golsVisitante)
			nVitoriasVisitante++;
		else
			nEmpates++;

		mGols += partida.golsVisitante + partida.golsCasa;
		mPublico += partida.publico;
		mRenda += partida.renda;

		if(partida.renda > maiorRenda.renda)
			maiorRenda = partida;
	}
	mGols = mGols/nJogos;
	mPublico = mPublico/nJogos;
	mRenda = mRenda/nJogos;

	arqtxt = fopen("Relatorio.txt", "a");

	for(i = 0; i < 50; i++){
     	fprintf(arqtxt, "*");
     }
     fprintf(arqtxt, "\n\t\t*** Dados gerais do campeonato***\n");
     for(i = 0; i < 50; i++){
     	fprintf(arqtxt, "*");
     }

     fprintf(arqtxt, "\n\n");
     fprintf(arqtxt, "Media de gols por jogo: %.2f\n", mGols);
     fprintf(arqtxt, "Media de publico por jogo: %.2f\n", mPublico);
     fprintf(arqtxt, "Media de renda por jogo: %.2f\n", mRenda);
     fprintf(arqtxt, "Numero de vitorias do time da casa: %d\n", nVitoriasCasa);
     fprintf(arqtxt, "Numero de vitorias do time visitante: %d\n", nVitoriasVisitante);
     fprintf(arqtxt, "Numero de empates: %d\n", nEmpates);
     fprintf(arqtxt, "Jogo com maior renda: \n\t");
     fprintf(arqtxt, "%s (%d) X %s (%d), ", maiorRenda.nTimeCasa, maiorRenda.golsCasa, maiorRenda.nTimeVisitante, maiorRenda.golsVisitante);
     fprintf(arqtxt, "Dia %s , %d* Rodada,\n\tPublico %d, ", maiorRenda.data, maiorRenda.rodada, maiorRenda.publico);
     fprintf(arqtxt, "Renda R$ %.2f\n\n", maiorRenda.renda);

     for(i = 0; i < 50; i++){
     	fprintf(arqtxt, "*");
     }
    fclose(arqtxt);
}
