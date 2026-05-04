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
int search(int index, int key) {
    if (index >= MAX || tree[index] == -1) {
        return -1; // Key not found
    }
    if (tree[index] == key) {
        return index; // Key found at this index
    }
    if (key < tree[index]) {
        return search(2 * index + 1, key); // Search in left subtree
    } else {
        return search(2 * index + 2, key); // Search in right subtree
    }
}
int main() {
    int n, key;

    printf("Enter the number of elements in the level-order traversal: ");
    scanf("%d", &n);

    printf("Enter %d space-separated integers (-1 for NULL): ", n);
    for (int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);
        insert(value, i);
    }

    printf("Enter the key to search: ");
    scanf("%d", &key);

    int result = search(0, key);
    if (result != -1) {
        printf("Key %d found at index %d.\n", key, result);
    } else {
        printf("Key %d not found in the tree.\n", key);
    }

    return 0;
}