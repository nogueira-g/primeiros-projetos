#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#include "forca.h"

//variáveis globais
char palavraSecreta[TAMANHO_PALAVRA];
char chutes[26];
int chutesDados = 0;

void introducao(){
    printf("***********************\n");
    printf("*    Jogo de Forca    *\n");
    printf("***********************\n\n");
}

void chutaLetra(){
    char chute;
    printf("Qual letra? ");
    scanf(" %c", &chute);

    //coloca as letras sugeridas na lista de chutes
    chutes[chutesDados] = chute;
    chutesDados++;
}

int jaChutou(char letra){
    int achou = 0;

    //segundo loop: checa se alguma letra sugerida bate com a atual da palavra secreta na iteração
    for(int j = 0; j < chutesDados; j++){
        if(chutes[j] == letra){

            //caso a letra sugerida esteja certa, marcamos que "achou"
            achou = 1;
            break;
        }
    }

    return achou;
}

void montaForca(){
    int erros = chutesErrados();

    printf("  _______      \n");
    printf(" |/      |     \n");
    printf(" |      %c%c%c \n", (erros >= 1 ? '(' : ' '),
                                 (erros >= 1 ? '_' : ' '),
                                 (erros >= 1 ? ')' : ' '));
    printf(" |      %c%c%c \n", (erros >= 3 ? '\\' : ' '),
                                 (erros >= 2 ? '|' : ' '),
                                 (erros >= 3 ? '//': ' '));
    printf(" |       %c    \n", (erros >= 2 ? '|' : ' '));
    printf(" |      %c %c  \n", (erros >= 4 ? '/' : ' '),
                                 (erros >= 4 ? '\\': ' '));
    printf(" |             \n");
    printf("_|___          \n");
    printf("\n\n");

    printf("Você já deu %d chutes\n", chutesDados);

    //primeiro loop: uma iteração para cada letra da palavra secreta
        for(int i = 0; i < strlen(palavraSecreta); i++){

            int achou =  jaChutou(palavraSecreta[i]);

            //se achou, imprimimos a letra no lugar do underline
            if(achou){
                printf("%c ", palavraSecreta[i]);
            } else{
                printf("_ ");
            }
        }

        printf("\n");
}

void escolhePalavra(){
    FILE* f;

    f = fopen("banco_de_palavras.txt", "r");
    if(f == 0){
        printf("Desculpe, banco de dados de palavras não disponível\n\n");
        exit(1);
    }

    int qtdPalavras;
    fscanf(f, "%d", &qtdPalavras);

    srand(time(0));
    int randomico = rand() % qtdPalavras;

    for(int i = 0; i <= randomico; i++){
       fscanf(f, "%s", palavraSecreta);
    }

    fclose(f);
}

void adicionaPalavra(){
    char quer;

    printf("Você deseja adicionar uma nova palavra no jogo? (S/N)? ");
    scanf(" %c", &quer);

    if (quer == 'S'){

        char novaPalavra[TAMANHO_PALAVRA];
        printf("Qual a nova palavra, em letras maiúsculas? ");
        scanf("%s", novaPalavra);

        FILE* f;

        f = fopen("banco_de_palavras.txt", "r+");
        if(f == 0){
            printf("Desculpe, banco de dados de palavras não disponível\n\n");
            exit(1);
        }

        int qtd;
        fscanf(f, "%d", &qtd);
        qtd++;
        fseek(f, 0, SEEK_SET);
        fprintf(f, "%d", qtd);

        fseek(f, 0, SEEK_END);
        fprintf(f, "\n%s", novaPalavra);

        fclose(f);
    }
}

int chutesErrados(){
    int erros = 0;

    for(int i = 0; i < chutesDados; i++){
    int existe = 0;

        for(int j = 0; j < strlen(palavraSecreta); j++){
            if(chutes[i] == palavraSecreta[j]){

                existe = 1;
                break;
            }
        }

        if(!existe) erros++;

    }

    return erros;
}

int enforcou(){
    return chutesErrados() >= 5;
}

int acertou(){
    for(int i = 0; i < strlen(palavraSecreta); i++){
        if(!jaChutou(palavraSecreta[i])){
            return 0;
        }
    }

    return 1;
}

int main(){
    setlocale(LC_ALL, "");

    introducao();
    escolhePalavra();

    do {

        montaForca();
        chutaLetra();

    } while(!acertou() && !enforcou());

    if(acertou()){
        printf("\nParabéns, você ganhou!\n\n");

        printf("      ___________       \n");
        printf("     '._==_==_=_.'      \n");
        printf("     .-\\:      /-.     \n");
        printf("    | (|:.     |) |     \n");
        printf("     '-|:.     |-'      \n");
        printf("       \\::.    /       \n");
        printf("        '::. .'         \n");
        printf("          ) (           \n");
        printf("        _.' '._         \n");
        printf("       '-------'        \n\n");

    } else {
        printf("\nVocê foi enforcado! :(\n");
        printf("A palavra era **%s**\n\n", palavraSecreta);

        printf("                 uuuuuuu                 \n");
        printf("             uu$$$$$$$$$$$uu             \n");
        printf("          uu$$$$$$$$$$$$$$$$$uu          \n");
        printf("         u$$$$$$$$$$$$$$$$$$$$$u         \n");
        printf("        u$$$$$$$$$$$$$$$$$$$$$$$u        \n");
        printf("       u$$$$$$$$$$$$$$$$$$$$$$$$$u       \n");
        printf("       u$$$$$$$$$$$$$$$$$$$$$$$$$u       \n");
        printf("       u$$$$$$*   *$$$*   *$$$$$$u       \n");
        printf("       *$$$$*      u$u       $$$$*       \n");
        printf("        $$$u       u$u       u$$$        \n");
        printf("        $$$u      u$$$u      u$$$        \n");
        printf("         *$$$$uu$$$   $$$uu$$$$*         \n");
        printf("          *$$$$$$$*   *$$$$$$$*          \n");
        printf("            u$$$$$$$u$$$$$$$u            \n");
        printf("             u$*$*$*$*$*$*$u             \n");
        printf("  uuu        $$u$ $ $ $ $u$$       uuu   \n");
        printf(" u$$$$        $$$$$u$u$u$$$       u$$$$  \n");
        printf("  $$$$$uu      *$$$$$$$$$*     uu$$$$$$  \n");
        printf("u$$$$$$$$$$$uu    *****    uuuu$$$$$$$$$$\n");
        printf("$$$$***$$$$$$$$$$uuu   uu$$$$$$$$$***$$$*\n");
        printf(" ***      **$$$$$$$$$$$uu **$***         \n");
        printf("           uuuu **$$$$$$$$$$uuu          \n");
        printf("  u$$$uuu$$$$$$$$$uu **$$$$$$$$$$$uuu$$$ \n");
        printf("  $$$$$$$$$$***           **$$$$$$$$$$$* \n");
        printf("   *$$$$$*                      **$$$$** \n");
        printf("     $$$*                         $$$$** \n\n");;

    }
}
