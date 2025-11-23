#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void insertEnd(struct Node** head, int value) {
    struct Node* newNode = createNode(value);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

struct Node* concatenate(struct Node* list1, struct Node* list2) {
    if (list1 == NULL) return list2;
    if (list2 == NULL) return list1;

    struct Node* temp = list1;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = list2;

    return list1;
}

void display(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node *list1 = NULL, *list2 = NULL, *result = NULL;

    insertEnd(&list1, 10);
    insertEnd(&list1, 20);
    insertEnd(&list1, 30);

    insertEnd(&list2, 40);
    insertEnd(&list2, 50);
    insertEnd(&list2, 60);

    printf("List 1:\n");
    display(list1);

    printf("List 2:\n");
    display(list2);

    result = concatenate(list1, list2);

    printf("\nAfter Concatenation:\n");
    display(result);

    return 0;
}

