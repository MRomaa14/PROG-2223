#include <stdio.h>

void procura_dupla(int *tab, int tam, int *prim, int *seg){
    *prim = tab[0];
    
    for(int i = 1; i < tam; i++){
        if(tab[i] >= *prim){
            *seg = *prim;
            *prim = tab[i];
        }
        else if(tab[i] > *seg && tab[i] < *prim){
            *seg = tab[i];
        }
    }
}

int main(){
    int first, second = 0;
    //int tab[8] = {25,23,15,20,1,4,6,2};
    int tab[8] = {2, 25, 15, 20, 1, 4, 6, 30};

    procura_dupla(tab, 8, &first, &second);
    printf("Biggest number = %d\tSecond biggest = %d\n", first, second);

    return 0;
}