#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int stack[MAX], top = -1;

void push(int value) {
    if (top == MAX - 1)
        printf("Stack Overflow!\n");
    else {
        stack[++top] = value;
        printf("%d pushed into stack.\n", value);
    }
}

void pop() {
    if (top == -1)
        printf("Stack Underflow!\n");
    else
        printf("%d popped from stack.\n", stack[top--]);
}

void peek() {
    if (top == -1)
        printf("Stack is Empty!\n");
    else
        printf("Top element: %d\n", stack[top]);
}

void displayStack() {
    if (top == -1)
        printf("Stack is Empty!\n");
    else {
        printf("Stack elements: ");
        for (int i = 0; i <= top; i++)
            printf("%d ", stack[i]);
        printf("\n");
    }
}

int queue[MAX], front = -1, rear = -1;

void enqueue(int value) {
    if (rear == MAX - 1)
        printf("Queue Overflow!\n");
    else {
        if (front == -1) front = 0;
        queue[++rear] = value;
        printf("%d enqueued into queue.\n", value);
    }
}

void dequeue() {
    if (front == -1 || front > rear)
        printf("Queue Underflow!\n");
    else
        printf("%d dequeued from queue.\n", queue[front++]);
}

void displayQueue() {
    if (front == -1 || front > rear)
        printf("Queue is Empty!\n");
    else {
        printf("Queue elements: ");
        for (int i = front; i <= rear; i++)
            printf("%d ", queue[i]);
        printf("\n");
    }
}

int cqueue[MAX], cfront = -1, crear = -1;

void cenqueue(int value) {
    if ((cfront == 0 && crear == MAX - 1) || (crear + 1 == cfront))
        printf("Circular Queue Overflow!\n");
    else {
        if (cfront == -1) cfront = 0;
        crear = (crear + 1) % MAX;
        cqueue[crear] = value;
        printf("%d enqueued into circular queue.\n", value);
    }
}

void cdequeue() {
    if (cfront == -1)
        printf("Circular Queue Underflow!\n");
    else {
        printf("%d dequeued from circular queue.\n", cqueue[cfront]);
        if (cfront == crear)
            cfront = crear = -1;
        else
            cfront = (cfront + 1) % MAX;
    }
}

void displayCQueue() {
    if (cfront == -1)
        printf("Circular Queue is Empty!\n");
    else {
        printf("Circular Queue elements: ");
        int i = cfront;
        while (1) {
            printf("%d ", cqueue[i]);
            if (i == crear)
                break;
            i = (i + 1) % MAX;
        }
        printf("\n");
    }
}

int main() {
    int choice, value;

    while (1) {
        printf("\n--- MENU ---\n");
        printf("1. Stack Operations\n");
        printf("2. Queue Operations\n");
        printf("3. Circular Queue Operations\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {

        case 1:
            printf("\n--- STACK MENU ---\n");
            printf("1.Push\n2.Pop\n3.Peek\n4.Display\n");
            scanf("%d", &choice);

            if (choice == 1) {
                printf("Enter value: ");
                scanf("%d", &value);
                push(value);
            } else if (choice == 2)
                pop();
            else if (choice == 3)
                peek();
            else if (choice == 4)
                displayStack();
            break;

        case 2:
            printf("\n--- QUEUE MENU ---\n");
            printf("1.Enqueue\n2.Dequeue\n3.Display\n");
            scanf("%d", &choice);

            if (choice == 1) {
                printf("Enter value: ");
                scanf("%d", &value);
                enqueue(value);
            } else if (choice == 2)
                dequeue();
            else if (choice == 3)
                displayQueue();
            break;

        case 3:
            printf("\n--- CIRCULAR QUEUE MENU ---\n");
            printf("1.Enqueue\n2.Dequeue\n3.Display\n");
            scanf("%d", &choice);

            if (choice == 1) {
                printf("Enter value: ");
                scanf("%d", &value);
                cenqueue(value);
            } else if (choice == 2)
                cdequeue();
            else if (choice == 3)
                displayCQueue();
            break;

        case 4:
            exit(0);

        default:
            printf("Invalid Choice!\n");
        }
    }

    return 0;
}
