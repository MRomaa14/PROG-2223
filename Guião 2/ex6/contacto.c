#include "contacto.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

contacto* addContacto(contacto *tab, int* n){
    contacto *aux = realloc(tab, sizeof(contacto) * (*n+1));
    int existe;

    if(aux != NULL){
        tab = aux;
        printf("\t-----Novo Contacto-----\n");

        do{
            existe = 0;
            printf("Nome:");
            scanf("%s", tab[*n].nome);

            for(int i = 0; i < *n; i++){
                if(strcmp(tab[*n].nome, tab[i].nome) == 0)
                    existe = 1;
            }
        }while(existe == 1);

        printf("Numero:");
        scanf("%d", &tab[*n].num);

        (*n)++;
    }
    return tab;
}

void listaContactos(contacto *tab, int n){
    int i;

    for(i = 0; i < n; i++){
        printf("\t-----Contacto %d-----\n", i+1);
        printf("Nome: %s\n", tab[i].nome);
        printf("Numero: %d\n", tab[i].num);
    }
}

void procuraNum(contacto* tab, char nome[], int n){
    for(int i = 0; i < n; i++){
        if(strcmp(tab[i].nome, nome) == 0){
            printf("Numero do [%s]: %d\n", tab[i].nome, tab[i].num);
            return;
        }
    }
    printf("Contacto nao existente");
}

void atualizaContacto(contacto* tab, char* nome, int n){
    for(int i = 0; i < n; i++){
        if(strcmp(tab[i].nome, nome) == 0){
            printf("Contacto atual: %d\n", tab[i].num);
            printf("Novo contacto: ");
            scanf("%d", &tab[i].num);
            return;
        }
    }
    printf("Contacto nao existe!\n");
}

contacto* delContacto(contacto* tab, int *n, char* nome){
    contacto *aux, t;
    int i;

    for(i = 0; i < *n && (strcmp(tab[i].nome, nome) != 0); i++);

    if(i == *n){    //Chegou ao fim e nao encontrou um contacto com esse nome
        printf("Contacto nao existe!\n");
    }
    else if(*n == 1){   //So existe 1 contacto na agenda pelo que podemos dar free
        free(tab);
        *n = 0;
        return NULL;
    }
    else{   //Se houver mais que 1 contacto na lista
        t = tab[i];
        tab[i] = tab[*n-1];
        aux = realloc(tab, sizeof(contacto) * (*n-1));

        if(aux != NULL){
            tab = aux;
            (*n)--;
        }
        else
            tab[i] = t;

        return tab;
    }
}