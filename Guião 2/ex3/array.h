#ifndef GUIAO2_ARRAY_H
#define GUIAO2_ARRAY_H

#include <stdio.h>
#include <math.h>

#include "ponto.h"
#include "retangulo.h"

int addR(ret tab[], int *total);

void printAll(ret tab[], int total);

int delR(ret tab[], int *total);

int delLim(ret tab[], int *total, int lim);

void distEucl(ret tab[], int total);

#endif //GUIAO2_ARRAY_H
