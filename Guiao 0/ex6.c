#include <stdio.h>

void calcSum(int tab[], int dim, int val){
    for(int i = 0; i < dim - 2; i++){
        for(int j = i + 1; j < dim - 1; j++){
            for(int k = j + i; k < dim; k++){
                if((tab[i] + tab[j] + tab[k]) == val){
                    printf("%d %d %d\t", tab[i], tab[j], tab[k]);
                }
            }
        }
    }
}

int main(){
    int array[] = {1, -2, 3, 4, -5, 6};

    int size = sizeof(array)/sizeof(int);
    printf("Size of the array: %d\n", size);

    if(size < 3){
        printf("The size of the array is invalid: [%d] is too small\n", size);
        return 1;
    }

    int value;
    printf("Enter a value:");
    scanf("%d", &value);

    calcSum(array, size, value);
    return 0;
}