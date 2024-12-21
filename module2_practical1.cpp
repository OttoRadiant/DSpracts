#define _CRT_SECURE_NO_WARNINGS  
#include<stdio.h>

void main() {
    int a[10] = { 10, 23, 40, 1, 2, 0, 14, 13, 50, 9 };
    int item, i, flag = -1;  // Initialize flag to -1 (not found)

    printf("\nEnter Item which is to be searched: ");
    scanf("%d", &item);

    // Loop to search for the item
    for (i = 0; i < 10; i++) {
        if (a[i] == item) {  // Use equality comparison (==)
            flag = i + 1;  // Set flag to the position of the item (1-based index)
            break;
        }
    }

    // Output the result
    if (flag != -1) {
        printf("\nItem found at location %d\n", flag);
    }
    else {
        printf("\nItem not found\n");
    }
}
