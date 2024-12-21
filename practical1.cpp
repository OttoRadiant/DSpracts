#define _CRT_SECURE_NO_WARNINGS  
#include <stdio.h>

int main() {
    int i, n, temp, arr[10];
    printf("Enter number of elements: ");
    scanf("%d", &n);
    if (n <= 0 || n > 10) 
    return 1;
    printf("Enter elements: \n");
    for (i = 0; i < n; i++) 
    scanf("%d", &arr[i]);

    for (i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1]) 
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }

    printf("Sorted array: ");
    for (i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");

    return 0;
}


