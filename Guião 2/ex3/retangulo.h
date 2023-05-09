#ifndef GUIAO2_RETANGULO_H
#define GUIAO2_RETANGULO_H

#include "ponto.h"

typedef struct retangulo{
    ponto2D ci;
    int alt, larg;
}ret;

void imprime_cantos(ret a);

void imprime_quadrados(ret tab[], int n);

void elimina_retangulo(ret tab[], int n);

void initRet(ret* a);

int area(ret a);

int verificaDentro(ret a, ponto2D p);

void deslocaRet(ret* a, int x, int y);

#endif //GUIAO2_RETANGULO_H
