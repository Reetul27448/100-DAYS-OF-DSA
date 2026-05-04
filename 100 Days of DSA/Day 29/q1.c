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
struct Node* rotateRight(struct Node* head, int k) {
    if (head == NULL || k == 0) return head;

    // Compute the length of the linked list
    struct Node* current = head;
    int length = 1; // Start with 1 to count the head
    while (current->next != NULL) {
        current = current->next;
        length++;
    }

    // Connect the last node to the head to form a circular list
    current->next = head;

    // Find the new tail: (length - k % length - 1)th node
    // and the new head: (length - k % length)th node
    int new_tail_pos = length - (k % length) - 1;
    struct Node* new_tail = head;
    for (int i = 0; i < new_tail_pos; i++) {
        new_tail = new_tail->next;
    }
    struct Node* new_head = new_tail->next;

    // Break the circular list
    new_tail->next = NULL;

    return new_head;
}
int main() {
    struct Node* head = NULL;
    int n, k, data;

    printf("Enter the number of elements in the linked list: ");
    scanf("%d", &n);

    printf("Enter %d space-separated integers: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        append(&head, data);
    }

    printf("Enter the number of places to rotate right: ");
    scanf("%d", &k);

    head = rotateRight(head, k);

    printf("Rotated Linked List: ");
    printList(head);

    return 0;
}
