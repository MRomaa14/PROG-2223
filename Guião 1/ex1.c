#include <stdio.h>

int main(){
    int a, b, total; 
    int *p = &a, *q = &b, *r = &total;

    printf("Number 1:");
    scanf("%d", p);

    printf("Number 2:");
    scanf("%d", q);

    *r = *p + *q;

    printf("a= %d \t b= %d \t total= %d\n", a, b, total);
    return 0;
}