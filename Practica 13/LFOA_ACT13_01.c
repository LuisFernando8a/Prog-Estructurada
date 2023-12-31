//                             Ensenada, Baja California a 23 de Noviembre del 2023    //
// Nombre:              Luis Fernando Ochoa Angulo                                     //
// Matricula:           372746                                                         //
// Programa:            Crea registros con archivos binarios, desde cargar y crear     //
//                      archivos de textos                                             //
// Nombre del programa: LFOA_ATCV_13


#include "8a.h"
#define REG 5000
void menu(void);
int msgs(void);

//Funciones para la opcion 1
int genReg(Tdato vect[],int i);
void genRegRand(Tdato vect[],int i);
int buscarTelefono(Tdato vect[],int i,double num);
void genPuesto(Tdato vect[],int i);


//Funciones para la opcion 2 
void editarReg(Tdato vect[],int i,int orden);
void editMenu(Tdato vect[],int pos);
void editPuesto(Tdato vect[],int pos);
float validNumF(char txt[],int limi,int lims);


//Funciones para la opcion 3
int eliminarEmpleado(Tdato vect[],int i,int orden);

//Funciones para la opcion 4
void buscarEmpleado(Tdato vect[],int i,int orden);
void printEmpleadoReg(Tdato empleado);
//Funciones para la opcion 5 
int ordenEmpleado(Tdato vect[],int i,int ordenM);
//Funciones para la opcion 6
void printEmpleados(Tdato vect[],int i);
void printEmpleadoTab(Tdato empleado);
//Funcione para la opcion 7
void genArchivoTxt(Tdato vect[],int i);
//Funcione para la opcion 8
void printArchTxt(void);
//Funcione para la opcion 9
void genArchivoBin(Tdato vect[],int i);
//Funcione para la opcion 10
int cargarArchivoBin(Tdato vect[],int i);
//Funcione para la opcion 11
void printDel(void);

int main()
{
    srand(time(NULL));    
    menu();
    return 0;
}

int msgs(void)
{
    printf(" Menu\n\n");
    printf(" 1 Agregar\n");
    printf(" 2 Editar Reistro\n");
    printf(" 3 Eliminar Registro\n");
    printf(" 4 Buscar\n");
    printf(" 5 Ordenar\n");
    printf(" 6 Imprimir\n");
    printf(" 7 Generar Archivo Texto\n");
    printf(" 8 Ver Archivo Texto\n");
    printf(" 9 Crear Archivo Binario\n");
    printf("10 Cargar Archivo Binario\n");
    printf("11 Mostrar Eliminados\n");
    printf("12 Salir\n");
    return (validNum("Escoge una opcion: ",1,12));
}

void menu(void)
{
    FILE *fa;
    Tdato empleados[REG];
    int op;
    int orden=0,ordenMetodo=0,cargBin=1,del=0;
    int i=0;
    /*fa=fopen("registrosbin.dll","rb");
    if(fa)
    {
        fclose(fa);
        remove("registrosbin.dll");
    }*/

    do
    {
        op=msgs();
        switch(op)
        {
            case 1:
                i=genReg(empleados,i);
                if(i>2500)
                {
                    ordenMetodo=1;
                }
                orden=0;
                break;
            case 2:
                editarReg(empleados,i,orden);
                break;
            case 3:
                del+=eliminarEmpleado(empleados,i,orden);
                break;
            case 4:
                buscarEmpleado(empleados,i,orden);
                break;
            case 5:
                if(!orden)
                {
                    orden=ordenEmpleado(empleados,i,ordenMetodo);
                }
                else
                {
                    printf("\nLos empleados ya estan ordenados\n");
                }
                break;
            case 6:
                printEmpleados(empleados,i);
                break;
            case 7:
                genArchivoTxt(empleados,i);
                break;
            case 8:
                printArchTxt();
                break;
            case 9:
                genArchivoBin(empleados,i);
                break;
            case 10:
                if(cargBin)
                {
                    i=cargarArchivoBin(empleados,i);
                    if(i>2500)
                    {
                        ordenMetodo=1;
                    }
                    orden=0;
                    cargBin=0;
                }
                else
                {
                    printf("\nYa se ha cargado el archivo binario!\nRealice otra opcion!\n");
                }
                break;
            case 11:
                if(del>0)
                {
                    printDel();
                }
                else
                {
                    printf("\nAun no hay empleados eliminados\n");
                }
                break;
        }

        printf("\n");
    }while(op!=12);

    /*fa=fopen("datosbin.tmp","rb");
    if(fa)
    {
        fclose(fa);
        remove("datosbin.tmp");
    }*/
}



//case 1
int genReg(Tdato vect[],int i)
{
    int j;
    if(i+100<=REG)
    {
        for(j=0;j<100;j++)
        {
            genRegRand(vect,i++);   
        }
        printf("\nSe generaron 100 registros\n");
    }
    else
    {
        if(i==REG)
        {
            printf("\nNo se pueden generar mas registros\n");
        }
        else
        {
            if(i+100>REG)
            {
                for(i;i<REG;i++)
                {
                    genRegRand(vect,i);   
                }
                printf("\nNo se pueden generar 100 registros\n");
                printf("\nSe generaron registros hasta llegar al limite\n");
            }   
        }
    }
    return i;
}

void genRegRand(Tdato vect[],int i)
{
    int s;
    int j;
    double num;
    vect[i].status=1;
    vect[i].key=genKey(vect,i,300000,399999);

    for(j=0;j<10;j++)
    {
        s=rand()%2;
    }

    if(s)
    {
        vect[i].sexo='H';
    }
    else
    {
        vect[i].sexo='M';
    }

    if(s)
    {
        genH_Name(vect,i);
    }
    else
    {
        genM_Name(vect,i);
    }

    genAp(vect,i);

    do
    {
        num=6460000000+(rand()%100000)+(rand()%99)*100000;
    }while(buscarTelefono(vect,i,num)!=-1);
    vect[i].telefono=num;

    genPuesto(vect,i);

}

void genPuesto(Tdato vect[],int i)
{
    char pst[12][L]={
        "OPERADOR","SUPERVISOR","MANTENIMIENTO","INGENIERO DE PROCESOS","INGENIERO DE CALIDAD",
        "OPERADOR DE MAQUINARIA", "ALMACENISTA", "JEFE DE ALMACEN", "INSPECTOR DE CALIDAD", 
        "GERENTE DE PRODUCCION", "TECNICO EN SEGURIDAD", "RECURSOS HUMANOS"
    };
    strcopy(vect[i].puesto,pst[(rand()%12)]);
}

int buscarTelefono(Tdato vect[],int i,double num)
{
    int j;
    for(j=0;j<i;j++)
    {
        if(vect[j].telefono==num)
        {
            return j;
        }
    }
    return -1;
}

//case 2
void editarReg(Tdato vect[],int i,int orden)
{
    int pos;
    int edit;
    if(i>0)
    {
        printf("Editar empleado\n\n");
        pos=validNum("Ingrese el numero de emplado que desea editar: ",300000,399999);
        if(orden)
        {
            pos=buscarTBin(vect,i,pos);
            if(pos!=-1)
            {
                if(vect[pos].status)
                {
                    printEmpleadoReg(vect[pos]);
                    editMenu(vect,pos);
                }
                else
                {
                    printf("\nEse empleado fue eliminado de los registros\n");
                }
            }
            else
            {
                printf("\nEse empleado no existe\n");
            }
        }
        else
        {
            pos=buscarTSec(vect,i,pos);
            if(pos!=-1)
            {
                if(vect[pos].status)
                {
                    printEmpleadoReg(vect[pos]);
                    editMenu(vect,pos);
                }
                else
                {
                    printf("\nEse empleado fue eliminado de los registros\n");
                }
            }
            else
            {//322010
                printf("\nEse empleado no existe\n");
            }
        }
    }
    else
    {
        printf("\nAun no hay empleados registrados\n");
    }
}

void editMenu(Tdato vect[],int pos)
{
    int op;
    int s;
    int j;
    char num[11];
    printf("\nEditar\n\n");
    printf("1) Puesto\n");
    printf("2) Nombre\n");
    printf("3) Apellido Paterno\n");
    printf("4) Apellido Materno\n");
    printf("5) Telefono\n");
    printf("6) Sexo\n");
    printf("7) Salir\n");
    op=validNum("Esoge una opcion: ",1,7);
    switch(op)
    {
        case 1:
            printf("Editar puesto\n\n");
            editPuesto(vect,pos);
            printf("\nSe edito el campo deseado\n");
            break;
        case 2:
            printf("Editar nombre\n\nIngresa el nuevo nombre: ");
            validStr(vect[pos].nombre);
            printf("\nSe edito el campo deseado\n");
            break;
        case 3:
            printf("Editar apellido paterno\n\nIngresa el nuevo apellido: ");
            validStr(vect[pos].apPat);
            printf("\nSe edito el campo deseado\n");
            break;
        case 4:
            printf("Editar apellido materno\n\nIngresa el nuevo apellido: ");
            validStr(vect[pos].apMat);
            printf("\nSe edito el campo deseado\n");
            break;
        case 5:
            printf("Editar telefono\n\n");
            vect[pos].telefono+=validNumF("Ingresa el telefono: 646",0,9999999);
            printf("\nSe edito el campo deseado\n");
            break;
        case 6:
            printf("Editar sexo\n\n");
            s=validNum("(1:Hombre 2:Mujer) Elige una opcion: ",1,2);
            if(s==1)
            {
                vect[pos].sexo='H';
            }
            else
            {
                vect[pos].sexo='M';
            }
            printf("\nSe edito el campo deseado\n");
            break;
    }
    
}
//308895 312946
void editPuesto(Tdato vect[],int pos)
{
    char pst[12][L]={
        "OPERADOR","SUPERVISOR","MANTENIMIENTO","INGENIERO DE PROCESOS","INGENIERO DE CALIDAD",
        "OPERADOR DE MAQUINARIA", "ALMACENISTA", "JEFE DE ALMACEN", "INSPECTOR DE CALIDAD", 
        "GERENTE DE PRODUCCION", "TECNICO EN SEGURIDAD", "RECURSOS HUMANOS"
    };
    
    printf("1) Operador\n");
    printf("2) Supervisor\n");
    printf("3) Mantenimiento\n");
    printf("4) Ingeniero de Procesos\n");
    printf("5) Ingeniero de Calidad\n");
    printf("6) Operador de Maquinaria\n");
    printf("7) Almacenista\n");
    printf("8) Jefe de Almacen\n");
    printf("9) Inspector de Calidad\n");
    printf("10) Gerente de Produccion\n");
    printf("11) Tecnico en Seguridad\n");
    printf("12) Recursos Humanos\n");
    strcopy(vect[pos].puesto,pst[validNum("Escoge una opcion: ",1,12)-1]);
}

float validNumF(char txt[],int limi,int lims)
{
    char r[STR];
    int rfloat;
    do
    {
        printf("%s",txt);
        fflush(stdin); 
        gets(r);
        rfloat=atof(r);
        if(rfloat<limi || rfloat>lims)
        {
            printf("Valor invalido, ingresalo de nuevo\n");
        }
    }while(rfloat<limi || rfloat>lims);
    return rfloat;
}

//case 3
int eliminarEmpleado(Tdato vect[],int i,int orden)
{
    int pos;
    int del;
    if(i>0)
    {
        printf("Eliminar empleado\n\n");
        pos=validNum("Ingrese el numero de emplado que desea eliminar: ",300000,399999);
        if(orden)
        {
            pos=buscarTBin(vect,i,pos);
            if(pos!=-1)
            {
                if(vect[pos].status)
                {
                    printEmpleadoReg(vect[pos]);
                    printf("\nDesea eliminar al empleado? (1:Si 2:No)\n");
                    del=validNum("Escoge una opcion: ",1,2);
                    if(del==1)
                    {
                        vect[pos].status=0;
                        return 1;
                    }
                }
                else
                {
                    printf("\nEse empleado ya fue eliminado de los registros\n");
                }
            }
            else
            {
                printf("\nEse empleado no existe\n");
            }
        }
        else
        {
            pos=buscarTSec(vect,i,pos);
            if(pos!=-1)
            {
                if(vect[pos].status)
                {
                    printEmpleadoReg(vect[pos]);
                    printf("\nDesea eliminar al empleado? (1:Si 2:No)\n");
                    del=validNum("Escoge una opcion: ",1,2);
                    if(del==1)
                    {
                        vect[pos].status=0;
                        return 1;
                    }
                }
                else
                {
                    printf("\nEse empleado ya fue eliminado de los registros\n");
                }
            }
            else
            {
                printf("\nEse empleado no existe\n");
            }
        }
    }
    else
    {
        printf("\nAun no hay empleados registrados\n");
    }
    return 0;
}

//case 4
void buscarEmpleado(Tdato vect[],int i,int orden)
{
    int pos;
    if(i>0)
    {
        printf("Buscar empleado\n\n");
        pos=validNum("Ingrese el numero de empleado que desea buscar: ",300000,399999);
        if(orden)
        {
            pos=buscarTBin(vect,i,pos);
            if(pos!=-1)
            {
                if(vect[pos].status)
                {
                    printEmpleadoReg(vect[pos]);
                }
                else
                {
                    printf("\nEse empleado fue eliminado de los registros\n");
                }
            }
            else
            {
                printf("\nEse empleado no existe\n");
            }
        }
        else
        {
            pos=buscarTSec(vect,i,pos);
            if(pos!=-1)
            {
                if(vect[pos].status)
                {
                    printEmpleadoReg(vect[pos]);
                }
                else
                {
                    printf("\nEse empleado fue eliminado de los registros\n");
                }
            }
            else
            {
                printf("\nEse empleado no existe\n");
            }
        }
    }
    else
    {
        printf("\nAun no hay empleados registrados\n");
    }
}

void printEmpleadoReg(Tdato empleado)
{
    printf("Status: %d\n",empleado.status);
    printf("\nNo. Empleado: %d\n",empleado.key);
    printf("Puesto: %s\n",empleado.puesto);
    printf("Apellido Paterno: %s\n",empleado.apPat);
    printf("Apellido Materno: %s\n",empleado.apMat);
    printf("Nombre: %s\n",empleado.nombre);
    printf("Telefono: %.0f\n",empleado.telefono);
    printf("Sexo: ");
    if(empleado.sexo=='H')
    {
        printf("MASCULINO");
    }
    else
    {
        printf("FEMENINO");
    }
    printf("\n");
}

//case 5
int ordenEmpleado(Tdato vect[],int i,int ordenM)
{
    if(i>0)
    {
        if(ordenM)
        {
            burbuja(vect,i);
        }
        else
        {
            seleccion(vect,i);
        }
        printf("\nSe ordenaron los empleados\n");
        return 1;
    }
    else
    {
        printf("\nAun no hay empleado registrados\n");
        return 0;
    }
}


//case 6
void printEmpleados(Tdato vect[],int i)
{
    int j,k=0;
    if(i>0)
    {      
        printf("| No   |STATUS|No. Empleado|         Puesto         | Apellido Paterno | Apellido Materno | Nombre               |  Telefono  |  Sexo    |\n");
        for(j=0;j<i;j++)
        {
            printf("| %4d ",k);
            printEmpleadoTab(vect[j]);
            k++;
        
        }
    }
    else
    {
        printf("\nAun no hay empleado registrados\n");
    }
}

void printEmpleadoTab(Tdato empleado)
{
    printf("| %4d |%11d | %-22s | %-16s | %-17s| %-20s | %.0f |",empleado.status,empleado.key,empleado.puesto,empleado.apPat,empleado.apMat,empleado.nombre,empleado.telefono);
    if(empleado.sexo=='H')
    {
        printf(" MASCULINO |\n");
    }
    else
    {
        printf(" FEMENINO  |\n");
    }
}

//case 7
void genArchivoTxt(Tdato vect[],int i)
{
    FILE *fa;
    int j,k;
    int len;
    char name[L];
    printf("Generar archivo\n\n");
    if(i>0)
    {
        printf("Ingresa el nombre del archivo de texto: ");
        gets(name);
        len=strlen(name);
        name[len++]='.';
        name[len++]='t';
        name[len++]='x';
        name[len++]='t';
        name[len]='\0';
        
        fa=fopen(name,"r");
        if(!fa)
        {
            fa=fopen(name,"a");
            fprintf(fa,"| No   |STATUS| No.Empleado |         Puesto        | Apellido Paterno | Apellido Materno | Nombre               |  Telefono  |   Sexo   |\n");
            k=0;
            for(j=0;j<i;j++)
            {
                if(vect[j].status)
                {
                    fprintf(fa,"| %4d ",k);
                    fprintf(fa,"| %4d | %11d |%-22s | %-16s | %-17s| %-20s | %.0f |",vect[j].status,vect[j].key,vect[j].puesto,vect[j].apPat,vect[j].apMat,vect[j].nombre,vect[j].telefono);
                    if(vect[j].sexo=='H')
                    {
                        fprintf(fa," MASCULINO |\n");
                    }
                    else
                    {
                        fprintf(fa," FEMENINO  |\n");
                    }
                    k++;
                }
            }
            printf("\nSe genero el archivo: %s\n",name);
            fclose(fa);
        }
        else
        {
            fclose(fa);
            printf("\nYa existe un archivo con ese nombre\n");
        }
    }
    else
    {
        printf("\nAun no hay empleados registrados\n");
    }
}

//case 8
void printArchTxt(void)
{
    FILE *fa;
    char name[L];
    int len;
    char c;
    printf("Mostrar archivo\n\n");
    printf("Ingresa el nombre del archivo de texto: ");
    gets(name);
    len=strlen(name);
    name[len++]='.';
    name[len++]='t';
    name[len++]='x';
    name[len++]='t';
    name[len]='\0';
    
    fa=fopen(name,"r");
    if(fa)
    {
        printf("\n %s\n\n",name);
        do
        {
            c=fgetc(fa);
            printf("%c",c);
        }while(!feof(fa));
        fclose(fa);
    }
    else
    {
        printf("\nEl nombre no coincide con un archivo existente\n");
    }
}

//case 9
void genArchivoBin(Tdato vect[],int i)
{
    FILE *fa;
    int j;
    if(i>0)
    {
        fa=fopen("datosbin.dll","rb");
        if(fa)
        {
            fclose(fa);
            fa=fopen("datosbin.tmp","rb");
            if(fa)
            {
                remove("datosbin.tmp");
                rename("datosbin.dll","datosbin.tmp");
                fa=fopen("datosbin.dll","wb");
                for(j=0;j<i;j++)
                {
                    fwrite(&vect[j],sizeof(Tdato),1,fa);
                }
                fclose(fa);
            }
            else
            {
                rename("datosbin.dll","datosbin.tmp");
                fa=fopen("datosbin.dll","wb");
                for(j=0;j<i;j++)
                {
                    fwrite(&vect[j],sizeof(Tdato),1,fa);
                }
                fclose(fa);
            }
        }
        else
        {
            fa=fopen("datosbin.dll","ab");
            for(j=0;j<i;j++)
            {
                fwrite(&vect[j],sizeof(Tdato),1,fa);
            }
            fclose(fa);
        }
        printf("\nSe genero el archivo binario\n");
    }
    else
    {
        printf("\nAun no hay empleados registrados\n");
    }
}

//case 10
int cargarArchivoBin(Tdato vect[],int i)
{
    FILE *fa;
    int j;
    fa=fopen("datosbin.dll","rb");
    if(fa)
    {
        j=0;
        while(!feof(fa))
        {
            fread(&vect[j],sizeof(vect[j]),1,fa);
            j++;
        }
        printf("\nSe cargo el archivo binario datos.dll a los registros\n");
        fclose(fa);
        return j;
    }
    else
    {
        printf("\nEl archivo binario a cargar no existe\n");
    }
    return 0;
}

//case 11
void printDel(void)
{
    FILE *fa;
    Tdato reg;
    int k;
    fa=fopen("datosbin.dll","rb");
    if(fa)
    {
        printf("\nEmpleados eliminados\n\n");
        printf("| No   |STATUS| No.Empleado |         Puesto         | Apellido Paterno | Apellido Materno | Nombre               |  Telefono  |  Sexo   |\n");
        k=0;
        while(!feof(fa))
        {
            fread(&reg,sizeof(Tdato),1,fa);
            if(reg.status != 1)
            {
                printf("| %4d ",k);
                printEmpleadoTab(reg);
                k++;
            }
        }
        fclose(fa);
    }
    else
    {
        printf("\nAun no hay un archivo binario\n");
    }
}