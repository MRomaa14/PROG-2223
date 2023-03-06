#include <stdio.h>
#include <ctype.h>

void verifica(char* tel, char* c){
    *c = 'V';

    if(tel[0] != '2'){
        *c = 'I';
    }

    for(int i = 0; tel[i] != '\0'; i++){
        if(isdigit(tel[i]) != 1){
            *c = 'I';
        }
    }

    if(*c == 'V'){
        printf("The phone number is valid!\n");
    }
    else{
        printf("The phone number is not valid!\n");
    }
}

int main(){
    char result;
    //char numb[10] = {"21c293369"};
    //char numb[10] = {"313293369"};
    char numb[10] = {"213293369"};


    verifica(numb, &result);

    return 0;
}