#include <stdio.h>
const int N = 512;
int Mat1[N][N], Mat2[N][N];
int Vect1[N], Vect2[N];

void main()
{
    initMats();
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

int mulMat(int Mat1, int Mat2, int MatRes)
{
}
