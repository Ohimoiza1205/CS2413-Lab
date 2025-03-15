#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Queue structure
typedef struct {
    int *data, front, rear, size, capacity;
} Queue;

// Create a queue
Queue* createQueue(int cap) {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->capacity = cap, q->size = 0, q->front = 0, q->rear = -1;
    q->data = (int*)malloc(cap * sizeof(int));
    return q;
}

// Queue operations
bool isEmpty(Queue* q) { return q->size == 0; }
void enqueue(Queue* q, int x) { q->data[++q->rear % q->capacity] = x; q->size++; }
int dequeue(Queue* q) { q->size--; return q->data[q->front++ % q->capacity]; }
int front(Queue* q) { return q->data[q->front]; }

// Stack structure using one queue
typedef struct { Queue* q; } MyStack;

// Initialize stack
MyStack* myStackCreate() {
    MyStack* stack = (MyStack*)malloc(sizeof(MyStack));
    stack->q = createQueue(100);
    return stack;
}

// Push element onto stack
void myStackPush(MyStack* s, int x) {
    enqueue(s->q, x);
    for (int i = 0; i < s->q->size - 1; i++) // Rotate elements
        enqueue(s->q, dequeue(s->q));
}

// Pop top element
int myStackPop(MyStack* s) { return dequeue(s->q); }

// Get top element
int myStackTop(MyStack* s) { return front(s->q); }

// Check if stack is empty
bool myStackEmpty(MyStack* s) { return isEmpty(s->q); }

// Free stack memory
void myStackFree(MyStack* s) { free(s->q->data); free(s->q); free(s); }
