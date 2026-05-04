#include <stdio.h>
#define MAX 100
int minHeap[MAX];
int size = 0;
void insert(int data) {
    if (size < MAX) {
        minHeap[size++] = data;
    } else {
        printf("Min Heap overflow! Cannot insert %d.\n", data);
    }
}
void delete() {
    if (size > 0) {
        int minIndex = 0;
        for (int i = 1; i < size; i++) {
            if (minHeap[i] < minHeap[minIndex]) {
                minIndex = i;
            }
        }
        printf("%d\n", minHeap[minIndex]);
        for (int i = minIndex; i < size - 1; i++) {
            minHeap[i] = minHeap[i + 1];
        }
        size--;
    } else {
        printf("-1\n");
    }
}
void peek() {
    if (size > 0) {
        int minIndex = 0;
        for (int i = 1; i < size; i++) {
            if (minHeap[i] < minHeap[minIndex]) {
                minIndex = i;
            }
        }
        printf("%d\n", minHeap[minIndex]);
    } else {
        printf("-1\n");
    }
}
int main() {
    int N;
    char operation[10];
    int value;

    printf("Enter the number of operations: ");
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%s", operation);
        if (operation[0] == 'i') { // insert
            scanf("%d", &value);
            insert(value);
        } else if (operation[0] == 'd') { // delete
            delete();
        } else if (operation[0] == 'p') { // peek
            peek();
        } else {
            printf("Invalid operation! Please try again.\n");
        }
    }

    return 0;
}
