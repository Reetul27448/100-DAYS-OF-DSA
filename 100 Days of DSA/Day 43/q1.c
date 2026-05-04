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
void inorder(int index) {
    if (index < MAX && tree[index] != -1) {
        inorder(2 * index + 1); // Left child
        printf("%d ", tree[index]);
        inorder(2 * index + 2); // Right child
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

    printf("Inorder Traversal: ");
    inorder(0);
    printf("\n");

    return 0;
}
