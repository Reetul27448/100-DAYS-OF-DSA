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
        struct Node* temp = createNode(arr[i]);
        *root = temp;
        insertLevelOrder(&((*root)->left), arr, 2 * i + 1, n);
        insertLevelOrder(&((*root)->right), arr, 2 * i + 2, n);
    }
}
void mirror(struct Node* root) {
    if (root == NULL) {
        return;
    }
    struct Node* temp = root->left;
    root->left = root->right;
    root->right = temp;
    mirror(root->left);
    mirror(root->right);
}
void inorder(struct Node* root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
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
    mirror(root);
    printf("Inorder traversal of mirrored tree: ");
    inorder(root);
    free(arr);
    return 0;
}