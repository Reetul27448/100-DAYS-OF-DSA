#include <stdio.h>
#define MAX 100
void findClosestToZero(int arr[], int size) {
    int closestSum = arr[0] + arr[1];
    int num1 = arr[0], num2 = arr[1];

    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            int sum = arr[i] + arr[j];
            if (abs(sum) < abs(closestSum)) {
                closestSum = sum;
                num1 = arr[i];
                num2 = arr[j];
            }
        }
    }

    printf("The pair of elements whose sum is closest to zero: %d %d\n", num1, num2);
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

    findClosestToZero(arr, n);

    return 0;
}
