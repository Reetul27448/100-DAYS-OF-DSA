#include <stdio.h>
#include <stdlib.h>
struct Node {
    int coeff;
    int exp;
    struct Node* next;
};
void append(struct Node** head_ref, int coeff, int exp) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head_ref;
    new_node->coeff = coeff;
    new_node->exp = exp;
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
void printPolynomial(struct Node* node) {
    while (node != NULL) {
        if (node->exp == 0) {
            printf("%d", node->coeff);
        } else if (node->exp == 1) {
            printf("%dx", node->coeff);
        } else {
            printf("%dx^%d", node->coeff, node->exp);
        }
        if (node->next != NULL) {
            printf(" + ");
        }
        node = node->next;
    }
    printf("\n");
}
int main() {
    struct Node* head = NULL;
    int n, coeff, exp;

    printf("Enter the number of terms in the polynomial: ");
    scanf("%d", &n);

    printf("Enter coefficient and exponent for each term:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &coeff, &exp);
        append(&head, coeff, exp);
    }

    printf("Polynomial: ");
    printPolynomial(head);

    return 0;
}
