//Ochoa Angulo Luis Fernando 372746
//10-09-23    10-09-23
//Algoritmo que encuentra el numero de en medio y su valor
//LFOA_Act5_05_432

#include<stdio.h>

int main()
{
     int num1,num2,num3;
     printf("Cual es el primer numero: ");
     scanf("%d",&num1);
     printf("Cual es el segundo numero: ");
     scanf("%d",&num2);
     printf("Cual es el tercer numero: ");
     scanf("%d",&num3);

     if(num1 > num2 and num1 > num3)
     {
          if(num2 > num3)
          {
               printf("\nEl de numero de en medio es: %d",num2);          
          }
          else
          {
               printf("\nEl de numero de en medio es: %d",num3);        
          }
     }
     if(num2 > num1 and num2 > num3)
     {
          if(num1 > num3)
          {
               printf("\nEl de numero de en medio es: %d",num1);                  
          }
          else
          {
               printf("\nEl de numero de en medio es: %d",num3);        
          }
     }
     if(num3 > num1 and num3 > num2)
     {
          if(num1 > num2)
          {
               printf("\nEl de numero de en medio es: %d",num1);                  
          }
          else
          {
               printf("\nEl de numero de en medio es: %d",num2);        
          }
     }
    return 0;
}