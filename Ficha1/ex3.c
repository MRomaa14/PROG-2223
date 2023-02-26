#include <stdio.h>

int findTimes(int arr[], int n){
    int biggest = arr[0];
    int times = 1;

    for(int i = 1; i < n; i++){ //No need to verify if the first number of the array is bigger than the biggest variable
        if(arr[i] > biggest){
            biggest = arr[i];
            times = 1;
        }
        else if(arr[i] == biggest){
            times++;
        }
    }
    printf("Biggest number: [%d]\n", biggest);

    return times;
}

int main(){
    int array[] = {10, 2, 3, 11, 5, 9, 11};

    int size = sizeof(array)/sizeof(int);
    printf("Numbers in the array: %d\n", size);

    int x = findTimes(array, size);
    printf("The biggest number appears [%d] time(s) in the array\n", x);

    return 0;
}
