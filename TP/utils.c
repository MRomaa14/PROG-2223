// Miguel Umbelino da Mota Roma - a2021138955

#include "utils.h"

void gerarCodigo(char* cod){
    const char caracteres[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    const int n_caracteres = sizeof(caracteres) - 1; // -1 para desconsiderar o caractere nulo
    srand(time(NULL));

    for(int i = 0; i < 4; i++){
        cod[i] = caracteres[rand() % n_caracteres];
    }
    cod[4] = '\0';
}


int lerFich(char *nomeF){
    FILE *fp = fopen(nomeF,"r");
    if(fp == NULL) {
        printf("ERRO: nao foi possivel abrir o ficheiro %s\n", nomeF);
        fclose(fp);
        return 1;
    }

    char buffer[MAX];
    while(fgets(buffer, MAX, fp) != NULL)
        printf("%s", buffer);

    fclose(fp);
    return 0;
}




