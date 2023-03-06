#include <stdio.h>

void swapArr(int *arr, int *n){
    float sum = 0;
    float avg = 0;

    for(int i = 0; i < *n; i++){
        sum += arr[i];
    }

    avg = sum / *n;
    printf("Average = [%.2f]\n", avg);
    
    for(int i = 0; i < *n; i++){
        if(arr[i] < avg){
            arr[i] = 0;
        }
    }

    printf("Final array:\n");
    for(int i = 0; i < *n; i++){
        printf("%d ", arr[i]);
    }

}

int main(){
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    int size = sizeof(arr)/sizeof(int);
    printf("There are [%d] numbers in the array\n", size);

    printf("Initial array:\n");
    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }

    swapArr(arr, &size);
    return 0;
}