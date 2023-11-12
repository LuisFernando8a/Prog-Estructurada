//Libreria hecha por LUIS FERNANDO 8A Angulo
//Libreria utilizada para Actividad 12 de PE
//LFOA_Libreria_432

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// Funcion para validar numeros dentro de un rango
int validar_num(int ri, int rf, char msge[])
{
    char xnum[30];
    int num;
    do
    {
        puts(msge);
        fflush(stdin);
        gets(xnum);
        // fgets(xnum, 30, stdin);
        num = atoi(xnum);
    } while (num < ri || num > rf);
    return num;
}

// Funcion que busca un numero dentro de un vector
int busq_sec(int vect[], int n, int num)
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

// Funcion para llenar un vector de manera aleatorio con numeros dentro de un rango
void llenar_vector_sr(int vect[], int n, int ri, int rf)
{
    int rango, num;
    rango = (rf - ri) + 1;

    srand(time(NULL));

    for (int i = 0; i < n; i++)
    {
        do
        {
            num = (rand() % rango) + ri;
        } while (busq_sec(vect, i, num) != -1);
        vect[i] = num;
    }
}

// Funcion para imprimir un vector
void imprimir_vector(int vect[], int tam)
{
    for (int i = 0; i < tam; i++)
    {
        printf("%d-[%d]", i + 1, vect[i]);
        if (i < tam - 1)
        {
            printf(", ");
        }
    }
}

// Funcion para ordenar un vector de menor a mayor
void ordenar(int vect[], int n)
{
    int i, j;
    int temp;

    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
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

// Funcion para llenar una matriz con numeros aleatorios
void llenar_matriz(int vect[][4], int filas, int columnas)
{
    int vect1[16];
    int i = 0;
    llenar_vector_sr(vect1, 16, 1, 16);

    for (int f = 0; f < filas; f++)
    {
        for (int c = 0; c < columnas; c++)
        {
            vect[f][c] = vect1[i];
            i++;
        }
    }
}

// Funcion para imprimir una matriz
void imprimir_matriz(int vect[][4], int filas, int columnas)
{
    for (int f = 0; f < filas; f++)
    {
        for (int c = 0; c < columnas; c++)
        {
            printf("[%d][%d]-%d ", f + 1, c + 1, vect[f][c]);
        }
        printf("\n");
    }
}

// Funcion para buscar un numero y te dice si existe y en que indice se encuentra
void buscar(int vect[], int m)
{
    int num, pos;
    printf("\nQue numero deseas buscar? ");
    scanf("%d", &num);
    pos = busq_sec(vect, 15, num);
    if (pos > -1)
    {
        printf("El numero %d si existe en el vector y se encuentra en la posicion %d", num, pos + 1);
    }
    else
    {
        printf("El numero %d no existe dentro del vector", num);
    }
}



// Funcion para separar por vocales y consonantes
void vocales_conso(char cadena[], char vocal[], char consonante[])
{
    int j, i = 0, k = 0;
    for (j = 0; cadena[j] != '\0'; j++)
    {
        if (cadena[j] != 'A' && cadena[j] != 'E' && cadena[j] != 'I' && cadena[j] != 'O' && cadena[j] != 'U')
        {
            consonante[i] = cadena[j];
            i++;
        }
        else
        { // VOCALES//
            vocal[k] = cadena[j];
            k++;
        }
    }
    consonante[i] = '\0';
    vocal[i] = '\0';
}

// Funcion para revisar palabras prohibidas
int revisar(char nom[])
{
    strupr(nom);
    char *nom1[81] = {"BACA", "BAKA", "BUEI", "BUEY", "CACA", "CACO", "CAGA", "CAGO", "CAKA", "CAKO",
                      "COGE", "COGI", "COJA", "COJE", "COJI", "COJO", "COLA", "CULO", "FALO", "FETO", "GETA", "GUEI",
                      "GUEY", "JETA", "JOTO", "KACA", "KACO", "KAGA", "KAGO", "KAKA", "KAKO", "KOGE", "KOGI", "KOJA",
                      "KOJE", "KOJI", "KOJO", "KOLA", "KULO", "LILO", "LOCA", "LOCO", "LOKA", "LOKO", "MAME", "MAMO",
                      "MEAR", "MEAS", "MEON", "MIAR", "MION", "MOCO", "MOKO", "MULA", "MULO", "NACA", "NACO", "PEDA",
                      "PEDO", "PENE", "PIPI", "PITO", "POPO", "PUTA", "PUTO", "QULO", "RATA", "ROBA", "ROBE", "ROBO",
                      "RUIN", "SENO", "TETA", "VACA", "VAGA", "VAGO", "VAKA", "VUEI", "VUEY", "WUEI", "WUEY"};
    int dato;
    for (int i = 0; i < 81; i++)
    {
        dato = strcmp(nom, nom1[i]);
        if (dato == 0)
        {
            return 0;
        }
    }

    return dato;
}

// Funcion para validar que solo ingrese letras y no mas de un espacio seguido
int validarnombre(char nombres[30])
{
    for (int i = 0; nombres[i] != '\0'; i++)
    {
        if (!((nombres[i] >= 65 && nombres[i] <= 90) || (nombres[i] >= 97 && nombres[i] <= 122)) || nombres[i] == 32)
        {
            printf("Unicamente ingrese letras y en caso de ser requerido especios(ojo no mas de un espacio seguido)\n");
            return 0;
        }
        else
        {
            if (nombres[i - 1] == 32 && nombres[i] == 32)
            {
                printf("No puedes ingresar dos espacios seguidos\n");
                return 0;
            }
        }
    }
    return 1;
}

// Funcion para asignar la abreviatura de los estados
char *estadocurp(int num)
{
    char *edo;
    edo = (char *)malloc(3 * sizeof(char));
    if (num == 1)
    {
        strcpy(edo, "AS");
        return edo;
    }
    if (num == 2)
    {
        strcpy(edo, "BC");
        return edo;
    }
    if (num == 3)
    {
        strcpy(edo, "BS");
        return edo;
    }
    if (num == 4)
    {
        strcpy(edo, "CC");
        return edo;
    }
    if (num == 5)
    {
        strcpy(edo, "CS");
        return edo;
    }
    if (num == 6)
    {
        strcpy(edo, "CH");
        return edo;
    }
    if (num == 7)
    {
        strcpy(edo, "DF");
        return edo;
    }
    if (num == 8)
    {
        strcpy(edo, "CL");
        return edo;
    }
    if (num == 9)
    {
        strcpy(edo, "CM");
        return edo;
    }
    if (num == 10)
    {
        strcpy(edo, "DG");
        return edo;
    }
    if (num == 11)
    {
        strcpy(edo, "MX");
        return edo;
    }
    if (num == 12)
    {
        strcpy(edo, "GT");
        return edo;
    }
    if (num == 13)
    {
        strcpy(edo, "GR");
        return edo;
    }
    if (num == 14)
    {
        strcpy(edo, "HG");
        return edo;
    }
    if (num == 15)
    {
        strcpy(edo, "JC");
        return edo;
    }
    if (num == 16)
    {
        strcpy(edo, "MN");
        return edo;
    }
    if (num == 17)
    {
        strcpy(edo, "MS");
        return edo;
    }
    if (num == 18)
    {
        strcpy(edo, "NT");
        return edo;
    }
    if (num == 19)
    {
        strcpy(edo, "NL");
        return edo;
    }
    if (num == 20)
    {
        strcpy(edo, "OC");
        return edo;
    }
    if (num == 21)
    {
        strcpy(edo, "PL");
        return edo;
    }
    if (num == 22)
    {
        strcpy(edo, "QO");
        return edo;
    }
    if (num == 23)
    {
        strcpy(edo, "QR");
        return edo;
    }
    if (num == 24)
    {
        strcpy(edo, "SP");
        return edo;
    }
    if (num == 25)
    {
        strcpy(edo, "SL");
        return edo;
    }
    if (num == 26)
    {
        strcpy(edo, "SR");
        return edo;
    }
    if (num == 27)
    {
        strcpy(edo, "TC");
        return edo;
    }
    if (num == 28)
    {
        strcpy(edo, "TS");
        return edo;
    }
    if (num == 29)
    {
        strcpy(edo, "TL");
        return edo;
    }
    if (num == 30)
    {
        strcpy(edo, "VZ");
        return edo;
    }
    if (num == 31)
    {
        strcpy(edo, "YN");
        return edo;
    }
    if (num == 32)
    {
        strcpy(edo, "ZS");
        return edo;
    }
    if (num == 33)
    {
        strcpy(edo, "NE");
        return edo;
    }
}

char *estadoarchivo(int num)
{
    char *edo;
    edo = (char *)malloc(25 * sizeof(char));
    if (num == 1)
    {
        strcpy(edo, "AGUASCALIENTES");
        return edo;
    }
    if (num == 2)
    {
        strcpy(edo, "BAJA CALIFORNIA");
        return edo;
    }
    if (num == 3)
    {
        strcpy(edo, "BAJA CALIFORNIA SUR");
        return edo;
    }
    if (num == 4)
    {
        strcpy(edo, "CAMPECHE");
        return edo;
    }
    if (num == 5)
    {
        strcpy(edo, "CHIAPAS");
        return edo;
    }
    if (num == 6)
    {
        strcpy(edo, "CHIHUAHUA");
        return edo;
    }
    if (num == 7)
    {
        strcpy(edo, "CIUDAD DE MEXICO");
        return edo;
    }
    if (num == 8)
    {
        strcpy(edo, "COAHUILA");
        return edo;
    }
    if (num == 9)
    {
        strcpy(edo, "COLIMA");
        return edo;
    }
    if (num == 10)
    {
        strcpy(edo, "DURANGO");
        return edo;
    }
    if (num == 11)
    {
        strcpy(edo, "ESTADO DE MEXICO");
        return edo;
    }
    if (num == 12)
    {
        strcpy(edo, "GUANAJUATO");
        return edo;
    }
    if (num == 13)
    {
        strcpy(edo, "GUERRERO");
        return edo;
    }
    if (num == 14)
    {
        strcpy(edo, "HIDALGO");
        return edo;
    }
    if (num == 15)
    {
        strcpy(edo, "JALISCO");
        return edo;
    }
    if (num == 16)
    {
        strcpy(edo, "MICHOACAN");
        return edo;
    }
    if (num == 17)
    {
        strcpy(edo, "MORELOS");
        return edo;
    }
    if (num == 18)
    {
        strcpy(edo, "NAYARIT");
        return edo;
    }
    if (num == 19)
    {
        strcpy(edo, "NUEVO LEON");
        return edo;
    }
    if (num == 20)
    {
        strcpy(edo, "OAXACA");
        return edo;
    }
    if (num == 21)
    {
        strcpy(edo, "PUEBLA");
        return edo;
    }
    if (num == 22)
    {
        strcpy(edo, "QUERETARO");
        return edo;
    }
    if (num == 23)
    {
        strcpy(edo, "QUINTANA ROO");
        return edo;
    }
    if (num == 24)
    {
        strcpy(edo, "SAN LUIS POTOSI");
        return edo;
    }
    if (num == 25)
    {
        strcpy(edo, "SINALOA");
        return edo;
    }
    if (num == 26)
    {
        strcpy(edo, "SONORA");
        return edo;
    }
    if (num == 27)
    {
        strcpy(edo, "TABASCO");
        return edo;
    }
    if (num == 28)
    {
        strcpy(edo, "TAMAULIPAS");
        return edo;
    }
    if (num == 29)
    {
        strcpy(edo, "TLAXCALA");
        return edo;
    }
    if (num == 30)
    {
        strcpy(edo, "VERACRUZ");
        return edo;
    }
    if (num == 31)
    {
        strcpy(edo, "YUCATAN");
        return edo;
    }
    if (num == 32)
    {
        strcpy(edo, "ZACATECAS");
        return edo;
    }
    if (num == 33)
    {
        strcpy(edo, "NACIDO EN EL EXTRANJERO");
        return edo;
    }
}

// Funcion que regresa el dia del curp
char *diacurp(int num)
{
    switch (num)
    {
    case 1:
        return "01";
        break;
    case 2:
        return "02";
        break;
    case 3:
        return "03";
        break;
    case 4:
        return "04";
        break;
    case 5:
        return "05";
        break;
    case 6:
        return "06";
        break;
    case 7:
        return "07";
        break;
    case 8:
        return "08";
        break;
    case 9:
        return "09";
        break;
    case 10:
        return "10";
        break;
    case 11:
        return "11";
        break;
    case 12:
        return "12";
        break;
    case 13:
        return "13";
        break;
    case 14:
        return "14";
        break;
    case 15:
        return "15";
        break;
    case 16:
        return "16";
        break;
    case 17:
        return "17";
        break;
    case 18:
        return "18";
        break;
    case 19:
        return "19";
        break;
    case 20:
        return "20";
        break;
    case 21:
        return "21";
        break;
    case 22:
        return "22";
        break;
    case 23:
        return "23";
        break;
    case 24:
        return "24";
        break;
    case 25:
        return "25";
        break;
    case 26:
        return "26";
        break;
    case 27:
        return "27";
        break;
    case 28:
        return "28";
        break;
    case 29:
        return "29";
        break;
    case 30:
        return "30";
        break;
    case 31:
        return "31";
        break;

    default:
        break;
    }
    return "01";
}

// Funcion para incorporar el mes al curp, regresa el numero de mes en dos caracteres
char *mescurp(int num)
{
    switch (num)
    {
    case 1:
        return "01";
        break;
    case 2:
        return "02";
        break;
    case 3:
        return "03";
        break;
    case 4:
        return "04";
        break;
    case 5:
        return "05";
        break;
    case 6:
        return "06";
        break;
    case 7:
        return "07";
        break;
    case 8:
        return "08";
        break;
    case 9:
        return "09";
        break;
    case 10:
        return "10";
        break;
    case 11:
        return "11";
        break;
    case 12:
        return "12";
        break;
    default:
        break;
    }
    return "01";
}

// Funcion para regresar el año para el curp
char *aniocurp(int num)
{
    char c_anio[4];
    char *cadena;
    cadena = (char *)malloc(2 * sizeof(char));
    sprintf(c_anio, "%d", num);

    cadena[0] = c_anio[2];
    cadena[1] = c_anio[3];

    return cadena;
}

char apellidocompuesto(char apellido[])
{

    int tamano = strlen(apellido);
    int contador = 0;
    char cadena[25];

    for (int i = 0; i < tamano; i++)
    {
        if (apellido[i] == ' ')
        {
            // inicializamos para vover a capturar palabras
            contador = 0;
            cadena[0] = '\0';
        }
        else
        {
            cadena[contador] = apellido[i];
            contador++;
        }
    }
    return cadena[0];
}

char *sexocurp(int num)
{
    if (num == 1)
    {
        return "H";
    }
    if (num == 2)
    {
        return "M";
    }
    return "B";
}

// retorna la primera consonante (que no es la primera letra)
char consonante(char cadena[])
{

    for (int i = 1; i < 20; i++)
    {
        if (cadena[i] == 'a' || cadena[i] == 'e' || cadena[i] == 'i' || cadena[i] == 'o' || cadena[i] == 'u' || cadena[i] == 'A' || cadena[i] == 'E' || cadena[i] == 'I' || cadena[i] == 'O' || cadena[i] == 'U' || cadena[i] == ' ')
        {
        }
        else
        {
            return cadena[i];
        }
    }
}

// retorna la primera vocal (despues de la primera letra)
char vocal(char cadena[])
{

    for (int i = 1; i < 20; i++)
    {
        if (cadena[i] == 'a' || cadena[i] == 'e' || cadena[i] == 'i' || cadena[i] == 'o' || cadena[i] == 'u' || cadena[i] == 'A' || cadena[i] == 'E' || cadena[i] == 'I' || cadena[i] == 'O' || cadena[i] == 'U')
        {
            return cadena[i];
        }
    }
    return 'X';
}

// funcion que retorna el caracter del nombre
char letranombre(char nombre[])
{
    char *posicion = 0;
    char elcaracter = 'a';

    // char buscar = strchr(nombre, ' ');
    if (posicion = strchr(nombre, ' '))
    {
        printf("\n >> La cadena tiene un espacio!! ");

        // ahora divido la cadena (el divisor es el espacio ), el resultado es el "primer nombre"
        char *cadenadiv = strtok(nombre, " ");
        printf("\n cadena div %s", cadenadiv); // cadena obtiene la primera palabra de nombre (el divisor fue el espacio)
        if (strcmp(cadenadiv, "MARIA") == 0 || strcmp(cadenadiv, "JOSE") == 0 || strcmp(cadenadiv, "MA") == 0)
        {
            cadenadiv = strtok(NULL, " ");                      // con esto toma la siguiente cadena (segundo nombre)
            printf("\n Si fue M o J cadena div %s", cadenadiv); // cadenadiv aqui es la segunda palabra (el divisor es el espacio)

            // aqui debo de obtener la primera vocal de la segunda palabra.
            return cadenadiv[0];
        }
    }
    else
    { // Si no esta el espacio, es un solo nombre, entonces solo busco o retorno el primer caracter del nombre.

        return nombre[0]; // retorno el primer caracter del nombre (variable)
    }
}

char numerorandom()
{

    char caracter[4];
    // srand(time(NULL));
    int numero = rand() % (9) + 0;
    sprintf(caracter, "%d", numero);
    // printf("\n\n NO random %d", numero);

    return caracter[0];
}
// funcion que regresa las primera 4 letras
const char *cuatroletras(char nom[], char apa[], char ama[])
{

    // char cadena[4], dato;
    char *cadena, dato;
    strupr(nom);
    strupr(apa);
    strupr(ama);
    // como vamos a regresar mas de un caracter, debemos decirle a C que el apuntador tiene el
    //  tamaño de 4 caracteres (asi no da error)
    cadena = (char *)malloc(4 * sizeof(char));
    // si el apellido paterno no existe, se le asigna X
    if (strlen(apa) == 0)
    {
        cadena[0] = 'X';
    }
    else
    {
        char capa = apellidocompuesto(apa);
        cadena[0] = capa;
    }
    // si el apellido materno no existe se le asigna X
    if (strlen(ama) == 0)
    {
        cadena[2] = 'X';
    }
    else
    {
        char cama = apellidocompuesto(ama);
        cadena[2] = cama;
    }

    cadena[1] = vocal(apa);

    char letran = letranombre(nom);
    cadena[3] = letran;

    cadena[0] = (cadena[0]);
    cadena[1] = (cadena[1]);
    cadena[2] = (cadena[2]);
    cadena[3] = (cadena[3]);
    cadena[4] = '\0';
    // printf("\n cadena %s  dentro de 4letras", cadena);

    if (revisar(cadena) == 0)
    {
        // printf("\n La cadena %s  SI esta prohibida", cadena);
        cadena[1] = 'X';
    }

    return cadena;
}

const char *generacurp(char nombre[], char apaterno[], char amaterno[], int anio, int mes, int dia, int sexo, int estado)
{
    // pasamos los datos a mayusculas
    // int c = 0;

    // while (nombre[c])
    // {
    //     nombre[c] = strupr(nombre[c]);
    //     c++;
    // }
    // c = 0;
    // while (apaterno[c])
    // {
    //     apaterno[c] = strupr(apaterno[c]);
    //     c++;
    // }
    // c = 0;
    // while (amaterno[c])
    // {
    //     amaterno[c] = strupr(amaterno[c]);
    //     c++;
    // }

    char curp[18] = {"\0"};
    char *dato;
    dato = cuatroletras(nombre, apaterno, amaterno);
    curp[0] = dato[0];
    curp[1] = dato[1];
    curp[2] = dato[2];
    curp[3] = dato[3];

    dato = aniocurp(anio);
    curp[4] = dato[0];
    curp[5] = dato[1];
    dato = mescurp(mes);
    curp[6] = dato[0];
    curp[7] = dato[1];
    dato = diacurp(dia);
    curp[8] = dato[0];
    curp[9] = dato[1];
    dato = sexocurp(sexo);
    curp[10] = dato[0];
    dato = estadocurp(estado);
    curp[11] = dato[0];
    curp[12] = dato[1];
    char letra = 'a';
    letra = consonante(apaterno);
    curp[13] = letra;
    letra = consonante(amaterno);
    curp[14] = letra;
    letra = consonante(nombre);
    curp[15] = letra;

    if (anio < 1999)
    {
        curp[16] = '0';
    }
    if (anio >= 2000)
    {
        curp[16] = 'A';
    }
    if (anio >= 2010)
    {
        curp[16] = 'B';
    }
    if (anio >= 2020)
    {
        curp[16] = 'C';
    }
    curp[17] = numerorandom();
    // curp[17] = '8';
    curp[18] = '\0';

    // for (int i = 0; i < 18; i++)
    // {
    //     curp[i] = toupper(curp[i]);
    // }
    strupr(curp);

    // printf("\n\n La cadena del CURP es [ %s ]  ", curp);
    //  Si retornamos un arreglo de caracteres no funciona (porque la funcion generacurp dice que para retornar uan cadena usa un puntero)
    char *p_curp = malloc(18);
    p_curp = curp;
    return p_curp;
}