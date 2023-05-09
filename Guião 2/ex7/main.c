#include <stdlib.h>
#include <stdio.h>

#include "movimento.h"


int main(){
    mov *banco = NULL;
    int total = 0;

    banco = malloc(sizeof(mov));
    if(banco == NULL){
        printf("Erro na alocacao de memoria\n");
        return 0;
    }

    for(int i = 0; i < 3; i++){
        addMov(banco, &total);
    }
    listaMov(banco, total);

    /*
    data inf = {2, 3, 2000};
    data sup = {20, 5, 2001};
    listaLim(banco, total, sup, inf);

    char conta[] = "miguel11";
    infoNum(banco, total, conta);;
    */

    data elim = {14, 2, 2003};
    delMov(banco, &total, elim);
    listaMov(banco, total);

    free(banco);
    return 0;
}
