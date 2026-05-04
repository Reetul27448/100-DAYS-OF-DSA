#include <stdio.h>
#define MAX 100
int stack[MAX];
int top = -1;
void push(int value) {
    if (top < MAX - 1) {
        stack[++top] = value;
        printf("Pushed %d onto the stack.\n", value);
    } else {
        printf("Stack overflow! Cannot push %d.\n", value);
    }
}
void pop() {
    if (top >= 0) {
        printf("Popped %d from the stack.\n", stack[top--]);
    } else {
        printf("Stack Underflow! Cannot pop from an empty stack.\n");
    }
}
void display() {
    if (top >= 0) {
        printf("Stack elements (top to bottom): ");
        for (int i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    } else {
        printf("Stack is empty! Nothing to display.\n");
    }
}
int main() {
    int n, operation, value;

    printf("Enter the number of operations: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter operation (1 for push, 2 for pop, 3 for display): ");
        scanf("%d", &operation);
        switch (operation) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            default:
                printf("Invalid operation! Please try again.\n");
        }
    }

    return 0;
}
