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
            return &aux[i];
        }
    }
    return NULL;
}

//REGISTAR UMA LINHA NA LISTA LIGADA E PARAGEM OBRIGATORIA
plinha regLinha(plinha p, pparagem pp, int n){
    plinha novo, aux;
    pparagem pnova, verf;

    char nomeLinha[100], nomeParagem[100], ch;
    int existe, encontrado;

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
                printf("[AVISO] Linha '%s' ja esta REGISTADA!\n\n", nomeLinha);
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
            //encontrado = 1;
        }
        else {
            verf = novo->lista;
            while (verf != NULL) {
                if (strcmp(verf->nome, nomeParagem) == 0) {
                    printf("[AVISO] Paragem [%s] JA se encontra na LINHA!\n", nomeParagem);
                    encontrado = 1;
                    break;
                }
                verf = verf->prox;
            }

            if(encontrado == 0) {
                pnova = malloc(sizeof(paragem));
                if (pnova == NULL) {
                    printf("ERRO ao alocar memoria para PARAGEM!\n");
                    return p;
                }

                printf("Paragem adicionada com SUCESSO!\n");
                strcpy(pnova->nome, nomeParagem);
                strcpy(pnova->codigo, temp->codigo);
                temp->numLinhas++;

                if (novo->lista == NULL) {
                    novo->lista = pnova;
                } else {
                    verf = novo->lista;
                    while (verf->prox != NULL)
                        verf = verf->prox;
                    verf->prox = pnova;
                }
                novo->nParag++;
            }
        }

        printf("\n-> Inserir outra paragem? (S/N)");
        do{
            fflush(stdin);
            ch = getchar();
        }while(ch != 'S' && ch != 's' && ch != 'N' && ch != 'n');

    }while(ch == 'S' || ch == 's');

    return p;
}

//ADICIONAR PARAGENS A UMA LINHA
void addParagemLinha(plinha p, pparagem pp, int n){
    plinha temp;
    pparagem novo, aux;

    char nomeLinha[100], nomeParagem[100], ch;

    do {
        system("cls");
        fflush(stdin);

        printf("\n\t\t\t\t\t  --------------------------------------------\n");
        printf("\n\t\t\t\t\t  |         ADICIONAR PARAGEM A LINHA        |\n");
        printf("\n\t\t\t\t\t  --------------------------------------------\n");

        temp = p;
        printf("-> Linha a atualizar: ");
        scanf(" %99[^\n]", nomeLinha);

        while (temp != NULL && (strcmp(temp->nome, nomeLinha) != 0)) {
            temp = temp->prox;
        }

        if (temp == NULL) {
            printf("[AVISO] LINHA '%s' NAO registada!\n", nomeLinha);

            printf("\n-> Inserir outra linha (S/N)?");
            do {
                fflush(stdin);
                ch = getchar();
            }while(ch != 'S' && ch != 's' && ch != 'N' && ch != 'n');

            if(ch == 'N' || ch == 'n')
                return;
        }
    }while(temp == NULL);

    do{
        printf("-> Paragem a adicionar: ");
        scanf(" %99[^\n]", nomeParagem);

        aux = procuraParagem(pp, n, nomeParagem);
        if(aux == NULL){
            printf("[AVISO] NENHUMA paragem com o nome [%s] no SISTEMA\n", nomeParagem);

            printf("-> Inserir outra paragem (S/N)?");
            do {
                fflush(stdin);
                ch = getchar();
            }while(ch != 'S' && ch != 's' && ch != 'N' && ch != 'n');

            if(ch == 'N' || ch == 'n')
                return;
        }
        else {
            aux = p->lista;
            while(aux != NULL){
                if(strcmp(nomeParagem, aux->nome) == 0){
                    printf("Paragem JA definida na LINHA!\n");
                    break;
                }
                aux = aux->prox;
            }

            if(aux == NULL) {
                novo = malloc(sizeof(paragem));
                if (novo == NULL) {
                    printf("[AVISO] ERRO ao alocar memoria para PARAGEM!\n");
                    return;
                }
                aux = procuraParagem(pp, n, nomeParagem);
                strcpy(novo->nome, nomeParagem);
                strcpy(novo->codigo, aux->codigo);
                aux->numLinhas++;

                novo->prox = NULL;
                if(temp->lista == NULL) {
                    temp->lista = novo;
                }
                else{
                    aux = temp->lista;
                    while(aux->prox != NULL){
                        aux = aux->prox;
                    }
                    aux->prox = novo;
                }
                p->nParag++;
                printf("Paragem adicionada com SUCESSO!\n");
            }
        }

        printf("\n-> Inserir outra paragem? (S/N)");
        do{
            ch = getchar();
            fflush(stdin);
        }while(ch != 'S' && ch != 's' && ch != 'N' && ch != 'n');
    }while(ch == 'S' || ch == 's');
}

//ELIMINAR PARAGENS DE UMA LINHA
void elimParagemLinha(plinha p, pparagem pp, int n) {
    plinha linha;
    pparagem apagar;

    char nomeLinha[100], nomeParagem[100];
    char ch;

    do{
        system("cls");
        fflush(stdin);

        printf("\n\t\t\t\t\t  --------------------------------------------\n");
        printf("\n\t\t\t\t\t  |         ELIMINAR PARAGEM DA LINHA        |\n");
        printf("\n\t\t\t\t\t  --------------------------------------------\n");

        printf("-> Linha a alterar: ");
        scanf(" %99[^\n]", nomeLinha);

        linha = p;
        while(linha != NULL && strcmp(linha->nome, nomeLinha) != 0)
            linha = linha->prox;

        if(linha == NULL){
            printf("[AVISO] LINHA '%s' NAO registada!\n", nomeLinha);

            printf("\n-> Inserir outra linha (S/N)?");
            do {
                fflush(stdin);
                ch = getchar();
            }while(ch != 'S' && ch != 's' && ch != 'N' && ch != 'n');

            if(ch == 'N' || ch == 'n')
                return;
        }
    }while(linha == NULL);

    do{
        fflush(stdin);

        printf("-> Paragem a eliminar: ");
        scanf(" %99[^\n]", nomeParagem);

        apagar = procuraParagem(pp, n, nomeParagem);
        apagar->numLinhas--;

        pparagem ant = NULL;
        apagar = linha->lista;
        while(apagar != NULL && strcmp(apagar->nome, nomeParagem) != 0){
            ant = apagar;
            apagar = apagar->prox;
        }

        if(apagar == NULL){
            printf("[AVISO] PARAGEM [%s] NAO registada na LINHA!\n", nomeParagem);

            printf("-> Introduzir outra paragem (S/N)?");
            do{
                fflush(stdin);
                ch = getchar();
            }while(ch != 'S' && ch != 's' && ch != 'N' && ch != 'n');
        }
        else{
            if(ant == NULL)
                //p->lista = apagar->prox;
                linha->lista = apagar->prox;
            else
                ant->prox = apagar->prox;

            linha->nParag--;
            free(apagar);

            printf("PARAGEM [%s] eliminada com SUCESSO!\n", nomeParagem);

            if (linha->lista == NULL) {
                // No stops remaining, delete the line
                if (linha == p) {
                    // If the line is the first one
                    p = p->prox;
                }
                else {
                    // Find the previous line
                    plinha prev = p;
                    while (prev->prox != linha)
                        prev = prev->prox;

                    prev->prox = linha->prox;
                }
                free(linha);
                printf("LINHA [%s] eliminada por nao ter mais paragens.\n", nomeLinha);
            }

            printf("-> Eliminar outra paragem (S/N)?");
            do{
                fflush(stdin);
                ch = getchar();
            }while(ch != 'S' && ch != 's' && ch != 'N' && ch != 'n');
        }
    }while(ch == 'S' || ch == 's');
}

//LISTAR AS LINHAS DO METRO E AS SUAS PARAGENS
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
            int i = 1;

            printf("|------- LINHA '%s' -------|\n", p->nome);
            printf("\t  [%d] paragens\n\n", p->nParag);
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

//LISTAR AS LINHAS QUE PASSEM NA PARAGEM INTRODUZIDA PELO UTILIZADOR
void listarLinhasParagem(plinha p){
    pparagem aux;

    char nomeParagem[100], ch;
    int encontrada = 0;

    fflush(stdin);
    system("cls");

    printf("\n\t\t\t\t\t  --------------------------------------------\n");
    printf("\n\t\t\t\t\t  |    LISTA DA LINHA QUE PASSA NA PARAGEM   |\n");
    printf("\n\t\t\t\t\t  --------------------------------------------\n");

    printf("Listar linhas com a paragem: ");
    scanf(" %99[^\n]", nomeParagem);

    while(p != NULL){
        aux = p->lista;
        while(aux != NULL){
            if(strcmp(aux->nome, nomeParagem) == 0){
                printf("\tLINHA '%s'\n", p->nome);
                encontrada = 1;
                break;
            }
            aux = aux->prox;
        }
        p = p->prox;
    }

    if(encontrada == 0){
        printf("NENHUMA linha com a paragem [%s]\n", nomeParagem);
    }

    printf("\n-> ENTER para voltar ao menu anterior");
    do{
        fflush(stdin);
        ch = getchar();
    }while( ch != '\n');
}

