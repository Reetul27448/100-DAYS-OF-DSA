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
int isMirror(struct Node* left, struct Node* right) {
    if (left == NULL && right == NULL) {
        return 1;
    }
    if (left == NULL || right == NULL) {
        return 0;
    }
    return (left->data == right->data) &&
           isMirror(left->left, right->right) &&
           isMirror(left->right, right->left);
}
int isSymmetric(struct Node* root) {
    if (root == NULL) {
        return 1;
    }
    return isMirror(root->left, root->right);
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
    if (isSymmetric(root)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    free(arr);
    return 0;
}