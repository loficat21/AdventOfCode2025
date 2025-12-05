#include <stdio.h>
#include <string.h>

int main() {
    FILE* fptr;
    fptr = fopen("input.txt", "r");

    if (fptr == NULL) {
        printf("File loading failed");
    }

    char line[140];
    int arr[142][142] = {0}; // extra zero buffer around the grid

    int rowCount = 0;
    int cols = 0;
    while(fgets(line, 140, fptr)) {
        int lineCols = (int)strcspn(line, "\n"); // length of data line without \n
        cols = lineCols;

        for(int i = 0; i < lineCols; i++) {
            if (line[i] == '@') {
                arr[rowCount + 1][i + 1] = 1;
            } else {
                arr[rowCount + 1][i + 1] = 0;
            }
        }
        ++rowCount;
    }

    // print array including the buffer rows/cols
    // for (int r = 0; r < rowCount + 2; r++) {
    //     for (int c = 0; c < cols + 2; c++) {
    //         printf("%d", arr[r][c]);
    //     }
    //     printf("\n");
    // }

    int total = 0;
    for(int i = 1; i < rowCount + 1; i++) {
        for(int j = 1; j < cols + 1; j++) {

            if (arr[i][j] == 1) { // if roll of paper, check 8 neighbours

                int count = 0;
                for(int k = -1; k <= 1; k++) {
                    for(int l = -1; l <= 1; l++) {
                        if (arr[i+k][j+l] == 1 && (k != 0 || l != 0)) {
                            count++;
                        }
                    }
                }
                
                if (count < 4) {
                    total++;
                }

            }
        }
    }



    printf("%d\n", total);
    fclose(fptr);
}




// helper function that counts num paper rolls around positon i, j
