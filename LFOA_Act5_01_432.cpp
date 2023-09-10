//Ochoa Angulo Luis Fernando 372746
//09-09-23    09-09-23
//Algoritmo que calcula el promedio y despliega un mensaje dependiendo la calificacion optimizado en forma de arbol
//LFOA_Act5_01_432

#include <stdio.h>

int main()
{
    float calif1, calif2, calif3, prom;
    printf("  CALCULADORA DE PROMEDIO  ");
    printf("\nIngrese la primer calificacion: ");
    scanf("%f",&calif1);
    printf("Ingrese la segunda calificacion: ");
    scanf("%f",&calif2);
    printf("Ingrese la tercer calificacion: ");
    scanf("%f",&calif3);

    prom = (calif1 + calif2 + calif3)/3;

    printf("Tu promedio es: %.2f",prom);

    if (prom < 80)
    {
        if(prom < 60)
        {
            if(prom < 30)
            {
                printf("\nRepetir");
            }
            else
            {
                printf("\nExtraordinario");
            }
        }
        else
        {
            if(prom < 70)
            {
                printf("\nSuficiente");
            }
            else
            {
                printf("\nRegular");
            }
        }
    }
    else
    {
        if(prom < 98)
        {
            if(prom < 90)
            {
                printf("\nBien");
            }
            else
            {
                printf("\nMuy bien");
            }
        }
        else
        {
            if(prom <= 100)
            {
                printf("\nExcelente");
            }
            else
            {
                printf("\nERROR");
            }
        }
    }
    return 0;
}