#include <stdio.h>

#define M 5
#define N 6

void procura(int nLin, int nCol, char mat[][nCol], char* pal){
    int pos = 0;
    int lInic, cInic;

    for(int i = 0; i < nLin; i++){
        for(int j = 0; j < nCol; j++){
            if(pal[pos] == mat[i][j]){
                while(pal[pos] != '\0'){
                    pos++;
                    if(pal[pos])
                }
            }
        }
    }
}

int main(){
    char ret[M][N] = {{'e', 'b', 'a', 'u', 'l', 'q'},
                      {'l', 'e', 'r', 'r', 's', 's'},
                      {'u', 'w', 'u', 'q', 'g', 'r'},
                      {'a', 'a', 'l', 'l', 'u', 'a'},
                      {'p', 'm', 'h', 'u', 'd', 'j'}};
    char palavra[20];

    printf("Palavra a procurar:");
    scanf("%s", palavra);

    procura(M, N, ret, palavra);
}