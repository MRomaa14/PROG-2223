#include <stdio.h>

void mediaCol(int nLin, int nCol, float a[][nCol], int* min, int* max){
    float maiorVal = 0, menorVal = 0;

    for(int i = 0; i < nCol; i++){
        float val = 0;
        for(int j = 0; j < nLin; j++){
            val += a[j][i];
            printf("Val = %.1f\n", val);
        }
        float media = 0;
        media = val / (float)nLin;
        printf("Coluna %d = %.2f\n", i, media);

        if(media > maiorVal){
            maiorVal = media;
            *max = i;
        }
        else if(media < *min){
            menorVal = media;
            *min = i;
        }
    }
}

void escreveMat(int nLin, int nCol, float a[][nCol]){
    for(int i = 0; i < nLin; i++){
        for(int j = 0; j < nCol; j++){
            printf("%.1f\t", a[i][j]);
        }
        putchar('\n');
    }
}

int main(int argc, char** argv) {
    float m1[3][2] = {{1.0, 4.5},{-2.5, 8.9},{0.3, 1.4}};
    float m2[2][6] = {{1.0, 1.6, 4.2, 1.4, 0.5, -3.4},{2.5, 8.1, 0.9, -0.1, 0.8, 3.5}};
    int min1=0, max1=0, min2=0, max2=0;

    escreveMat(2, 6, m2);

    mediaCol(2, 6, m2, &min2, &max2);
    //mediaCol(3, 2, m1, &min1, &max1);

    printf("Matriz m2: (%d, %d)\n", min2, max2);
    return 0;
}
