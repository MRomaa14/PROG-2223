// Miguel Umbelino da Mota Roma - a2021138955

#include "ficheiros.h"

//TRATA DE GUARDAR AS PARAGENS NUM FICHEIRO BINARIO
void guardaParagens(paragem *p, int total){
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
void guardaLinhas(plinha p) {
    FILE *f;
    f = fopen("linhas.dat", "wb");
    if (f == NULL) {
        printf("ERRO ao guardar o ficheiro das LINHAS\n");
        return;
    }

    while (p != NULL) {
        linha lin;
        strcpy(lin.nome, p->nome);
        lin.nParag = p->nParag;
        lin.lista = p->lista;
        lin.prox = p->prox;

        fwrite(&lin, sizeof(linha), 1, f);

        p = p->prox;
    }

    fclose(f);
}

plinha recuperaLinhas(){
    plinha p = NULL;
    linha lin;

    FILE *f;
    f = fopen("linhas.dat", "rb");
    if(f == NULL){
        printf("ERRO na leitura do ficheiro das LINHAS\n");
        return NULL;
    }

    while (fread(&lin, sizeof(linha), 1, f) == 1) {
        plinha novo = malloc(sizeof(linha));
        if (novo == NULL) {
            fclose(f);
            return p;
        }
        strcpy(novo->nome, lin.nome);
        novo->nParag = lin.nParag;
        novo->prox = NULL;

        pparagem paragem = NULL;
        for (int i = 0; i < lin.nParag; i++) {
            pparagem novaParagem = malloc(sizeof(paragem));
            if (novaParagem == NULL) {
                // Libera a memória alocada até o momento
                free(p);
                fclose(f);
                return NULL;
            }
            fread(novaParagem, sizeof(paragem), 1, f);
            novaParagem->prox = NULL;

            // Insere a paragem na lista de paragens da linha
            if (paragem == NULL) {
                novo->lista = novaParagem;
                paragem = novaParagem;
            } else {
                paragem->prox = novaParagem;
                paragem = paragem->prox;
            }
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