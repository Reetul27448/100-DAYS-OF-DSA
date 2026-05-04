#include <stdio.h>
#define MAX 100
void deleteAtPosition(int arr[], int *size, int pos) {
    if (pos < 1 || pos > *size) {
        printf("Invalid position! Please enter a position between 1 and %d.\n", *size);
        return;
    }
    for (int i = pos - 1; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*size)--;
}
int main() {
    int arr[MAX];
    int n, pos;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter %d space-separated integers: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the position to delete (1-based index): ");
    scanf("%d", &pos);

    deleteAtPosition(arr, &n, pos);

    printf("Updated array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
