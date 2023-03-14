#include <stdio.h>
#include <string.h>

void clearSpaces(char str[]){
    char straux[50];
    int len = strlen(str);

    printf("After deleting spaces:");
    /*for(int i = 0; i <= len && str[i] != '\0'; i++){
        if(str[i] != ' '){
            while(str[i] != ' '){
                straux[i] = str[i];
                printf("%c", straux[i]);
                i++;
            }
            putchar(' ');
        }
    }*/

    int j = 1;
    for(int i = 1; i < len && str[i] != '\0'; i++){
        if(str[i] != ' ' || str[i - 1] != ' '){
            str[j] = str[i];
            j++;
        }
    }
    str[j] = '\0';
    printf("%s\n",str);
}

int main(){
    char string[] = {"There      are     some spaces    to  delete  "};
    printf("Original string:%s\n", string);

    clearSpaces(string);
    return 0;
}