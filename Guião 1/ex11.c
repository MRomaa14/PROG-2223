#include <stdio.h>

int verificaCond(int* v1, int tam1, int* v2, int tam2){
    if(tam1 != tam2){
        return 0;
    }

    for(int i = 0; i < tam1; i++){
        if(v1[i] != v2[i]){
            return 0;
        }
    }

    return 1;
}


int main(){
    int t1[10] = {25,25,15,20,1,4,6,2, 3};
    int t2[10] = {25,25,15,20,1,4,6,2, 3};

    int res = verificaCond(t1, 10, t2, 10);
    if(res == 1)
        printf("Os dois vetores sao iguais!\n");
    else
        printf("Os dois vetores nao sao iguais!\n");

    return 0;
}