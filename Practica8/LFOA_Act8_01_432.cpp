//Ochoa Angulo Luis Fernando 372746
//27-09-23    03-10-23
//Algoritmo con un menu para vectores y generar una matriz
//LFOA_Act8_01_432

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <time.h>
#define M 10

//FUNCIONES//
void menu();
void llenar_vect1(int vect1[], int m);
void llenar_vect2(int vect2[], int m, int ri, int rf);
void llen_vectores(int vect1[], int vect2[], int vect3[], int m);
void imp_vectores(int vect1[], int vect2[], int vect3[], int m);
void llen_matriz(int vect1[], int vect2[], int matriz[4][4]);
void imp_matriz(int matriz[4][4]);
//FUNCIONES EXTRAS//
int val_num(int ri, int rf);
bool no_repetir(int vect2[], int n);

int main()
{
    menu();
}
//MENU//
void menu()
{
    int opc,vect1[M],vect2[M],vect3[M*2],m,matriz[4][4];
    do{
        printf("\n--------------- MENU --------------");
        printf("\n1.- LLENAR VECTOR 1 (MANUALMENTE)");
        printf("\n2.- LLENAR VECTOR 2 ALEATORIAMENTE");
        printf("\n3.- LLENAR VECTOR 3 (CON VECTOR1 Y VECTOR2)");
        printf("\n4.- IMPRIMIR VECTORES");
        printf("\n5.- LLENAR MATRIZ 4 X 4");
        printf("\n6.- IMPRIMIR MATRIZ");
        printf("\n0.- SALIR");
        printf("\nIngresa el numero: ");
        scanf("%d", &opc);
        switch(opc)
        {
            case 1:
                llenar_vect1(vect1,M);
                break;

            case 2:
                llenar_vect2(vect2,M,1,10);
                break;

            case 3:
                llen_vectores(vect1,vect2,vect3,M);
                break;

            case 4:
                imp_vectores(vect1,vect2,vect3,M);
                break;
                
            case 5:
                llen_matriz(vect1,vect2,matriz);
                break;
            
            case 6:
                imp_matriz(matriz);
                break;

            case 0:
                break;

            default:
                break;
        }
    }while(opc != 0);
}
//EVITAR NUMEROS REPETIDOS EN VECTOR 2//
bool no_repetir(int vect2[],int n)
{
    int i;
    for (i = 0; i <10; i++)
    {
        if (n == vect2[i])
        {
            return true;
        }            
    }
    return false;
}
//VALIDAR NUMEROS//
int val_num(int ri, int rf)
{
    int n;
    char num[30];
    printf("\nIngresa un numero entre el %d y %d: ", ri, rf);
    scanf("%c", &num);
    fflush(stdin);
    gets(num);
    n = atoi(num);
    if (n > rf)
    {
        printf("\nNumero muy alto del rango");
        n = 70;
    }
    
    if (n < ri)
    {
        printf("\nNumero muy bajo del rango");
        n = 30;
    }
    return n;
}
//LLENAR VECTOR 1 MANUALMENTE//
void llenar_vect1(int vect1[], int m)
{
    int i;
    for(i = 0; i < m; i++)
    {
        vect1[i] = val_num(30, 70);
        printf("\nPRESIONA ENTER PRIMERO y despues digita el numero");

    }
}
//LLENAR VECTOR 2 ALEATORIAMENTE//
void llenar_vect2(int vect2[], int m, int ri, int rf)
{
    int rango, i, n;
    rango = (rf - ri) + 1;
    srand(time(NULL)); 
    for(i = 0; i < m; i++)
    {
        do
        {
            n = (rand()%rango) + ri;
        } while (no_repetir(vect2, n));
        vect2[i] = n;  
    }
}
//LLENAR EL VECTOR 3 CON EL VECTOR 1 Y 2//
void llen_vectores(int vect1[], int vect2[], int vect3[], int m)
{
    int i;
    for(i = 0; i < m; i++)
    {
        vect3[i] = vect1[i];
    }

    for(i = 0; i < m; i++)
    {
        vect3[i+10] = vect2[i];
    }
}
//IMPRIMIR LOS 3 VECTORES//
void imp_vectores(int vect1[], int vect2[], int vect3[], int m)
{
    int i;
    printf("\nVECTOR 1");
    printf("\n[");
    for (i = 0; i < m; i++)
    {
        printf("%d, ", vect1[i]);
    }
    printf("]");
    printf("\n");

    printf("\nVECTOR 2");
    printf("\n[");
    for (i = 0; i < m; i++)
    {
        printf("%d, ", vect2[i]);
    }
    printf("]");
    printf("\n");

    printf("\nVECTOR 3");
    printf("\n[");
    for (i = 0; i < m*2; i++)
    {
        printf("%d, ", vect3[i]);
    }
    printf("]");
    printf("\n");
}
//LLENAR UNA MATRIZ// 
void llen_matriz(int vect1[], int vect2[], int matriz[4][4])
{
    int j, i, k;
    k = 0;
    for (j = 0; j < 2; j++)
    {
        for (i = 0; i < 4; i++)
        {
            matriz[j][i] = vect1[k];
            k = k + 1;
        }
    }
    matriz[2][0] = vect1[8];
    matriz[2][1] = vect1[9];
    matriz[2][2] = vect2[0];
    matriz[2][3] = vect2[1];

    for (i = 0; i < 4; i++)
    {
        matriz[3][i] = vect2[i+2];
    }

}
//IMPRIMIR MATRIZ//
void imp_matriz(int matriz[4][4])
{
    int j, i;
    printf("\n");
    for (j = 0; j < 4; j++)
    {
        printf("\n[");
        for(i = 0; i < 4; i++)
        {
            printf("%d, ", matriz[j][i]);
        }
        printf("]");
    }
    printf("\n");
}