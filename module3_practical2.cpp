#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
} *top = NULL;

void push(int);
void pop();
void display();

int main() {
    int choice, value;
    printf("\nIMPLEMENTING STACKS USING LINKED LISTS\n");

    while (1) {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("\nEnter your choice: ");
        scanf_s("%d", &choice); // Use scanf_s instead of scanf

        switch (choice) {
        case 1:
            printf("\nEnter the value to insert: ");
            scanf_s("%d", &value); // Use scanf_s instead of scanf
            push(value);
            break;

        case 2:
            pop();
            break;

        case 3:
            display();
            break;

        case 4:
            printf("\nExiting program.\n");
            exit(0);

        default:
            printf("\nInvalid Choice\n");
        }
    }
}

void push(int value) {
    struct Node* newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    if (top == NULL) {
        newNode->next = NULL;
    }
    else {
        newNode->next = top;
    }

    top = newNode;
    printf("Node %d is Inserted\n\n", value);
}

void pop() {
    if (top == NULL) {
        printf("\nEMPTY STACK\n");
    }
    else {
        struct Node* temp = top;
        printf("\nPopped Element: %d\n", temp->data);
        top = temp->next;
        free(temp);
    }
}

void display() {
    if (top == NULL) {
        printf("\nEMPTY STACK\n");
    }
    else {
        printf("The stack is: \n");
        struct Node* temp = top;

        while (temp != NULL) {
            printf("%d", temp->data);
            if (temp->next != NULL) {
                printf(" ---> ");
            }
            temp = temp->next;
        }
        printf(" ---> NULL\n\n");
    }
}
