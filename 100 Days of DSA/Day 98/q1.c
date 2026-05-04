#include <stdio.h>
#include <stdlib.h>
#define MAX 1000
typedef struct {
    int start;
    int end;
} Interval;
int compare(const void *a, const void *b) {
    Interval *intervalA = (Interval *)a;
    Interval *intervalB = (Interval *)b;
    return intervalA->start - intervalB->start; // Sort by start time
}   
void mergeIntervals(Interval intervals[], int n) {
    if (n <= 0) return;

    qsort(intervals, n, sizeof(Interval), compare);

    printf("Merged Intervals:\n");
    Interval merged[MAX];
    int mergedCount = 0;

    merged[mergedCount++] = intervals[0];

    for (int i = 1; i < n; i++) {
        if (intervals[i].start <= merged[mergedCount - 1].end) {
            // Overlapping intervals, merge them
            if (intervals[i].end > merged[mergedCount - 1].end) {
                merged[mergedCount - 1].end = intervals[i].end;
            }
        } else {
            // No overlap, add to merged list
            merged[mergedCount++] = intervals[i];
        }
    }

    for (int i = 0; i < mergedCount; i++) {
        printf("[%d, %d]\n", merged[i].start, merged[i].end);
    }
}
int main() {
    int n;

    printf("Enter the number of intervals: ");
    scanf("%d", &n);

    Interval intervals[MAX];
    printf("Enter the start and end of each interval (start end):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &intervals[i].start, &intervals[i].end);
    }

    mergeIntervals(intervals, n);

    return 0;
}
