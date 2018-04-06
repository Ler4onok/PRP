#include <stdio.h>
#define SIZE 255

int main() {
    int num = 0;
    int even = 0;
    int uneven = 0;
    int quantity = 0;
    float quantity_f = 0.0;
    int positive = 0;
    int negative = 0;
    int maximum = -10000;
    int minimum = 10000;
    int sum = 0;
    int index = 0;
    int mas[SIZE];

    while (scanf ("%d ", &num) ==1 /* != EOF*/) {
        if (num > 10000 || num < -10000){
            for(index = 0; index < quantity; index++)
            {
                printf("%d", mas[index]);
                if (index != quantity-1)
                    printf(", ");
            }
            printf("\nError: Vstup je mimo interval!\n");
            return 100;
        }
        if(maximum < num)
            maximum = num;
        if(minimum > num)
            minimum = num;

        sum += num;
        mas[index] = num;
        index++;
        quantity++;

        if(num > 0)
            positive++;
        if(num < 0)
            negative++;

        if(num%2 == 0)
            even++;
        else
            uneven++;
    }

    for(index = 0; index < quantity; index++)
    {
        printf("%d", mas[index]);
        if (index != quantity-1)
            printf(", ");
    }
    printf("\nPocet cisel: %d\n", quantity);
    printf("Pocet kladnych: %d\n", positive);
    printf("Pocet zapornych: %d\n", negative);
    quantity_f = quantity;
    printf("Procento kladnych: %.2f\n", (positive/quantity_f)*100);
    printf("Procento zapornych: %.2f\n", (negative/quantity_f)*100);
    printf("Pocet sudych: %d\n", even);
    printf("Pocet lichych: %d\n", uneven);
    printf("Procento sudych: %.2f\n", (even/quantity_f)*100);
    printf("Procento lichych: %.2f\n", (uneven/quantity_f)*100);
    printf("Prumer: %.2f\n", sum/quantity_f);
    printf("Maximum: %d\n", maximum);
    printf("Minimum: %d\n", minimum);

    return 0;
}
