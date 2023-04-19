// Miguel Umbelino da Mota Roma - a2021138955

#ifndef TP_P_LINHA_H
#define TP_P_LINHA_H

#include "paragem.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct linha linha, *plinha;
struct linha{
    char nome[100];
    int nParag;


    plinha prox;
};

void preenche(plinha p);

plinha addParagem(plinha p);

plinha delLinha(plinha p);

int contaLinhas(plinha p);

void listaLinhas(plinha p);

void procuraLinha(plinha p, char* proc);


#endif //TP_P_LINHA_H
