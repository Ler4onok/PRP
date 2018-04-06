#include <stdio.h>
#include <stdlib.h>
void freeMemory(int **mas, int line);

int main() {

    char simbol;
    int line1 = 0;
    int line2 = 0;
    int column1 = 0;
    int column2 = 0;
    int **mas1 = NULL;
    int **mas2 = NULL;

//Ð’Ð?ÐµÐ´Ð¸N‚Ðµ N€Ð°Ð·ÐLÐµN€Ð?ÐlNN‚NS ÐzÐµN€Ð?ÐlÐlÐl ÐLÐ°NNÐ¸Ð?Ð°
    scanf("%d %d", &line1, &column1);

//Ð’N‹Ð´ÐµÐ»ÐµÐ?Ð¸Ðµ ÐzÐ°ÐLNZN‚Ð¸ ÐzÐlÐ´ 1-N‹Ða ÐLÐ°NNÐ¸Ð?
    mas1 = (int **)calloc(line1*column1, sizeof(int*));
    for (int i1 = 0; i1 < line1; i1++) {
        mas1[i1] = (int *)calloc(column1, sizeof(int));
    }

//Ð’Ð?ÐµÐ´Ð¸N‚Ðµ NTÐ»ÐµÐLÐµÐ?N‚N‹ 1-ÐlÐl ÐLÐ°NNÐ¸Ð?Ð°
    for (int ii = 0; ii < line1; ii++) {
        for (int jj = 0; jj < column1; jj++) {
            scanf("%d", &mas1[ii][jj]);
        }
    }
//Ð’Ð?ÐµÐ´Ð¸N‚Ðµ ÐsÐ°ÐLÐ°Ð?Ð´N? "+","-","*"
    scanf("%c", &simbol);
    scanf("%c", &simbol);
    //simbol = getchar();
    //printf("%d\n", simbol);

//Ð’Ð?ÐµÐ´Ð¸N‚Ðµ N€Ð°Ð·ÐLÐµN€Ð?ÐlNN‚NS Ð?N‚ÐlN€ÐlÐlÐl ÐLÐ°NNÐ¸Ð?Ð°
    scanf("%d %d", &line2, &column2);

//Ð’N‹Ð´ÐµÐ»ÐµÐ?Ð¸Ðµ ÐzÐ°ÐLNZN‚Ð¸ ÐzÐlÐ´ 2-ÐlÐa ÐLÐ°NNÐ¸Ð?
    mas2 = (int **)calloc(line2*column2, sizeof(int*));
    for (int i1 = 0; i1 < line2; i1++) {
        mas2[i1] = (int *)calloc(column2, sizeof(int));
    }

//Ð’Ð?ÐµÐ´Ð¸N‚Ðµ NTÐ»ÐµÐLÐµÐ?N‚N‹ 2-ÐlÐl ÐLÐ°NNÐ¸Ð?Ð°
    for (int ii = 0; ii < line2; ii++) {
        for (int jj = 0; jj < column2; jj++) {
            scanf("%d", &mas2[ii][jj]);
        }
    }
//Ð’N‹ÐzÐlÐ»Ð?ÐµÐ?Ð¸Ðµ ÐlÐzÐµN€Ð°N†N‹Ða N ÐLÐ°NNÐ¸Ð?Ð°ÐLÐ¸
    switch (simbol)
    {
    case '+':
        if (line1 == line2 && column1 == column2) {
            for (int ii = 0; ii < line1; ii++) {
                for (int jj = 0; jj < column1; jj++) {
                    mas1[ii][jj] = mas1[ii][jj] + mas2[ii][jj];
                }
            }
            //Ð’N‹Ð?ÐlÐ´ N€ÐµÐ·N?Ð»NSN‚Ð°N‚Ð° NÐ»ÐlÐ¶ÐµÐ?Ð¸NZ ÐLÐ°N‚N€Ð¸N†
            printf("%d %d\n", line1, column1);
            for (int ii = 0; ii < line1; ii++) {
                for (int jj = 0; jj < column1; jj++) {
                    printf("%d", mas1[ii][jj]);
                    if (jj < column1-1)
                        printf(" ");
                }
                printf("\n");
            }
        }
        else {
            fprintf(stderr, "Error: Chybny vstup!\n");
            freeMemory(mas1, line1);
            freeMemory(mas2, line2);
            return 100;
        }
        break;
    case '-':
        if (line1 == line2 && column1 == column2) {
            for (int ii = 0; ii < line1; ii++) {
                for (int jj = 0; jj < column1; jj++) {
                    mas1[ii][jj] = mas1[ii][jj] - mas2[ii][jj];
                }
            }
            //Ð’N‹Ð?ÐlÐ´ N€ÐµÐ·N?Ð»NSN‚Ð°N‚Ð° N€Ð°Ð·Ð?Ð¸N† ÐLÐ°N‚N€Ð¸N†
            printf("%d %d\n", line1, column1);
            for (int ii = 0; ii < line1; ii++) {
                for (int jj = 0; jj < column1; jj++) {
                    printf("%d", mas1[ii][jj]);
                    if(jj < column1-1)
                        printf(" ");
                }
                printf("\n");
            }
        }
        else {
            fprintf(stderr, "Error: Chybny vstup!\n");
            freeMemory(mas1, line1);
            freeMemory(mas2, line2);
            return 100;
        }
        break;
    case '*':
        if (column1 == line2) {
            int **mas_result = NULL;
            mas_result = (int **)calloc(line1*column2, sizeof(int*));
            for (int i1 = 0; i1 < line1; i1++) {
                mas_result[i1] = (int *)calloc(column2, sizeof(int));
            }
            int i = 0, j = 0, k = 0;
            for (i = 0; i < line1; i++)
            {
                for (j = 0; j < column2; j++)
                {
                    for (k = 0; k < line2; k++)
                    {
                        mas_result[i][j] += mas1[i][k] * mas2[k][j];
                    }
                }
            }
            //Ð’N‹Ð?ÐlÐ´ N€ÐµÐ·N?Ð»NSN‚Ð°N‚Ð° N?ÐLÐ?ÐlÐ¶ÐµÐ?Ð¸NZ ÐLÐ°N‚N€Ð¸N†
            printf("%d %d\n", line1, column2);
            for (int ii = 0; ii < line1; ii++) {
                for (int jj = 0; jj < column2; jj++) {
                    printf("%d", mas_result[ii][jj]);
                    if (jj < column2 - 1)
                        printf(" ");
                }
                printf("\n");
            }
            freeMemory(mas_result, line1);
        }
        else {
            fprintf(stderr, "Error: Chybny vstup!\n");
            freeMemory(mas1, line1);
            freeMemory(mas2, line2);
            return 100;
        }
        break;
    default:
        fprintf(stderr, "Error: Chybny vstup!\n");
        freeMemory(mas1, line1);
        freeMemory(mas2, line2);
        return 100;
    }

    freeMemory(mas1, line1);
    freeMemory(mas2, line2);

    return 0;
}

void freeMemory(int **mas, int line) {
    for (int i = 0; i < line; i++)
        free(mas[i]);
    free(mas);
}