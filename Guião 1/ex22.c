#include <stdio.h>
#include <string.h>

#define N	5


void escreve_sin(char *sin[][2], int tot_lin){
    for(int i = 0; i < tot_lin; i++){
        for(int j = 0; j < 2; j++){
            printf("%s\t", sin[i][j]);
        }
        putchar('\n');
    }
}

char *pesquisa_sinonimo(char *sin[][2], int tot_lin, char *p) {
    for(int i = 0; i < tot_lin; i++){
        for(int j = 0; j < 2; j++){
            if(strcmp(p, sin[i][j]) == 0){
                if(j == 1)
                    return sin[i][j-1];
                else
                    return sin[i][j+1];
            }
        }
    }
    return NULL;
}

char pesquisa_frase(char *s[][2], int tam){
    char pal[50],frase[100];
    char *sinonimo;

    printf("Frase>>");
    gets(frase);

    int i, pos;
    for(i = 0; i < strlen(frase); i++){
        pos = 0;
        while(frase[i] != ' '){
            pal[pos] = frase[i];
            i++;
            pos++;
        }
        pal[pos] = '\0';

        sinonimo = pesquisa_sinonimo(s, N, pal);
        if(sinonimo != NULL)
            printf("Palavra = %s\tSinonimo = %s\n",pal,sinonimo);
    }

    return 0;
}

int conta_duplicado(char *s[][2], int tot_lin){
    int num,res = 0;
    char pal[50];

    for(int i = 0; i < tot_lin; i++){
        for(int j = 0; j < 2; j++){
            num = 0;
            for(int ii = 0; ii < tot_lin; ii++){
                for(int jj = 0; jj < 2; jj++){
                    if(strcmp(s[i][j],s[ii][jj]) == 0)
                        num++;
                }
            }
            if(num > 1)
                res++;
        }
    }
    return res/2;
}

int main()
{
    char palavra[50], *p;
    int num;

    char *s[N][2] = {{"estranho", "bizarro"},
                     {"desconfiar", "suspeitar"},
                     {"vermelho", "encarnado"},
                     {"duvidar", "desconfiar"},
                     {"carro", "automovel"}};

/*
    escreve_sin(s, N);		// alinea 22.1

    printf("Palavra a pesquisar: ");
    scanf(" %s", palavra);

    p = pesquisa_sinonimo(s, N, palavra); // alinea 22.2

    if(p == NULL)
        printf("A palavra %s nao tem sinonimo conhecido\n", palavra);
    else
        printf("A palavra %s e sinonimo de %s\n", p, palavra);


    pesquisa_frase(s, N);
*/
    printf("Existem %d palavras repetidas na tabela\n", conta_duplicado(s, N));

    return 0;
}
