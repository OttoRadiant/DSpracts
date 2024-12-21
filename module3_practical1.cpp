#include <stdio.h> 

int stack[100], i, j, choice = 0, n, top = -1;

void push();
void pop();
void show();

int main() // Correcting the return type of main
{
    printf("Enter the number of elements in the stack: ");
    scanf_s("%d", &n);  // Use scanf_s for secure input
    printf("***Stack operations using array***\n");
    printf("---------------------------------\n");

    while (choice != 4) {
        printf("Choose one from the below options...\n");
        printf("1. Push\n2. Pop\n3. Show\n4. Exit\n");
        printf("Enter your choice: ");
        scanf_s("%d", &choice); // Use scanf_s for secure input

        switch (choice) {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            show();
            break;
        case 4:
            printf("Exiting....\n");
            break;
        default:
            printf("Please enter a valid choice.\n");
        }
    }

    return 0; // Return 0 to indicate successful execution
}

void push()
{
    int val;
    if (top == n - 1) // Corrected overflow condition
        printf("\nOverflow: Stack is full.\n");
    else {
        printf("Enter the value to push onto the stack: ");
        scanf_s("%d", &val);  // Use scanf_s for secure input
        top = top + 1;
        stack[top] = val;
    }
}

void pop()
{
    if (top == -1)
        printf("Underflow: Stack is empty. Cannot pop.\n");
    else
        top = top - 1;
}

void show()
{
    if (top == -1) { // Check if stack is empty
        printf("Stack is empty.\n");
    }
    else {
        printf("Stack elements are:\n");
        for (i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}
