//Ochoa Angulo Luis Fernando 372746
//11-10-23    17-10-23
//Algoritmo con un menu para registros
//LFOA_Act10_01_432

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "8a.h"

#define N 500

typedef struct _alum
{
    int status;
    int matri;
    char nombre[30];
    char appater[30];
    char apmater[30];
    int sexo;
    int edad;
} Talum;

Talum gen_reg_man();
Talum gen_rega_alea();
Talum eliminar_regs(Talum vect[], int *n);
void imp_registros(Talum vect[], int n);
void ordenar_reg(Talum vect[], int n);
void buscar_reg(Talum vect[], int n);
void menu();

int main()
{
    menu();
    return 0;
}
void menu()
{
    int x = 0;
    int i = 0, opc;
    Talum vect[500];
    do
    {
        printf("------------- M E N U -------------\n");
        printf("1.- AGREGAR (AUTOM 10 REGISTROS)\n");
        printf("2.- AGREGAR MANUAL\n");
        printf("3.- ELIMINAR REGISTRO (lógico)\n");
        printf("4.- BUSCAR\n");
        printf("5.- ORDENAR\n");
        printf("6.- IMPRIMIR\n");
        printf("0.- SALIR\n ");
        opc = valid_num(0, 6, "Elije la opcion: ");
        int j = i + 10;
        switch (opc)
        {
        case 0:
            opc = 0;
        case 1:
            for (i; i < j; i++)
            {
                vect[i] = gen_rega_alea();
            }
            printf("%d", i);
            break;
        case 3:
            eliminar_regs(vect, &i);
            break;
        case 2:
            vect[i] = gen_reg_man();
            i++;
            break;
        case 4:
            buscar_reg(vect,i);
            break;
        case 5:
            ordenar_reg(vect, i);
            break;
        case 6:
            imp_registros(vect, i);
            break;
        default:
            break;
        }

    } while (opc != 0);
}

Talum gen_reg_man()
{
    Talum regis;
    regis.status = 1;
    regis.matri = valid_num(300000, 399999, "Ingresa tu martirucla");
    printf("Ingresa tu nombre: ");
    fflush(stdin);
    gets(regis.nombre);
    printf("Ingresa tu apellido parterno: ");
    fflush(stdin);
    gets(regis.appater);
    printf("Ingresa tu apellido materno: ");
    fflush(stdin);
    gets(regis.apmater);
    printf("Presiona: \n");
    printf("1.- Hombre \n");
    printf("2.- Mujer \n");
    regis.sexo = valid_num(1, 2, "Ingresa tu sexo");
    regis.edad = valid_num(1, 100, "Ingresa tu edad");
    return regis;
}

Talum gen_rega_alea()
{
    Talum regis;

    char *nHombre[10] = {"Yepiz", "Enrique", "Pedro", "Tonysinz", "Daniel", "Miguel", "Alejandro", "José", "Javier", "Antonio"};
    char *nMujer[10] = {"Elizabeth", "Valentina", "Jazmin", "Sofia", "Yaquelin", "Maria", "Dana", "Raquel", "Denisse", "Karen"};
    char *apellidos[20] = {"Flores", "Morales", "Vazquez", "Jimenez", "Reyes", "Diaz", "Torres", "Gutierrez", "Ruiz", "Mendoza",
                        "Gonzalez", "Lopez", "Rodriguez", "Martinez", "Valencia", "Fernandez", "Gomez", "Sanchez", "Ramirez", "Torres"};
    regis.status = 1;
    regis.matri = (rand() % 100000) + 300000;
    int sexo = rand() % 100;
    if (sexo%2 == 1)
    {
        strcpy(regis.nombre, nHombre[rand() % 10]);
        regis.sexo = 1;
    }
    else
    {
        strcpy(regis.nombre, nMujer[rand() % 10]);
        regis.sexo = 2;
    }
    strcpy(regis.appater, apellidos[rand() % 20]);
    strcpy(regis.apmater, apellidos[rand() % 20]);
    regis.edad = (rand() % 88) + 13;
    return regis;
}

Talum eliminar_regs(Talum vect[], int *n)
{
    int matri = valid_num(300000, 399999, "Ingresar matricula del registro que quieres borrar: ");
    int k = 0;
    Talum veck[N];

    for (int i = 0; i < *n; i++)
    {
        if (matri != vect[i].matri)
        {
            veck[k] = vect[i];
            k++;
        }
    }

    if (k == *n)
    {
        printf("La matricula no esta en el registro \n");
        return vect[N];
    }
    else
    {
        printf("Registro con matrícula %d borrado.\n", matri);
        *n = k; 
        for (int i = 0; i < k; i++)
        {
            vect[i] = veck[i];
        }
        return vect[k];
    }
}

void imp_registros(Talum vect[], int n)
{
    printf("*****************************\n");
    printf("|  n°  |  matricula  |    nombre   |  ap.paterno  |   ap.materno   |  sexo  |  edad  |\n");
    printf("*****************************\n");

    for (int i = 0; i < n; i++)
    {
        printf("| %4d | %11d | %12s | %12s | %13s | %5d | %5d |\n", i, vect[i].matri, vect[i].nombre, vect[i].appater, vect[i].apmater, vect[i].sexo, vect[i].edad);
    }
    printf("*****************************\n");
}

void ordenar_reg(Talum vect[], int n)
{
    int i, j;
    Talum temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (vect[j].matri < vect[i].matri)
            {
                temp = vect[i];
                vect[i] = vect[j];
                vect[j] = temp;
            }
        }
    }
}

void buscar_reg(Talum vect[], int n)
{
    int i;
    int matri = valid_num(300000, 399999, "Ingresa la matricula del registro que deseas buscar: ");

    for (i = 0; i < n; i++)
    {
        if (matri == vect[i].matri)
        {
            printf("Se encontro el usuario con matricula %d en el registro.\n", matri);
            printf("Estos son sus datos personales: ");
            printf("-------------------------------------------------------------------------------------\n");
            printf("|  n°  |  matricula  |    nombre   |  ap.paterno  |   ap.materno   |  sexo  |  edad  |\n");
            printf("-------------------------------------------------------------------------------------\n");
            printf("| %4d | %11d | %12s | %12s | %13s | %5d | %5d |\n", i, vect[i].matri, vect[i].nombre, vect[i].appater, vect[i].apmater, vect[i].sexo, vect[i].edad);
            printf("-------------------------------------------------------------------------------------\n");
            return;
        }
    }
    if(i == n)
    {
        printf("No existe el usuario con matricula %d", matri);
    }
}