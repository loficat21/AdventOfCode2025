#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE* fptr;
    fptr = fopen("input.txt", "r");

    if (fptr == NULL) {
        printf("Failed to open file.");
    } else {

        int counter = 0;
        int curr = 50; // start at 50
        char line[20]; // instructions to move
        while(fgets(line, 20, fptr) != NULL) {
            int value = strtol(line + 1, NULL, 10); // shift by this value; line + 1 means we skip direction (L/R) since line is a pointer

            if (line[0] == 'L') { // comparing ascii codes here, literally
                // Part 2 Logic:
                int c = curr - value;
                if (c < 0) {
                    while(c < 0) {
                        c += 100;
                        counter++;
                    }
                }
                // Part 1 Logic:
                curr = (curr - value) % 100;
                if (curr < 0) {
                    curr += 100;
                }
            }
            else { // move to right
                // Part 2 Logic:
                int c = curr + value;
                if (c > 100) {
                    while(c > 100) {
                        c -= 100;
                        counter++;
                    }
                }
                // Part 1 Logic:
                curr = (curr + value) % 100;
            }

            printf("Current Position: %d\n", curr);
            if (curr == 0) {
                ++counter;
            }
        }

        printf("%d\n", counter);
        fclose(fptr);
    }

    return 0;
}