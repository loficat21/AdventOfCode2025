#include <stdio.h>
#include <string.h>

int main() {
    FILE* fptr;
    fptr = fopen("input.txt", "r");
    
    if (fptr == NULL) {
        printf("File loading failed");
    } else {

        char line[120];
        int total = 0;
        while (fgets(line, 120, fptr)) {

            int largest = line[0];
            int largestPos = 0;
            int size = strcspn(line, "\n");

            for (int i = 1; i < (size - 1); i++) { // find largest digit first, not last digit
                if (line[i] >= '0' && line[i] <= '9' && line[i] > largest) {
                    largest = line[i];
                    largestPos = i;
                }
            }

            int secondLargest = 0;
            for (int i = largestPos + 1; i < size; i++) {
                if (line[i] >= '0' && line[i] <= '9' && line[i] > secondLargest) {
                    secondLargest = line[i];
                }
            }

            char highest[3];
            highest[0] = largest;
            highest[1] = secondLargest;
            highest[2] = '\0';

            int maxComb;
            sscanf(highest, "%d", &maxComb);
            total += maxComb;
            printf("Line: %s has highest: %d\n", line, maxComb);
        }
        printf("Total: %d\n", total);
        fclose(fptr);
    }
}


// code does not handle a few edge cases like: 00..001