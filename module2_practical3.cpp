#include <stdio.h>  // Make sure this is included

#define SIZE 7

int arr[SIZE];

// Initialize the array with -1
void init() {
    int i;
    for (i = 0; i < SIZE; i++) {
        arr[i] = -1;  // Mark all slots as empty
    }
}

// Insert function using modulo operation for hashing
void insert(int value) {
    int key = value % SIZE;  // Modulo division to calculate the key

    if (arr[key] == -1) {  // If the slot is empty
        arr[key] = value;
        printf("%d inserted at arr[%d]\n", value, key);  // printf used here
    }
    else {  // If there is a collision
        printf("Collision: arr[%d] has element %d already!\n", key, arr[key]);
        printf("Unable to insert %d\n", value);
    }
}

// Search function to find if a value exists
void search(int value) {
    int key = value % SIZE;  // Modulo division to calculate the key

    if (arr[key] == value) {  // If the value exists at the key
        printf("Search Found: %d is at arr[%d]\n", value, key);
    }
    else {  // If not found
        printf("Search Not Found\n");
    }
}

// Display the hash table
void display() {
    int i;
    for (i = 0; i < SIZE; i++) {
        if (arr[i] != -1) {
            printf("arr[%d] = %d\n", i, arr[i]);  // printf used here
        }
        else {
            printf("arr[%d] = -1 (empty)\n", i);  // printf used here
        }
    }
}

int main() {
    init();  // Initialize the hash table

    insert(10);  // key = 10 % 7 => 3
    insert(4);   // key = 4 % 7 => 4
    insert(2);   // key = 2 % 7 => 2
    insert(3);   // key = 3 % 7 => 3 (collision)

    printf("Hash table:\n");  // printf used here
    display();

    printf("\n");

    printf("Searching value 4..\n");  // printf used here
    search(4);

    return 0;
}
