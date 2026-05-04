#include <stdio.h>
#define MAX 1000
void bucketSort(float arr[], int n) {
    float buckets[MAX][MAX];
    int bucketCount[MAX] = {0};

    // Distribute input array values into buckets
    for (int i = 0; i < n; i++) {
        int bucketIndex = (int)(arr[i] * MAX);
        buckets[bucketIndex][bucketCount[bucketIndex]++] = arr[i];
    }

    // Sort individual buckets using insertion sort
    for (int i = 0; i < MAX; i++) {
        for (int j = 1; j < bucketCount[i]; j++) {
            float key = buckets[i][j];
            int k = j - 1;
            while (k >= 0 && buckets[i][k] > key) {
                buckets[i][k + 1] = buckets[i][k];
                k--;
            }
            buckets[i][k + 1] = key;
        }
    }

    // Concatenate sorted buckets
    int index = 0;
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < bucketCount[i]; j++) {
            arr[index++] = buckets[i][j];
        }
    }
}
int main() {
    float arr[MAX];
    int n;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter %d space-separated real numbers in [0, 1): ", n);
    for (int i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
    }

    bucketSort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }
    printf("\n");

    return 0;
}
