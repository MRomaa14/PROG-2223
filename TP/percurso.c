// Miguel Umbelino da Mota Roma - a2021138955

#include "percurso.h"

void percursoLinhaUnica(plinha p) {
    plinha paux;
    char nomePartida[100], nomeChegada[100], ch;
    int encontrado = 0;

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

    paux = p;
    while (paux != NULL) {
        pparagem partida = paux->lista;

        while (partida != NULL) {
            if (strcmp(nomePartida, partida->nome) == 0) {
                pparagem chegada = partida->prox;

                while (chegada != NULL) {
                    if (strcmp(nomeChegada, chegada->nome) == 0) {
                        encontrado = 1;
                        printf("\nPercurso na linha %s:\n", paux->nome);
                        printf("%s -> ", nomePartida);

                        pparagem percurso = partida->prox;
                        while (percurso != chegada) {
                            printf("%s -> ", percurso->nome);
                            percurso = percurso->prox;
                        }

                        printf("%s\n", nomeChegada);
                        break;
                    }
                    chegada = chegada->prox;
                }
            }

            if (encontrado == 1)
                break;

            partida = partida->prox;
        }

        if (encontrado == 1)
            break;

        paux = paux->prox;
    }

    if (encontrado == 0) {
        // Tenta encontrar o percurso no sentido inverso
        paux = p;
        while (paux != NULL) {
            pparagem partida = paux->lista;

            while (partida != NULL) {
                if (strcmp(nomeChegada, partida->nome) == 0) {
                    pparagem chegada = partida->prox;

                    while (chegada != NULL) {
                        if (strcmp(nomePartida, chegada->nome) == 0) {
                            encontrado = 1;
                            printf("\nPercurso na linha %s:\n", paux->nome);
                            printf("%s -> ", nomeChegada);

                            pparagem percurso = partida->prox;
                            while (percurso != chegada) {
                                printf("%s -> ", percurso->nome);
                                percurso = percurso->prox;
                            }

                            printf("%s\n", nomePartida);
                            break;
                        }
                        chegada = chegada->prox;
                    }
                }

                if (encontrado == 1)
                    break;

                partida = partida->prox;
            }

            if (encontrado == 1)
                break;

            paux = paux->prox;
        }
    }

    if (encontrado == 0) {
        printf("[AVISO] NENHUM percurso encontrado entre '%s' e '%s'\n", nomePartida, nomeChegada);
    }

    printf("\n-> ENTER para voltar ao menu anterior");
    do {
        fflush(stdin);
        ch = getchar();
    } while (ch != '\n');
}

void percursoLinhaTroca(){

}