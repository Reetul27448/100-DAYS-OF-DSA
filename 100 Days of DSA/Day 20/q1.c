#include <stdio.h>
#define MAX 100
int countZeroSumSubarrays(int arr[], int size) {
    int count = 0;

    // Check all subarrays
    for (int start = 0; start < size; start++) {
        int sum = 0;
        for (int end = start; end < size; end++) {
            sum += arr[end];
            if (sum == 0) {
                count++;
            }
        }
    }

    return count;
}
int main() {
    int arr[MAX];
    int n;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter %d space-separated integers: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int result = countZeroSumSubarrays(arr, n);
    printf("Count of subarrays having sum zero: %d\n", result);

    return 0;
}
