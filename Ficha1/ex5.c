#include <stdio.h>

int findNum(int arr[], int n, int val){
    int found = 0;
    
    for(int i = 0; i < n; i++){
        if(val == arr[i]){
            found = 1;
            break;
        }
    }

    return found;
}

int main(){
    int array[] = {1, 2, 5, 8, 9, 10};
    int value;

    int size = sizeof(array)/sizeof(int);
    printf("Numbers in the array: %d\n", size);

    printf("Enter a number to search:");
    scanf("%d", &value);

    if(findNum(array, size, value) == 0){
        printf("The value [%d] is not in the array\n", value);
    }
    else{
        printf("The value [%d] is in the array\n", value);
    }

    return 0;
}
