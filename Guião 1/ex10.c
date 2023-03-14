#include <stdio.h>
#include <string.h>
int tres_consecutivos(char *frase){
    char aux[20];
    int j = 0;

    for(int i = 0; frase[i] != '\0'; i++, j++){
        if(frase[i] == ' ')
            i++;
        aux[j] = frase[i];
    }
    aux[j] = '\0';


    printf("%s\n", aux);
    for(int i = 0; aux[i+2] != '\0'; i++){
        if(aux[i] == aux[i+1] && aux[i+1] == aux[i+2]){
            //printf("%c = %c = %c\n", aux[i], aux[i+1], aux[i+2]);
            return 1;
        }
    }

    return 0;
}

int main(){
    char frase[20] = {"Olaa adoro chuva"};
    //char frase[20] = {"Ola adoro chuva"};

    int res = tres_consecutivos(frase);
    if(res == 1)
        printf("Existem 3 caracteres consecutivos iguais!\n");
    else
        printf("Nao existem 3 caracteres consecutivos iguais!\n");

    return 0;
}