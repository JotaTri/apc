#include <stdio.h>

int main(){

    float idade, altura, peso, mediaIdadeT, mediaPesoT, maiorAltura, mediaIdade, mediaPeso;
    int i, j, numT, numJ, codigo, codigoMaior, timeMaior;

    mediaIdadeT = 0;
    mediaPesoT = 0;
    maiorAltura = 0;
    printf("Indique a quantidade de times a serem analizados: ");
    scanf("%d", &numT);
    printf("Indique a quantidade de jogadores em cada um dos %d times: ", numT);
    scanf("%d", &numJ);

    for(i = 1; i <= numT; i++){
                mediaPeso = 0;
                mediaIdade = 0;
        for(j = 1; j <= numJ; j++){
            printf("\n\nIndique o codigo do %d* jogador do %d* time: ", j, i);
            scanf("%d", &codigo);
            printf("Indique a altura do jogador '%d'", codigo);
            scanf("%f", &altura);
            printf("Indique o peso do jogador '%d'", codigo);
            scanf("%f", &peso);
            printf("Indique a idade do jogador '%d'", codigo);
            scanf("%f", &idade);

            mediaPeso += peso;
            mediaIdade += idade;
            if(altura > maiorAltura){
                maiorAltura = altura;
                codigoMaior = codigo;
                timeMaior = i;
            }
        }
        printf("\n\nO peso medio dos %d jogadores do time %d e': %.2f", j-1, i, (float)mediaPeso/(j-1));
        printf("\nA idade media dos %d jogadores do time %d e': %.2f", j-1, i, (float)mediaIdade/(j-1));
        mediaIdadeT += mediaIdade;
        mediaPesoT += mediaPeso;
    }
    printf("\n\nO peso medio dos %d jogadores dos  %d times e': %.2f \n", (j-1)*(i-1), i-1, (float)mediaPesoT/((j-1)*(i-1)));
    printf("A idade media dos %d jogadores dos  %d times e': %.2f \n", (j-1)*(i-1), i-1, (float)mediaIdadeT/((j-1)*(i-1)));
    printf("O jogador com maior altura corresponde ao jogador '%d' do %d* time com altura de %.2fcm \n\n",codigoMaior, timeMaior, maiorAltura);
}
