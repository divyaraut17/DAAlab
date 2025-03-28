#include <stdio.h>
#include <stdlib.h>

// Structure to represent an interval
typedef struct {
    int start;
    int end;
} Interval;

// Comparison 
int compare(const void *a, const void *b) {
    Interval *intervalA = (Interval *)a;
    Interval *intervalB = (Interval *)b;
    return (intervalA->end - intervalB->end);
}


void intervalScheduling(Interval intervals[], int n) {
   
    qsort(intervals, n, sizeof(Interval), compare);

    printf("Selected intervals:\n");
    
    // Select the first interval
    int lastEndTime = intervals[0].end;
    printf("(%d, %d)\n", intervals[0].start, intervals[0].end);

    int i;
    for ( i = 1; i < n; i++) {
        if (intervals[i].start >= lastEndTime) {
            
            printf("(%d, %d)\n", intervals[i].start, intervals[i].end);
            lastEndTime = intervals[i].end;
        }
    }
}

int main() {
    int n;
    int i;
    
    printf("Enter the number of intervals: ");
    scanf("%d", &n);

    Interval intervals[n];

    for ( i = 0; i < n; i++) {
        printf("Enter start and end time for interval %d: ", i + 1);
        scanf("%d %d", &intervals[i].start, &intervals[i].end);
    }

   
    intervalScheduling(intervals, n);

    return 0;
}
