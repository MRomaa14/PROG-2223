// Miguel Umbelino da Mota Roma - a2021138955
#ifndef TP_P_LINHA_H
#define TP_P_LINHA_H

#include "utils.h"
#include "paragem.h"

typedef struct linha linha, *plinha;
struct linha{
    char nome[100];
    int nParag;

    pparagem lista;
    plinha prox;
};

int contaNos(plinha p);

pparagem procuraParagem(pparagem pp, int n, char *nomeParagem);

plinha regLinha(plinha p, pparagem parag, int n);

void addParagemLinha(plinha p, pparagem b, int n);

void elimParagemLinha(plinha p, pparagem pp, int n);

void listarLinhas(plinha p);

void listarLinhasParagem(plinha p);

#endif //TP_P_LINHA_H
