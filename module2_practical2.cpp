#include <stdio.h>

int main() {
    int first, last, middle, size, i, key, list[100];

    // Get the size of the list
    printf("Enter the size of the list: ");
    scanf_s("%d", &size);  // Changed to scanf_s

    // Get the list of integers in ascending order
    printf("Enter %d integer values in Ascending order\n", size);
    for (i = 0; i < size; i++) {
        scanf_s("%d", &list[i]);  // Changed to scanf_s
    }

    // Get the key to search for
    printf("Enter value to be searched: ");
    scanf_s("%d", &key);  // Changed to scanf_s

    // Initialize first, last, and middle
    first = 0;
    last = size - 1;
    middle = (first + last) / 2;

    // Binary search logic
    while (first <= last) {
        if (list[middle] < key) {
            // Move the first pointer to middle + 1
            first = middle + 1;
        }
        else if (list[middle] == key) {
            // Element found
            printf("Element found at index %d.\n", middle);
            break;
        }
        else {
            // Move the last pointer to middle - 1
            last = middle - 1;
        }

        // Recalculate middle after each iteration
        middle = (first + last) / 2;
    }

    // If element not found
    if (first > last) {
        printf("Element not found in the list.\n");
    }

    return 0;
}
