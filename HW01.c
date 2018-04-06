#include <stdio.h>
#include <stdlib.h>

/* The main program */
int main(void)
{
    int a = 0;
    int b = 0;
    float c = 0;

    scanf ("%d%d", &a, &b);

    if ( 10000 >= a && a >= -10000 && 10000 >= b && b >= -10000 ) {
        printf("Desitkova soustava: %d %d\n", a, b);
        printf("Sestnactkova soustava: %x %x\n", a, b);
        printf("Soucet: %d + %d = %d\n", a, b, a + b);
        printf("Rozdil: %d - %d = %d\n", a, b, a - b);
        printf("Soucin: %d * %d = %d\n", a, b, a * b);
        if (b != 0)
            printf("Podil: %d / %d = %d\n", a, b, a/b);
        else
            printf("Nedefinovany vysledek!\n");
        c = a+b;
        printf("Prumer: %1.1f\n", c = (a+b)/2.0);

    } else
        printf("Vstup je mimo interval!\n");




    return 0;
}


