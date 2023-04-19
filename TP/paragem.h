// Miguel Umbelino da Mota Roma - a2021138955

#ifndef TP_P_PARAGEM_H
#define TP_P_PARAGEM_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct paragem paragem, *pparagem;
struct paragem{
    char nome[100];
    char codigo[5];
    int numLinhas;
};

paragem* inicParagem();

paragem obtemInfo(paragem *tab, int n);

paragem* regParagem(paragem *tab, int *n);

paragem* elimParagem(paragem *tab, int *n);

void listaParagens(paragem *tab, int n);

#endif
