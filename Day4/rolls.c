#include <stdio.h>
#include <string.h>

int removePaper(int arr[142][142], int rowCount, int cols);

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
    
    fclose(fptr);

    // print array including the buffer rows/cols
    // for (int r = 0; r < rowCount + 2; r++) {
    //     for (int c = 0; c < cols + 2; c++) {
    //         printf("%d", arr[r][c]);
    //     }
    //     printf("\n");
    // }

    int grandTotal = 0;
    while(1) {
        int removed = removePaper(arr, rowCount, cols);
        if (removed == 0) break;
        grandTotal += removed;
    }

    printf("%d\n", grandTotal);
}


int removePaper(int arr[142][142], int rowCount, int cols) {

    int toRemove[142][142] = {0};  // mark cells to remove this round
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
                    toRemove[i][j] = 1;
                }

            }
        }
    }

    // now actually remove the marked rolls
    for (int i = 1; i < rowCount + 1; i++) {
        for (int j = 1; j < cols + 1; j++) {
            if (toRemove[i][j]) {
                arr[i][j] = 0;
                total++;
            }
        }
    }

    return total;
}