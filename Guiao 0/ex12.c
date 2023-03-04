#include <stdio.h>
#include <string.h>

void eachLine(char str[]){
    int len = strlen(str) - 1;
    
    printf("After separation:\n");
    for(int i = 0; i <= len; i++){
        if(str[i] == ' '){
            i++;
        }
        else{
            while(str[i] != ' ' && str[i] != '\0'){
                printf("%c", str[i]);
                i++;
            }
            putchar('\n');
        }
    }
}


int main(){
    char string[] = {"    Today     is     Sunday!"};
    
    printf("Original string: %s\n", string);
    eachLine(string);
    
    return 0;
}