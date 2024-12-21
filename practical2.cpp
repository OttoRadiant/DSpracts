#define _CRT_SECURE_NO_WARNINGS  // Disable 'scanf' deprecation warning

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, n, temp, j, arr[10];

    // Step 1: Get the number of elements to be entered
    printf("Enter the maximum elements you want to store : ");
    scanf("%d", &n);

    // Step 2: Validate the input for n (should be between 1 and 10)
    if (n <= 0 || n > 10) {
        printf("Invalid input! Please enter a value between 1 and 10.\n");
        return 1; // Exit if the input is invalid
    }

    // Step 3: Input the elements into the array
    printf("Enter the elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Step 4: Bubble Sort to sort the array
    for (i = 0; i < n - 1; i++) {  // Outer loop runs n-1 times
        for (j = 0; j < n - i - 1; j++) {  // Inner loop runs n-i-1 times
            if (arr[j] > arr[j + 1]) {  // If elements are out of order, swap them
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    // Step 5: Print the sorted array
    printf("The array sorted in ascending order is :\n");
    for (i = 0; i < n; i++) {
        printf("%d\t", arr[i]);
    }
    printf("\n");

    return 0;
}
