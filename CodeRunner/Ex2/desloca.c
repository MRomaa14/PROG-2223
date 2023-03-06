#include <stdio.h>

void desloca(int v[], int tam, int shift){
    int vaux[tam];
    int j = 0;

    if(shift < tam){
        for(int i = tam - shift; i < tam; i++){
            vaux[j] = v[i];
            j++;
        }
        for(int i = 0; i < tam - shift; i++){
            vaux[j] = v[i];
            j++;
        }
        for(int i = 0; i < tam; i++){
            v[i] = vaux[i];
        }
    }
}

void printv(int v[], int n){
    for(int i = 0; i < n; i++){
        printf("%d ", v[i]);
    }
}

int main(){
    //int tab[6] = {1, 2, 3, 4, 5, 6};
    //desloca(tab, 6, 1);
    //printv(tab, 6);

    int tab2[5] = {2, 4, 6, 8, 10};
    desloca(tab2, 5, 2);
    printv(tab2, 5);

    return 0;
}