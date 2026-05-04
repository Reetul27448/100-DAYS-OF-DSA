#include <stdio.h>
#define MAX 100
int queue[MAX];
int front = -1, rear = -1;
void enqueue(int data) {
    if (rear < MAX - 1) {
        if (front == -1) {
            front = 0;
        }
        queue[++rear] = data;
    } else {
        printf("Queue overflow! Cannot enqueue %d.\n", data);
    }
}
void display() {
    if (front >= 0) {
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    } else {
        printf("Queue is empty! Nothing to display.\n");
    }
}
void reverseQueue() {
    int stack[MAX];
    int top = -1;

    // Push all elements of the queue onto the stack
    for (int i = front; i <= rear; i++) {
        stack[++top] = queue[i];
    }

    // Pop all elements from the stack back to the queue
    for (int i = front; i <= rear; i++) {
        queue[i] = stack[top--];
    }
}
int main() {
    int n, data;

    printf("Enter the number of elements in the queue: ");
    scanf("%d", &n);

    printf("Enter %d space-separated integers: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        enqueue(data);
    }

    reverseQueue();

    printf("Reversed queue: ");
    display();

    return 0;
}
