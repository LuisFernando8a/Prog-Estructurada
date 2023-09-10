//Ochoa Angulo Luis Fernando 372746
//09-09-23    09-09-23
//Algoritmo que sirve para jugar PIEDRA, PAPEL o TIJERA contra la computadora
//LFOA_Act5_03_432

#include<stdio.h>
#include<cstdlib>
#define PIEDRA 1
#define PAPEL 2
#define TIJERA 3

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

    switch(j1)
    {
        case PIEDRA:
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
                    printf("\nElegiste piedra ");
                }
            }
        break;

        case PAPEL:
            if (cpu == 2)
            {
                printf("EMPATE");
            }
            else
            {
                if (cpu == 1)
                {
                    printf("\nJugador 1 gana");
                    printf("\nElegiste papel");
                }
                else
                {
                    printf("\nComputadora gana");
                    printf("\nComputadora eligio tijeras");
                }

            }
        break;

        case TIJERA:
            if (cpu == 3)
            {
                printf("EMPATE");
            }
            else
            {
                if (cpu == 1)
                {
                    printf("\nComputadora gana");
                    printf("\nComputadora eligio piedra");
                }
                else
                {
                    printf("\nJugador 1 gana");
                    printf("\nElegiste tijeras");
                }
            }
        break;

        default:
            printf("ERROR");

    }
    return 0;
}