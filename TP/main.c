// Miguel Umbelino da Mota Roma - a2021138955

#include "paragem.h"
#include "linha.h"
#include "menus.h"

int main(){
    paragem *sistema = NULL; //adicionar paragens no array dinamico
    linha *linhas = NULL; //adicionar linhas na lista ligada
    FILE* dados; //adicionar linha pelo ficheiro de texto

    int total = 0;
    int opt_inic, opt_perc, opt_lin, opt_parag;

    sistema = inicParagem();

    do{
        opt_inic = menuInicial();
        switch (opt_inic) {
            case 1:
                do{
                    opt_perc = menuPercurso();
                    switch (opt_perc) {
                        case 1:
                            addParagem(linhas);
                            break;
                        case 2:
                            break;
                        case 3:
                            listaLinhas(linhas);
                            break;
                        case 4:
                            break;
                        default:
                            printf("Opcao invalida!\n");
                            break;
                    }
                }while(opt_perc != 4);
                break;
            case 2:
                do{
                    opt_lin = menuLinhas();
                    switch(opt_lin){
                        case 1:
                            addParagem(linhas);
                            break;
                        case 2:
                            elimParagem(sistema, &total);
                            break;
                        case 3:
                            listaLinhas(linhas);
                            break;
                        case 4:
                            break;
                        default:
                            printf("Opcao invalida!\n");
                            break;
                    }
                }while(opt_lin != 4);
                break;
            case 3:
                do{
                    opt_parag = menuParagens();
                    switch(opt_parag){
                        case 1:
                            sistema = regParagem(sistema, &total);
                            break;
                        case 2:
                            sistema = elimParagem(sistema, &total);
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
                }while(opt_parag != 4);
                break;
            case 4:
                break;
            default:
                printf("Opcao invalida!\n");
                break;
        }
    }while(opt_inic != 4);

    free(sistema);
    return 0;
}