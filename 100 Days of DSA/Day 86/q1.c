#include <stdio.h>
#define MAX 1000
int integerSquareRoot(int n) {
    if (n < 2) {
        return n; // The square root of 0 is 0 and the square root of 1 is 1
    }

    int low = 0, high = n, mid, sqrt;

    while (low <= high) {
        mid = low + (high - low) / 2;
        long long midSquared = (long long)mid * mid;

        if (midSquared == n) {
            return mid; // Found exact square root
        } else if (midSquared < n) {
            sqrt = mid; // Update sqrt to the largest integer whose square is less than n
            low = mid + 1; // Search in the right half
        } else {
            high = mid - 1; // Search in the left half
        }
    }
    return sqrt; // Return the integer square root
}
int main() {
    int n;

    printf("Enter a non-negative integer: ");
    scanf("%d", &n);

    int result = integerSquareRoot(n);
    printf("The integer square root of %d is %d\n", n, result);

    return 0;
}
