#include <stdio.h>

#define M 3
#define N 3

int verificaMat(int nLin, int nCol, int mat1[][nCol], int mat2[][nCol]){
    for(int i = 0; i < nLin; i++){
        for(int j = 0; j < nCol; j++){
            if(mat1[i][j] != mat2[i][j])
                return 0;
        }
    }

    return 1;
}


int main(){
    int t1[M][N] = {{25,25,15},{20,1,4},{6,2, 3}};
    int t2[M][N] = {{25,25,15},{20,1,4},{6,2, 3}};

    int res = verificaMat(M, N, t1, t2);
    if(res == 1)
        printf("As duas matrizes sao iguais!\n");
    else
        printf("As duas matrizes NAO sao iguais!\n");

    return 0;
}