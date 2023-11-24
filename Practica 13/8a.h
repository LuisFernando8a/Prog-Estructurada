#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

//constantes de dimensiones
#define NM 4
#define STR 100
#define L 30
#define LN 50


typedef int Tkey;

typedef struct _empleado{
    Tkey key;
    char nombre[LN];
    char apPat[L];
    char apMat[L];
    char sexo;
    int status;
    char puesto[L];
    double telefono;
}Tdato;


int validNum(char txt[],int limi,int lims);
int validStr(char str[]);


void strConcat(char str2[],char str1[]);
void strprint(char str[]);
void strcopy(char str2[],char str[]);

int validNumUnLimit(char txt[]);




//Busqueda binaria y secuencial 
int buscarTBin(Tdato vect[],int i,int num);
int buscarTSec(Tdato vect[],int i,int num);

//Datos generados 
int genKey(Tdato vect[],int i,int ri,int rf);
void genH_Name(Tdato vect[],int i);
void genM_Name(Tdato vect[],int i);
void genAp(Tdato vect[],int i);


int validNum(char txt[],int limi,int lims)
{
    char r[STR];
    int rint;
    do
    {
        printf("%s",txt);
        fflush(stdin); 
        gets(r);
        rint=atoi(r);
        if(rint<limi || rint>lims)
        {
            printf("Valor invalido, ingresalo de nuevo\n");
        }
    }while(rint<limi || rint>lims);
    return rint;
}

int validStr(char str[])
{
    int i=0,invalido=0;
    fflush(stdin);
    gets(str);
    do
    {
        if(str[i]>90)
        {
            if(str[i]<97)
            {
                printf("\nEl simbolo %c no es valido \n",str[i]);
                invalido++;
            }
        }
        else
        {
            if(str[i]>122)
            {
                printf("\nEl simbolo %c no es valido \n",str[i]);
                invalido++;
            }
            else
            {
                if(str[i]<65)
                {
                    if(str[i]==' ')
                    {
                        if(i==0)
                        {
                            printf("\nLa cadena no debe empezar con espacio\n");
                            invalido++;
                        }
                        else
                        {
                            if(str[i-1]==' ')
                            {
                                printf("\nLa cadena no debe llevar dos espacios seguidos\n");
                                invalido++;
                            }
                        }
                    }
                    else
                    {
                        if(str[i]=='\0')
                        {
                            if(str[i-1]==' ')
                            {
                                printf("\nLa cadena no debe terminar en espacio\n");
                                invalido++;
                            }
                        }
                        else
                        {
                            printf("\nEl simbolo %c no es valido \n",str[i]);
                            invalido++;
                        }
                    }
                }
            }
        }
        i++;
    }while(str[i-1]!='\0');
    return invalido;
}

int validNumUnLimit(char txt[])
{
    char r[STR];
    int rint;
    printf("%s",txt);
    fflush(stdin);
    gets(r);
    rint=atoi(r);
    return rint;
}




void strprint(char str[])
{
    int i;
    for(i=0;str[i]!='\0';i++)
    {
        printf("%c",str[i]);
    }
}

void strcopy(char str2[],char str[])
{
    int i=0;
    for(i=0;str[i]!='\0';i++)
    {
        str2[i]=str[i];
    }
    str2[i]='\0';
}



void strConcat(char str2[],char str1[])
{
    int j,k=0;
    j=strlen(str2); 
    str2[j++]=' '; 
    while(str1[k]!='\0')    
    {
        str2[j]=str1[k];    
        k++;
        j++;
    }
    str2[j]='\0';  
}

//METODOS DE ORDENACION

void intercambiar(Tdato *a, Tdato *b)
{
    Tdato temporal = *a;
    *a = *b;
    *b = temporal;
}

//Burbujita
void burbuja(Tdato a[], int total)
{
    Tdato temporal;
    for (int x = 0; x < total; x++)
    {
        for (int y = 0; y < total - x - 1; y++)
        {
            if (a[y].key > a[y + 1].key)
            {
                temporal = a[y];
                a[y] = a[y + 1];
                a[y + 1] = temporal;
            }
        }
    }
}
//Por seleccion
void seleccion(Tdato arr[], int n)
{
    int i, j, min_idx;

    for (i = 0; i < n - 1; i++)
    {
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j].key < arr[min_idx].key)
                min_idx = j;
                
        intercambiar(&arr[min_idx], &arr[i]);
    }
}


//METODOS DE BUSQUEDA
//Binaria
int buscarTBin(Tdato vect[],int i,int num)
{
    int izq,drcha;
    int med;
    izq=0;
    drcha=i-1;
    while(izq<=drcha) 
    {
        med=izq+(drcha-izq)/2;
        if(vect[med].key==num)
        {
            return med;
        }
        
        if(vect[med].key<num)
        {
            izq=med+1;
        } 
        else
        {
            drcha=med-1;
        }
    }
    return -1;
}
//Secuencial 
int buscarTSec(Tdato vect[],int i,int num)
{
    int j;
    for(j=0;j<i;j++)    
    {
        if(num==vect[j].key)  
        {
            return j; 
        }
    }
    return -1;  
}

int genKey(Tdato vect[],int i,int ri,int rf)
{
    int num;
    int rango=rf-ri;
    do
    {
        num=(rand()%rango+1)+ri;
    }while(buscarTSec(vect,i,num)!=-1);
    return num;
}

void genH_Name(Tdato vect[],int i)
{
    char h_name[100][LN]={
        "GOJO","ICHIGO","ITADORI","NANAMI","RIMURU","VELDORA","SOE","SUKUNA","YUTA","EREN",
        "ARMIN","JEAN","MEGUMIN","TOJI","EDWARD","ALPHONSE","LIVE","KILLUA","LELOUCH",
        "ROY","PEDRO","MARTIN","ROBERTO","EDUARDO","MARIO","ARMANDO","SERGIO","RAUL",
        "ALFREDO","RAFAEL","RICARDO","HECTOR","OSCAR","GERARDO","DAVID","DANIEL","HUGO",
        "JAIME","JULIO","RUBEN","RAMON","MARCO","GABRIEL","EDGAR","GUADALUPE","ALFONSO",
        "GUILLERMO","SALVADOR","OMAR","IVAN","HUMBERTO","FELIPE","ERNESTO","PABLO","IGNACIO",
        "GUSTAVO","ANDRES","ADRIAN","JOEL","DAZAI","OIKAWA","HYAKKIMARU","ROGELIO","RENE",
        "LORENZO","GERMAN","MAURICIO","LEONARDO","JOSUE","EMMANUEL","JULIAN","MOISES","SANTIAGO",
        "EFRAIN","ALONSO","ABEL","WILBERT","ALVARO","FELIX","MARCOS","ADOLFO","RODRIGO","RAMIRO",
        "SAMUEL","JOAQUIN","ABRAHAM","ESTEBAN","ULISES","RAYMUNDO","FIDEL","TOMAS","SAUL","ISRAEL",
        "OCTAVIO","VICENTE","NOE","GREGORIO","ISMAEL","NICOLAS","BENJAMIN",
    };
    int prob;
    prob=rand()%10;
    if(prob<=7)
    {
        strcpy(vect[i].nombre,h_name[rand()%100]);
    }
    else
    {
        strcpy(vect[i].nombre,h_name[rand()%100]);
        strConcat(vect[i].nombre,h_name[rand()%100]);
    }
}

void genM_Name(Tdato vect[],int i)
{
    char m_name[100][LN]={
        "MIKASA","NOBARA","TOUKA","RUKIA","SHINOE","LUST","LETICIA","ELENA","EVA","DORA",
        "CATALINA","LIDIA","VICTORIA","DULCE","DANA","SARA","EVELIN","DANIELA","ELIZABETH",
        "ANNIE","PATRICIA","ISABEL","ALICIA","MARGARITA","LUZ","ANGELICA","CLAUDIA","JAZMIN",
        "SILVIA","NORMA","JUANA","GABRIELA","ADRIANA","VERONICA","TERESA","ALEJANDRA","ALMA",
        "BEATRIZ","YANET","YOLANDA","BLANCA","SANDRA","ARACELI","IRMA","GLORIA","CARMEN","LUZ",
        "ROCIO","CONCEPCION","CRISTINA","EDITH","ESTHER","LILIA","LORENA","MAGDALENA","CECILIA",
        "JOSEFINA","DOLORES","KARINA","LUCIA","ESTELA","SUSANA","MARIBEL","LUCINA","LOURDES","ERIKA",
        "MONICA","AGUSTINA","DIANA","EUGENIA","ALEJANDRINA","PILAR","FRANCISCA","VIRGINIA","LILIANA",
        "GRACIELA","BERTHA","OLGA","MIRIAM","FABIOLA","DELIA","CAROLINA","KARLA","HILDA","ANTONIA",
        "MARICELA","SONIA","NANCY","BERENICE","YADIRA","MAYRA","NAYDELIN","MARISOL","KAROL","REYNA",
        "MICHELL","OLIVIA","RAQUEL","IRENE","ELVIRA",
    };
    int prob;
    prob=rand()%10;
    if(prob<=7)
    {
        strcpy(vect[i].nombre,m_name[rand()%100]);
    }
    else
    {
        strcpy(vect[i].nombre,m_name[rand()%100]);
        strConcat(vect[i].nombre,m_name[rand()%100]);
    }
}

void genAp(Tdato vect[],int i)
{
    char ap[100][L]={
        "HERNANDEZ","GARCIA","MARTINEZ","LOPEZ","GONZALEZ","RODRIGUEZ",
        "PEREZ","SANCHEZ","RAMIREZ","FLORES","CRUZ","GOMEZ","MORALES",
        "VAZQUEZ","JIMENEZ","REYES","DIAZ","TORRES","GUTIERREZ","RUIZ",
        "AGUILAR","MENDOZA","CASTILLO","ORTIZ","MORENO","RIVERA","RAMOS",
        "ROMERO","JUAREZ","ALVAREZ","MENDEZ","CHAVEZ","HERRERA","MEDINA",
        "DOMINGUEZ","CASTRO","GUZMAN", "VARGAS","VELAZQUEZ","SALAZAR",
        "ROJAS","ORTEGA","CORTES","SANTIAGO","GUERRERO","CONTRERAS","BAUTISTA",
        "ESTRADA","LUNA","LARA","RIOS","AVILA","ALVARADO","DE LA CRUZ","SILVA",
        "DELGADO","CARRILLO","SOLIS","SOTO","LEON","FERNANDEZ","CERVANTES",
        "MARQUEZ","ESPINOSA","MEJIA","VEGA","SANDOVAL","CAMPOS","NAVA","CABRERA",
        "IBARRA","ESPINOZA","SANTOS","ACOSTA","CAMACHO","VALDEZ","FUENTES",
        "VARELA","MIRANDA","MALDONADO","ROBLES","ROSAS","MEZA","MOLINA",
        "TREJO","ROSALES","PACHECO","NAVARRO","SALGADO","AGUIRRE","SALAS","VELASCO",
        "CARDENAS","PINEDA","OROZCO","SERRANO","RANGEL","VALENCIA","SOSA","VASQUEZ"
    };
    int prob;
    prob=rand()%10;
    if(prob<9)
    {
        strcpy(vect[i].apPat,ap[rand()%99]);
        strcpy(vect[i].apMat,ap[rand()%99]);
    }
    else
    {
        strcpy(vect[i].apPat,ap[rand()%99]);
        vect[i].apMat[0]='X';
        vect[i].apMat[1]='\0';
    }
}