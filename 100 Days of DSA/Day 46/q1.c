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
void levelOrder(int index) {
    if (index < MAX && tree[index] != -1) {
        printf("%d ", tree[index]);
        levelOrder(2 * index + 1); // Left child
        levelOrder(2 * index + 2); // Right child
    }
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

    printf("Level Order Traversal: ");
    levelOrder(0);
    printf("\n");

    return 0;
}
