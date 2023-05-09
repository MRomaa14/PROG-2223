#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "movimento.h"

mov* addMov(mov *tab, int *n){
    mov *aux;
    aux = realloc(tab, sizeof(mov) * (*n+1));


    if(aux != NULL){
        tab = aux;
        printf("\t-----NOVO MOVIMENTO-----\n");

        printf("Data da transacao(dd/mm/aaaa): ");
        scanf("%d %d %d", &tab[*n].dMov.d, &tab[*n].dMov.m, &tab[*n].dMov.a);

        printf("ID da conta: ");
        scanf("%s", tab[*n].nconta);

        printf("Valor movimentado: ");
        scanf("%d", &tab[*n].val);

        (*n)++;
    }
    return tab;
}

void listaMov(mov *tab, int n){
    for(int i = 0; i < n; i++){
        printf("\n\t-----MOVIMENTO %d-----\n", i+1);
        printf("Data(dd/mm/aaaa): %d/%d/%d\n", tab[i].dMov.d, tab[i].dMov.m, tab[i].dMov.a);
        printf("ID da conta: %s\n", tab[i].nconta);
        printf("Montante: %d\n", tab[i].val);
    }
}

void listaLim(mov *tab, int n, data limSup, data limInf){
    printf("\n\t-----LISTA NO LIMITE-----\n");
    for(int i = 0; i < n; i++){
        if(tab[i].dMov.d >= limInf.d && tab[i].dMov.d <= limSup.d){
            if(tab[i].dMov.m >= limInf.m && tab[i].dMov.m <= limSup.m){
                if(tab[i].dMov.a >= limInf.a && tab[i].dMov.a <= limSup.a){
                    printf("\n\t-----MOVIMENTO %d-----\n", i+1);
                    printf("Data(dd/mm/aaaa): %d/%d/%d\n", tab[i].dMov.d, tab[i].dMov.m, tab[i].dMov.a);
                    printf("ID da conta: %s\n", tab[i].nconta);
                    printf("Montante: %d\n", tab[i].val);
                }
            }
        }
    }
}

void infoNum(mov *tab, int n, char* num){
    int movs = 0, saldo = 0;
    int lev = 0, depos = 0;
    for(int i = 0; i < n; i++){
        if(strcmp(tab[i].nconta, num) == 0){
            movs++;
            saldo += tab[i].val;
            if(tab[i].val > 0)
                depos++;
            else
                lev++;
        }
    }
    printf("Informacao da conta [%s]\n", num);
    printf("Movimentos: %d\tSaldo: %d\n", movs, saldo);
    printf("Levantamentos: %d\tDepositos: %d\n", lev, depos);
}

mov* delMov(mov *tab, int *n, data data1){
    mov *aux;
    int i, j = 0;

    for(i = 0; i < *n; i++){
        if(tab[i].dMov.d == data1.d && tab[i].dMov.m == data1.m && tab[i].dMov.a == data1.a){
            j++;
        } else {
            tab[i-j] = tab[i];
        }
    }

    if(j > 0){
        aux = realloc(tab, sizeof(mov) * (*n-j));
        if(aux != NULL){
            tab = aux;
            (*n) -= j;
        }
    }

    if(*n == 0){
        free(tab);
        return NULL;
    }

    return tab;
}