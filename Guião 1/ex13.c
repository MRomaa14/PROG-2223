#include <stdio.h>

double produto_escalar (double *a, double *b, int n){
    double prod = 0.00;
    for(int i = 0; i < n; i++){
        prod += a[i]*b[i];
    }

    printf("Produto escalar = %.2lf", prod);
}

int main(){
    double v1[5] = {1, 2,3 ,4,5};
    double v2[5] = {6, 7, 8, 9, 10};

    produto_escalar(v1, v2, 5);

    return 0;
}