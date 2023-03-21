#include <stdio.h>
#include <string.h>

void tradutor(char st[]){
    char *pt[] = {"Janeiro", "Fevreiro", "Marco", "Abril", "Maio", "Junho", "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"};
    char *ing[] = {"January", "February", "March", "April", "June", "July", "August", "September", "October", "November", "December"};

    for(int i = 0; i < 12; i++){
        if(strcmp(st, pt[i]) == 0){
            printf("%s - %s\n", st, ing[i]);
            return;
        }
    }
    printf("O mes %s nao existe\n", st);
}


int main(){
    char str[20];

    printf("Mes >>");
    scanf("%s", str);

    tradutor(str);

    return 0;
}