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
struct Node* findLCA(struct Node* root, int n1, int n2) {
    if (root == NULL) {
        return NULL;
    }
    if (root->data == n1 || root->data == n2) {
        return root;
    }
    struct Node* leftLCA = findLCA(root->left, n1, n2);
    struct Node* rightLCA = findLCA(root->right, n1, n2);
    if (leftLCA && rightLCA) {
        return root;
    }
    return (leftLCA != NULL) ? leftLCA : rightLCA;
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
    int n1, n2;
    printf("Enter the two node values: ");
    scanf("%d %d", &n1, &n2);
    struct Node* lca = findLCA(root, n1, n2);
    if (lca != NULL) {
        printf("LCA of %d and %d is: %d\n", n1, n2, lca->data);
    } else {
        printf("LCA does not exist.\n");
    }
    free(arr);
    return 0;
}
