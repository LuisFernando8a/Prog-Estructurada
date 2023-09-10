//Ochoa Angulo Luis Fernando 372746
//10-09-23    10-09-23
//Algoritmo que lee 3 números y despliega los números en orden ascendente
//LFOA_Act5_07_432

#include<stdio.h>
#include<stdlib.h>

int mes();
void zodiaco();

int main()
{
    zodiaco();
}


int mes()
{
    int mes,dia;
    printf("Elige el numero segun corresponda al mes de tu nacimiento");
    printf("\n1) Enero");
    printf("\n2) Febrero");
    printf("\n3) Marzo");
    printf("\n4) Abril");
    printf("\n5) Mayo");
    printf("\n6) Junio");
    printf("\n7) Julio");
    printf("\n8) Agosto)");
    printf("\n9) Septiembre");
    printf("\n10) Octubre");
    printf("\n11) Noviembre");
    printf("\n12) Diciembre");
    printf("\nColoca el numero: ");
    scanf("%d",&mes);
    return (mes);
}
void zodiaco()
{
    int signo,dia; 
    signo = mes();
    printf("Cual es el dia de tu nacimiento? ");
    scanf("%d",&dia);
    switch (signo)
    {
    case 1:
        if(dia < 20)
        {
            printf("Eres Capricornio");
            printf("\nHoy, 10 de Septiembre de 2023 \n");
            printf("Los momentos difíciles duelen, y mucho, pero con calma todo reencuentra un camino diferente,");
            printf(" el ser humano está hecho para adaptarse a toda situación, así que no te preocupes.");
            printf(" En el amor todo pasa por momentos difíciles, es el caso para tu signo, pero después todo estará mejor.");
        }
        else
        {
            printf("Eres Acuario");
            printf("\nHoy, 10 de Septiembre de 2023 \n");
            printf("Acuario es uno de los signos que disfruta de la compañía de otra persona,");
            printf(" aunque en realidad todo ser humano necesite de ello. En todo caso,");
            printf(" Acuario, tu pareja está por llegar y será esa persona con quien podrás compartir todo lo que les gusta.");
        }
        break;
    case 2:
        if(dia <= 18)
        {
            printf("Eres Acuario");
            printf("\nHoy, 10 de Septiembre de 2023 \n");
            printf("Acuario es uno de los signos que disfruta de la compañía de otra persona,");
            printf(" aunque en realidad todo ser humano necesite de ello. En todo caso,");
            printf(" Acuario, tu pareja está por llegar y será esa persona con quien podrás compartir todo lo que les gusta.");
        }
        else
        {
            printf("Eres Piscis");
            printf("\nHoy, 10 de Septiembre de 2023 \n");
            printf("El amor se debe de disfrutar en su máximo esplendor, aprende de lo que no se dio");
            printf(" y renueva y hazlo mejor en esta nueva oportunidad.");
            printf(" En lo profesional estás en una muy buena etapa para ello.");
        }
        break;
    case 3:
        if(dia < 20)
        {
            printf("Eres Piscis");
            printf("\nHoy, 10 de Septiembre de 2023 \n");
            printf("El amor se debe de disfrutar en su máximo esplendor, aprende de lo que no se dio");
            printf(" y renueva y hazlo mejor en esta nueva oportunidad.");
            printf(" En lo profesional estás en una muy buena etapa para ello.");
        }
        else
        {
            printf("Eres Aries");
            printf("\nHoy, 10 de Septiembre de 2023 \n");
            printf("Días de éxitos en las relaciones amorosas se aproximan,"); 
            printf("prepárate para recibirlos puesto que las alegrías en pareja llegan en este momento.");
            printf("\nTus números son el 7 y el 18, haz buen uso de ellos y disfruta de lo bello del amor.");
        }
        break;
    case 4:
        if(dia <= 21)
        {
            printf("Eres Aries");
            printf("\nHoy, 10 de Septiembre de 2023 \n");
            printf("Días de éxitos en las relaciones amorosas se aproximan,"); 
            printf("prepárate para recibirlos puesto que las alegrías en pareja llegan en este momento.");
            printf("\nTus números son el 7 y el 18, haz buen uso de ellos y disfruta de lo bello del amor.");
        }
        else
        {
            printf("Eres Tauro");
            printf("\nHoy, 10 de Septiembre de 2023 \n");
            printf("La confianza y la estabilidad son dos cosas que se construyen con el tiempo y paso a paso.");
            printf(" No apresures la relación con la persona que acabas de conocer.");
            printf(" Cuida de tu salud, en especial de tu estomago que es el que siempre te causa malestares.");
        }
        break;
    case 5:
        if(dia < 21)
        {
            printf("Eres Tauro");
            printf("\nHoy, 10 de Septiembre de 2023 \n");
            printf("La confianza y la estabilidad son dos cosas que se construyen con el tiempo y paso a paso.");
            printf(" No apresures la relación con la persona que acabas de conocer.");
            printf(" Cuida de tu salud, en especial de tu estomago que es el que siempre te causa malestares.");

        }
        else
        {
            printf("Eres Geminis");
            printf("\nHoy, 10 de Septiembre de 2023 \n");
            printf("Estás en una muy buena etapa de tu vida, con salud inigualable,"); 
            printf(" saca provecho de ella y avanza en lo que tienes que programar y realizar. ");
            printf("\nTus números son el 2 y el 33, utilízalos este día.");
        }
        break;
    case 6:
        if(dia <= 21)
        {
            printf("Eres Gemenis");
            printf("\nHoy, 10 de Septiembre de 2023 \n");
            printf("Estás en una muy buena etapa de tu vida, con salud inigualable,"); 
            printf(" saca provecho de ella y avanza en lo que tienes que programar y realizar. ");
            printf("\nTus números son el 2 y el 33, utilízalos este día.");
        }
        else
        {
            printf("Eres Cancer");
            printf("\nHoy, 10 de Septiembre de 2023 \n");
            printf("El blanco es tu color para este día, ponlo entre tus ropas y utilízalo.");
            printf(" Un presente inesperado alegrará tu día, vendrá de una persona muy grata en tu vida.");
            printf(" Una oportunidad de mejora laboral está por llegar, ponte atento y saca provecho de esta situación");
            printf("\nTus números son el 5 y el 44.");
        }
        break;
    case 7:
        if(dia < 22)
        {
            printf("Eres Cancer");
            printf("\nHoy, 10 de Septiembre de 2023 \n");
            printf("El blanco es tu color para este día, ponlo entre tus ropas y utilízalo.");
            printf(" Un presente inesperado alegrará tu día, vendrá de una persona muy grata en tu vida.");
            printf(" Una oportunidad de mejora laboral está por llegar, ponte atento y saca provecho de esta situación");
            printf("\nTus números son el 5 y el 44.");
        }
        else
        {
            printf("Eres Leo");
            printf("\nHoy, 10 de Septiembre de 2023 \n");
            printf("En lo profesional tu signo pasa por un momento de ventajas a tu favor.");
            printf(" Saca provecho de ellas puesto que podrías mejorar tu situación con un empleo");
            printf(" mejor pagado y que te permita mostrar más de tus capacidades.");
        }
        break;
    case 8:
        if(dia <= 23)
        {
            printf("Eres Leo");
            printf("\nHoy, 10 de Septiembre de 2023 \n");
            printf("En lo profesional tu signo pasa por un momento de ventajas a tu favor.");
            printf(" Saca provecho de ellas puesto que podrías mejorar tu situación con un empleo");
            printf(" mejor pagado y que te permita mostrar más de tus capacidades.");
        }
        else
        {
            printf("Eres Virgo");
            printf("\nHoy, 10 de Septiembre de 2023 \n");
            printf("La vida está hecha de experiencias, y ");
            printf(" cada una es una enseñanza de la que se tiene que sacar provecho.");
            printf("Adopta una actitud más motivadora y aviéntate a ti mismo hacia adelante teniéndote confianza.");

        }
        break;
    case 9:
        if(dia <= 23)
        {
            printf("Eres Virgo");
            printf("\nHoy, 10 de Septiembre de 2023 \n");
            printf("La vida está hecha de experiencias, y ");
            printf(" cada una es una enseñanza de la que se tiene que sacar provecho.");
            printf("Adopta una actitud más motivadora y aviéntate a ti mismo hacia adelante teniéndote confianza.");
        }
        else
        {
            printf("Eres Libra");
            printf("\nHoy, 10 de Septiembre de 2023 \n");
            printf("Hoy tienes que estar atento, las ex parejas siempre guardan resentimientos, ");
            printf("una de ellas podría aparecer queriéndote lastimar.");
            printf(" Utiliza la cabeza para solucionar las cosas y evitar el conflicto."); 
            printf("\nTus números para este día son el 6 y el 99 ");          
        }
        break;
    case 10:
        if(dia <= 23)
        {
            printf("Eres Libra");
            printf("\nHoy, 10 de Septiembre de 2023 \n");
            printf("Hoy tienes que estar atento, las ex parejas siempre guardan resentimientos, ");
            printf("una de ellas podría aparecer queriéndote lastimar.");
            printf(" Utiliza la cabeza para solucionar las cosas y evitar el conflicto."); 
            printf("\nTus números para este día son el 6 y el 99 "); 
        }
        else
        {
            printf("Eres Escorpio");
            printf("\nHoy, 10 de Septiembre de 2023 \n");
            printf("Abre la mente y el corazón a los nuevos encuentros, porque por ahí puede estar la persona que estás buscando.");
            printf("Sal y relaciónate, porque ahí es en donde se conocerá a gente interesante,");
            printf(" además, el ser humano es sociable por naturaleza.");
        }
        break;
    case 11:
        if(dia <= 23)
        {
            printf("Eres Escorpio");
            printf("\nHoy, 10 de Septiembre de 2023 \n");
            printf("Abre la mente y el corazón a los nuevos encuentros, porque por ahí puede estar la persona que estás buscando.");
            printf("Sal y relaciónate, porque ahí es en donde se conocerá a gente interesante,");
            printf(" además, el ser humano es sociable por naturaleza.");
        }
        else
        {
            printf("Eres Sagitario");
            printf("\nHoy, 10 de Septiembre de 2023 \n");
            printf("Sal del espacio habitual, la vida es una aventura así que vívela");
            printf(" y aprovecha de lo nuevo que aprendas y descubras.");
            printf(" Este día estará lleno de sorpresas, o negativas o positivas, pero quedarás boquiabierto.");
        }
        break;
    case 12:
        if(dia <= 22)
        {
            printf("Eres Sagitario");
            printf("\nHoy, 10 de Septiembre de 2023 \n");
            printf("Sal del espacio habitual, la vida es una aventura así que vívela");
            printf(" y aprovecha de lo nuevo que aprendas y descubras.");
            printf(" Este día estará lleno de sorpresas, o negativas o positivas, pero quedarás boquiabierto.");
        }
        else
        {
            printf("Eres Capricornio");
            printf("\nHoy, 10 de Septiembre de 2023 \nDebes afrontar las cosas con más confianza,");
            printf("Los momentos difíciles duelen, y mucho, pero con calma todo reencuentra un camino diferente,");
            printf(" el ser humano está hecho para adaptarse a toda situación, así que no te preocupes.");
            printf(" En el amor todo pasa por momentos difíciles, es el caso para tu signo, pero después todo estará mejor.");
        }
        break;
    default:
        {
            printf("No elegiste bien tu Mes o Dia de nacimiento");
        }
        break;
    }
}