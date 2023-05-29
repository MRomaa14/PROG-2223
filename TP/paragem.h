// Miguel Umbelino da Mota Roma - a2021138955

#ifndef TP_P_PARAGEM_H
#define TP_P_PARAGEM_H

#include "utils.h"

typedef struct paragem paragem, *pparagem;
struct paragem{
    char nome[100];
    char codigo[5];
    int numLinhas;

    pparagem prox;
};

pparagem inicParagem();

paragem obtemInfo(paragem *tab, int n);

pparagem regParagem(paragem *tab, int *n);

pparagem elimParagem(paragem *tab, int *n);

void listaParagens(paragem *tab, int n);

void guardaParagens(paragem *p, int total);

pparagem leParagens(int *total);

#endif
