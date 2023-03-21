#include <stdio.h>

#define N 3

void transp(int nCol, int mat[][nCol]){
    int mataux[nCol][nCol];

    for(int i = 0; i < nCol; i++){
        for(int j = 0; j < nCol; j++){
            mataux[i][j] = mat[i][j];
        }
    }

    for(int i = 0; i < nCol; i++){
        for(int j = 0; j < nCol; j++){
            mat[i][j] = mataux[j][i];
        }
    }
}

void printMat(int nCol, int mat[][nCol]){
    for(int i = 0; i < nCol; i++){
        for(int j = 0; j < nCol; j++){
            printf("%d ", mat[i][j]);
        }
        putchar('\n');
    }
}

int main(){
    int mat[N][N] = {{1,3,5}, {6,3,2,}, {10,45,4}};

    printf("----ANTES DE TRANSPOR-----\n");
    printMat(N, mat);

    transp(N,mat);

    printf("----DEPOIS DE TRANSPOR-----\n");
    printMat(N, mat);
    return 0;
}