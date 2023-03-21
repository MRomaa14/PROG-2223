#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
    char s[10][50];

    if(argc < 1){
        printf("Numero de argumentos invalido\n");
        return 1;
    }
    else if(argc > 20 || (argc % 2) == 1){
        printf("Nao cumpre os requisitos\n");
        return 2;
    }

    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 50; j++){
        }
    }

    return 0;
}