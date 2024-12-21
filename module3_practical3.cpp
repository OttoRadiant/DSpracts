#include<stdio.h>
#include<string.h>
#include<math.h> // For power operation

#define MAX 50 // max size defined
int stack[MAX]; // global stack to store numbers
char post[MAX]; // global array to store the postfix expression
int top = -1; // initializing top to -1

void pushstack(int tmp); // push function to push data into the stack
void evaluate(char c); // function to evaluate and perform operations

int main() {
    int i, l;
    printf("Insert a postfix notation: ");
    fgets(post, MAX, stdin); // safer alternative to gets
    l = strlen(post);

    // Remove newline character from the string if present
    if (post[l - 1] == '\n') {
        post[l - 1] = '\0';
        l--;
    }

    // Process the postfix expression
    for (i = 0; i < l; i++) {
        if (post[i] >= '0' && post[i] <= '9') {
            pushstack(post[i] - '0'); // convert char to int and push to stack
        }
        else if (post[i] == '+' || post[i] == '-' || post[i] == '*' ||
            post[i] == '/' || post[i] == '^') { // operators
            evaluate(post[i]);
        }
    }

    // Print the result from the top of the stack
    printf("\n\nResult: %d\n", stack[top]);
    return 0;
}

void pushstack(int tmp) {
    top++; // increment top
    stack[top] = tmp; // push the number onto the stack
}

void evaluate(char c) {
    int a, b, ans;
    a = stack[top]; // pop the top element
    top--;
    b = stack[top]; // pop the next element
    top--;

    // Perform operation based on the operator
    switch (c) {
    case '+':
        ans = b + a;
        break;
    case '-':
        ans = b - a;
        break;
    case '*':
        ans = b * a;
        break;
    case '/':
        ans = b / a;
        break;
    case '^':
        ans = (int)pow(b, a); // Use pow() to calculate the power
        break;
    default:
        ans = 0; // default case
    }

    top++; // increment top 
    stack[top] = ans; // push the result back onto the stack
}
