#include <stdio.h>
#include <stdlib.h>

/* The main program */
int main(int argc, char *argv[])
{
    int N = 0;
    int i = 0;
    int k = 0;
    int j = 0;
    int count = 0;
    int status;
    status = scanf("%d", &N);
    while (status == 1) {//scanf_s
        count = 0;
        k = 0;
        if (N == 0) break;
        for (j = 2; j<N; j++) {
            if (N % j == 0)
                count++;
        }
        if (N < 0) {
            fprintf(stderr, "Error: Chybny vstup!\n");
            return 100;
        }
        if (N == 1) {
            printf("Prvociselny rozklad cisla %d je:\n%d\n", N, N);
        }
        if (N != 1) {
            printf("Prvociselny rozklad cisla %d je:\n", N);
            for (i = 2; i*i <= N; i++) {
                if (N%i == 0) {
                    if (i >= 3 && k >= 1)
                        printf(" x %d", i);
                    else
                        printf("%d", i);
                    for (k = 0; N%i == 0; k++) {
                        N /= i;
                    }
                    if (k >= 2) {
                        printf("^%d", k);
                    }
                    if (N == 1)
                        printf("\n");
                }
            }

            if (N>1) {
                if (count == 0)
                    printf("%d\n", N);
                else
                    printf(" x %d\n", N);
            }
        }
        status = scanf("%d", &N);
    }
    if (status == 0) {
        fprintf(stderr, "Error: Chybny vstup!\n");
        return 100;
    }

    return 0;
}