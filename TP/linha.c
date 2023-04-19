// Miguel Umbelino da Mota Roma - a2021138955

#include "linha.h"

void preenche(plinha p){
    printf("Nova linha:");
    fgets(p->nome, sizeof(p->nome), stdin);
    p->nome[strcspn(p->nome, "\n")] = '\0';

    p->prox = NULL;
}

plinha addParagem(plinha p){
    plinha novo = NULL;
    plinha aux = NULL;

    novo = malloc(sizeof(linha));
    if(novo == NULL){
        printf("Erro na alocacao de memoria\n");
        return p;
    }
    preenche(p);

    if(p == NULL)
        p = novo;
    else{
        aux = p;
        while(aux->prox)
            aux = aux->prox;
        aux->prox = novo;
    }
    return p;
}

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


plinha delParagemLinha(plinha p){
    plinha atual, anterior = NULL;
    atual = p;


    while(atual != NULL && atual->nome != lin)
    {
        anterior = atual;
        atual = atual->prox;
    }
    if(atual == NULL)
        return p;
    if(anterior == NULL)
        p = atual->prox;
    else
        anterior->prox = atual->prox;
    free(atual);
    return p;
}

*/
int contaLinhas(plinha p){
    while(p != NULL){

    }
}

void listaLinhas(plinha p){
    char ch;

    fflush(stdin);
    system("cls");

    if(p != NULL){
        while(p != NULL){
            printf("%s\t%d\n",
                   p->nome, p->nParag);
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


void procuraLinha(plinha p, char *proc){
    printf("adsa");

    while(p != NULL && p->nome != proc)
        p = p->prox;
    if(p != NULL)
        printf("%s\t%d\n",p->nome,p->nParag);
    else
        printf("Linha inexistente\n");
}

