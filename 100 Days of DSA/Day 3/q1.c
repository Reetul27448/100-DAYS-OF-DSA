#include <stdio.h>
void linearSearch(int arr[], int size, int key) {
    int comparisons = 0;
    for (int i = 0; i < size; i++) {
        comparisons++;
        if (arr[i] == key) {
            printf("Found at index %d\n", i);
            printf("Comparisons = %d\n", comparisons);
            return;
        }
    }
    printf("Not Found\n");
    printf("Comparisons = %d\n", comparisons);
}
int main() {
    int arr[100];
    int n, key;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter %d space-separated integers: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the key to search: ");
    scanf("%d", &key);

    linearSearch(arr, n, key);

    return 0;
}
