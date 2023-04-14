// Miguel Umbelino da Mota Roma - a2021138955

#include "paragem.h"
#include "utils.h"

paragem* inicParagem(){
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

    printf("\n\t\t-----NOVA PARAGEM-----\n");

    do{
        existe = 0;
        printf("Nome da paragem:");
        scanf("%s", t.nome);

        for(i = 0; i < n; i++){
            if(strcmp(t.nome, tab[i].nome) == 0){
                printf("Linha com esse nome ja se encontra no sistema!\n\n");
                existe = 1;
            }
        }

    }while(existe == 1);
    gerarCodigo(t.codigo);
    printf("Codigo: %s\n", t.codigo);

    t.numLinhas = 0;

    return t;
}

paragem* regParagem(paragem *tab, int *n){
    paragem *aux = NULL;
    aux = realloc(tab, sizeof(paragem) * (*n+1));

    fflush(stdin);
    system("cls");

    printf("Realloc num %d", *n+1);
    if(aux != NULL){
        tab = aux;


        tab[*n] = obtemInfo(tab, *n);
        (*n)++;
        printf("Paragem registada com sucesso!\n");
    }
    else{
        printf("ERRO na alocacao de memoria!\n");
        return tab;
    }

    return tab;
}

paragem* elimParagem(paragem* tab, int *n){
    paragem t, *aux;
    int i;

    fflush(stdin);
    system("cls");

    char cod[5];
    printf("Codigo da paragem a eliminar:");
    scanf("%s", cod);

    for(i = 0; i < *n && tab[i].codigo != cod; i++);

    if(tab[i].numLinhas == 0){
        if(i == *n){    //Chegou ao fim e nao encontrou nenhuma paragem com esse nome
            printf("Paragem nao existe\n");
        }
        else if(*n == 1){   //So existe 1 paragem no sistema pelo que podemos dar free
            free(tab);
            *n = 0;
            return NULL;
        }
        else{   //Se houver mais que 1 paragem no sistema
            t = tab[i];
            tab[i] = tab[*n-1];
            aux = realloc(tab, sizeof(paragem) * (*n-1));

            if(aux != NULL){
                tab = aux;
                (*n)--;
            }
            else
                tab[i] = t;

            return tab;
        }
    }
    else{
        printf("Esta paragem pertence a %d linhas\n", tab[i].numLinhas);
        printf("Nao pode ser eliminada!!\n");
        return tab;
    }
    return tab;
}

void listaParagens(paragem *tab, int n){
    char ch;
    int i;

    fflush(stdin);
    system("cls");

    printf("EXISTEM %d PARAGENS REGISTADAS NO SISTEMA\n", n);
    for(i = 0; i < n; i++){
        printf("\n\t\t-----PARAGEM %d-----\n", i+1);
        printf("Nome: %s\n", tab[i].nome);
        printf("Codigo: %s\n", tab[i].codigo);
        printf("Pertence a %d linhas\n", tab[i].numLinhas);
    }
    printf("\n-> ENTER para voltar ao menu anterior");

    do{
        ch = getchar();
        fflush(stdin);
    }while( ch != '\n');
}


/*
printf("\n-> Deseja adicionar outra paragem (Y|N)? ");

do{
    scanf("%c", &ch);
    fflush(stdin);
}while(ch != 'Y' && ch != 'y' && ch != 'N' && ch != 'n');
 */