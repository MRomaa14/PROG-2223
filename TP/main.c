// Miguel Umbelino da Mota Roma - a2021138955

#include "menus.h"
#include "ficheiros.h"
#include "paragem.h"
#include "linha.h"
#include "utils.h"

int main(){
    pparagem sistema = NULL; //adicionar paragens no array dinamico
    plinha linhas = NULL; //adicionar linhas na lista ligada
    FILE* dados; //adicionar linha pelo ficheiro de texto

    int total = 0;
    int opt_inic, opt_perc, opt_lin, opt_parag;

    sistema = recuperaParagens(&total);
    linhas = recuperaLinhas();

    do{
        opt_inic = menuInicial();
        switch (opt_inic) {
            case 1:
                do{
                    opt_perc = menuPercurso();
                    switch (opt_perc) {
                        case 1:
                            //criarLinha(linhas);
                            break;
                        case 2:
                            //linhamultipla();
                            break;
                        default:
                            printf("Opcao invalida!\n");
                            break;
                    }
                }while(opt_perc != 3);
                break;
            case 2:
                do{
                    opt_lin = menuLinhas();
                    switch(opt_lin){
                        case 1:
                            linhas = regLinha(linhas, sistema, total);
                            break;
                        case 2:
                            addParagemLinha(linhas, sistema, total);
                            break;
                        case 3:
                            elimParagemLinha(linhas, sistema, total);
                            break;
                        case 4:
                            listarLinhas(linhas);
                            break;
                        case 5:
                            listarLinhasParagem(linhas);
                            break;
                        default:
                            break;
                    }
                }while(opt_lin != 6);
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
                        default:
                            printf("Nenhuma opcao valida inserida!\n");
                            break;
                    }
                }while(opt_parag != 4);
                break;
            case 4:
                guardaParagens(sistema, total);
                guardaLinhas(linhas);
                break;
            default:
                printf("Opcao invalida!\n");
                break;
        }
    }while(opt_inic != 4);

    free(sistema);
    free(linhas);
    return 0;
}