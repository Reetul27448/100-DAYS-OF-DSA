#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
void insertLevelOrder(struct Node** root, int arr[], int i, int n) {
    if (i < n) {
        if (arr[i] == -1) {
            *root = NULL;
            return;
        }
        struct Node* temp = createNode(arr[i]);
        *root = temp;
        insertLevelOrder(&((*root)->left), arr, 2 * i + 1, n);
        insertLevelOrder(&((*root)->right), arr, 2 * i + 2, n);
    }
}
void verticalOrder(struct Node* root, int hd, int* minHd, int* maxHd) {
    if (root == NULL) {
        return;
    }
    if (hd < *minHd) {
        *minHd = hd;
    }
    if (hd > *maxHd) {
        *maxHd = hd;
    }
    verticalOrder(root->left, hd - 1, minHd, maxHd);
    printf("%d ", root->data);
    verticalOrder(root->right, hd + 1, minHd, maxHd);
}
int main() {
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    int* arr = (int*)malloc(n * sizeof(int));
    printf("Enter the level-order traversal: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    struct Node* root = NULL;
    insertLevelOrder(&root, arr, 0, n);
    int minHd = 0, maxHd = 0;
    verticalOrder(root, 0, &minHd, &maxHd);
    free(arr);
    return 0;
}