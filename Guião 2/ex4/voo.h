#ifndef GUIAO2_VOO_H
#define GUIAO2_VOO_H

#include <stdio.h>
#include "tempo.h"

typedef struct voo{
    struct tempo partida;
    int numVoo;
    char nomeCompanhia[50];
    char cidadeDest[50];
}voo;

void printInfo(voo a);

void preencheInfo(voo *a);

void alteraHora(voo *a);

int verificaPartida(voo a, struct tempo atual);

/*
void adicionaTab(voo tab[], int *n);

void printTab(voo tab[], int n);

void verifica30(voo tab[], int n, tempo atual);

void delTab(voo tab[], int *n, tempo atual);
*/
#endif //GUIAO2_VOO_H
