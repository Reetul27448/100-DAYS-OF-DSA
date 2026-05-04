#include <stdio.h>
#define MAX 100
void mergeLogs(int log1[], int size1, int log2[], int size2, int mergedLog[]) {
    int i = 0, j = 0, k = 0;

    while (i < size1 && j < size2) {
        if (log1[i] < log2[j]) {
            mergedLog[k++] = log1[i++];
        } else {
            mergedLog[k++] = log2[j++];
        }
    }

    while (i < size1) {
        mergedLog[k++] = log1[i++];
    }

    while (j < size2) {
        mergedLog[k++] = log2[j++];
    }
}
int main() {
    int log1[MAX], log2[MAX], mergedLog[MAX];
    int size1, size2;

    printf("Enter the number of entries in server log 1: ");
    scanf("%d", &size1);
    printf("Enter %d sorted integers for server log 1: ", size1);
    for (int i = 0; i < size1; i++) {
        scanf("%d", &log1[i]);
    }

    printf("Enter the number of entries in server log 2: ");
    scanf("%d", &size2);
    printf("Enter %d sorted integers for server log 2: ", size2);
    for (int i = 0; i < size2; i++) {
        scanf("%d", &log2[i]);
    }

    mergeLogs(log1, size1, log2, size2, mergedLog);

    printf("Merged chronological log: ");
    for (int i = 0; i < size1 + size2; i++) {
        printf("%d ", mergedLog[i]);
    }
    printf("\n");

    return 0;
}
