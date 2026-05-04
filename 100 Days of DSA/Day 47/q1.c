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
int height(int index) {
    if (index >= MAX || tree[index] == -1) {
        return 0; // Height of an empty tree is 0
    }
    int leftHeight = height(2 * index + 1); // Left child
    int rightHeight = height(2 * index + 2); // Right child
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
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

    printf("Height of the tree: %d\n", height(0));

    return 0;
}
