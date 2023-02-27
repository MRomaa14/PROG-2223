#include <stdio.h>

void unique(int v[], int tam){
    int vec[tam];
    int k = 0;

    for(int i = 0; i < tam; i++){
        int flag = 0;
        for(int j = 0; j < tam; j++){
            if(v[i] == v[j]){
                flag++;
            }
        }

        if(flag == 1){
            vec[k] = v[i];
            k++;
        }
    }

    for(int i = 0; i < k; i++){
        printf("%d ", vec[i]);
    }
}

int main(){
    int tab[10] = {2, 30, 4, 7, 10, 3, 12, 15, 2, 10};

    unique(tab, 10);

    return 0;
}