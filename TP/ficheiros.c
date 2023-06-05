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
                // Libera a memória alocada até o momento
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

void leFicheiro(){
    FILE *f;

    f = fopen("linha1.txt", "r");
    if(f == NULL){
        printf("[ERRO] Nao foi possivel abrir o ficheiro.\n");
        return;
    }

    plinha nova = malloc(sizeof(linha));
    if (nova == NULL) {
        printf("[ERRO] Falha na alocacao de memoria.\n");
        return;
    }
    nova->prox = NULL;
    //nova->ant = NULL;

    char nomeLinha[100];
    fgets(nomeLinha, sizeof(nomeLinha), f);
    //nomeLinha[strcspn(nomeLinha, "\n")] = '\0';

    strcpy(nova->nome, nomeLinha);
    nova->nParag = 0;
    nova->lista = NULL;

}