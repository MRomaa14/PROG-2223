#include "ponto.h"
#include <stdio.h>

// alinea b)
void printPonto(ponto2D a){
    printf("Ponto: (%d,%d)\n", a.x, a.y);
}

// alinea c)
void initPonto(ponto2D* p){
    printf("x:");
    scanf("%d", &p->x);

    printf("y:");
    scanf("%d", &p->y);
}

// alinea d)
void movePonto(ponto2D* p, int dx, int dy){
    p->x += dx;
    p->y += dy;
}

int verifica(ponto2D* p1, ponto2D* p2, ponto2D* p3){
    float m1, m2, mX, mY;

    mY = (p2->y) - (p1->y);
    mX = (p2->x) - (p1->x);

    if(mX != 0){
        m1 = mX/mY;
    }else{
        return 1;
    }

    mY = (p3->y) - (p2->y);
    mX = (p3->x) - (p2->x);

    if(mX != 0)
        m2 = mY/mX;
    else
        return 1;


    if(m1 == m2)
        return 1;
    else
        return 0;


}
