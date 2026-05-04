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
    int n, m, value;

    printf("Enter the number of elements to push: ");
    scanf("%d", &n);

    printf("Enter %d integers to push onto the stack: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        push(value);
    }

    printf("Enter the number of pops: ");
    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        pop();
    }

    printf("Remaining stack elements after pops:\n");
    display();

    return 0;
}
