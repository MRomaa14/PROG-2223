// Miguel Umbelino da Mota Roma - a2021138955

#include "paragem.h"
#include "linha.h"
#include "menus.h"

int main(){
    paragem *sistema = NULL; //adicionar paragens no array dinamico

    sistema = malloc(sizeof(paragem));
    if(sistema == NULL){
        printf("Erro na alocacao de memoria\n");
        return 1;
    }

    int total = 0;
    for(int i = 0; i < 3; i++){
        regParagem(sistema, &total);
    }
    listaParagens(sistema, total);

    elimParagem(sistema, &total);
    listaParagens(sistema, total);
    /*
    linha *paragens = NULL; //adicionar linhas na lista ligada
    FILE* dados; //adicionar linha pelo ficheiro de texto

    int total = 0;
    int opt = 0;
    int num;

    while(1){
        opt = menuInicial();
        switch (opt) {
            case 1:
                break;
            case 2:
                while(1){
                    opt = menuLinhas();
                    switch(opt){
                        case 1:
                            addParagem(paragens, &total);
                            break;
                        case 2:
                            elimParagem(sistema, &total);
                            break;
                        case 3:
                            listaParagens(sistema, total);
                            break;
                        case 4:
                            break;
                        default:
                            printf("Opcao invalida!\n");
                            break;
                    }
                    if(opt == 4)
                        break;
                }
                break;
            case 3:
                while(1){
                    opt = menuParagens();
                    switch(opt){
                        case 1:
                            regParagem(sistema, &total);
                            break;
                        case 2:
                            elimParagem(sistema, &total);
                            break;
                        case 3:
                            listaParagens(sistema, total);
                            break;
                        case 4:
                            break;
                        default:
                            printf("Opcao invalida!\n");
                            break;
                    }
                    if(opt == 4)
                        break;
                }
                break;
            case 4:
                break;
            default:
                printf("Ainda nao sei o que meter aqui acho que vou trocar por if's");
                break;
        }
    }
*/
    free(sistema);
    return 0;

}