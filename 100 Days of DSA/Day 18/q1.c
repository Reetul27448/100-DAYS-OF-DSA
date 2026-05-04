/*
Problem: Given an array of integers, rotate the array to the right by k positions.

Input:
- First line: integer n
- Second line: n integers
- Third line: integer k

Output:
- Print the rotated array

Example:
Input:
5
1 2 3 4 5
2

Output:
4 5 1 2 3
*/
#include <stdio.h>
#define MAX 100
void rotateRight(int arr[], int size, int k) {
    k = k % size; // Handle cases where k is greater than size
    int temp[MAX];

    // Copy the last k elements to temp
    for (int i = 0; i < k; i++) {
        temp[i] = arr[size - k + i];
    }

    // Shift the first size-k elements to the right
    for (int i = size - 1; i >= k; i--) {
        arr[i] = arr[i - k];
    }

    // Copy the temp elements back to the front of the array
    for (int i = 0; i < k; i++) {
        arr[i] = temp[i];
    }
}
int main() {
    int arr[MAX];
    int n, k;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter %d space-separated integers: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the number of positions to rotate (k): ");
    scanf("%d", &k);

    rotateRight(arr, n, k);

    printf("Rotated array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
