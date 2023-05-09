#include "contacto.h"

#include <stdio.h>
#include <stdlib.h>

int main(){
    contacto *agenda = NULL;
    int total = 0;

    agenda = malloc(sizeof(contacto));
    if(agenda == NULL){
        printf("Erro na alocacao de memoria\n");
        return 0;
    }

    for(int i = 0; i < 3; i++)
        addContacto(agenda, &total);

    listaContactos(agenda, total);

    char nome[100] = {"Miguel"};
    procuraNum(agenda, nome, total);

    atualizaContacto(agenda, nome,total);
    listaContactos(agenda, total);

    agenda = delContacto(agenda, &total, nome);
    listaContactos(agenda, total);

    //Libertar array dinamico
    free(agenda);

    return 0;
}
