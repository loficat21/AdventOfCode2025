// read all 5 lines with fgets
// loop through each line in steps of four, saving each four chars into separate array and running atoi on it
// save these four values in array[6] that starts with a number defining * or +
// do the actual calculation

#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE* fptr;
    fptr = fopen("input.txt", "r");

    if (fptr == NULL) {
        printf("File loading failed");
    }


    // READING IN NUMERICAL VALUES:
    int values[2000][4];
    int rowCount = 0;
    int totalCols = 0;
    
    for (int i = 0; i < 4; i++) {
        char line[4000];
        fgets(line, 4000, fptr);
        char *p = line;
        int consumed;
        
        int colCount = 0;
        while (sscanf(p, "%d%n", &values[colCount][i], &consumed) == 1) {
            printf("%d ", values[colCount][i]);
            colCount++;
            p += consumed;
        }
        totalCols = colCount;
        printf("\n");
    }


    // READING IN OPERATIONS:
    char line[4000];
    fgets(line, 4000, fptr);

    char ops[2000];
    char *p = line;
    int consumed;
    int colCount = 0;

    while (sscanf(p, " %c%n", &ops[colCount], &consumed) == 1) { // that leerzeichen makes sscanf skip whitespace before any character
        printf("%c", ops[colCount]);
        colCount++;
        p += consumed;
    }

    // ACTUAL MATH:
    unsigned long long total = 0;
    printf("\n%d\n", totalCols);

    for (int i = 0; i < totalCols; i++) {

        if (ops[i] == '+') {
            unsigned long colSum = values[i][0];
            for (int j = 1; j < 4; j++) {
                colSum += values[i][j];
            }
            total += colSum;

        } else if (ops[i] == '*') {
            unsigned long long colMult = values[i][0];
            for (int j = 1; j < 4; j++) {
                colMult *= values[i][j];
            }
            total += colMult;

        } else {
            printf("how did we end up here..\n");
        }

    }

    printf("%lld\n", total);

    fclose(fptr);
}