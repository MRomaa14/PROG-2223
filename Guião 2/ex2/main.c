#include <stdio.h>
#include "retangulo.h"

int main(){
    ret r1 = {3, 3}, r2;

    //imprime_cantos(r1);

    initRet(&r2);
    imprime_cantos(r2);

    int medidaArea = area(r2);
    printf("Area = %d\n", medidaArea);

    int x = verificaDentro(r2, 3, 3);
    if(x == 1)
        printf("Dentro do retangulo\n");
    else
        printf("Fora do retangulo\n");

    deslocaRet(&r2, 2, 2);

    return 0;
}
