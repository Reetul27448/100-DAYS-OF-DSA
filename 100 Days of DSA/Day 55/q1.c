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
void rightView(struct Node* root, int level, int* maxLevel) {
    if (root == NULL) {
        return;
    }
    if (level > *maxLevel) {
        printf("%d ", root->data);
        *maxLevel = level;
    }
    rightView(root->right, level + 1, maxLevel);
    rightView(root->left, level + 1, maxLevel);
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
    int maxLevel = 0;
    printf("Right view of the binary tree: ");
    rightView(root, 1, &maxLevel);
    free(arr);
    return 0;
}
