//Ochoa Angulo Luis Fernando 372746
//10-09-23    10-09-23
//Algoritmo que lee 3 números y despliega los números en orden ascendente
//LFOA_Act5_06_432

#include<stdio.h>

int main()
{
    int num1, num2, num3, temp;
    printf("Dame el valor del primer numero: ");
    scanf("%d",&num1);
    printf("Dame el valor del segundo numero: ");
    scanf("%d",&num2);
    printf("Dame el valor del tercer numero: ");
    scanf("%d",&num3);

     if(num1 > num2 and num1 > num3)
     {
          if(num2 > num3)
          {
               printf("Los numeros en forma ascendente: ");
               printf("\n%d\n%d\n%d",num3,num2,num1);          
          }
          else
          {
                printf("Los numeros en forma ascendente: ");
                printf("\n%d\n%d\n%d",num2,num3,num1);
          }
     }
     if(num2 > num1 and num2 > num3)
     {
          if(num1 > num3)
          {
                printf("Los numeros en forma ascendente: ");
                printf("\n%d\n%d\n%d",num3,num1,num2);          
          }
          else
          {
                printf("Los numeros en forma ascendente: ");
                printf("\n%d\n%d\n%d",num1,num3,num2);
          }
     }
     if(num3 > num1 and num3 > num2)
     {
          if(num1 > num2)
          {
                printf("Los numeros en forma ascendente: ");
                printf("\n%d\n%d\n%d",num2,num1,num3);          
          }
          else
          {
                printf("Los numeros en forma ascendente: ");
                printf("\n%d\n%d\n%d",num1,num2,num3);
          }
    }

}
