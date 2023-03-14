#include <stdio.h>
#include <string.h>
#include <ctype.h>

int verifyCond(char str[]){
    /*Works for strings without spaces
    int len = strlen(str);

    for(int i = len - 1, j = 0; i >= 0; i--, j++){
        //printf("str[%d]: %c\t str[%d]: %c\n", i, str[i], j, str[j]);
        if(tolower(str[i]) != tolower(str[j])){
            return 0;
        }

    }
    return 1;
    */

    char straux[20];
    int j = 0;
    for(int i = 0; str[i] != '\0'; i++, j++){
        if(str[i] == ' '){
            while(str[i] == ' ')
                i++;
        }
        straux[j] = tolower(str[i]);
    }
    straux[j] = '\0';
    printf("%s\n", straux);

    for(int i = 0, k = j - 1; straux[i] != '\0'; i++, k--){
        if(straux[i] != straux[k])
            return 1;
    }

    return 0;
}

int main(){
    //char string[20] = {"Romametemamor"};
    char string[30] = {"Roma   me tem amor"};

    int flag = verifyCond(string);
    if(flag == 0){
        printf("The string has a 'capicua' stored!\n");
    }
    else{
        printf("The string doesn't have a 'capicua' stored!\n");
    }

    return 0;
}