#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void shellsort(int arr[], int num) {
    int i, j, k, tmp;

    // Shell Sort Algorithm
    for (i = num / 2; i > 0; i = i / 2) {
        for (j = i; j < num; j++) {
            for (k = j - i; k >= 0; k = k - i) {
                if (arr[k + i] >= arr[k]) break;
                else {
                    tmp = arr[k];
                    arr[k] = arr[k + i];
                    arr[k + i] = tmp;
                }
            }
        }
    }
}

int main() {
    int arr[30];
    int k, num;

    // Get the number of elements from the user
    printf("Enter total number of elements: ");
    scanf("%d", &num);  // This line will not give an error now

    // Get the elements of the array from the user
    printf("\nEnter %d numbers: \n", num);
    for (k = 0; k < num; k++) {
        scanf("%d", &arr[k]);  // This line will not give an error now
    }

    // Call shellsort function to sort the array
    shellsort(arr, num);

    // Print the sorted array
    printf("\nSorted array is: ");
    for (k = 0; k < num; k++) {
        printf("%d ", arr[k]);
    }

    return 0;
}
