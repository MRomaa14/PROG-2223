#ifndef GUIAO2_TEMPO_H
#define GUIAO2_TEMPO_H

#include <stdio.h>
#include <time.h>

struct tempo{
    int h, m;
};
struct tempo hora_atual(){
    time_t a;
    struct tm* b;
    struct tempo atual;
    time(&a);
    b = localtime(&a);
    atual.h = b->tm_hour;
    atual.m = b->tm_min;
    return atual;
}

#endif //GUIAO2_TEMPO_H
