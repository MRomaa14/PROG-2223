// Miguel Umbelino da Mota Roma - a2021138955

#include "linha.h"

void preenche(plinha* p){
    printf("Nova linha:");

}

plinha addParagem(plinha* p, char* lin){
    plinha novo = NULL;
    plinha aux = NULL;

    novo = malloc(sizeof(linha));
    if(novo == NULL){
        printf("Erro na alocacao de memoria\n");
        return p;
    }
    preenche(&p);

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

//plinha addLinha(Linha);

plinha delLinha(plinha p, char* lin){
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


int lista_vazia(plinha p){
    if(p == NULL)
        return 1;
    else
        return 0;
}

void listaLinhas(plinha p){
    char ch;

    system("cls");

    if(p != NULL){
        while(p != NULL){
            printf("%s\t%d\n",
                   p->nome, p->nParag);
            p = p->prox;
        }
    }
    else {
        printf("Nao existe nenhuma linha no sistema de mobilidade!\n");
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

