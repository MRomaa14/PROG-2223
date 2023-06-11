// Miguel Umbelino da Mota Roma - a2021138955

#include "percurso.h"

void percursoLinhaUnica(plinha p) {
    plinha paux = p;
    char nomePartida[100], nomeChegada[100], ch;
    int encontrado, perc = 0;

    fflush(stdin);
    system("cls");

    printf("\n\t\t\t\t\t  --------------------------------------------\n");
    printf("\n\t\t\t\t\t  |       LISTAR PERCURSO DE UMA LINHA       |\n");
    printf("\n\t\t\t\t\t  --------------------------------------------\n");

    printf("-> Paragem de partida: ");
    fflush(stdin);
    scanf(" %99[^\n]", nomePartida);

    printf("-> Paragem de chegada: ");
    fflush(stdin);
    scanf(" %99[^\n]", nomeChegada);

    while(paux != NULL){
        encontrado = 0;
        pparagem partida = paux->lista;

        while(partida != NULL){
            if(strcmp(nomePartida, partida->nome) == 0){
                pparagem chegada = partida->prox;

                while(chegada != NULL){
                    if(strcmp(nomeChegada, chegada->nome) == 0){
                        encontrado = 1;
                        perc = 1;

                        printf("\nPercurso na linha '%s':\n", paux->nome);
                        printf("%s -> ", nomePartida);

                        pparagem percurso = partida->prox;
                        while(percurso != chegada){
                            printf("%s -> ", percurso->nome);
                            percurso = percurso->prox;
                        }
                        printf("%s\n", nomeChegada);
                    }
                    if(encontrado == 1)
                        break;

                    chegada = chegada->prox;
                }
            }
            if(encontrado == 1)
                break;

            partida = partida->prox;
        }

        if (encontrado == 0) {
            partida = paux->lista;

            while (partida != NULL) {
                if (strcmp(nomePartida, partida->nome) == 0) {
                    pparagem chegada = partida->ant;

                    while (chegada != NULL) {
                        if (strcmp(nomeChegada, chegada->nome) == 0) {
                            encontrado = 1;
                            perc = 1;

                            printf("\nPercurso na linha '%s':\n", paux->nome);
                            printf("%s -> ", nomePartida);

                            pparagem percurso = partida->ant;
                            while (percurso != chegada) {
                                printf("%s -> ", percurso->nome);
                                percurso = percurso->ant;
                            }
                            printf("%s\n", nomeChegada);
                        }
                        if(encontrado == 1)
                            break;

                        chegada = chegada->ant;
                    }
                }
                if (encontrado == 1)
                    break;

                partida = partida->prox;
            }
        }
        paux = paux->prox;
    }

    if (perc == 0) {
        printf("[AVISO] NENHUM percurso encontrado entre '%s' e '%s'\n", nomePartida, nomeChegada);
    }

    printf("\n-> ENTER para voltar ao menu anterior");
    do {
        fflush(stdin);
        ch = getchar();
    } while (ch != '\n');
}

void percursoLinhaTroca(plinha p) {
    char nomePartida[100], nomeChegada[100], ch;

    fflush(stdin);
    system("cls");

    printf("\n\t\t\t\t\t  --------------------------------------------\n");
    printf("\n\t\t\t\t\t  |       LISTAR PERCURSO DE VARIAS LINHAS   |\n");
    printf("\n\t\t\t\t\t  --------------------------------------------\n");

    printf("-> Paragem de partida: ");
    fflush(stdin);
    scanf(" %99[^\n]", nomePartida);

    printf("-> Paragem de chegada: ");
    fflush(stdin);
    scanf(" %99[^\n]", nomeChegada);

    plinha linhaAtual = p;

    while (linhaAtual != NULL) {
        pparagem paragemPartida = linhaAtual->lista;

        while (paragemPartida != NULL) {
            if (strcmp(paragemPartida->nome, nomePartida) == 0) {
                plinha linhaSeguinte = linhaAtual->prox;

                while (linhaSeguinte != NULL) {
                    pparagem paragemTransbordo = linhaSeguinte->lista;

                    while (paragemTransbordo != NULL) {
                        if (strcmp(paragemTransbordo->nome, nomeChegada) == 0) {
                            printf("Percurso encontrado com transbordo: %s -> %s -> %s\n", nomePartida, paragemPartida->nome, nomeChegada);
                        }

                        paragemTransbordo = paragemTransbordo->prox;
                    }

                    linhaSeguinte = linhaSeguinte->prox;
                }
            }

            if (strcmp(paragemPartida->nome, nomeChegada) == 0) {
                printf("Percurso encontrado: %s -> %s\n", nomePartida, nomeChegada);
            }

            paragemPartida = paragemPartida->prox;
        }

        linhaAtual = linhaAtual->prox;
    }

    printf("O percurso entre '%s' e '%s' nao existe com, no maximo, um transbordo.\n", nomePartida, nomeChegada);

    printf("\n-> ENTER para voltar ao menu anterior");
    do {
        fflush(stdin);
        ch = getchar();
    } while (ch != '\n');

}

/*
void percursoLinhaTroca(){
}
 */