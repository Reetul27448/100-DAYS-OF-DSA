#include <stdio.h>
#define MAX 100
void removeDuplicates(int arr[], int size) {
    if (size == 0) {
        return;
    }

    int uniqueIndex = 0; // Index to place the next unique element

    for (int i = 1; i < size; i++) {
        if (arr[i] != arr[uniqueIndex]) {
            uniqueIndex++;
            arr[uniqueIndex] = arr[i]; // Move unique element to the front
        }
    }

    // Print unique elements
    printf("Unique elements: ");
    for (int i = 0; i <= uniqueIndex; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main() {
    int arr[MAX];
    int n;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter %d space-separated integers (sorted array): ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    removeDuplicates(arr, n);

    return 0;
}
