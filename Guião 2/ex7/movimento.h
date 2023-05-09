#ifndef GUIAO2_MOVIMENTO_H
#define GUIAO2_MOVIMENTO_H

typedef struct {
    int d, m, a;
} data;

typedef struct movimento{
    data dMov;
    char nconta[15];
    int val;
}mov;

mov* addMov(mov *tab, int *n);

void listaMov(mov *tab, int n);

void listaLim(mov *tab, int n, data limSup, data limInf);

void infoNum(mov *tab, int n, char* num);

mov* delMov(mov *tab, int *n, data data1);

#endif //GUIAO2_MOVIMENTO_H
