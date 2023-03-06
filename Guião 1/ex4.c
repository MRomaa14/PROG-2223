#include <stdio.h>

void f(int *t, int tam, int *np, int *ni, int *maior, int *pos){
    *maior = t[0];
    *pos = 0;

    for(int i = 0; i < tam; i++){
        if(t[i] % 2 == 0){
            (*np)++;
        }
        else{
            (*ni)++;
        }

        if(t[i] > *maior){
            *maior = t[i];
            *pos = i;
        }
    }
}

int main(){
    int even = 0, odd = 0;
    int biggest, pos;
    int tab[10] = {1, 3, 7, 5, 2, 10, 9, 7, 7, 1};

    f(tab, 10, &even, &odd, &biggest, &pos);
    printf("Even = [%d]\tOdd = [%d]\n", even, odd);
    printf("Biggest = [%d]\tPosition = [%d]\n", biggest, pos);

    return 0;
}