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
        new_node->next = *head_ref; // Point to itself to make it circular
        return;
    }

    while (last->next != *head_ref) { // Traverse until we reach the last node
        last = last->next;
    }
    last->next = new_node; // Point last node to new node
    new_node->next = *head_ref; // Point new node to head to maintain circular structure
}
void printList(struct Node* head) {
    struct Node* temp = head;
    if (head != NULL) {
        do {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != head); // Traverse until we return to head
    }
    printf("\n");
}
int main() {
    struct Node* head = NULL;
    int n, data;

    printf("Enter the number of elements in the circular linked list: ");
    scanf("%d", &n);

    printf("Enter %d space-separated integers: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        append(&head, data);
    }

    printf("Circular Linked List: ");
    printList(head);

    return 0;
}
