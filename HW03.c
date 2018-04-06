#include <stdio.h>
#define SIZE 3
int main(void) {
    int sirka = 0;
    int vyska = 0;
    int plot = 0;
    int bottom_plot = 0;
    int i = 0;
    int ii = 0;
    int iii = 0;
    int j = 0;
    int jj = 0;
    int p1 = 0;
    int plot_sv = 0;
    int plot_true = 0;
    int da = 0;

    da = scanf("%d%d", &sirka, &vyska);
    if  (da != 2) {
        fprintf(stderr,"Error: Chybny vstup!\n");
        return 100;
    }

    if (sirka < 3 || sirka > 69 || vyska < 3 || vyska > 69) {
        fprintf(stderr,"Error: Vstup mimo interval!\n");
        return 101;

    }
    if (sirka%2 == 0) {
        fprintf(stderr, "Error: Sirka neni liche cislo!\n");
        return 102;
    }

    if(sirka == vyska){
        if (scanf("%d", &plot) == 0){
            fprintf(stderr,"Error: Chybny vstup!\n");
            return 100;
        }
        if (plot <= 0 || plot >= vyska) {
            fprintf(stderr, "Error: Neplatna velikost plotu!\n");
            return 103;
        }
    }

    for (i = 0; i < sirka/2; i++) {
        printf(" ");
    }
    printf("X\n");

    for (i = 1, j = sirka/2 - 1, jj = 1; i < sirka/2; i++, j--, jj=jj+2) {
        for (ii = 0; ii < j; ii++) {
            printf(" ");
        }
        printf("X");

        for(iii = 0; iii < jj; iii++){
            printf(" ");
        }
        printf("X\n");
    }

    for (i = 0; i < sirka; i++) {
        printf("X");
    }
    printf("\n");

    for (i = 0; i < vyska-2; i++) {
        if(plot > 0) {
            printf("X");
            if (i % 2 == 0) {
                for (ii = 1; ii < sirka - 1; ii++) {
                    if (ii % 2 == 0)
                        printf("*");
                    else
                        printf("o");
                }
            } else {
                for (ii = 1; ii < sirka - 1; ii++) {
                    if (ii % 2 == 0)
                        printf("o");
                    else
                        printf("*");
                }
            }
            printf("X");

            if (i > vyska - plot - 2) {
                if (i == vyska - plot - 1) {
                    plot_sv = plot;
                    if(plot_sv % 2 == 0) {
                        for (p1 = 1; p1 <= plot; p1++) {
                            if (p1 % 2 == 0) {
                                printf("|");
                            } else {
                                if (p1 != plot)
                                    printf("-");
                            }
                        }
                    } else {
                        for (p1 = 1; p1 <= plot; p1++) {
                            if (p1 % 2 == 0) {
                                printf("-");
                            } else {
                                if (p1 != plot)
                                    printf("|");
                            }
                        }
                        printf("|");
                    }
                } else {
                    for (p1 = 1; p1 <= plot; p1++) {
                        plot_sv = plot;
                        if(plot_sv % 2 == 0) {
                            if (p1 % 2 == 0)
                                printf("|");
                            else
                                printf(" ");
                        } else {
                            if (p1 % 2 == 0)
                                printf(" ");
                            else
                                printf("|");
                        }
                    }
                }
            }
        } else {
            printf("X");
            for(ii = 1; ii < sirka-1; ii++){
                printf(" ");
            }
            printf("X");
        }
        printf("\n");
    }

    for (i = 0; i < sirka; i++) {
        printf("X");
    }
    if(plot > 0) {
        plot_sv = plot;
        if(plot_sv % 2 == 0) {
            plot_true = plot;
            for (bottom_plot = 1; bottom_plot <= plot_true; bottom_plot++) {
                if (bottom_plot % 2 == 0)
                    printf("|");
                else {
                    if (bottom_plot != plot_true)
                        printf("-");
                }
            }
        } else {
            for (bottom_plot = 1; bottom_plot <= plot; bottom_plot++) {
                if (bottom_plot % 2 == 0)
                    printf("-");
                else {
                    if (bottom_plot != plot)
                        printf("|");
                }
            }
            printf("|");
        }
    }
   printf("\n");

    return 0;
}