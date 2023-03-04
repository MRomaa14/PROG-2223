#include <stdio.h>

int findBiggest(int arr[], int n){
    int biggest = arr[0];

    for(int i = 1; i < n; i++){ //No need to verify if the first number of the array is bigger than the biggest variable
        if(arr[i] > biggest){
            printf("I found a new biggest number = [%d]\n", arr[i]);
            biggest = arr[i];
        }
    }

    return biggest;
}

int main(){
    int array[] = {1, 2, 3, 11, 5, 9};

    int size = sizeof(array)/sizeof(int);
    printf("Numbers in the array: %d\n", size);

    int x = findBiggest(array, size);
    printf("The biggest number is = [%d]\n", x);

    return 0;
}
