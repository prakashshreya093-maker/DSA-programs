#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* last = NULL;   

void insertAtBeginning(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    if (last == NULL) {  
        last = newNode;
        last->next = last;
    } else {
        newNode->next = last->next;
        last->next = newNode;
    }
    printf("Inserted %d at beginning\n", value);
}

void insertAtEnd(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    if (last == NULL) {
        last = newNode;
        last->next = last;
    } else {
        newNode->next = last->next;
        last->next = newNode;
        last = newNode;  
    }
    printf("Inserted %d at end\n", value);
}

void deleteNode(int value) {
    if (last == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node *temp = last->next, *prev = last;

    if (last == last->next && last->data == value) {
        free(last);
        last = NULL;
        printf("Deleted %d\n", value);
        return;
    }

      do {
        if (temp->data == value)
            break;
        prev = temp;
        temp = temp->next;
    } while (temp != last->next);

    
    if (temp->data != value) {
        printf("Value %d not found\n", value);
        return;
    }

   
    prev->next = temp->next;

   
    if (temp == last)
        last = prev;

    printf("Deleted %d\n", value);
    free(temp);
}


void display() {
    if (last == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = last->next;
    printf("Circular Linked List: ");

    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != last->next);

    printf("(head)\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\n--- Circular Linked List Menu ---\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Delete node\n");
        printf("4. Display list\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtBeginning(value);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtEnd(value);
                break;

            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteNode(value);
                break;

            case 4:
                display();
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
