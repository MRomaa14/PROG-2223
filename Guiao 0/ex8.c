#include <stdio.h>
#include <math.h>

#define N 5

int validateCond(int b[][3], int l, int val){
    if(val > 100 || val < 1){
        printf("This number is not valid!\n");
        return 1;
    }
    
    for(int i = 0; i < l; i++){
        if(b[0][i] == val){
                return 1;
            }
    }

    return 0;
}

void showArr(int c[][3], int l){
    for(int i = 0; i < l; i++){
        for(int j = 0; j < 3; j++){
            printf("%d\t", c[i][j]);
        }
        putchar('\n');
    }
}

void fillMat(int a[][3], int nLines){
    int num;
    
    for(int i = 0; i < nLines; i++){
        for(int j = 0; j < 3; j++){
            if(i == 0){
                do{
                    printf("Insert a number for column [%d]:", j + 1);
                    scanf("%d", &num);
                }while((validateCond(a, nLines, num)) == 1);

                a[i][j] = num; 
            }
            else{
                a[i][j] = pow(a[0][j], i + 1);
            }
        }
    }
    
    printf("---The final multidimensional array---\n");
    showArr(a, nLines);
}

int main(){
    int multiArray[N][3];

    fillMat(multiArray, N);
    return 0;
}