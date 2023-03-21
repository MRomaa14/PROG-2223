#include <stdio.h>
#include <stdlib.h>

void media(int v[], int n){
    int soma = 0;
    float media = 0;

    for(int i = 0; i < n; i++){
        soma += v[i];
    }

    media = soma/n;
    printf("Media = %.2f", media);
}

int main(int argc, char* argv[]){
    int arr[20];
    int tam = 0;

    if(argc < 1){
        printf("Numero de argumentos invalido\n");
        return 1;
    }

    for(int i = 1; i < argc; i++){
        arr[tam] = atoi(argv[i]);
        tam++;
    }

    printf("Array de inteiros:");
    for(int i = 0; i < tam; i++){
        printf("%d ", arr[i]);
    }
    putchar('\n');

    media(arr, tam);
    return 0;
}