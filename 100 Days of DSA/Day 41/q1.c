#include <stdio.h>
#include <stdlib.h> 
typedef struct Node {
    int data;
    struct Node* next;
} Node;
typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;
void enqueue(Queue* q, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}
void dequeue(Queue* q) {
    if (q->front == NULL) {
        printf("-1\n");
        return;
    }
    Node* temp = q->front;
    printf("%d\n", temp->data);
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
}
int main() {
    Queue q;
    q.front = q.rear = NULL;
    int N, data;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        char operation[10];
        scanf("%s", operation);
        if (operation[0] == 'e') { // enqueue
            scanf("%d", &data);
            enqueue(&q, data);
        } else if (operation[0] == 'd') { // dequeue
            dequeue(&q);
        }
    }
    return 0;
}
