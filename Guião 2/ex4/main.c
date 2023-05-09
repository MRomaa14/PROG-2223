#include <stdio.h>

#include "voo.h"
#include "tempo.h"

int main(){
    voo v;
    struct tempo t1 = {22, 15};

    struct tempo t = hora_atual();
    printf(" São %2.2d:%2.2d\n", t.h, t.m);
    /*
    preencheInfo(&v);
    printInfo(v);

    alteraHora(&v);
    printInfo(v);

    int valida = verificaPartida(v, hora_atual());
    if(valida)
        printf("\nO VOO JA PARTIU!!!!\n");
    else
        printf("\nO VOO AINDA NAO PARTIU!!!!\n");
    */
    return 0;
}
/*
int main(){
    voo v1;
    tempo t1 = {22, 15};

    voo vooTab[300];
    int existem = 0;

    /*
    struct tempo t = hora_atual();
    printf(" São %2.2d:%2.2d\n", t.horas, t.minutos);

    preencheInfo(&v1);
    printInfo(v1);

    alteraHora(&v1);
    printInfo(v1);

    int valida = verificaPartida(v1, hora_atual());
    if(valida)
        printf("\nO VOO JA PARTIU!!!!\n");
    else
        printf("\nO VOO AINDA NAO PARTIU!!!!\n");


    adicionaTab(vooTab, &existem);
    printTab(vooTab, existem);

    verifica30(vooTab, existem, t1);
    delTab(vooTab, &existem, t1);

    int selection;
    do{
        printf("1. Introduzir novos voos\n");
        printf("2. Listar todos os voos\n");
        printf("3. Listar proximos voos\n");
        printf("4. Atualizar tabela de voos\n");
        printf("5. Terminar\n");


        printf("\nEscolha uma opcao:");
        scanf("%d", &selection);

        switch(selection){
            case 1:
                preencheInfo(&v1);
                break;
            case 2:
                printTab(vooTab, existem);
                break;
            case 3:
                verifica30(vooTab, existem, hora_atual());
                break;
            case 4:
                delTab(vooTab, &existem, hora_atual());
                break;
            case 5:
                printf("A encerrar o programa......\n");
                break;
            default:
                printf("ERRO! Opcao invalida!\n");
        }
    }while(selection != 5);

    return 0;
}
*/