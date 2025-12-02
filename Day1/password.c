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
            int dir = (line[0] == 'R') ? +1 : -1;
            
            for (int i = 0; i < value; i++) {
                curr = (curr + dir + 100) % 100;
                if (curr == 0) {
                    ++counter;
                }   
            }            
        }

        printf("%d\n", counter);
        fclose(fptr);
    }

    return 0;
}