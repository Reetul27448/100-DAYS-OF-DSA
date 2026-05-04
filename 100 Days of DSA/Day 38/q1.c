#include <stdio.h>
#define MAX 100
int deque[MAX];
int front = -1, rear = -1;
void push_front(int data) {
    if (front == 0 && rear == MAX - 1) {
        printf("Deque overflow! Cannot push %d at the front.\n", data);
        return;
    }
    if (front == -1) { // First element
        front = rear = 0;
    } else if (front == 0) { // Wrap around
        front = MAX - 1;
    } else {
        front--;
    }
    deque[front] = data;
    printf("Pushed %d at the front of the deque.\n", data);
}
void push_back(int data) {
    if (front == 0 && rear == MAX - 1) {
        printf("Deque overflow! Cannot push %d at the back.\n", data);
        return;
    }
    if (rear == -1) { // First element
        front = rear = 0;
    } else if (rear == MAX - 1) { // Wrap around
        rear = 0;
    } else {
        rear++;
    }
    deque[rear] = data;
    printf("Pushed %d at the back of the deque.\n", data);
}
void pop_front() {
    if (front == -1) {
        printf("Deque underflow! Cannot pop from the front.\n");
        return;
    }
    printf("Popped %d from the front of the deque.\n", deque[front]);
    if (front == rear) { // Only one element
        front = rear = -1;
    } else if (front == MAX - 1) { // Wrap around
        front = 0;
    } else {
        front++;
    }
}
void pop_back() {
    if (rear == -1) {
        printf("Deque underflow! Cannot pop from the back.\n");
        return;
    }
    printf("Popped %d from the back of the deque.\n", deque[rear]);
    if (front == rear) { // Only one element
        front = rear = -1;
    } else if (rear == 0) { // Wrap around
        rear = MAX - 1;
    } else {
        rear--;
    }
}
void display() {
    if (front == -1) {
        printf("Deque is empty! Nothing to display.\n");
        return;
    }
    printf("Deque elements from front to rear: ");
    int i = front;
    while (1) {
        printf("%d ", deque[i]);
        if (i == rear) break;
        i = (i + 1) % MAX; // Wrap around
    }
    printf("\n");
}
int main() {
    push_back(10);
    push_back(20);
    push_front(5);
    push_front(1);
    display();

    pop_front();
    display();

    pop_back();
    display();

    return 0;
}