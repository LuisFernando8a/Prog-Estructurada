//Ochoa Angulo Luis Fernando 372746
//15-10-23    23-10-23
//Algoritmo que genera la CURP
//LFOA_Act9_3/4_432

#include <stdio.h>
#include "8a.h"
#define N 30

//funcionas para rellernar las cadenas//
char nombre1(char nombre[]);
char nombre2(char nombre[]);
char apellido1(char apellido1[]);
char apellido2(char apellido2[]);
char sexo();
char lugar(char estado[]);
void curp();

int main()
{
    printf("Hola Buen dia usuario a continuacion se determinara su curp, favor de ingresar sus datos correctamente\n");
    curp();

}

void curp()
{
    
    int i,j,k, op1, op2, op3, sin_nombre = 0, usar_nom2 = 0,num,num2,dia,mes,año;
    char numc[3],num2c[3];
    
    char CURP[18];
    char diac[5],mesc[5],añoc[5],nombr1[30],nombr2[30],apelli1[30],apelli2[30];
    char nombr1_vocal[20];
    char nombr2_vocal[20];
    char apelli1_vocal[30];
    char apelli2_vocal[30];

    char nombr1_conso[20];
    char nombr2_conso[20];
    char apelli1_conso[30];
    char apelli2_conso[30];
    char sex;
    char estado[3];

    char composicion[81][5] = {"BAKA", "BACA", "BUEI", "BUEY", "CACA", "CACO", "CAGA", "CAGO", "CAKA", "CAKO", "COGE",
                        "COGI", "COJA", "COJE", "COJI", "COJO", "COLA", "CULO", "FALO", "FETO", "GETA", "GUEI", "GUEY", "JETA", "JOTO", "KACA",
                        "KACO", "KAGA", "KAGO", "KAKA", "KAKO", "KOGE", "KOGI", "KOJA", "KOJE", "KOJI", "KOJO", "KOLA", "KULO", "LILO", "LOCA", "LOCO", "LOKA", "LOKO",
                        "MAME", "MAMO", "MEAR", "MEAS", "MEON", "MIAR", "MION", "MOCO", "MOKO", "MULA", "MULO", "NACA", "NACO", "PEDA", "PEDO", "PENE", "PIPI", "PITO",
                        "POPO", "PUTA", "PUTO", "QULO", "RATA", "ROBA", "ROBE", "ROBO", "RUIN", "SENO", "TETA", "VACA", "VAGO", "VAGA", "VAKA", "VUEI", "WUEI", "WUEY"};
    char nombres_prohibidos[10][8] = {"MARIA", "MA.", "MA", "M.", "M", "JOSE", "J.", "J"};
    char letras_feas[6][4] = {"Ü","/","'","-","."};


    // DATOS PERSONALES//
    nombre1(nombr1);
    printf("Presiona:\n1- Si\n2- No\n");
    op1 = vali_num(0,3,"Tienes segundo nombre?: ");
    if (op1 == 1)
    {
        nombre2(nombr2);
    }
    printf("Presiona:\n1- Si\n2- No\n");
    op2 = vali_num(1,2,"Tienes primer apellido?: ");
    if (op2 == 1)
    {
        apellido1(apelli1);
    }
    printf("Presiona:\n1- Si\n2- No\n");
    op3 = vali_num(1,2,"Tienes segundo apellido?: ");
    if (op3 == 1)
    {
        apellido2(apelli2);
    }
    dia = vali_num(1,31,"En que dia naciste: ");
    mes = vali_num(1,12,"En que mes de naciste(con numero): ");
    año = vali_num(1920,2023,"En que año naciste: ");
    sex = sexo();
    lugar(estado);

    // se cambian de tipo de datos las fechas para meterlos a la curp
    sprintf(diac, "%d", dia);
    sprintf(mesc, "%d", mes);
    sprintf(añoc, "%d", año);
    // verificamos y cambiamos las fechas en el formato DD/MM/AA
    if (tam_carac(diac) == 1)
    {
        char aux;
        aux = diac[0];
        diac[1] = aux;
        diac[0] = '0';
    }
    if (tam_carac(mesc) == 1)
    {
        char aux;
        aux = mesc[0];
        mesc[1] = aux;
        mesc[0] = '0';
    }
    eliminarEspacioInicial(nombr1);
    eliminarEspacioInicial(nombr2);
    eliminarEspacioInicial(apelli1);
    eliminarEspacioInicial(apelli2);

    a_mayusculas(nombr1);
    a_mayusculas(nombr2);
    a_mayusculas(apelli1);
    a_mayusculas(apelli2);
    quitar_ene(nombr1);
    quitar_ene(nombr2);
    quitar_ene(apelli1);
    quitar_ene(apelli2);

    for (int i = 0; i < 10; i++)
    {
        if (strcmp(nombr1, nombres_prohibidos[i]) == 0)
        {
            usar_nom2 = 1;
            break;
        }
    }
    // aqui comprobamos si trae mas de una palabra sus nombre y apellidos
    separar_nombre(nombr1);
    separar_nombre(nombr2);
    separar_nombre(apelli1);
    separar_nombre(apelli2);

    //separamos es vocales y consonantes para chambear mejorcito
    vocales_conso(nombr1,nombr1_vocal,nombr1_conso);
    vocales_conso(nombr2,nombr2_vocal,nombr2_conso);
    vocales_conso(apelli1,apelli1_vocal,apelli1_conso);
    vocales_conso(apelli2,apelli2_vocal,apelli2_conso);



    if (op2 == 1)
    {
        // tiene primer apellido
        CURP[0] = apelli1[0];
        if(apelli1[0] == 'A'||apelli1[0] == 'E'|| apelli1[0] == 'I'|| apelli1[0] == 'O'||  apelli1[0] == 'U')
        {
            CURP[1] = apelli1_vocal[1];
        }
        else
        {
            CURP[1] = apelli1_vocal[0];
        }
    }
    else
    {
        // sin primer apellido 
        CURP[0] = 'X';
        CURP[1] = 'X';
        sin_nombre = 1;
    }
    if (op3 == 1)
    {
        CURP[2] = apelli2[0];
    }
    else
    {
        CURP[2] = 'X';
    }

    for (int i = 0; i < 10; i++)
    {
        if (strcmp(nombr1, nombres_prohibidos[i]) == 0)
        {
            usar_nom2 = 1;
            break;
        }
    }
    if (usar_nom2 != 1)
    {
        CURP[3] = nombr1[0];
    }
    else
    {
        CURP[3] = nombr2[0];
    }
    // checamos si las primeras cuatro letras forman la palabra prohibida//
    for (int i = 0; i < 81; i++)
    {
        if (strcmp(CURP, composicion[i]) == 0)
        {
            CURP[1] = 'X';
            break;
        }
    }

    CURP[4] = añoc[2];
    CURP[5] = añoc[3];
    CURP[6] = mesc[0];
    CURP[7] = mesc[1];
    CURP[8] = diac[0];
    CURP[9] = diac[1];
    CURP[10] = sex;
    CURP[11] = estado[0];
    CURP[12] = estado[1];
    if (op2 == 1)
    {
        if(CURP[0] == apelli1_conso[0])
        {
            if(strlen(apelli1_conso) > 2)
            {
                CURP[13] = apelli1_conso[1];
            }
            else
            {
                CURP[13] = 'X';
            }
        }
        else
        {
            CURP[13] = apelli1_conso[0];
        }
    }
    else
    {
        CURP[13] = 'X';
    }
 
    if (op3 == 1)
    {
        if(strlen(apelli2_conso) > 2)
        {
            if(CURP[2] == apelli2_conso[0])
            {
                CURP[14] = apelli2_conso[1];
            }
            else
            {
                CURP[14] = apelli2_conso[0];
            }
        }
        else
        {
            CURP[14] = 'X';
        }
    }
    else
    {
        CURP[14] = 'X';
    }
    for (int i = 0; i < 10; i++)
    {
        if (strcmp(nombr1, nombres_prohibidos[i]) == 0)
        {
            usar_nom2 = 1;
            break;
        }
    }
    if (usar_nom2 != 1)
    {
        if(CURP[3] == nombr1_conso[0])
        {
            if(strlen(nombr1_conso) > 2)
            {
                CURP[15] = nombr1_conso[1];
            }
            else
            {
                CURP[15] = 'X';
            }
        }
        else
        {
            CURP[15] = nombr1_conso[0];
        }
        
    }
    else
    {
        if(CURP[3] == nombr2_conso[0])
        {
            if(strlen(nombr2_conso) > 2)
            {
                CURP[15] = nombr2_conso[1];
            }
            else
            {
                CURP[15] = 'X';
            }
        }
        else
        {
            CURP[15] = nombr2_conso[0];
        }
        
    }

    if (año < 1999)
    {
        num = rand() % 9;
        sprintf(numc, "%d", num);
        CURP[16] = numc[0];
    }

    else
    {
        if (año <= 2010)
        {
            CURP[16] = 'A';
        }
        else
        {
            if (año <= 2020)
            {
                CURP[16] = 'B';
            }
            else
            {
                if (año <= 2030)
                {
                    CURP[16] = 'C';
                }
            }
        }
    }

    num2 = rand() % 9;
    sprintf(num2c, "%d", num2);
    CURP[17] = num2c[0];
    CURP[18] = '\0';
    printf("Tu curp es la siguiente: ");
    a_mayusculas(CURP);
    imprimir(CURP);
    printf("\nEsperamos que haya sido correcto");
   
}

char nombre1(char nombre[])
{

    validar_datos("Cual es tu primer nombre: ",nombre);
    return nombre[N];
}
char nombre2(char nombre[])
{
    validar_datos("Cual es tu segundo nombre: ",nombre);
    return nombre[N];
}
char apellido1(char apPaterno[])
{
    validar_datos("Cual es tu primer apellido: ",apPaterno);
    return apPaterno[N];
}
char apellido2(char apMaterno[])
{
    validar_datos("Cual es tu segundo apellido: ",apMaterno);
    return apMaterno[N];
}

char sexo()
{
    int op = vali_num(1,2,"Presione\n1)Hombre\n2)Mujer\n");
    if(op == 1)
    {
        return 'H';
    }
    else
    {
        return 'M';
    }   
}

char lugar(char estado[])
{
    int op;
    printf("Ingrese el numero segun el estado donde nacio.\n");
    printf("1- Aguascalientes\n2- Baja California\n3-Baja California Sur\n4-Campeche\n5-Coahuila\n");
    printf("6-Colima\n7-Chiapas\n8-Chihuahua\n9-Distrito Federal\n10-Durango\n11-Guanajuato\n12-Guerrero\n");
    printf("13-Hidalgo\n14-Jalisco\n15-Mexico\n16-Michoacan\n17-Morelos\n18-Nayarit\n19-Nuevo Leon\n20-Oaxaca\n");
    printf("21-Puebla\n22-Queretaro\n23-Quintana Roo\n24-San Luis Potosi\n25-Sinaloa\n26-Sonora\n27-Tabasco\n");
    printf("28-Tamaulipas\n29-Tlaxcala\n30-Veracruz\n31-Yucatan\n32-Zacatecas\n33-Si naciste en el extranjero\n");
    op = vali_num(1,33,"En que estado naciste?: ");
    switch (op)
    {
    case 1:
        strcpy(estado, "AS");
        break;
    case 2:
        strcpy(estado,"BC");
        break;
    case 3:
        strcpy(estado,"BS");
        break;
    case 4:
        strcpy(estado,"CC");
        break;
    case 5:
        strcpy(estado,"CL");
        break;
    case 6:
        strcpy(estado,"CM");
        break;
    case 7:
        strcpy(estado,"CS");
        break;
    case 8:
        strcpy(estado,"CH");
        break;
    case 9:
        strcpy(estado,"DF");
        break;
    case 10:
        strcpy(estado,"DG");
        break;
    case 11:
        strcpy(estado,"GT");
        break;
    case 12:
        strcpy(estado,"GR");
        break;
    case 13:
        strcpy(estado,"HG");
        break;
    case 14:
        strcpy(estado,"JC");
        break;
    case 15:
        strcpy(estado,"MC");
        break;
    case 16:
        strcpy(estado,"MN");
        break;
    case 17:
        strcpy(estado,"MS");
        break;
    case 18:
        strcpy(estado,"NT");
        break;
    case 19:
        strcpy(estado,"NL");
        break;
    case 20:
        strcpy(estado,"OC");
        break;
    case 21:
        strcpy(estado,"PL");
        break;
    
    case 22:
        strcpy(estado,"QT");
        break;
    case 23:
        strcpy(estado,"QR");
        break;
    case 24:
        strcpy(estado,"SP");
        break;
    case 25:
        strcpy(estado,"SL");
        break;
    case 26:
        strcpy(estado,"SR");
        break;
    case 27:
        strcpy(estado,"TC");
        break;
    
    case 28:
        strcpy(estado,"TS");
        break;
    case 29:
        strcpy(estado,"TL");
        break;
    case 30:
        strcpy(estado,"VZ");
        break;
    case 31:
        strcpy(estado,"YN");
        break;
    case 32:
        strcpy(estado,"ZS");
        break;
    case 33:
        strcpy(estado,"NE");
        break;
    default:
        
        break;
    }
    return estado[2];
}