#include <stdio.h>
#include <string.h>

int countWords(char str[]){
    int words = 0;

    int len = strlen(str);

    for(int i = 0; i <= len && str[i] != '\0'; i++){
        if(str[i] != ' '){
            while(str[i] != ' '){
                printf("%c", str[i]);
                i++;
            }
            putchar('\n');
            words++;
        }
    }

    return words;
}


int main()
{
    char string[50] = {"This   is   a  niceeeee    random string  "};

    int numWords = countWords(string);
    printf("There are %d words in the string!\n", numWords);
    return 0;
}
