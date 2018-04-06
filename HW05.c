#include <stdlib.h>
#include <ctype.h>
#define ALPHA 52
#define SIZE 3
char * memory(char *str, int capacity);
char * rotate(char *original, int col, int offset);
int compare(char *str1, char *str2, int col);
void delete_two(char *str1, char *str2);
void delete_three(char *str1, char *str2, char *str3);

int main() {

    int weight[ALPHA];
    int i = 0, ii = 0;
    int j = 0, jj = 0;
    int col1 = SIZE;
    int col2 = SIZE;
    char *str1 = NULL;
    char *str2 = NULL;
    char *str_temp = NULL;

//    str1 = (char *)malloc(SIZE * sizeof(char));
    str1 = memory(str1, SIZE);
    str2 = memory(str2, SIZE);


    while ((str1[i] = getchar()) != '\n') {
        if (isalpha(str1[i]) == 0) {
            delete_two(str1, str2);
            fprintf(stderr,"Error: Chybny vstup!\n");
            return 100;
        }
        j++;
        if (++i == col1) {
            col1 = col1 + SIZE;
            str1 = memory(str1, col1);
        }
    }

    while ((str2[ii] = getchar()) != '\n') {
        if (isalpha(str2[ii]) == 0) {
            delete_two(str1, str2);
            fprintf(stderr,"Error: Chybny vstup!\n");
            return 100;
        }
        jj++;
        if (++ii == col2) {
            col2 = col2 + SIZE;
            str2 = memory(str2, col2);
        }
    }
    if (j != jj) {
        delete_two(str1, str2);
        fprintf(stderr, "Error: Chybna delka vstupu!\n");
        return 101;
    }

    str_temp = memory(str_temp, i+1);

    for (int k = 0; k < ALPHA; k++) {
//        strcpy(str_temp, str1);
        for (int kk = 0; kk < ii; kk++) {
            str_temp[kk] = str1[kk];
        }
        str_temp = rotate(str_temp, ii, k);
        weight[k] = compare(str_temp, str2, ii);
    }

    int temp = 0;
    int temp1 = 0;
    for (int p = 0; p < ALPHA; p++) {
        if (weight[p] > temp) {
            temp = weight[p];
            temp1 = p;
        }
    }

    str1 = rotate(str1, ii, temp1);
    for (i = 0; i < jj; i++)
        printf("%c", str1[i]);
    printf("\n");

    delete_three(str1, str2,str_temp);

    return 0;
}
char * memory(char *str, int capacity) {
//        printf("%d", capacity);
        if ((str = (char *)realloc(str, capacity * sizeof(char))) == NULL) {
            puts("Error!");
            exit(EXIT_FAILURE);
        }
        return str;
}
int compare(char *str1, char *str2, int col) {
    int equally = 0;
    for (int s = 0; s < col; s++) {
        if (str1[s] == str2[s])
            equally++;
    }
    return equally;
}
char * rotate(char *original, int col, int offset) {
    for (int i = 0; i < col; i++) {
        if(offset < 26){
            if (isupper(original[i])) {
                if((original[i] - 'A' - offset + 26) / 26 == 0){
                    original[i] = (original[i] - 'A' - offset + 26) % 26;
                    original[i] = original[i] + 'a';
                } else {
                    original[i] = (original[i] - 'A' - offset + 26) % 26;
                    original[i] = original[i] + 'A';
                }
            }
            else {
                if((original[i] - 'a' - offset + 26) / 26 == 0){
                    original[i] = (original[i] - 'a' - offset + 26) % 26;
                    original[i] = original[i] + 'A';
                } else{
                    original[i] = (original[i] - 'a' - offset + 26) % 26;
                    original[i] = original[i] + 'a';
                }
            }
        } else {
            if (isupper(original[i])) {
                int off = 0;
                off = offset - 26;
                if((original[i] - 'A' - off + 26) / 26 == 0){
                    original[i] = (original[i] - 'A' - off + 26) % 26;
                    original[i] = original[i] + 'A';
                } else {
                    original[i] = (original[i] - 'A' - off + 26) % 26;
                    original[i] = original[i] + 'a';
                }
            }
            else {
                int off = 0;
                off = offset - 26;
                if((original[i] - 'a' - off + 26) / 26 == 0){
                    original[i] = (original[i] - 'a' - off + 26) % 26;
                    original[i] = original[i] + 'a';
                } else {
                    original[i] = (original[i] - 'a' - off + 26) % 26;
                    original[i] = original[i] + 'A';
                }
            }
        }
    }
    return original;
}
void delete_two(char *str1, char *str2){
    free(str1);
    free(str2);
    str1 = NULL;
    str2 = NULL;
}
void delete_three(char *str1, char *str2, char *str3){
    free(str1);
    free(str2);
    free(str3);
    str1 = NULL;
    str2 = NULL;
    str3 = NULL;
}