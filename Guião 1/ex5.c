#include <stdio.h>

int countComm(int *tabA, int tamA, int *tabB, int tamB){
    int common = 0;

    for(int i = 0; i < tamA; i++){
        for(int j = 0; j < tamB; j++){
            if(tabA[i] == tabB[j]){
                common++;
            }
        }
    }

    return common;
}

int main(){
    int tab1[10] = {1, 2, 4, 5, 7, 8, 10, 11};
    int tab2[5] = {1, 3, 5, 7, 9};

    int x = countComm(tab1, 10, tab2, 5);
    printf("There are [%d] numbers in common!\n", x);
}