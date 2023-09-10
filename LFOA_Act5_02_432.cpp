//Ochoa Angulo Luis Fernando 372746
//09-09-23    09-09-23
//Algoritmo que sirve para jugar PIEDRA, PAPEL o TIJERA contra la computadora
//LFOA_Act5_02_432

#include<stdio.h>
#include<cstdlib>

int main()
{
    int j1, cpu;
    printf("Bienvenido al famoso PIEDRA, PAPEL o TIJERA");
    printf("\nElige ");
    printf("\n1)Piedra");
    printf("\n2)Papel");
    printf("\n3)Tijera");
    printf("\nIngresa lo que elegiras: ");
    scanf("%d", &j1);
    cpu = 1 + rand() % 3;
    if (j1 == 1)
    {
        if (cpu == 1)
        {
            printf("EMPATE");
        }
        else
        {
            if (cpu == 2)
            {
                printf("\nComputadora gana");
                printf("\nLa computadora eligio papel");
            }
            else
            {
                printf("\nJugador 1 gana");
                printf("\nElegiste piedra");
            }
        }    
    }

if (j1 == 2)
{
    if (cpu == 2)
    {
        printf("EMPATE");
    }
    else
    {
        if (cpu == 3)
        {
            printf("\nComputadora gana");
            printf("\nLa computadora eligio tijera");
        }
        else
        {
            printf("\nJugador 1 gana");
            printf("\nElegiste papel");
        }
    }
}
if (j1 == 3)
{    
    if (cpu == 3)
    {
        printf("EMPATE");
    }
    else
    {
        if (cpu == 1)
        {
            printf("\nComputadora gana");
            printf("\nLa computadora eligio piedra");
        }
        else
        {
            printf("\nJugador 1 gana");
            printf("\nElegiste tijera");
        }
    }
}
return 0;
}