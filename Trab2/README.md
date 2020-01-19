# Trabalho Prático 2
 Aluno: João Tribouillet Marcial de Menezes

 
Programa que cria relatórios de um campeonato de futebol a partir de escrita de registros de partidas em arquivos binários. A qualquer momento o usuário poderá escolher opções de como proseguir com o uso do programa a partir de funções mostradas em um menu principal. Cada opção escolhida checará a viabilidade de sua própria execução e realizará uma ação apropriada ao obter uma resposta.

O arquivo binário com todos os jogos incuidos pelo usuário é organizado a partir do número da rodada e, após isso, pelo número do jogo a cada inclusão feita pelo usuário para melhor manuseio e organização do arquivo.

Um arquivo de texto pode ser criado a qualquer momento, onde, a partir de uma organização pre determinada, todos os jogos e seus conteudos são expressos em ordem de rodada e de jogo. Esse arquivo termina com estatísticas finais de  todos os jogos que se encontravam no arquivo binário.

## Running
Para executarmos o programa, é necessário compilar o arquivo `Trabalho Pratico 1 - 140043209.c` e executar seu executável. A seguir segue um exemplo utilizando o gcc e a linha de comando:

```
gcc -o Trab Trabalho\ Pratico\ 2.c
./Trab
```