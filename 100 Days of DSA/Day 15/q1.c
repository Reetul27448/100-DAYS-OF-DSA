#include <stdio.h>
#define MAX 100
int main() {
    int m, n;
    int matrix[MAX][MAX];

    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &m, &n);

    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int diagonalSum = 0;
    for (int i = 0; i < m && i < n; i++) {
        diagonalSum += matrix[i][i];
    }

    printf("Sum of primary diagonal elements: %d\n", diagonalSum);

    return 0;
}
