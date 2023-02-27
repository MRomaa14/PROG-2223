#include <stdio.h>
#include <string.h>

void reverse(char str[]){
    int len = strlen(str) - 1;
    
    //printf("Test 1: %c\n", str[strlen(str)]);
    //printf("Test 2: %c\n", str[strlen(str) - 1]);
    
    printf("Reversed string: ");
    for(int i = len; i >= 0; i--){
        printf("%c", str[i]);
    }
}

int main(){
    char string[] = {"Today is Sunday!"};
    
    printf("Original string: %s\n", string);
    reverse(string);
    
    return 0;
}