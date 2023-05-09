// Miguel Umbelino da Mota Roma - a2021138955

#include "linha.h"
#include "paragem.h"

int contaNos(plinha p) {
    int cont = 0;

    while(p != NULL){
        cont++;
        p = p->prox;
    }
    return cont;
}

plinha regLinha(plinha p){
    plinha novo, aux;

    char nomeLinha[100];
    int existe;

    novo = malloc(sizeof(linha));
    if(novo == NULL)
        return p;

    fflush(stdin);
    system("cls");

    printf("\n\t\t\t\t\t  --------------------------------------------\n");
    printf("\n\t\t\t\t\t  |           ADICIONAR NOVA LINHA           |\n");
    printf("\n\t\t\t\t\t  --------------------------------------------\n");

    do{
        existe = 0;
        aux = p;

        printf("Nome da linha: ");
        scanf(" %99[^\n]", nomeLinha);

        while(aux != NULL){
            if(strcmp(aux->nome, nomeLinha) == 0){
                printf("[AVISO] LINHA COM ESSE NOME JA SE ENCONTRA REGISTADA!\n\n");
                existe = 1;
                break;
            }
            aux = aux->prox;
        }
    }while(existe == 1);

    strcpy(novo->nome, nomeLinha);
    novo->nParag = 0;
    novo->lista = NULL;
    novo->prox = NULL;

    if(p == NULL){
        p = novo;
    }
    else {
        aux = p;
        while (aux->prox != NULL) {
            aux = aux->prox;
        }
        aux->prox = novo;
    }

    /* add paragens to the new linha
    do {
        encontrada = 0;
        printf("Digite o nome da paragem que deseja adicionar a esta linha (ou 0 para parar): ");
        scanf(" %99[^\n]", nomeLinha);

        // search for the paragem in the system
        paragem_atual = paragens;
        paragem_anterior = NULL;
        while (paragem_atual != NULL) {
            if (strcmp(paragem_atual->nome, nomeLinha) == 0) {
                encontrada = 1;
                break;
            }
            paragem_anterior = paragem_atual;
            paragem_atual = paragem_atual->prox;
        }

        if (encontrada) {
            // add the paragem to the new linha
            if (novo->lista == NULL) {
                novo->lista = paragem_atual;
                paragem_atual->numLinhas++;
            } else {
                paragem_anterior->prox = paragem_atual;
                paragem_atual->numLinhas++;
            }
            novo->nParag++;
        } else if (strcmp(nomeLinha, "0") != 0) {
            printf("[AVISO] PARAGEM NAO ENCONTRADA!\n\n");
        }

    } while (strcmp(nomeLinha, "0") != 0 && novo->nParag == 0);
     */
    return p;
}

/*
void adicParagem(plinha p){
    pparagem novo;
    char nomeLinha[100];



    while(p != NULL && strcmp(p->nome, n_d) != 0)
        p = p->prox;
    if(p != NULL){
        novo = malloc(sizeof(paragem));
        if(novo == NULL) {
            return;
        }

        strcpy(novo->nome, n_al);
        strcpy(novo->numero, id);
        novo->prox = p->lista; //insere no inicio
        p->lista = novo;
        p->nParag++;
    }
}
*/

/*
void elimParagemLinha(plinha p, pparagem par) {
    char *cod;
    char *nomeLinha;

    printf("-> Linha a alterar: ");
    fgets(nomeLinha, sizeof(nomeLinha), stdin);
    nomeLinha[strcspn(nomeLinha, "\n")] = '\0';

    printf("-> Paragem a eliminar: ");
    scanf("%s", cod);

    while(p != NULL) {
        if(strcmp(p->nome, nomeLinha) == 0) {
            int i;
            for(i = 0; i < p->nParag; i++) {
                if(strcmp(par->codigo, cod) == 0) {
                    // encontrou a paragem a remover
                    // mover todas as paragens seguintes para a posição anterior
                    int j;
                    for(j = i; j < p->nParag-1; j++) {
                        strcpy(p->nome[j], p->nome[j+1]);
                    }
                    p->nParag--;
                    printf("Paragem %s eliminada da linha %s\n", nomeParagem, nomeLinha);
                    return;
                }
            }
            // a paragem não foi encontrada na linha
            printf("Paragem %s nao encontrada na linha %s\n", nomeParagem, nomeLinha);
            return;
        }
        p = p->prox;
    }
    // a linha não foi encontrada
    printf("Linha %s nao encontrada\n", nomeLinha);
}
*/

void listarLinhas(plinha p){
    pparagem aux;
    char ch;
    int n;

    fflush(stdin);
    system("cls");

    n = contaNos(p);
    if(p != NULL){
        if(n == 1){
            printf("\n\t\t\t\t\t  --------------------------------------------\n");
            printf("\n\t\t\t\t\t  |    EXISTE 1 LINHA REGISTADA NO SISTEMA    |\n");
            printf("\n\t\t\t\t\t  --------------------------------------------\n");
        }
        else{
            printf("\n\t\t\t\t\t  --------------------------------------------\n");
            printf("\n\t\t\t\t\t  |  EXISTEM %d LINHAS REGISTADAS NO SISTEMA  |\n", n);
            printf("\n\t\t\t\t\t  --------------------------------------------\n");
        }


        while(p != NULL){
            printf("|------- LINHA '%s' -------|\n", p->nome);
            printf(" [%d] paragens:\n", p->nParag);
            //p = p->prox;
            aux = p->lista;
            while(aux != NULL){
                printf("\t%s\t%s\n", aux->nome, aux->codigo);
                aux = aux->prox;
            }
            putchar('\n');
            p = p->prox;
        }
    }
    else {
        printf("\n\t\t\t\t\t  --------------------------------------------\n");
        printf("\n\t\t\t\t\t  |  EXISTEM 0 LINHAS REGISTADAS NO SISTEMA  |\n");
        printf("\n\t\t\t\t\t  --------------------------------------------\n");
    }
    printf("\n-> ENTER para voltar ao menu anterior");

    do{
        ch = getchar();
        fflush(stdin);
    }while( ch != '\n');
}

void listarLinhasParagem(plinha p){
    pparagem aux;
    char nomeParagem[100], ch;

    printf("Listar linhas com a paragem: ");
    scanf(" %99[^\n]", nomeParagem);

    while(p != NULL){
        while(aux != NULL){
            if(strcmp(aux->nome, nomeParagem) == 0){
                printf("-> LINHA '%s'\n", p->nome);
                aux = p->lista;
            }
            else{
                aux = aux->prox;
            }
        }
        p = p->prox;
    }
    printf("\n-> ENTER para voltar ao menu anterior");

    do{
        ch = getchar();
        fflush(stdin);
    }while( ch != '\n');
}

