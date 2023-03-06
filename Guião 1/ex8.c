#include <stdio.h>

int maior_subida(int *tab, int dim){
    int pos = 0;
    int mSub = 0;

    for(int i = 0; i < dim - 1; i++){
        int sub = tab[i+1] - tab[i];        
        if(sub > mSub){
            printf("tab[%d] - tab[%d] = %d\n", i+1, i, sub);
            mSub = sub;
            pos = i;
        }
    }

    return pos;
}

int main(){
    int tab[10] = {1, 3, 7, 5, 2, 10, 9, 7, 7, 1};

    int x = maior_subida(tab, 10);
    printf("Position = %d", x);

    return 0;
}