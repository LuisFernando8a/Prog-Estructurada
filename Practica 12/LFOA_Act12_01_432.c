//Ochoa Angulo Luis Fernando 372746
//05-11-23    11-11-23
//Algoritmo que genera un menu para crear archivos de texto
//LFOA_Act12_01_432

#include "Ochoa.h"
#include <conio.h>

typedef struct Personas
{
    int matricula;
    char nombre[25];
    char apaterno[25];
    char amaterno[25];
    int anio;
    int mes;
    int dia;
    int edad;
    int sexo;
    char sexor[15];
    int estado;
    char estador[20];
    char curp[18];
} Personas;

const char *nombrerandom(int genero)
{

    char nombresh[42][30] = 
       {
        "Fernando", "Andrés", "Antonio", "Miguel", "Rafael", "Alberto", "Roberto", "Mauricio",
        "Juan", "Luis", "Enrique", "Tony", "Omar", "DanieL", "Aaron", "Manuel", "Joel",
        "Kevin", "Bruno", "José", "Sergio", "Gabriel", "Lucas","Jorge", "Darío", "Íker", "Samuel",
        "Alejandro", "Mateo", "Ricardo", "Rodrigo", "Daniel", "Héctor", "Eduardo", "Erik", "Adan",
        "Oscar","Heriberto","Antonio","Max","Fidel","Natanael"};

    char nombresm[42][30] = {
        "Alejandra","Alicia", "Gloria", "Irene", "Eva", "Nora", "Angela", "Marina", "Cecilia", "Estela", 
        "Gabriela","María", "Carmen", "Laura", "Josefa", "Isabel", "Ana", "Marta", "Cristina", "Lucia", "Julia",
        "Rafaela", "Susana", "Paulina", "Renata", "Josefina", "Inés","Alexia","Alen","Aylin","Camila","Lucia",
        "Anna","Marla","Mayra","Sofia","Allison","Vianney","Arwen","Danna","Jaqueline","Manuella"};

    int numero = rand() % (42) + 0;

    char *dato = malloc(30);
    
    if (genero == 1)
    {
        strcpy(dato, nombresh[numero]);
    }
    else
    {
        strcpy(dato, nombresm[numero]);
    }
    return dato;
}

const char *apellidorandom()
{
    char apellido[51][30] = {
        "Peralta","Álvarez","Gallegos","Zamora","Castañeda","Escobar","Parra","Solís","Tovar","Gallardo","Gómez",
        "Flores","Morales","Vázquez","Jiménez","Reyes","Díaz","Torres","Gutiérrez","Ruiz","Hernández","García",
        "Martínez","López","González","Pérez","Rodríguez","Sánchez","Castillo","Soto","Cabrera","Gonzales",
        "Mendoza","Silva","Vega","Valdez","Pacheco","Delgado","Nuñez","Herrera","Medina","Ríos","Salazar", 
        "Guerrero", "Calderón", "Arroyo", "Paredes", "Molina", "Santos", "Villanueva", "Aguirre"};

    int numero = rand() % 51;

    char *dato = malloc(30);

    strcpy(dato, apellido[numero]);
    return dato;
}

int aniorandom()
{
    int nMax = 2022;
    int nMin = 1970;

    int numero = rand() % ((nMax + 1) - nMin) + nMin;
    return numero;
}

int mesrandom()
{
    int nMax = 12;
    int nMin = 1;

    int numero = rand() % ((nMax + 1) - nMin) + nMin;
    return numero;
}

int diarandom(int mes)
{
    if (mes == 1 || 3 || 5 || 7 || 8 || 10 || 12)
    {

        int numero = rand() % ((31 + 1) - 1) + 1;
    }
    if (mes == 2)
    {

        int numero = rand() % ((28 + 1) - 1) + 1;
    }
    if (mes == 4 || 6 || 9 || 11)
    {

        int numero = rand() % ((30 + 1) - 1) + 1;
    }
}

int matricularandom()
{
    int nMax = 389999;
    int nMin = 300000;


    int numero = rand() % ((nMax + 1) - nMin) + nMin;
    return numero;
}
int sexogenera()
{
    int n;
    n = rand() % 2 + 1;
    return n;
}

int estadogenera()
{
    return rand() % 34 + 1;
}

// Funcion para imprimir el registro
void imprimearreglo(Personas arr[], int total)
{
    int i = 0;
    int limite = 10;
    char formato[200] = {"  No   Matricula     Nombre        Apellido P.        Apellido M.     Edad    Sexo   "};
    if (total != 0)
    {
        printf("%s\n", formato);
    }
    while (i < total)
    {

        for (i; i < limite; i++)
        {
            arr[i].edad = 2023 - arr[i].anio;

            if (arr[i].sexo == 1)
            {
                strcpy(arr[i].sexor, "Hombre");

            }
            else
            {
                strcpy(arr[i].sexor, "Mujer");

            }
            printf(" %2d   %7d        %-12s  %-12s       %-12s   %4d     %-3s \n", i + 1, arr[i].matricula, arr[i].nombre, arr[i].apaterno, arr[i].amaterno, arr[i].edad, arr[i].sexor);
        }
        if (i != total)
        {
            printf("\nPresione enter para imprimir los siguientes registros\n");
            getch();
        }
        if ((i + limite) > total)
        {
            limite = (total - i) + i;
        }
        else
        {
            limite += 10;
        }
    }
    printf("\n");
}

// Metodo de la burbuja
void mibublesort(Personas a[], int total)
{
    struct Personas temporal;
    // BUBBLE SORT
    for (int x = 0; x < total; x++)
    {
        for (int y = 0; y < total - x - 1; y++)
        {
            if (a[y].matricula > a[y + 1].matricula)
            {
                temporal = a[y];
                a[y] = a[y + 1];
                a[y + 1] = temporal;
            }
        }
    }

    //   return a;
}

// Esta función intercambia dos estructuras de tipo Personas, representadas por los punteros a y b.
void intercambiar(Personas *a, Personas *b)
{
    Personas temporal = *a;
    *a = *b;
    *b = temporal;
    printf("\nIntercambio %d y %d", a->matricula, b->matricula);
}

void selectionSort(Personas arr[], int n)
{
    int i, j, min_idx;

    for (i = 0; i < n - 1; i++)
    {
        // Encontrar el elemento mínimo en el arreglo no ordenado
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j].matricula < arr[min_idx].matricula)
                min_idx = j;

        // Intercambiar el elemento mínimo encontrado con el primer elemento
        intercambiar(&arr[min_idx], &arr[i]);
    }
}

// Funcion que busca una matricula mediante la busqueda secuencial
void busqueda_secuencial(Personas arr[], int matricula, int t)
{
    int posicion = -1;
    int encontro = 0;
    char sexo;
    for (int i = 0; i < t; i++)
    {
        if (matricula == arr[i].matricula)
        {
            posicion = i;
            encontro = 1;
            break;
        }
    }
    if (encontro == 1)
    {
        printf("\nSe encontro la matricula %d y se encuentra en la posicion %d \n", matricula, posicion);
        printf("\n %d> Matricula: [%d]   Nombre: %s  -  Apellidop: %s  -  Apellidom: %s   - Sexo %d  CURP[%s]\n", posicion + 1, arr[posicion].matricula, arr[posicion].nombre, arr[posicion].apaterno, arr[posicion].amaterno, arr[posicion].sexo, arr[posicion].curp);
    }
    else
    {
        printf("\nNo se encontro la matricula %d \n", matricula);
    }
}

// Funcion para borrar una matricula del registro
int borraelemento(Personas arr[], int matricula, int t)
{
    int posicion = -1;
    int total = t;
    int encontro = 0;
    for (int i = 0; i < total; i++)
    {
        if (matricula == arr[i].matricula)
        {
            posicion = i;
            encontro = 1;
        }
    }

    if (posicion >= 0 && encontro == 1)
    {
        for (int i = posicion; i < total - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        t = t - 1;
    }
    if (posicion > -1)
    {
        printf("Se ha borrado exitosamente la matricula %d\n", matricula);
    }
    else
    {
        printf("No se ha encontrado la matricula %d\n", matricula);
    }

    return t;
}

// Funcion para crear el archivo
void salvaenarchivo(Personas persona[], int t, char nombre[])
{
    FILE *festructrura1;
    char *estado;
    strcat(nombre, ".txt");
    festructrura1 = fopen(nombre, "w+");
    char formato[200] = {"  No   Matricula     Nombre        Apellido P.        Apellido M.     Edad    Sexo   "};
    fprintf(festructrura1, "%s\n", formato);
    for (int i = 0; i < t; i++)
    {

        persona[i].edad = 2023 - persona[i].anio;

        if (persona[i].sexo == 1)
        {
            strcpy(persona[i].sexor, "Hombre");
        }
        else
        {
            strcpy(persona[i].sexor, "Mujer");

        }
        strcpy(persona[i].estador, estadoarchivo(persona[i].estado));

        fprintf(festructrura1, " %2d   %7d        %-12s  %-12s       %-12s   %4d     %-3s \n", i + 1, persona[i].matricula, persona[i].nombre, persona[i].apaterno, persona[i].amaterno, persona[i].edad, persona[i].sexor);
    }
    fclose(festructrura1);
}

int lee_archivo(Personas persona[], int i)
{
    Personas arr[2000];
    FILE *fa;
    int x, primeralinea = 0;
    char nombre[50], lalinea[200];
    int matricula = 0, edad = 0;
    char elnombre[25], apa[25], ama[25], sexor[15];
    char *dato;
    printf("Que archivo deseas cargar?\n");
    gets(nombre);
    // scanf("%s", &nombre);
    strcat(nombre, ".txt");
    fa = fopen(nombre, "r");
    if (fa != NULL)
    {
        while (fgets(lalinea, sizeof(lalinea), fa))
        {

            if (primeralinea == 0)
            {
                primeralinea = 1;
            }
            else
            {

                dato = strtok(lalinea, " ");
                printf("\n primer dato: [%s]", dato);
                dato = strtok(NULL, " ");
                printf(" segundo dato: [%s]", dato);
                matricula = atoi(dato);
                dato = strtok(NULL, " ");
                printf(" 3er dato: [%s]", dato);
                strcpy(elnombre, dato);
                dato = strtok(NULL, " ");
                printf(" 4to dato: [%s]", dato);
                strcpy(apa, dato);
                dato = strtok(NULL, " ");
                printf(" 5to dato: [%s]", dato);
                strcpy(ama, dato);
                dato = strtok(NULL, " ");
                printf(" 6to dato: [%s]", dato);
                edad = atoi(dato);
                dato = strtok(NULL, " ");
                printf(" 7mo dato: [%s]", dato);
                strcpy(sexor, dato);
                persona[i].matricula = matricula;
                strcpy(persona[i].nombre, elnombre);
                strcpy(persona[i].apaterno, apa);
                strcpy(persona[i].amaterno, ama);
                persona[i].edad = edad;
                strcpy(persona[i].sexor, sexor);
                i++;
            }
        }
    }
    else
    {
        printf("No existe el archivo %s", nombre);
    }
    fclose(fa);

    return i;
}

int main()
{
    char nombrearch[50];
    int op, matricula;
    int total = 0, max = 1500, incremento = 10;
    int i = 0, primera = 0;
    int ordenado = 0; // Variable para saber si ya esta ordenado el registro
    struct Personas persona[1500];
    srand(time(NULL));
    do
    {
        printf("\n---- M E N U ----\n");
        printf("1.- Cargar Archivo\n");
        printf("2.- Agregar\n");
        printf("3.- Eliminar\n");
        printf("4.- Buscar\n");
        printf("5.- Ordenar\n");
        printf("6.- Imprimir\n");
        printf("7.- Generar archivo\n");
        printf("0.- Salir\n");
        op = validar_num(0, 7, "Elige una opcion");

        switch (op)
        {
        case 1:
            total = lee_archivo(persona, i);
            printf("\nENTER para continuar   \n");
            getch();
            break;
        case 2:
            if (total == 1500)
            {
                printf("El registro esta lleno, no puede agregarle mas\n");
                printf("ENTER para continuar   \n");
                getch();
                break;
            }
            if (total > 1491)
            {
                for (i; i < max; i++)
                {
                    persona[i].matricula = matricularandom();
                    persona[i].sexo = sexogenera();
                    strcpy(persona[i].nombre, nombrerandom(persona[i].sexo));
                    strcpy(persona[i].apaterno, apellidorandom());
                    strcpy(persona[i].amaterno, apellidorandom());
                    persona[i].anio = aniorandom();
                    persona[i].mes = mesrandom();
                    persona[i].dia = diarandom(persona[i].mes);
                    persona[i].estado = estadogenera();

                    strcpy(persona[i].curp, generacurp(persona[i].nombre, persona[i].apaterno, persona[i].amaterno, persona[i].anio, persona[i].mes, persona[i].dia, persona[i].sexo, persona[i].estado));
                    
                }
                total = max;
                i = total;
                ordenado = 0;
                printf("Se genero de manera correcta el registo\n");
                printf("ENTER para continuar   \n");
                getch();
                break;
            }
            else
            {
                for (i; i < incremento + total; i++)
                {
                    persona[i].matricula = matricularandom();
                    persona[i].sexo = sexogenera();
                    strcpy(persona[i].nombre, nombrerandom(persona[i].sexo));
                    strcpy(persona[i].apaterno, apellidorandom());
                    strcpy(persona[i].amaterno, apellidorandom());
                    persona[i].anio = aniorandom();
                    persona[i].mes = mesrandom();
                    persona[i].dia = diarandom(persona[i].mes);
                    persona[i].estado = estadogenera();

                    strcpy(persona[i].curp, generacurp(persona[i].nombre, persona[i].apaterno, persona[i].amaterno, persona[i].anio, persona[i].mes, persona[i].dia, persona[i].sexo, persona[i].estado));

                }
                total += incremento;
                i = total;
                ordenado = 0;
                printf("Se genero de manera correcta el registo\n");
                printf("ENTER para continuar   \n");
                getch();
                break;
            }
        case 3:
            matricula = validar_num(300000, 399999, "¿Que matricula desea eliminar?");
            total = borraelemento(persona, matricula, total);
            printf("ENTER para continuar   \n");
            getch();
            break;
        case 4:
            matricula = validar_num(300000, 399999, "¿Que matricula desea buscar?");
            busqueda_secuencial(persona, matricula, total);
            printf("ENTER para continuar   \n");
            getch();
            break;
        case 5:
            if (ordenado == 0)
            {
                if (total < 1001)
                { 
                    mibublesort(persona, total);
                    printf("Se ordeno correctamente el registro\n");
                    printf("ENTER para continuar   \n");
                    getch();
                    ordenado = 1;
                    break;
                }
                else
                {
                    selectionSort(persona, total);
                    printf("Se ordeno correctamente el registro por seleccion \n");
                    printf("ENTER para continuar   \n");
                    getch();
                    ordenado = 1;
                    break;
                }
            }
            else
            {
                printf("El registro ya se encuentra ordenado\n");
                printf("ENTER para continuar   \n");
                getch();
                break;
            }
        case 6:
            imprimearreglo(persona, total);
            printf("ENTER para continuar . . . \n");
            getch();
            break;
        case 7:
            printf("Como desea nombrar su archivo? \n");
            gets(nombrearch);
            salvaenarchivo(persona, total, nombrearch);
            printf("Se creo exitosamente el archivo '%s'\n", nombrearch);
            printf("ENTER para continuar  \n");
            getch();
        default:
            break;
        }
    } while (op != 0);
}