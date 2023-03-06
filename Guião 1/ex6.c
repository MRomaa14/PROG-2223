#include <stdio.h>

void vizinhos(int *tab, int dim, int *eq){
    for(int i = 1; i < dim - 1; i++){
        int avg = (tab[i-1] + tab[i+1]) / 2;

        if(tab[i] == avg){
            (*eq)++;
        }
    }
}

int main(){
    int equal = 0;
    int tab[10] = {1, 4, 3, 4, 2, 6, 1, 8, 9, 10};

    vizinhos(tab, 10, &equal);
    printf("There are [%d] equal!\n", equal);

    return 0;
}