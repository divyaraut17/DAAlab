 // Compare function for qsort to sort intervals by their end time
int compare(const void *a, const void *b) {
   return (*(int **)a)[1] - (*(int **)b)[1];
}

int eraseOverlapIntervals(int** intervals, int intervalsSize, int* intervalsColSize) {
    if (intervalsSize == 0) return 0;

   
    qsort(intervals, intervalsSize, sizeof(int*), compare);

    int count = 0; 
    int end = intervals[0][1]; 

    for (int i = 1; i < intervalsSize; i++) {
        if (intervals[i][0] < end) {
            
            count++;
        } else {
            
            end = intervals[i][1];
        }
    }

    return count;
}
