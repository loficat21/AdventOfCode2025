#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int numPlaces(long int n);

// new helper: returns 1 if n is made of repeated digit-blocks, else 0
int isRepeatedPattern(long int n) {
    char buf[32];
    sprintf(buf, "%ld", n);
    int len = (int)strlen(buf);

    // try all possible block lengths
    for (int block = 1; block <= len / 2; ++block) {
        if (len % block != 0) continue; // must divide length exactly

        int ok = 1;
        for (int i = block; i < len; ++i) {
            if (buf[i] != buf[i - block]) {
                ok = 0;
                break;
            }
        }
        if (ok) {
            // built from repeating buf[0..block-1]
            return 1;
        }
    }
    return 0;
}

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

                if (isRepeatedPattern(i)) {
                    total += i;
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