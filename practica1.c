#include <stdio.h>
#include <stdlib.h>
#define N 512;
int Mat1[512][512], Mat2[512][512], MatRes[512][512];
int Vect1[512], Vect2[512];

int main()
{
    initMats();
    mulMat(Mat1, Mat2, MatRes);
    imprimirMatriu(MatRes);
}
void initMats()
{
    int i, j;
    srand(8824553);
    for (i = 0; i < 512; i++)
        for (j = 0; j < 512; j++)
        {
            Mat1[i][j] = rand() % 100;
            Mat2[i][j] = rand() % 100;
        }
    for (i = 0; i < 512; i++)
    {
        Vect1[i] = rand() % 100;
        Vect2[i] = rand() % 100;
    }
}

int mulMat(int Mat1[512][512], int Mat2[512][512], int MatRes[512][512])
{
    int i, j, k;
    for (i = 0; i < 512; i++)
    {
        for (j = 0; j < 512; j++)
        {
            MatRes[i][j] = 0;
            for (k = 0; k < 512; k++)
            {
                MatRes[i][j] += Mat1[i][k] * Mat2[k][j];
            }
        }
    }
}

void imprimirMatriu(int MatRes[512][512])
{
    int fila, columna;
    for (fila = 0; fila < 4; fila++)
    {
        for (columna = 0; columna < 4; columna++)
        {
            printf("%d     ", MatRes[fila][columna]);
        }
        printf("\n");
    }
}
