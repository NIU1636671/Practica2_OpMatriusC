#include <stdio.h>
#include <stdlib.h>
#define N 3
int Mat1[N][N], Mat2[N][N], MatRes[N][N], tempM1M2[N][N];
int Vect1[N], Vect2[N];

/*Inicialitzar matrius*/
void initMats()
{
    int i, j;
    srand(8824553);
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
        {
            Mat1[i][j] = rand() % 100;
            Mat2[i][j] = rand() % 100;
        }
    for (i = 0; i < N; i++)
    {
        Vect1[i] = rand() % 100;
        Vect2[i] = rand() % 100;
    }
}
/*Exercici 1*/
int mulMat(int Mat1[N][N], int Mat2[N][N], int MatRes[N][N])
{
    int i, j, k;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            MatRes[i][j] = 0;
            for (k = 0; k < N; k++)
            {
                MatRes[i][j] += Mat1[i][k] * Mat2[k][j];
            }
        }
    }
}
/*Exercici 2*/
void Saxpy(int k, int Vect1[N], int Vect2[N], int VectRes[N])
{
    for (int i = 0; i < N; ++i)
        VectRes[i] = k * Vect1[i] + Vect2[i];
}
/*Exercici 3*/
void transMat(int Matriu[N][N], int Transposada[N][N])
{
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
        {
            Transposada[j][i] = Matriu[i][j];
        }
}
/*Exercici 4*/

int sumDiagonal(int Matriu[N][N])
{
    int sumaDiag = 0;
    int i;
    for (i = 0; i < N; i++)
        sumaDiag = sumaDiag + Matriu[i][i];
    return sumaDiag;
}

/*Exercici 5*/
int sumElement(int Matriu[N][N], int Sumes[N])
{
    int i, j;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            Sumes[i] += Matriu[j][i];
        }
    }
    return Sumes;
}
/*Exercici 6*/
int PermutaF(int Matriu[N][N], int fila1, int fila2)
{
    int temp, i;
    if (fila1 > N || fila2 > N)
    {
        return 0;
    }
    for (i = 0; i < N; i++)
    {
        temp = Matriu[fila1 - 1][i];
        Matriu[fila1 - 1][i] = Matriu[fila2 - 1][i];
        Matriu[fila2 - 1][i] = temp;
    }
    return 1;
}

/*Imprimir matrius i vectors*/
void imprimirMatriu(int MatRes[N][N])
{
    int fila, columna;
    for (fila = 0; fila < N; fila++)
    {
        for (columna = 0; columna < N; columna++)
        {
            printf("%d     ", MatRes[fila][columna]);
        }
        printf("\n");
    }
}
void imprimirVector(int vector[N])
{
    int i;
    for (i = 0; i < N; i++)
    {
        printf("%d     ", vector[i]);
    }
}

int main()
{
    initMats();
}