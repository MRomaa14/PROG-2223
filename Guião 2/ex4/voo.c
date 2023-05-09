#include "voo.h"

void printInfo(voo a){
    printf("\t-----INFORMACAO DO VOO-----\n");
    printf("Numero do voo: %d\n", a.numVoo);
    printf("Nome da companhia: %s\n", a.nomeCompanhia);
    printf("Cidade destino: %s\n", a.cidadeDest);
    printf("Hora de partida: %d:%d\n", a.partida.h, a.partida.m);
}

void preencheInfo(voo *a){
    printf(" \t-----NOVO VOO-----\n");

    printf("Numero do voo:");
    scanf("%d", &a->numVoo);

    printf("Nome da companhia:");
    scanf("%s", a->nomeCompanhia);

    printf("Cidade destino::");
    scanf("%s", a->cidadeDest);

    printf("Hora de partida(HH MM):");
    scanf("%d %d", &a->partida.h, &a->partida.m);
}

void alteraHora(voo *a){
    printf("\nNova hora de partida(HH MM):");
    scanf("%d %d", &(a->partida.h), &(a->partida.m));
}

int verificaPartida(voo a, struct tempo atual){
    if(a.partida.h < atual.h)
        return 0;
    else if(a.partida.h == atual.h){
        if(a.partida.m < atual.m)
            return 0;
        else
            return 1;
    }
    else
        return 1;
}
/*
void adicionaTab(voo tab[], int *n){
    printf("\t-----ADICIONAR NA TABELA-----\n");

    int num;
    printf("Numero de voos a adicionar:");
    scanf("%d", &num);

    for(int i = 0; i < num; i++){
        preencheInfo(&tab[*n]);
        (*n)++;
    }
    printf("\nEXISTEM AGORA %d VOOS\n", *n);
}

void printTab(voo tab[], int n){
    for(int i = 0; i < n; i++)
        printInfo(tab[i]);
}

void verifica30(voo tab[], int n, tempo atual){
    printf("\t-----VOOS QUE PARTEM EM 30-----\n");
    for(int i = 0; i < n; i++){
        if(tab[i].partida.horas == atual.horas){
            int restam = (tab[i].partida.minutos - atual.minutos);
            if(restam >= 30){
                printf("Numero do voo: %d\n", tab[i].numVoo);
                printf("Destino: %s\n", tab[i].cidadeDest);
                printf("Tempo restante: %dmin\n", restam);
            }
        }
        else if (tab[i].partida.horas < atual.horas){
            int restam =  (atual.horas*60 + atual.minutos) - (tab[i].partida.horas * 60 + tab[i].partida.minutos);
            printf("Restam: %d\n", restam);
            if(restam >= 30){
                printf("Numero do voo: %d\n", tab[i].numVoo);
                printf("Destino: %s\n", tab[i].cidadeDest);
                printf("Tempo restante: %dmin\n", restam);
            }
        }
        putchar('\n');
    }
}

void delTab(voo tab[], int *n, tempo atual){
    int numVoos = *n;
    for(int i = 0; i < numVoos; i++){


    }

}
 */