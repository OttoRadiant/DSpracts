#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define SIZE 10

int ht[SIZE];

void store(int x[], int n);
int modulodivision(int key);
int linearprobe(int address);

int main() {
    int i, n, x[10];

    printf("Enter the number of elements: ");
    scanf_s("%d", &n);

    printf("Enter the elements:\n");
    for (i = 0; i < n; i++) {
        scanf_s("%d", &x[i]);
    }

    store(x, n);





    printf("Hashtable is as shown:\n");
    for (i = 0; i < SIZE; i++) {
        printf("%d ", ht[i]);
    }

    return 0;
}

void store(int x[], int n) {
    int i, key, address;

    // Initializing hash table to empty (-1 indicates empty slot)
    for (i = 0; i < SIZE; i++) {
        ht[i] = -1;
    }

    // Copying elements from original array to hash table
    for (i = 0; i < n; i++) {
        key = x[i];
        address = modulodivision(key);

        // If collision occurs, resolve using linear probing
        if (ht[address] != -1) {
            address = linearprobe(address);
        }

        ht[address] = key;
    }
}

// Hash function using modulo operation
int modulodivision(int key) {
    return key % SIZE;  // Correcting the range to [0, SIZE-1]
}

// Collision resolution using linear probing
int linearprobe(int address) {
    while (ht[address] != -1) {
        address++;
        if (address == SIZE) {  // If it reaches the end, wrap around
            address = 0;
        }
    }
    return address;
}
