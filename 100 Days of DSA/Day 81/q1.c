#include <stdio.h>
#define MAX 1000
int lowerBound(int arr[], int n, int x) {
    int low = 0, high = n, mid;
    while (low < high) {
        mid = low + (high - low) / 2;
        if (arr[mid] < x) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    return low; // This will be the index of the lower bound
}
int upperBound(int arr[], int n, int x) {
    int low = 0, high = n, mid;
    while (low < high) {
        mid = low + (high - low) / 2;
        if (arr[mid] <= x) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    return low; // This will be the index of the upper bound
}
int main() {
    int arr[MAX];
    int n, x;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter %d space-separated sorted integers: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the target value x: ");
    scanf("%d", &x);

    int lb = lowerBound(arr, n, x);
    int ub = upperBound(arr, n, x);

    printf("Lower Bound Index: %d\n", lb);
    printf("Upper Bound Index: %d\n", ub);

    return 0;
}