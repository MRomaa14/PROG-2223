#include <stdio.h>

#define N 3

void printMat(int a[][3], int lin){
    for(int i = 0; i < lin; i++){
        for(int j = 0; j < 3; j++){
            printf("%d\t", a[i][j]);
        }
        putchar('\n');
    }
    
}

int main()
{
    int mat[N][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    
    printMat(mat, N);

    return 0;
}