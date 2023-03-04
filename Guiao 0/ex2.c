#include <stdio.h>

int findPos(int arr[], int n){
    int biggest = arr[0];
    int pos = 1;

    for(int i = 1; i < n; i++){ //No need to verify if the first number of the array is bigger than the biggest variable
        if(arr[i] > biggest){
            biggest = arr[i];
            pos = i + 1;
        }
    }
    printf("Biggest number: [%d]\n", biggest);

    return pos;
}

int main(){
    int array[] = {10, 2, 3, 11, 5, 9, 11};

    int size = sizeof(array)/sizeof(int);
    printf("Numbers in the array: %d\n", size);

    int x = findPos(array, size);
    printf("First position: [%d]\n", x);

    return 0;
}
