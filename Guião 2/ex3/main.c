#include <stdio.h>

#include "retangulo.h"
#include "ponto.h"
#include "array.h"

int main(){
    ret tab[10];
    int total = 0;

    for(int i = 0; i < 3; i++){
        addR(tab, &total);
    }

    printf("Antes de apagar:");
    printAll(tab, total);

    //delR(tab, &total);
    delLim(tab, &total, 15);

    printf("Depois de apagar:\n");
    printAll(tab, total);

    return 0;
}
