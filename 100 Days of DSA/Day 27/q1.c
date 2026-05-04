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
int getLength(struct Node* head) {
    int length = 0;
    while (head != NULL) {
        length++;
        head = head->next;
    }
    return length;
}
struct Node* findIntersection(struct Node* head1, struct Node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);
    int diff = abs(len1 - len2);

    // Advance the pointer of the longer list by 'diff' nodes
    if (len1 > len2) {
        for (int i = 0; i < diff; i++) {
            head1 = head1->next;
        }
    } else {
        for (int i = 0; i < diff; i++) {
            head2 = head2->next;
        }
    }

    // Traverse both lists simultaneously to find the intersection point
    while (head1 != NULL && head2 != NULL) {
        if (head1 == head2) {
            return head1; // Intersection point found
        }
        head1 = head1->next;
        head2 = head2->next;
    }

    return NULL; // No intersection
}
int main() {
    struct Node* head1 = NULL;
    struct Node* head2 = NULL;
    int n, m, data;

    printf("Enter the number of elements in the first linked list: ");
    scanf("%d", &n);
    printf("Enter %d space-separated integers for the first linked list: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        append(&head1, data);
    }

    printf("Enter the number of elements in the second linked list: ");
    scanf("%d", &m);
    printf("Enter %d space-separated integers for the second linked list: ", m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &data);
        append(&head2, data);
    }

    struct Node* intersectionNode = findIntersection(head1, head2);
    if (intersectionNode != NULL) {
        printf("Intersection at node with value: %d\n", intersectionNode->data);
    } else {
        printf("No Intersection\n");
    }

    return 0;
}