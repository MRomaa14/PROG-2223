#include <stdio.h>

int findMostCommon(int arr[], int n){
    int common = arr[0];
    int finalCount = 0;

    for(int i = 0; i < n; i++){
        int countAux = 0;

        for(int j = i + 1; j < n; j++){
            if(arr[i] == arr[j]){
                countAux++;
            }
        }

        if(countAux > finalCount){
            finalCount = countAux;
            common = arr[i];
        }
        else if(countAux == finalCount){
            if(arr[i] > common){
                common = arr[i];
            }
        }
    }

    return common;
}

int main(){
    int array[] = {1, 2, 5, 11, 5, 10, 12};

    int size = sizeof(array)/sizeof(int);
    printf("Numbers in the array: %d\n", size);

    int x = findMostCommon(array, size);
    printf("The most common number is [%d]\n", x);

    return 0;
}
