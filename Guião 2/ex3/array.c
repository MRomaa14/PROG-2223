#include "array.h"

int addR(ret tab[], int* total){
    printf("Ha %d retangulo(s) no array\n", *total);
    if(*total >= 10){
        printf("O array esta totalmente preenchido!\n");
        return 1;
    }
    initRet(&tab[*total]);
    (*total)++;

    return 0;
}

void printAll(ret tab[], int total){
    for(int i = 0; i < total; i++){
        imprime_cantos(tab[i]);
    }
}

int delR(ret tab[], int *total){
    if(*total == 0){
        printf("Nao ha retangulos para apagar\n");
        return 1;
    }

    int maisPeq = area(tab[0]);
    int pos = 0;

    for(int i = 1; i < *total; i++){
        if(area(tab[i]) < maisPeq){
            maisPeq = area(tab[i]);
            pos = i;
        }
    }

    for(int i = pos; i < *total - 1; i++)
        tab[i] = tab[i + 1];
    (*total)--;

    return 0;
}

int delLim(ret tab[], int *total, int lim){
    for(int i = 0; i < *total; i++){
        if(area(tab[i]) < lim){
            for(int j = i; j < *total - 1; j++){
                tab[j] = tab[j + 1];
            }
            i--;
            (*total)--;
        }
    }

    return 0;
}