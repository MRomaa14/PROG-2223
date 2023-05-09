#ifndef GUIAO2_CONTACTO_H
#define GUIAO2_CONTACTO_H

typedef struct contacto{
    char nome[50];
    int num;
}contacto;

contacto* addContacto(contacto *tab, int *n);

void listaContactos(contacto tab[], int n);

void procuraNum(contacto* tab, char* nome, int n);

void atualizaContacto(contacto* tab, char* nome, int n);

contacto* delContacto(contacto* tab, int *n, char* nome);

#endif //GUIAO2_CONTACTO_H
