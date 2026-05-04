#include <stdio.h>
#define MAX 100
void countFrequency(int arr[], int size) {
    int frequency[MAX] = {0}; // Initialize frequency array to 0

    // Count frequency of each element
    for (int i = 0; i < size; i++) {
        frequency[arr[i]]++;
    }

    // Print the frequency of each distinct element
    printf("Element:Frequency\n");
    for (int i = 0; i < MAX; i++) {
        if (frequency[i] > 0) {
            printf("%d:%d ", i, frequency[i]);
        }
    }
    printf("\n");
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

    countFrequency(arr, n);

    return 0;
}
