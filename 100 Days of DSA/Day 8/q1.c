#include <stdio.h>
int power(int a, int b) {
    if (b == 0) {
        return 1; // Any number raised to the power of 0 is 1
    } else {
        return a * power(a, b - 1); // Recursive call
    }
}
int main() {
    int a, b;

    printf("Enter two space-separated integers (a and b): ");
    scanf("%d %d", &a, &b);

    int result = power(a, b);
    printf("%d raised to the power of %d is: %d\n", a, b, result);

    return 0;
}
