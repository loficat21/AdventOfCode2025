// PART 1: 
// first idea i had:
// save all id numbers in array
// only then go through each range and per range 
// loop over all id numbers in array once and if
// any of them are in, add +1 to total counter

// PART 2:
// sort intervals by smaller end (ie sort by intervals[i][0])
// merge all overlapping or touching intervals
// sum lengths of merged intervals



#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    const long long *x = a;
    const long long *y = b;

    if(x[0] < y[0]) return -1;
    if(x[0] > y[0]) return 1;
    return 0;
}

int main() {
    FILE* fptr;
    fptr = fopen("input.txt", "r");

    if (fptr == NULL) {
        printf("File loading failed");
    }

    // READING IN FILE:
    char buf[128]; // temporary char array to store each line
    long long int intervals[182][2];
    long long int ids[1000];

    int intervalCount = 0;
    int idCount = 0;

    while(fgets(buf, 128, fptr)) {

        long long int a, b;
        if(strchr(buf, '-') && sscanf(buf, "%lld-%lld", &a, &b) == 2) {
            intervals[intervalCount][0] = a;
            intervals[intervalCount][1] = b;
            //printf("%llu - %llu\n", a, b);
            intervalCount++;
        } else if(sscanf(buf, "%lld", &a) == 1) {
            ids[idCount++] = a;
            //printf("%llu\n", a);
        }
        
    }


    // COUNTING NUM FRESH ITEMS: PART 2
    qsort(intervals, intervalCount, sizeof(intervals[0]), compare); // 182 is size of intervals array and 16 is size of intervals[i] which is 2 llu's so 16bytes

    
    long long int currStart = intervals[0][0];
    long long int currEnd = intervals[0][1];

    long long int total = 0;
    for (int i = 1; i < intervalCount; i++) {

        if (intervals[i][0] > currEnd) { // disjoint
            total += (currEnd - currStart + 1);
            currStart = intervals[i][0];
            currEnd = intervals[i][1];
        } else { // new interval extends curr
            if (intervals[i][1] > currEnd) {
                currEnd = intervals[i][1];
            }
        }
        
    }

    total += (currEnd - currStart + 1);

    printf("%lld\n", total);


    // CHECKING FRESHNESS: PART 1
    // int totalCount = 0;
    // for(int i = 0; i < 182; i++) {
    //     for(int j = 0; j < 1000; j++) {
    //         if (ids[j] >= intervals[i][0] && ids[j] <= intervals[i][1]) {
    //             totalCount++;
    //             ids[j] = -1;
    //         }
    //     }
    // }

    fclose(fptr);
}