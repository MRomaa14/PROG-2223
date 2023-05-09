#include <stdio.h>
#include "retangulo.h"

void imprime_cantos(ret a) {
    printf("  \t----Coordenadas----\n");

    printf("Canto i.e: X = %d\tY = %d\n", a.ci.x, a.ci.y);
    printf("Canto s.e: X = %d\tY = %d\n", a.ci.x, a.ci.y + a.alt);

    putchar('\n');

    printf("Canto i.d: X = %d\tY = %d\n", a.ci.x + a.larg, a.ci.y);
    printf("Canto s.d: X = %d\tY = %d\n", a.ci.x + a.larg, a.ci.y + a.alt);
}

void initRet(ret* a){
    printf("Canto inferior esquerdo:");
    scanf("%d %d", &a->ci.x, &a->ci.y);

    printf("Largura:");
    scanf("%d", &a->larg);

    printf("Altura:");
    scanf("%d", &a->alt);
}

int area(ret a){
    int area = a.alt*a.larg;
    return area;
}

int verificaDentro(ret a, ponto2D p){
    if(p.x > a.ci.x && p.x < a.ci.x+a.larg){
        if(p.y > a.ci.y && p.y <a.ci.y+a.alt){
            return 1;
        }
    }
    return 0;
}


void deslocaRet(ret* a, int x, int y){
    a->ci.x += x;
    a->ci.y += y;

    printf("Novas coordenadas: X = %d\t Y = %d\n", a->ci.x, a->ci.y);
    imprime_cantos(*a);
}