#include <stdio.h>
#include <string.h>

int main() {
    FILE* fptr;
    fptr = fopen("./input.txt", "r");

    if (fptr == NULL) {
        printf("File not opened.");
        return 1;
    }

    // recursion where we have array of length of one line: arr[l] 
    // base case: arr[position of S] = 1, all others 0
    // whenever we're at currPos and get ^ and arr[currPos] = 1, we do total++, change arr[currPos] = 0 and set arr[currPos - 1] = 1 and arr[currPos + 1] = 1
    
    int arr[150] = { 0 };
    
    // Initialization: Finding S
    char read[150];
    fgets(read, 150, fptr);
    int n = strcspn(read, "\n");

    for (int i = 0; i < n; i++) {
        if (read[i] == 'S') {
            arr[i] = 1;
            printf("%d\n", i);
        }
    }

    int newArr[n];
    memset(newArr, 0, sizeof(newArr));

    long int total = 0;
    int rowCount = 1;
    while(fgets(read, 150, fptr)) {
        
        if (rowCount % 2 == 0) {
            
            for (int i = 0; i < n; i++) {
                if ((read[i] == '^') && (arr[i] == 1)) {
                    printf("Splitter: %d at row: %d\n", i, rowCount);
                    total++;
                    if (i > 0) newArr[i - 1] = 1;
                    if (i + 1 < n) newArr[i + 1] = 1;
                    arr[i] = 0;
                }
                
                if (arr[i] == 1) newArr[i] = 1;
            }

            memcpy(arr, newArr, sizeof(newArr));
            memset(newArr, 0, sizeof(newArr));
        }

        rowCount++;
    }

    printf("%ld\n", total);


    fclose(fptr);
}