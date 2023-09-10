//Ochoa Angulo Luis Fernando 372746
//10-09-23    10-09-23
//Algoritmo que encuentra el numero mayor y su valor
//LFOA_Act5_04_432

#include<stdio.h>

int main()
{
    int num1,num2,num3;
    printf("Valor del primer numero: ");
    scanf("%d",&num1);
    printf("Valor del segundo numero: ");
    scanf("%d",&num2);
    printf("Valor del tercer numero: ");
    scanf("%d",&num3);
    
    if(num1 > num2 and num1 > num3)
    {
        printf("El mayor es el: %d",num1);
    }
    if(num2 > num1 and num2 > num3)
    {
        printf("El mayor es el: %d",num2);
    }
    if(num3 > num1 and num3 > num2)
    {
        printf("El mayor es el: %d",num3);
    }
}
