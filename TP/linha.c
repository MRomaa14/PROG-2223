// Miguel Umbelino da Mota Roma - a2021138955

#include "linha.h"
#include "paragem.h"

//CONTA OS NÓS NA LISTA LIGADA PRINCIPAL (DAS LINHAS)
int contaNos(plinha p){
    int cont = 0;
    while(p != NULL){
        cont++;
        p = p->prox;
    }
    return cont;
}

//VERIFICA SE A PARAGEM PASSADA COMO ARGUMENTO EXISTE NO SISTEMA
pparagem procuraParagem(pparagem pp, int n, char *nomeParagem){
    pparagem aux = pp;
    for (int i = 0; i < n; i++) {
        if (strcmp(aux[i].nome, nomeParagem) == 0) {
            return aux;
        }
    }
    return NULL;
}

//REGISTAR UMA LINHA NA LISTA LIGADA E PARAGEM OBRIGATORIA
plinha regLinha(plinha p, pparagem pp, int n){
    plinha novo, aux;
    pparagem pnova, verf;

    char nomeLinha[100], nomeParagem[100], ch;
    int existe, encontrado, i;

    fflush(stdin);
    system("cls");

    printf("\n\t\t\t\t\t  --------------------------------------------\n");
    printf("\n\t\t\t\t\t  |           ADICIONAR NOVA LINHA           |\n");
    printf("\n\t\t\t\t\t  --------------------------------------------\n");

    novo = malloc(sizeof(linha));
    if(novo == NULL){
        printf("ERRO na alocacao de memoria da LINHA\n");
        return p;
    }

    do{
        existe = 0;
        aux = p;

        printf("Nome da linha: ");
        scanf(" %99[^\n]", nomeLinha);

        while(aux != NULL){
            if(strcmp(aux->nome, nomeLinha) == 0){
                printf("Linha [%s] JA REGISTADA!\n\n", nomeLinha);
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

    do{
        encontrado = 0;

        printf("Nome da paragem: ");
        scanf(" %99[^\n]", nomeParagem);

        pparagem temp = procuraParagem(pp, n, nomeParagem);
        if(temp == NULL){
            printf("NENHUMA paragem com o nome [%s] no SISTEMA\n", nomeParagem);
            encontrado = 1;
        }
        else {
            pnova = malloc(sizeof(paragem));
            if (pnova == NULL) {
                printf("ERRO ao alocar memoria para PARAGEM!\n");
                return p;
            }

            /*
            verf = novo->lista;
            while (verf != NULL) {
                if (strcmp(verf->nome, nomeParagem) == 0) {
                    printf("Paragem [%s] JA se encontra na LINHA!\n", nomeParagem);
                    encontrado = 1;
                    break;
                }
                verf = verf->prox;
            }
            if (encontrado == 1)
                break;
        */

            strcpy(pnova->nome, nomeParagem);
            strcpy(pnova->codigo, temp->codigo);
            temp->numLinhas++;

            if (novo->lista == NULL) {
                novo->lista = pnova;
            }
            else {
                verf = novo->lista;
                while (verf->prox != NULL)
                    verf = verf->prox;
                verf->prox = pnova;
            }
            novo->nParag++;
        }

        printf("\n-> Inserir outra paragem? (S/N)");
        do{
            ch = getchar();
            fflush(stdin);
        }while(ch != 'S' && ch != 's' && ch != 'N' && ch != 'n');

    }while(encontrado == 1 || ch == 'S' || ch == 's');

    return p;
        /*
        if(verificaParagem(pp, n, nomeParagem) == 0){
            pnova = novo->lista;
            while(pnova != NULL){
                if(strcmp(pnova->nome, nomeParagem) == 0){
                    printf("Paragem [%s] JA se encontra na LINHA!\n", nomeParagem);
                    encontrado = 1;
                    break;
                }
                pnova = pnova->prox;
            }

            if(encontrado == 0){
                pnova = malloc(sizeof(paragem));
                if(pnova == NULL){
                    printf("ERRO ao alocar memoria para PARAGEM!\n");
                    return p;
                }

                strcpy(pnova->nome, nomeParagem);
                pnova->numLinhas = 1;
                pnova->prox = NULL;

                if (novo->lista == NULL) {
                    novo->lista = pnova;
                } else {
                    temp = novo->lista;
                    while (temp->prox != NULL)
                        temp = temp->prox;
                    temp->prox = pnova;
                }

                novo->nParag++;
            }
        }
        else{
            printf("NENHUMA paragem com o nome [%s] no SISTEMA\n", nomeParagem);
            encontrado = 1;
        }
    */
}


void addParagemLinha(plinha p, pparagem b, int n){
    pparagem novo;
    pparagem aux;

    system("cls");
    fflush(stdin);

    char nomeLinha[100], nomeParagem[100], ch;
    int i;

    printf("\n\t\t\t\t\t  --------------------------------------------\n");
    printf("\n\t\t\t\t\t  |         ADICIONAR PARAGEM A LINHA        |\n");
    printf("\n\t\t\t\t\t  --------------------------------------------\n");

    do{
        printf("Nome da linha a atualizar: ");
        scanf(" %99[^\n]", nomeLinha);

        while(p != NULL && (strcmp(p->nome, nomeLinha) != 0)){
            p = p->prox;
        }

        if(p == NULL){
            printf("LINHA com o nome [%s] NAO registada!\n", nomeLinha);
            return;
        }
        else{
            printf("Paragem a adicionar: ");
            scanf(" %99[^\n]", nomeParagem);

            for(i = 0; i < n; i++){
                if(strcmp(b[i].nome, nomeParagem) == 0){
                    novo = malloc(sizeof(paragem));
                    if(novo == NULL)
                        return;

                    strcpy(novo->nome, nomeLinha);
                    strcpy(novo->codigo, b[i].codigo);
                    b[i].numLinhas++;

                    p->nParag++;
                    novo->prox = p->lista;
                    p->lista = novo;
                }
            }

            while(p != NULL){
                aux = p->lista;
                while(aux != NULL){
                    if(strcmp(nomeParagem, aux->nome) == 0){
                        printf("Paragem ja se encontra definida na linha!\n");
                    }
                    aux = aux->prox;
                }
                p = p->prox;
            }

        }

        printf("\n-> Inserir outra paragem? (S/N)");
        do{
            ch = getchar();
            fflush(stdin);
        }while(ch != 'S' && ch != 's' && ch != 'N' && ch != 'n');

    }while(ch == 'S' || ch == 's');
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
*/

void listarLinhas(plinha p){
    pparagem aux;
    char ch;
    int n, i = 1;

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
            printf("\t  [%d] paragens\n\n", p->nParag);
            //p = p->prox;
            aux = p->lista;
            while(aux != NULL){
                printf("%d. Nome:%s Codigo:%s\n", i, aux->nome, aux->codigo);
                aux = aux->prox;
                i++;
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

void listarLinhasParagem(plinha p, pparagem pp, int n){
    pparagem aux;
    char nomeParagem[100], ch;
    int existe = 0;

    fflush(stdin);
    system("cls");

    printf("\n\t\t\t\t\t  --------------------------------------------\n");
    printf("\n\t\t\t\t\t  |    LISTA DA LINHA QUE PASSA NA PARAGEM   |\n");
    printf("\n\t\t\t\t\t  --------------------------------------------\n");

    printf("Listar linhas com a paragem: ");
    scanf(" %99[^\n]", nomeParagem);
    fflush(stdin);

    for(int i = 0; i < n; i++){
        if(strcmp(nomeParagem, pp[i].nome) == 0){
            existe = 1;
            break;
        }
    }

    if(existe == 0){
        printf("Paragem NAO registada no sistema!\n");
        return;
    }

    while(p != NULL){
        aux = p->lista;
        while(aux != NULL){
            if(strcmp(aux->nome, nomeParagem) == 0){
                printf("-> LINHA '%s'\n", p->nome);
                //aux = p->lista;
                break;
            }
            aux = aux->prox;
        }
        p = p->prox;
    }
    printf("\n-> ENTER para voltar ao menu anterior");

    do{
        ch = getchar();
        fflush(stdin);
    }while( ch != '\n');
}

