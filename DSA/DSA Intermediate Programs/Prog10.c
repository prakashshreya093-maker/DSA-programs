#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

void push(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = top;
    top = newNode;
    printf("%d pushed to stack\n", value);
}

void pop() {
    if (top == NULL) {
        printf("Stack Underflow\n");
        return;
    }
    struct Node* temp = top;
    printf("Popped: %d\n", top->data);
    top = top->next;
    free(temp);
}

void displayStack() {
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    struct Node* temp = top;
    printf("Stack (Top -> Bottom): ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

struct Node *front = NULL, *rear = NULL;

void enqueue(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    printf("%d enqueued to queue\n", value);
}

void dequeue() {
    if (front == NULL) {
        printf("Queue Underflow\n");
        return;
    }
    struct Node* temp = front;
    printf("Dequeued: %d\n", front->data);
    front = front->next;
    if (front == NULL)
        rear = NULL;
    free(temp);
}

void displayQueue() {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    struct Node* temp = front;
    printf("Queue (Front -> Rear): ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

struct Node *cqFront = NULL, *cqRear = NULL;

void cqEnqueue(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    if (cqFront == NULL) {
        cqFront = cqRear = newNode;
        newNode->next = cqFront;
    } else {
        newNode->next = cqFront;
        cqRear->next = newNode;
        cqRear = newNode;
    }
    printf("%d enqueued to circular queue\n", value);
}

void cqDequeue() {
    if (cqFront == NULL) {
        printf("Circular Queue Underflow\n");
        return;
    }

    struct Node* temp = cqFront;
    printf("Dequeued: %d\n", cqFront->data);

    if (cqFront == cqRear) {
        cqFront = cqRear = NULL;
    } else {
        cqFront = cqFront->next;
        cqRear->next = cqFront;
    }
    free(temp);
}

void displayCircularQueue() {
    if (cqFront == NULL) {
        printf("Circular Queue is empty\n");
        return;
    }
    struct Node* temp = cqFront;
    printf("Circular Queue: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != cqFront);
    printf("(back to front)\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\n===== MAIN MENU =====\n");
        printf("1. Stack Operations\n");
        printf("2. Queue Operations\n");
        printf("3. Circular Queue Operations\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        int op;

        switch (choice) {
        case 1:
            printf("\n--- STACK MENU ---\n");
            printf("1. Push\n2. Pop\n3. Display\n");
            scanf("%d", &op);

            if (op == 1) {
                printf("Enter value: ");
                scanf("%d", &value);
                push(value);
            } else if (op == 2) {
                pop();
            } else if (op == 3) {
                displayStack();
            }
            break;

        case 2:
            printf("\n--- QUEUE MENU ---\n");
            printf("1. Enqueue\n2. Dequeue\n3. Display\n");
            scanf("%d", &op);

            if (op == 1) {
                printf("Enter value: ");
                scanf("%d", &value);
                enqueue(value);
            } else if (op == 2) {
                dequeue();
            } else if (op == 3) {
                displayQueue();
            }
            break;

        case 3:
            printf("\n--- CIRCULAR QUEUE MENU ---\n");
            printf("1. Enqueue\n2. Dequeue\n3. Display\n");
            scanf("%d", &op);

            if (op == 1) {
                printf("Enter value: ");
                scanf("%d", &value);
                cqEnqueue(value);
            } else if (op == 2) {
                cqDequeue();
            } else if (op == 3) {
                displayCircularQueue();
            }
            break;

        case 4:
            exit(0);

        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}
