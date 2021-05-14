#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

int main()
{

    //permite uso de acentua��o
    setlocale(LC_ALL,"");

    printf("\n\n");
    printf("          P  /_\\  P                              \n");
    printf("         /_\\_|_|_/_\\                            \n");
    printf("     n_n | ||. .|| | n_n          Bem vindo ao    \n");
    printf("     |_|_|nnnn nnnn|_|_|      Jogo de Adivinha��o!\n");
    printf("    |" "  |  |_|  |"  " |                         \n");
    printf("    |_____| ' _ ' |_____|                         \n");
    printf("          \\__|_|__/                              \n");
    printf("\n\n");


    int segundos = time(0);
    srand(segundos);

    int numeroGrande = rand();

    int numeroSecreto = numeroGrande % 100;
    int chute;
    int tentativas = 1;
    double pontos = 1000;

    int acertou = 0;
    int numeroTentativas;
    int nivel;

    printf("Qual o n�vel de dificuldade?\n");
    printf("(1) F�cil, (2) M�dio, (3) Dif�cil\n");
    printf("Escolha: \n");
    scanf("%d", &nivel);

    switch(nivel){
        case 1:
            numeroTentativas = 20;
            break;

        case 2:
            numeroTentativas = 15;
            break;

        default:
            numeroTentativas = 6;
            break;
    }

    for(int i = 1; i <= numeroTentativas; i++){
        printf("Tentativa %d\n", tentativas);
        printf("Qual � o seu chute?\n");

        scanf("%d", &chute);
        printf("Seu chute foi %d \n", chute);

        if(chute < 0){
            printf("Voc� n�o pode chutar n�meros negativos\n");
            printf("\n");
            continue;
        }

        acertou = (chute == numeroSecreto);
        int maior = (chute > numeroSecreto);

        if(acertou){
            break;

        } else if(maior){
            printf("Seu chute foi maior que o n�mero secreto.\n");
            printf("\n");

        } else{
            printf("Seu chute foi menor que o n�mero secreto.\n");
            printf("\n");

        }

        tentativas++;

        double pontosPerdidos = abs(chute - numeroSecreto) / (double)2;
        pontos = pontos - pontosPerdidos;

    }

    printf("Fim de jogo!\n");
    printf("\n");

    if(acertou){
        printf("             OOOOOOOOOOO               \n");
        printf("         OOOOOOOOOOOOOOOOOOO           \n");
        printf("      OOOOOO  OOOOOOOOO  OOOOOO        \n");
        printf("    OOOOOO      OOOOO      OOOOOO      \n");
        printf("  OOOOOOOO  #   OOOOO  #   OOOOOOOO    \n");
        printf(" OOOOOOOOOO    OOOOOOO    OOOOOOOOOO   \n");
        printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  \n");
        printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  \n");
        printf("OOOO  OOOOOOOOOOOOOOOOOOOOOOOOO  OOOO  \n");
        printf(" OOOO  OOOOOOOOOOOOOOOOOOOOOOO  OOOO   \n");
        printf("  OOOO   OOOOOOOOOOOOOOOOOOOO  OOOO    \n");
        printf("    OOOOO   OOOOOOOOOOOOOOO   OOOO     \n");
        printf("      OOOOOO   OOOOOOOOO   OOOOOO      \n");
        printf("         OOOOOO         OOOOOO         \n");
        printf("             OOOOOOOOOOOO              \n");
        printf("\n\n");


        printf("Voc� ganhou!\n");
        printf("Voc� acertou em %d tentativas!\n", tentativas);
        printf("Total de pontos: %.1f\n", pontos);
    } else {
        printf("Voc� perdeu! Tente de novo!\n");

        printf("       \\|/ ____ \\|/    \n");
        printf("        @~/ ,. \\~@      \n");
        printf("       /_( \\__/ )_\\    \n");
        printf("          \\__U_/        \n");

    }

}
