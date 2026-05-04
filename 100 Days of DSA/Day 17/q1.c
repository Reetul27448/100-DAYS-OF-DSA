#include <stdio.h>
#define MAX 100
void findMaxMin(int arr[], int size, int *max, int *min) {
    *max = arr[0];
    *min = arr[0];

    for (int i = 1; i < size; i++) {
        if (arr[i] > *max) {
            *max = arr[i];
        }
        if (arr[i] < *min) {
            *min = arr[i];
        }
    }
}
int main() {
    int arr[MAX];
    int n, max, min;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter %d space-separated integers: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    findMaxMin(arr, n, &max, &min);

    printf("Max: %d\n", max);
    printf("Min: %d\n", min);

    return 0;
}
