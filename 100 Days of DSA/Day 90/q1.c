#include <stdio.h>
#define MAX 1000

int max(int a, int b) {
    return (a > b) ? a : b;
}

int sum(int arr[], int n) {
    int total = 0;
    for (int i = 0; i < n; i++) {
        total += arr[i];
    }
    return total;
}

int getMax(int arr[], int n) {
    int m = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > m)
            m = arr[i];
    }
    return m;
}

int isFeasible(int arr[], int n, int k, int mid) {
    int painters = 1, curr = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > mid)
            return 0;

        if (curr + arr[i] > mid) {
            painters++;
            curr = arr[i];
            if (painters > k)
                return 0;
        } else {
            curr += arr[i];
        }
    }
    return 1;
}

int findMinimumTime(int arr[], int n, int k) {
    if (n == 0) return 0;

    if (k > n) k = n;  // important fix

    int low = getMax(arr, n);
    int high = sum(arr, n);

    while (low < high) {
        int mid = low + (high - low) / 2;

        if (isFeasible(arr, n, k, mid))
            high = mid;
        else
            low = mid + 1;
    }
    return low;
}

int main() {
    int n, k;
    int arr[MAX];

    scanf("%d %d", &n, &k);

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("%d\n", findMinimumTime(arr, n, k));
    return 0;
}