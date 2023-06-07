// Miguel Umbelino da Mota Roma - a2021138955

#include "ficheiros.h"

//TRATA DE GUARDAR AS PARAGENS NUM FICHEIRO BINARIO
void guardaParagens(pparagem p, int total){
    FILE *f;

    f = fopen("paragens.dat", "wb");
    if(f == NULL){
        printf("ERRO ao guardar o ficheiro das PARAGENS\n");
        return;
    }

    fwrite(&total, sizeof(int), 1, f);
    fwrite(p, sizeof(paragem), total, f);
    fclose(f);
}

//TRATA DE RECUPERAR AS PARAGENS DE UM FICHEIRO BINARIO
pparagem recuperaParagens(int *total){
    FILE *f;
    pparagem aux = NULL;

    *total = 0;
    f = fopen("paragens.dat", "rb");
    if(f == NULL){
        printf("ERRO na leitura do ficheiro\n");
        return NULL;
    }
    fread(total, sizeof(int), 1, f);

    aux = malloc(sizeof(paragem) * (*total));
    if(aux == NULL){
        fclose(f);
        *total = 0;
        return NULL;
    }
    fread(aux, sizeof(paragem), *total, f);

    fclose(f);
    return aux;
}


//TRATA DE GUARDAR AS LINHAS NUM FICHEIRO BINARIO
void guardaLinhas(plinha p){
    FILE *f;
    f = fopen("linhas.dat", "wb");
    if (f == NULL) {
        printf("ERRO na leitura do ficheiro das LINHAS\n");
        return;
    }
    if(f==NULL)
        return;

    while(p != NULL){
        fwrite(p, sizeof(linha), 1, f);

        while(p->lista != NULL){
            fwrite(p->lista, sizeof (paragem), 1, f);
            p->lista = p->lista->prox;
        }

        p = p->prox;
    }
    fclose(f);
}

//TRATA DE RECUPERAR AS LINHAS DE UM FICHEIRO BINARIO
plinha recuperaLinhas() {
    plinha p = NULL;

    FILE *f;
    f = fopen("linhas.dat", "rb");
    if (f == NULL) {
        printf("ERRO na leitura do ficheiro das LINHAS\n");
        return NULL;
    }

    linha lin;
    while (fread(&lin, sizeof(linha), 1, f) == 1) {
        plinha novo = malloc(sizeof(linha));
        if (novo == NULL) {
            fclose(f);
            return p;
        }
        *novo = lin;
        novo->prox = NULL;
        novo->lista = NULL;

        int nPara = novo->nParag;
        while (nPara > 0) {
            pparagem novaParagem = malloc(sizeof(paragem));
            if (novaParagem == NULL) {
                free(p);
                fclose(f);
                return NULL;
            }
            fread(novaParagem, sizeof(paragem), 1, f);
            novaParagem->prox = NULL;
            novaParagem->ant = NULL;

            // Insere a paragem na lista de paragens da linha
            if (novo->lista == NULL) {
                novo->lista = novaParagem;
            } else {
                pparagem paragem = novo->lista;
                while (paragem->prox != NULL) {
                    paragem = paragem->prox;
                }
                paragem->prox = novaParagem;
                novaParagem->ant = paragem;
            }

            nPara--;
        }

        // Insere a linha na lista de linhas
        if (p == NULL) {
            p = novo;
        } else {
            plinha aux = p;
            while (aux->prox != NULL) {
                aux = aux->prox;
            }
            aux->prox = novo;
        }
    }

    fclose(f);
    return p;
}

int verificaLinhaExiste(plinha p, char* nomeLinha) {
    plinha lin = p;
    while (lin != NULL) {
        if (strcmp(lin->nome, nomeLinha) == 0) {
            return 1;
        }
        lin = lin->prox;
    }
    return 0;
}

int verificaParagemExiste(plinha p, pparagem pp, int n, char* nomeParagem, char* codigo) {
    pparagem aux = pp;
    plinha temp = p;

    for(int i = 0; i < n; i++){
        if (strcmp(aux->nome, nomeParagem) == 0 || strcmp(aux->codigo, codigo) == 0)
            return 1;
    }

    while (temp != NULL) {
        pparagem verf = temp->lista;
        while (verf != NULL) {
            if (strcmp(verf->nome, nomeParagem) == 0) {
                return 1;
            }
            verf = verf->prox;
        }
        temp = temp->prox;
    }

    return 0;
}

plinha lerFicheiroTxt(plinha p, pparagem* pp, int *n){
    FILE *f;

    char nomeLinha[100], nomeParagem[100];
    char cod[5];

    f = fopen("linha1.txt", "r");
    if (f == NULL) {
        printf("[AVISO] Erro ao abrir o ficheiro!\n");
        return p;
    }

    fscanf(f, " %99[^\n]", nomeLinha);
    if(verificaLinhaExiste(p, nomeLinha) == 1){
        printf("[AVISO] Linha [%s] já existe no sistema!\n", nomeLinha);
        printf("Informação do ficheiro não será adicionada\n");
        fclose(f);
        return p;
    }

    plinha nova = malloc(sizeof(linha));
    if (nova == NULL) {
        printf("[AVISO] Erro ao alocar memória para a nova linha!\n");
        fclose(f);
        return p;
    }

    strcpy(nova->nome, nomeLinha);
    nova->nParag = 0;
    nova->lista = NULL;
    nova->prox = NULL;

    pparagem aux = NULL;
    while (fscanf(f, " %99[^#] #%4s", nomeParagem, cod) == 2) {
        nomeParagem[strlen(nomeParagem) - 1] = '\0';

        if (verificaParagemExiste(p, *pp, *n, nomeParagem, cod) == 1) {
            printf("[AVISO] Paragem [%s] já existe no sistema!\n", nomeParagem);
            printf("Informação do ficheiro não será adicionada.\n");
            fclose(f);
            free(nova);
            return p;
        }

        pparagem pnova = malloc(sizeof(paragem));
        if(pnova == NULL){
            printf("[AVISO] Erro ao alocar memória para a nova paragem!\n");
            fclose(f);
            free(pnova);
            return p;
        }

        strcpy(pnova->nome, nomeParagem);
        strcpy(pnova->codigo, cod);
        pnova->numLinhas = 1;
        pnova->ant = NULL;
        pnova->prox = NULL;

        if(aux == NULL){
            nova->lista = pnova;
        }
        else{
            aux->prox = pnova;
            pnova->ant = aux;
        }

        nova->nParag++;
        aux = pnova;

        (*n)++;
        *pp = realloc(*pp, sizeof(paragem) * (*n));
        if (*pp == NULL) {
            printf("[AVISO] Erro ao realocar memória para o array de paragens!\n");
            fclose(f);
            return p;
        }

        (*pp)[(*n) - 1] = *pnova;
    }

    fclose(f);

    if (p == NULL) {
        return nova;
    } else {
        plinha linhaAtual = p;
        while (linhaAtual->prox != NULL) {
            linhaAtual = linhaAtual->prox;
        }
        linhaAtual->prox = nova;
        return p;
    }
}