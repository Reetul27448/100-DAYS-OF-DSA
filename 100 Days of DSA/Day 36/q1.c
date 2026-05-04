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
void dequeue() {
    if (front >= 0) {
        printf("Dequeued %d from the queue.\n", queue[front]);
        if (front == rear) {
            front = rear = -1; // Reset the queue when it's empty
        } else {
            front++;
        }
    } else {
        printf("Queue underflow! Cannot dequeue from an empty queue.\n");
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
int main() {
    int n, m, data;

    printf("Enter the number of elements to enqueue: ");
    scanf("%d", &n);

    printf("Enter %d space-separated integers: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        enqueue(data);
    }

    printf("Enter the number of dequeue operations: ");
    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        dequeue();
    }

    printf("Remaining queue elements from front to rear: ");
    display();

    return 0;
}
