#include <stdio.h>
#include <stdlib.h>
#define N 512
int Mat1[N][N], Mat2[N][N], MatRes[N][N], tempM1M2[N][N], tempTransM1M2[N][N];
int Vect1[N], Vect2[N], tempV1V2[N], tempC[N];

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

int main()
{
    int mat1Perm, mat2Perm, i, j;
    initMats();
    mulMat(Mat1, Mat2, tempM1M2);
    /*Mostrar per pantalla tempM1M2[10][10-19]*/
    printf("tempM1M2: ");
    for (i = 10; i <= 19; i++)
    {
        printf("%d     ", tempM1M2[10][i]);
    }
    printf("\ntempV1V2: ");
    Saxpy(4, Vect1, Vect2, tempV1V2);
    /*Mostrar per pantalla tempV1V2[100-119]*/
    for (i = 100; i <= 119; i++)
    {
        printf("%d     ", tempV1V2[i]);
    }
    transMat(tempM1M2, tempTransM1M2);
    /*Mostrar per pantalla tempTransM1M2[10-19][10]*/
    printf("tempTransM1M2: ");
    for (i = 10; i <= 19; i++)
    {
        printf("%d     ", tempM1M2[i][10]);
    }
    mat1Perm = PermutaF(Mat1, 5, 10);
    mat2Perm = PermutaF(Mat2, 100, 512);
    if (mat1Perm = 1)
    {
        printf("\nS'ha pogut permutar les files a Mat1\n");
    }
    else
    {
        printf("No s'ha pogut permutar les files a Mat1\n");
    }
    if (mat2Perm = 1)
    {
        printf("S'ha pogut permutar les files a Mat2\n");
    }
    else
    {
        printf("No s'ha pogut permutar les files a Mat2\n");
    }
    printf("Suma diagonal de tempTransM1M2: %d\n", sumDiagonal(tempTransM1M2));
    sumElement(tempTransM1M2, tempC);
    /*Mostrar per pantalla tempC[100-419]*/
    printf("tempC: ");
    for (i = 100; i <= 419; i++)
    {
        printf("%d     ", tempC[i]);
    }
}