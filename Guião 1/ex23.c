#include <stdio.h>
#include <string.h>

int alterna(char s1[], char s2[]){
    int tam1 = 0, tam2 = 0;
    for(int i = 0; s1[i] != '\0'; i++){
        tam1++;
    }
    for(int i = 0; s2[i] != '\0'; i++){
        tam2++;
    }

    if(tam1 != tam2){
        printf("As palavras originais nao tem o mesmo tamanho!\n");
        return 1;
    }

    char frase[50];
    int pos = 0;
    for(int i = 0; s1[i] != '\0'; i++){
        frase[pos] = s1[i];
        pos++;
        frase[pos] = s2[i];
        pos++;
    }
    frase[pos] = '\0';
    printf("\nFrase >> %s", frase);

    return 0;
}

int main(){
    char pal1[50];
    char pal2[50];

    printf("\nPalavra 1 >>");
    scanf("%s", pal1);

    printf("\nPalavra 2 >>");
    scanf("%s", pal2);

    alterna(pal1, pal2);

    return 0;
}