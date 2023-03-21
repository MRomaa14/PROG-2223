#include <stdio.h>

#define M 3
#define N 3

void somaMat(int nLin, int nCol, int m1[][nCol], int m2[][nCol]){
    for(int i = 0; i < nLin; i++){
        for(int j = 0; j < nCol; j++){
            m1[i][j] += m2[i][j];
        }
    }
}

void printMat(int nLin, int nCol, int matA[][nCol]){
    printf("----DEPOIS DE SOMAR-----\n");
    for(int i = 0; i < nLin; i++){
        for(int j = 0; j < nCol; j++){
            printf("%d ", matA[i][j]);
        }
        putchar('\n');
    }
}

int main(){
    int matA[M][N] = {{1,2,3},{7,8,9},{13,14,15}};
    int matB[M][N] = {{4,5,6},{10,11,12},{16,17,18}};

    somaMat(M, N, matA, matB);
    printMat(M, N, matA);
    return 0;
}
