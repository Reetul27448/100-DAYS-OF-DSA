#include <stdio.h>
#define MAX 100
int longestZeroSumSubarray(int arr[], int size) {
    int prefixSum[MAX];
    prefixSum[0] = arr[0];
    
    for (int i = 1; i < size; i++) {
        prefixSum[i] = prefixSum[i - 1] + arr[i];
    }
    
    int maxLength = 0;
    
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (prefixSum[j] - prefixSum[i] == 0) {
                int length = j - i;
                if (length > maxLength) {
                    maxLength = length;
                }
            }
        }
    }
    
    return maxLength;
}
int main() {
    int arr[MAX];
    int size;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &size);

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    int result = longestZeroSumSubarray(arr, size);
    printf("Length of the longest subarray with sum equal to zero: %d\n", result);

    return 0;
}
