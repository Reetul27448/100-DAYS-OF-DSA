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
int main() {
    int n, data;

    printf("Enter the number of elements in the queue: ");
    scanf("%d", &n);

    printf("Enter %d space-separated integers: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        enqueue(data);
    }

    printf("Queue elements from front to rear: ");
    display();

    return 0;
}
