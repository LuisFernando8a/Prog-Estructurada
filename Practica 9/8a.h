#include <stdio.h>
#include <stdlib.h>
#define A 4

//VALIDAR NUMEROS//
int valid_num(int ri, int rf, char msge[])
{
    char xnum[30];
    int num;
    do
    {
        puts(msge);
        fflush(stdin);
        gets(xnum);
        num = atoi(xnum);
    } while (num < ri || num > rf);
    return num;
}
//ORDENAR VECTOR//
void ordenar(int vect[], int m)
{
    int i, j;
    int temp;
    for (i = 0; i < m - 1; i++)
    {
        for (j = i + 1; j < m; j++)
        {
            if (vect[j] < vect[i])
            {
                temp = vect[i];
                vect[i] = vect[j];
                vect[j] = temp;
            }
        }
    }
}
//BUSCAR NUM DENTRO DEL VECTOR//
int busq_secu(int vect[], int n, int num)
{
    for (int i = 0; i < n; i++)
    {
        if (num == vect[i])
        {
            return i;
        }
    }
    return -1;
}
//EVITAR NUMEROS REPETIDOS EN VECTOR//
int no_repetir(int vect[], int n, int num)
{
    for (int i = 0; i < n; i++)
    {
        if (num == vect[i])
        {
            return 1;
        }
    }
    return 0;
}
//EVITAR NUMEROS REPETIDOS EN MATRIZ//
int no_repMat(int mat[][A], int m, int n,int num)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            
            if (num == mat[i][j])
            {
                return 1;
            }
        }
    }
    return 0;
}