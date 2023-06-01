// Miguel Umbelino da Mota Roma - a2021138955

#include "paragem.h"

pparagem inicParagem(){
    paragem* aux = NULL;

    aux = malloc(sizeof(paragem));
    if(aux == NULL){
        printf("ERRO na alocacao de memoria da paragem");
        free(aux);
        return NULL;
    }
    return aux;
}

paragem obtemInfo(paragem *tab, int n){
    paragem t;
    int existe, i;

    printf("\n\t\t\t\t\t  --------------------------------------------\n");
    printf("\n\t\t\t\t\t  |          ADICIONAR NOVA PARAGEM          |\n");
    printf("\n\t\t\t\t\t  --------------------------------------------\n");

    do{
        existe = 0;
        printf("Nome da paragem:");
        scanf(" %99[^\n]", t.nome);

        for(i = 0; i < n; i++){
            if(strcmp(t.nome, tab[i].nome) == 0){
                printf("[AVISO] Paragem JA se encontra no sistema!\n\n");
                existe = 1;
            }
        }

    }while(existe == 1);
    gerarCodigo(t.codigo);
    printf("Codigo: %s\n", t.codigo);

    t.numLinhas = 0;

    return t;
}


pparagem regParagem(pparagem tab, int *n){
    char ch;

    do{
        paragem *aux = realloc(tab, sizeof(paragem) * (*n+1));

        fflush(stdin);
        system("cls");

        if(aux != NULL){
            tab = aux;
            tab[*n] = obtemInfo(tab, *n);
            (*n)++;
        }

        printf("\n-> Pretende adicionar outra paragem? (S/N)");
        do{
            ch = getchar();
            fflush(stdin);
        }while(ch != 'S' && ch != 's' && ch != 'N' && ch != 'n');

    }while(ch == 'S' || ch == 's');

    return tab;
}

pparagem elimParagem(pparagem tab, int *n){
    paragem t, *aux;
    int i;
    char ch;

    do{
        fflush(stdin);
        system("cls");

        printf("\n\t\t\t\t\t  --------------------------------------------\n");
        printf("\n\t\t\t\t\t  |             ELIMINAR PARAGEM             |\n");
        printf("\n\t\t\t\t\t  --------------------------------------------\n");

        if(*n == 0){
            printf("-> Nenhuma paragem no sistema, ENTER para voltar");
            do{
                fflush(stdin);
                ch = getchar();
            }while(ch != '\n');
            break;
        }

        char cod[5];
        printf("Codigo da paragem a eliminar:");
        scanf(" %4[^\n]", cod);

        for(i = 0; i < *n && (strcmp(tab[i].codigo,cod) != 0); i++);

        if(i == *n){    //Chegou ao fim e nao encontrou nenhuma paragem com esse nome
            printf("[AVISO] Nenhuma paragem com o codigo [ %s ]!\n", cod);
        }
        else if(tab[i].numLinhas == 0){
            if(*n == 1){   //So existe 1 paragem no sistema pelo que podemos dar free
                printf("[AVISO] Paragem [ %s ] eliminada com sucesso!\n", tab[i].nome);

                free(tab);
                *n = 0;

                printf("\n-> Nenhuma paragem no sistema, ENTER para voltar");
                do{
                    fflush(stdin);
                    ch = getchar();
                }while(ch != '\n');
                return NULL;
            }
            else{   //Se houver mais que 1 paragem no sistema
                printf("\nParagem [ %s ] eliminada com sucesso!\n", tab[i].nome);

                t = tab[i];
                tab[i] = tab[*n-1];
                aux = realloc(tab, sizeof(paragem) * (*n-1));


                if(aux != NULL){
                    tab = aux;
                    (*n)--;
                }
                else{
                    tab[i] = t;
                }
            }
        }
        else if(tab[i].numLinhas != 0){
            printf("Esta paragem pertence a %d linhas\n", tab[i].numLinhas);
            printf("Nao pode ser eliminada!!\n");
        }

        printf("\n-> Eliminar outra paragem? (S/N)");
        do {
            ch = getchar();
            fflush(stdin);
        } while (ch != 'S' && ch != 's' && ch != 'N' && ch != 'n');

    } while (ch == 'S' || ch == 's');

    return tab;
}

void listaParagens(paragem *tab, int n){
    char ch;
    int i;

    fflush(stdin);
    system("cls");

    if(n == 1){
        printf("\n\t\t\t\t\t  --------------------------------------------\n");
        printf("\n\t\t\t\t\t  |   EXISTE 1 PARAGEM REGISTADA NO SISTEMA  |\n");
        printf("\n\t\t\t\t\t  --------------------------------------------\n");
    }
    else{
        printf("\n\t\t\t\t\t  --------------------------------------------\n");
        printf("\n\t\t\t\t\t  | EXISTEM %d PARAGENS REGISTADAS NO SISTEMA |\n", n);
        printf("\n\t\t\t\t\t  --------------------------------------------\n");
    }

    for(i = 0; i < n; i++){
        printf("|------- PARAGEM NUMERO %d ------|\n", i+1);
        printf("\tNome: %s\n", tab[i].nome);
        printf("\tCodigo: %s\n", tab[i].codigo);
        printf("\tPertence a %d linhas\n", tab[i].numLinhas);

        putchar('\n');
    }
    printf("\n-> ENTER para voltar ao menu anterior");

    do{
        ch = getchar();
        fflush(stdin);
    }while( ch != '\n');
}

