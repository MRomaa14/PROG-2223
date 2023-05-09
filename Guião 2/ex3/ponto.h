#ifndef GUIAO2_PONTO_H
#define GUIAO2_PONTO_H

typedef struct ponto{
    int x, y;
}ponto2D;

void printPonto(ponto2D a);

void initPonto(ponto2D* p);

void movePonto(ponto2D* p, int dx, int dy);

int verifica(ponto2D* p1, ponto2D* p2, ponto2D* p3);

#endif //GUIAO2_PONTO_H
