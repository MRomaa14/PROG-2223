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

int verifyCond(int b[][3], int lin){
    
    int sumL1 = 0, sumL2 = 0, sumL3 = 0;
    for(int i = 0; i < lin; i++){
        for(int j = 0; j < 3; j++){
            if(i == 0){
                sumL1 += b[i][j];
            }
            else if(i == 1){
                sumL2 += b[i][j];
            }
            else if(i == 2){
                sumL3 += b[i][j];
            }
        }
    }
    
    int sumC1 = 0, sumC2 = 0, sumC3 = 0;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < lin; j++){
            if(i == 0){
                sumC1 += b[i][j];
            }
            else if(i == 1){
                sumC2 += b[i][j];
            }
            else if(i == 2){
                sumC3 += b[i][j];
            }
        }
    }
    
    int sumD1 = 0, sumD2 = 0;
    for(int i = 0, j = 0; i < lin; i++, j++){
        //printf("%d\t", b[i][j]);
        sumD1 += b[i][j];
    }

    for(int i = 0, j = 2; i < lin; i++, j--){
        //printf("%d\t", b[i][j]);
        sumD2 += b[i][j];
    }
    
    putchar('\n');
    printf("sumL1:%d\t sumL2: %d\t sumL3: %d\n", sumL1, sumL2, sumL3);
    printf("sumC1:%d\t sumC2: %d\t sumC3: %d\n", sumC1, sumC2, sumC3);
    printf("sumD1:%d\t sumD2: %d\n", sumD1, sumD2);
    
    putchar('\n');
    if(sumL1 == sumL2 && sumL2 == sumL3 && sumL3 == sumC1 && sumC1 == sumC2 && sumC2 == sumC3 && sumC3 == sumD1 && sumD1 == sumD2){
        //printf("Correct!\n");
        return 0;
    }
    else{
        //printf("Wrong!\n");
        return 1;
    }
       
}

int main()
{
    int mat[N][3] = {{6, 1, 8}, {7, 5, 3}, {2, 9, 4}};
    
    printMat(mat, N);
    
    if(verifyCond(mat, N) == 0){
        printf("We have a magical square!\n");        
    }
    else{
        printf("This is not a magical square!\n");
    }
    
    return 0;
}