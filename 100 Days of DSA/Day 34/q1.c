
#include <stdio.h>
#include <stdlib.h>
#define MAX 100
struct Node {
    int data;
    struct Node* next;
};
struct Stack {
    struct Node* top;
};
void push(struct Stack* stack, int value) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = value;
    new_node->next = stack->top;
    stack->top = new_node;
}
int pop(struct Stack* stack) {
    if (stack->top == NULL) {
        printf("Stack Underflow! Cannot pop from an empty stack.\n");
        return -1; // Return -1 on underflow
    }
    struct Node* temp = stack->top;
    int value = temp->data;
    stack->top = stack->top->next;
    free(temp);
    return value;
}
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0; // For non-operator characters
}
int evaluatePostfix(char* expression) {
    struct Stack stack;
    stack.top = NULL;
    for (int i = 0; expression[i] != '\0'; i++) {
        char token = expression[i];
        if (token == ' ') continue; // Skip spaces
        if (token >= '0' && token <= '9') {
            push(&stack, token - '0'); // Convert char to int and push
        } else { // Operator
            int val2 = pop(&stack);
            int val1 = pop(&stack);
            int result;
            switch (token) {
                case '+': result = val1 + val2; break;
                case '-': result = val1 - val2; break;
                case '*': result = val1 * val2; break;
                case '/': result = val1 / val2; break;
                default: printf("Invalid operator '%c'!\n", token); return -1;
            }
            push(&stack, result); // Push result back to stack
        }
    }
    return pop(&stack); // Final result is on top of stack
}
int main() {
    char expression[MAX];
    printf("Enter a postfix expression: ");
    fgets(expression, MAX, stdin);
    int result = evaluatePostfix(expression);
    if (result != -1) {
        printf("Result: %d\n", result);
    }
    return 0;
}
