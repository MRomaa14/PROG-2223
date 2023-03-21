#include <stdio.h>

int unicaMat(int nLin, int nCol, int mat[][nCol]){
    for (int i = 0; i < nLin; i++) {
        for (int j = 0; j < nCol; j++) {
            for (int k = 0; k < nLin; k++) {
                for (int l = 0; l < nCol; l++) {
                    if ((i != k || j != l) && mat[i][j] == mat[k][l]) {
                        return 0;
                    }
                }
            }
        }
    }
    return 1;
}


int main(){
    int mat[3][2]={{1,2, 3},{4, 5, 6},{7, 8, 9}};

    int x = unicaMat(3, 2, mat);
    if(x == 1)
        printf("Todos os elementos da matriz sao unicos!\n");
    else
        printf("Ha elementos repetidos na matriz!\n");

    return 0;
}