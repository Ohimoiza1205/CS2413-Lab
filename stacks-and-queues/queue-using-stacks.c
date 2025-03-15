#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Stack structure
typedef struct {
    int *data, top, capacity;
} Stack;

// Create stack
Stack* createStack(int cap) {
    Stack* s = malloc(sizeof(Stack));
    s->capacity = cap, s->top = -1;
    s->data = malloc(cap * sizeof(int));
    return s;
}

// Stack operations
#define isEmpty(s) ((s)->top == -1)
#define push(s, x) ((s)->data[++(s)->top] = (x))
#define pop(s) (isEmpty(s) ? -1 : (s)->data[(s)->top--])
#define peek(s) (isEmpty(s) ? -1 : (s)->data[(s)->top])

// Queue using two stacks
typedef struct { Stack *s1, *s2; } MyQueue;

// Create queue
MyQueue* myQueueCreate() {
    MyQueue* q = malloc(sizeof(MyQueue));
    q->s1 = createStack(100), q->s2 = createStack(100);
    return q;
}

// Push to queue
void myQueuePush(MyQueue* q, int x) { push(q->s1, x); }

// Pop from queue
int myQueuePop(MyQueue* q) {
    if (isEmpty(q->s2)) while (!isEmpty(q->s1)) push(q->s2, pop(q->s1));
    return pop(q->s2);
}

// Peek front element
int myQueuePeek(MyQueue* q) {
    if (isEmpty(q->s2)) while (!isEmpty(q->s1)) push(q->s2, pop(q->s1));
    return peek(q->s2);
}

// Check if queue is empty
bool myQueueEmpty(MyQueue* q) { return isEmpty(q->s1) && isEmpty(q->s2); }

// Free memory
void myQueueFree(MyQueue* q) {
    free(q->s1->data), free(q->s1), free(q->s2->data), free(q->s2), free(q);
}
