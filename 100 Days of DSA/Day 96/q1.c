#include <stdio.h>
#define MAX 1000
void merge(int arr[], int temp[], int left, int mid, int right, long long *invCount) {
    int i = left; // Starting index for left subarray
    int j = mid + 1; // Starting index for right subarray
    int k = left; // Starting index for to be sorted subarray

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            *invCount += (mid - i + 1); // Count inversions
        }
    }

    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (i = left; i <= right; i++) {
        arr[i] = temp[i];
    }
}
void mergeSort(int arr[], int temp[], int left, int right, long long *invCount) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, temp, left, mid, invCount);
        mergeSort(arr, temp, mid + 1, right, invCount);

        merge(arr, temp, left, mid, right, invCount);
    }
}
int main() {
    int arr[MAX], temp[MAX];
    int n;
    long long invCount = 0;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter %d space-separated integers: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    mergeSort(arr, temp, 0, n - 1, &invCount);

    printf("Number of inversions: %lld\n", invCount);

    return 0;
}