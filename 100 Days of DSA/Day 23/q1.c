#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
void append(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head_ref;
    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL) {
        last = last->next;
    }
    last->next = new_node;
}
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}
struct Node* mergeSortedLists(struct Node* list1, struct Node* list2) {
    struct Node* mergedHead = NULL;
    struct Node** lastPtrRef = &mergedHead;

    while (list1 != NULL && list2 != NULL) {
        if (list1->data <= list2->data) {
            *lastPtrRef = list1;
            list1 = list1->next;
        } else {
            *lastPtrRef = list2;
            list2 = list2->next;
        }
        lastPtrRef = &((*lastPtrRef)->next);
    }

    if (list1 != NULL) {
        *lastPtrRef = list1;
    } else {
        *lastPtrRef = list2;
    }

    return mergedHead;
}
int main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;
    int n, m, data;

    printf("Enter the number of elements in the first linked list: ");
    scanf("%d", &n);
    printf("Enter %d space-separated integers for the first linked list: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        append(&list1, data);
    }

    printf("Enter the number of elements in the second linked list: ");
    scanf("%d", &m);
    printf("Enter %d space-separated integers for the second linked list: ", m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &data);
        append(&list2, data);
    }

    struct Node* mergedList = mergeSortedLists(list1, list2);

    printf("Merged Linked List: ");
    printList(mergedList);

    return 0;
}
    