#include <stdio.h>

void swap(float* n1, float* n2, float* n3){
    float aux = *n1;

    *n1 = *n3;
    *n3 = *n2;
    *n2 = aux;
}

int main(){
    float num1 = 2.3, num2 = 4.5, num3 = 6.7;

    printf("Before swapping:\n");
    printf("Num1 = [%.2f]\tNum2 = [%.2f]\tNum3 = [%.2f]\n", num1, num2, num3);

    swap(&num1, &num2, &num3);

    printf("After swapping:\n");
    printf("Num1 = [%.2f]\tNum2 = [%.2f]\tNum3 = [%.2f]\n", num1, num2, num3);

    return 0;
}