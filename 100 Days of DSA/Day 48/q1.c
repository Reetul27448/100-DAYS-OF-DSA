#include <stdio.h>
#define MAX 100
int tree[MAX];
void insert(int value, int index) {
    if (index < MAX) {
        tree[index] = value;
    } else {
        printf("Index out of range\n");
    }
}
int countLeafNodes(int index) {
    if (index >= MAX || tree[index] == -1) {
        return 0; // No node here
    }
    if ((2 * index + 1 >= MAX || tree[2 * index + 1] == -1) && 
        (2 * index + 2 >= MAX || tree[2 * index + 2] == -1)) {
        return 1; // This is a leaf node
    }
    return countLeafNodes(2 * index + 1) + countLeafNodes(2 * index + 2);
}
int main() {
    int n;

    printf("Enter the number of elements in the level-order traversal: ");
    scanf("%d", &n);

    printf("Enter %d space-separated integers (-1 for NULL): ", n);
    for (int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);
        insert(value, i);
    }

    printf("Number of leaf nodes: %d\n", countLeafNodes(0));

    return 0;
}
