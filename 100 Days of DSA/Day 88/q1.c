#include <stdio.h>
#include <stdlib.h>
#define MAX 1000
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}
int isFeasible(int stalls[], int n, int k, int mid) {
    int cowsPlaced = 1; // Place the first cow in the first stall
    int lastPosition = stalls[0];

    for (int i = 1; i < n; i++) {
        if (stalls[i] - lastPosition >= mid) {
            cowsPlaced++;
            lastPosition = stalls[i];
            if (cowsPlaced == k) {
                return 1; // Successfully placed all cows with at least mid distance
            }
        }
    }
    return 0; // Not feasible to place all cows with at least mid distance
}
int findMaxMinDistance(int stalls[], int n, int k) {
    qsort(stalls, n, sizeof(int), compare);

    int low = 1; // Minimum possible distance
    int high = stalls[n - 1] - stalls[0]; // Maximum possible distance
    int result = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (isFeasible(stalls, n, k, mid)) {
            result = mid; // Update result and try for a larger distance
            low = mid + 1;
        } else {
            high = mid - 1; // Try for a smaller distance
        }
    }
    return result;
}
int main() {
    int n, k;
    int stalls[MAX];

    printf("Enter the number of stalls and cows: ");
    scanf("%d %d", &n, &k);

    printf("Enter the positions of the stalls: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &stalls[i]);
    }

    int maxMinDistance = findMaxMinDistance(stalls, n, k);
    printf("Maximum minimum distance between any two cows: %d\n", maxMinDistance);

    return 0;
}
