#include <stdio.h>
#include <string.h>

int main() {
    FILE* fptr;
    fptr = fopen("input.txt", "r");

    if (fptr == NULL) {
        printf("File loading failed");
    } else {

        char line[120];
        long long int total = 0;
        int keep = 12;
        while (fgets(line, 120, fptr)) {

            int size = strcspn(line, "\n");
            int drop = size - 12;

            char out[120];
            int outLength = 0;

            for (int i = 0; i < size; i++) {

                while (outLength > 0 && drop > 0 && out[outLength - 1] < line[i]) {
                    outLength--;
                    drop--;
                }

                out[outLength++] = line[i];
            }

            if (outLength > keep) {
                outLength = keep; // cut off right ones
            }

            long long value = 0;
            for (int i = 0; i < outLength; ++i) {
                value = value * 10 + (out[i] - '0');
            }

            total += value;
            printf("%s yields %lld\n", out, value);
        }

        printf("Total: %lld\n", total);
        fclose(fptr);
    }
}


// code does not handle a few edge cases like: 00..001