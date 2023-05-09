#include <stdio.h>
#include "retangulo.h"

void imprime_cantos(ret a){
    printf("Canto s.e: X = %d\tY = %d\n", a.larg, a.alt-a.alt);
    printf("Canto i.e: X = %d\tY = %d\n", a.larg-a.larg, a.alt-a.alt);

    printf("Canto s.d: X = %d\tY = %d\n", a.larg, a.alt);
    printf("Canto i.d: X = %d\tY = %d\n", a.larg-a.larg, a.alt);
}

void initRet(ret* a){
    printf("\nCoordenada X:");
    scanf("%d", &a->larg);

    printf("Coordenada Y:");
    scanf("%d", &a->alt);
}

int area(ret a){
    int area = a.alt*a.larg;
    return area;
}

int verificaDentro(ret a, int x, int y){
    if(x < a.larg && x > 0){
        if(y < a.alt && y > 0)
            return 1;
    }
    return 0;
}

void deslocaRet(ret* a, int x, int y){
    a->alt += y;
    a->larg += x;

    printf("Novas coordenadas: X = %d\t Y = %d\n", a->larg, a->alt);
    imprime_cantos(*a);
}