//Ochoa Angulo Luis Fernando 372746
//03-10-23    10-10-23
//Algoritmo con un menu para vectores y generar una matriz
//LFOA_Act9_01_432

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "8a.h"
#define M 15
#define A 4

int llena_mat(int mat[][A], int m, int n, int ri, int rf);
int llenar_vect(int vect[], int m, int ri, int rf);

void mostrar_mat(int mat[][A], int m, int n);
void mostrar_vect(int vect[], int m);

void menu();
int main()
{
    menu();
}
void menu()
{
    int resp = 1;
    int opc;
    do
    {
        printf("-------------- M E N U -----------------\n");
        printf("1.-) Llenar vector aleatorio sin repetir\n");
        printf("2.-) Llenar matriz aleatorio sin repetir\n");
        printf("3.-) Mostrar vector llenado aleatoriamente\n");
        printf("4.-) Mostrar matriz llenado aleatoriamente\n");
        printf("5.-) Ordenar el vector\n");
        printf("6.-) Buscar un valor en el vector\n");
        printf("0.-) Salir\n");
        opc = valid_num(1,6,"Ingrese la opcion a realizar:");
        switch (opc)
        {
            int vect[M];
            int mat[A][A];
            int num;
        case 1:
            llenar_vect(vect, M, 100, 200);
            break;
        case 2:
            llena_mat(mat, A, A, 1, 16);
            break;
        case 3:
            mostrar_vect(vect, M);
            break;
        case 4:
            mostrar_mat(mat, A, A);
            break;
        case 5:
            ordenar(vect, M);
            break;
        case 6:
            printf("Que numero buscabas? ");
            scanf("%d",&num);
            busq_secu(vect, M, num);
            break;
        default:
            break;
        }
        printf("1.- Continuar\n");
        printf("0.- Para salir\n");
        resp = valid_num(0,1,"Deseas continuar? \n");
    } while (resp == 1);
}
//LLENADO ALEATORIO DEL VECTOR//
int llenar_vect(int vect[], int m, int ri, int rf)
{
    int numero, rango;
    rango = (rf - ri) + 1;
    srand(time(NULL));
    for (int i = 0; i < m; i++)
    {
        do
        {
            numero = (rand() % rango) + ri;

        } while (no_repetir(vect, m, numero) == 1);
        vect[i] = numero;
    }
    return vect[M];
}
//LLENADO ALEATORIO DE LA MATRIZ//
int llena_mat(int mat[][4], int m, int n, int ri, int rf)
{
    int numero, rango;
    srand(time(NULL));
    rango = (rf - ri) + 1;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            do
            {
                numero = (rand() % rango) + ri;
                
            } while (no_repMat(mat,m,n,numero) == 1);
            mat[i][j] = numero;
        }
    }
    return mat[4][4];
}
//MOSTRAR EL VECTOR LLENADO//
void mostrar_vect(int vect[], int m)
{
    for (int i = 0; i < m; i++)
    {
        printf("[");
        printf("%d", vect[i]);
        printf("]\n");
    }
}
//MOSTRAR MATRIZ LLENADA//
void mostrar_mat(int mat[][A], int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("[");
            printf("%d", mat[i][j]);
            printf("]");
        }
        printf("\n");
    }
}