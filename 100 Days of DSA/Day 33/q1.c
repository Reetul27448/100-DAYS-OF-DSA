#include <stdio.h>
#include <stdlib.h>
#define MAX 100
char stack[MAX];
int top = -1;
void push(char value) {
    if (top < MAX - 1) {
        stack[++top] = value;
    } else {
        printf("Stack overflow! Cannot push '%c'.\n", value);
    }
}
char pop() {
    if (top >= 0) {
        return stack[top--];
    } else {
        printf("Stack Underflow! Cannot pop from an empty stack.\n");
        return '\0'; // Return null character on underflow
    }
}
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0; // For non-operator characters
}
int main() {
    char infix[MAX], postfix[MAX];
    int j = 0;

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    for (int i = 0; infix[i] != '\0'; i++) {
        char token = infix[i];
        if ((token >= 'A' && token <= 'Z') || (token >= 'a' && token <= 'z')) {
            postfix[j++] = token; // Add operand to postfix
        } else if (token == '(') {
            push(token); // Push '(' onto stack
        } else if (token == ')') {
            while (top >= 0 && stack[top] != '(') {
                postfix[j++] = pop(); // Pop until '(' is found
            }
            pop(); // Pop the '(' from stack
        } else { // Operator
            while (top >= 0 && precedence(stack[top]) >= precedence(token)) {
                postfix[j++] = pop(); // Pop operators with higher or equal precedence
            }
            push(token); // Push current operator onto stack
        }
    }

    // Pop remaining operators from stack
    while (top >= 0) {
        postfix[j++] = pop();
    }
    postfix[j] = '\0'; // Null-terminate the postfix string

    printf("Postfix expression: %s\n", postfix);
    return 0;
}
