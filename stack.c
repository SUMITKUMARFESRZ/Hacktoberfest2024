#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100  // Maximum size of the stack

// Define the stack structure
typedef struct {
    int items[MAX];
    int top;
} Stack;

// Initialize the stack
void initStack(Stack *s) {
    s->top = -1;
}

// Check if the stack is empty
bool isEmpty(Stack *s) {
    return s->top == -1;
}

// Check if the stack is full
bool isFull(Stack *s) {
    return s->top == MAX - 1;
}

// Push an item onto the stack
void push(Stack *s, int item) {
    if (isFull(s)) {
        printf("Stack Overflow\n");
        return;
    }
    s->items[++(s->top)] = item;
    printf("%d pushed to stack\n", item);
}

// Pop an item from the stack
int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        return -1; // Return -1 or some error value
    }
    return s->items[(s->top)--];
}

// Peek the top item of the stack
int peek(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return -1; // Return -1 or some error value
    }
    return s->items[s->top];
}

// Print all items in the stack
void printStack(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements are:\n");
    for (int i = 0; i <= s->top; i++) {
        printf("%d\n", s->items[i]);
    }
}

int main() {
    Stack s;
    initStack(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);

    printf("%d popped from stack\n", pop(&s));
    printf("Top element is %d\n", peek(&s));

    printStack(&s);

    return 0;
}
