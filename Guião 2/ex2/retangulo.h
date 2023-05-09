#ifndef GUIAO2_RETANGULO_H
#define GUIAO2_RETANGULO_H

typedef struct retangulo{
    int alt;
    int larg;
}ret;

void imprime_cantos(ret a);

void initRet(ret* a);

int area(ret a);

int verificaDentro(ret a, int x, int y);

void deslocaRet(ret* a, int x, int y);

#endif //GUIAO2_RETANGULO_H
