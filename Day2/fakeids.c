#include <stdio.h>
#include <stdlib.h>

int numPlaces(long int n);

int main() {
    FILE* fptr;
    fptr = fopen("input.txt", "r");
    
    if (fptr == NULL) {
        printf("File loading failed");
    } else {

        unsigned long int currStart;
        unsigned long int currEnd;
        unsigned long long int total = 0;

        while (fscanf(fptr, "%lu-%lu,", &currStart, &currEnd) == 2) { //fscanf returns an int value of nums it wrote to
            printf("currStart: %lu ", currStart);
            printf("and CurrEnd: %lu\n", currEnd);
            
            // loop over every number including two edge cases
            for (long int i = currStart; i <= currEnd; i++) {

                int size = numPlaces(i); // num digits in i
                int half = size / 2;

                // divide each number in half and subtract sides by eachother 
                long p = 1;
                for (int k = 0; k < half; k++) { p *= 10; }

                long int left, right;
                if (size % 2 == 0) {
                    left = i / p;
                    right = i % p;
                    // if == 0 then add this number to total:
                    if (left - right == 0) {
                        printf("Original Number: %lu and its left and right: %lu %lu\n", i, left, right);
                        total += i;
                    }
                }

                
            }
        }

        fclose(fptr);
        printf("Total: %llu\n", total);
    }
}

int numPlaces(long int n) {
    if (n < 10) return 1;
    if (n < 100) return 2;
    if (n < 1000) return 3;
    if (n < 10000) return 4;
    if (n < 100000) return 5;
    if (n < 1000000) return 6;
    if (n < 10000000) return 7;
    if (n < 100000000) return 8;
    if (n < 1000000000) return 9;
    return 10;
}