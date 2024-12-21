#include <stdio.h>  // Use standard input/output
#include <stdlib.h>  // For exit(), if needed

int largest(int a[], int size);  // Proper function declaration
void radix_sort(int a[], int size);

int main() {
    int i;
    int a[10] = { 90, 23, 101, 45, 65, 23, 67, 89, 34, 23 };

    radix_sort(a, 10);  // Pass array and size

    printf("\nThe sorted array is: \n");
    for (i = 0; i < 10; i++) {
        printf("%d\t", a[i]);
    }

    return 0;
}

int largest(int a[], int size) {
    int larger = a[0], i;
    for (i = 1; i < size; i++) {
        if (a[i] > larger) {
            larger = a[i];
        }
    }
    return larger;
}

void radix_sort(int a[], int size) {
    int bucket[10][10], bucket_count[10];
    int i, j, k, remainder, NOP = 0, divisor = 1, larger, pass;

    larger = largest(a, size);  // Correct function call

    while (larger > 0) {
        NOP++;
        larger /= 10;
    }

    for (pass = 0; pass < NOP; pass++) {  // Radix sort pass
        for (i = 0; i < 10; i++) {
            bucket_count[i] = 0;
        }

        // Place numbers in buckets based on the current digit
        for (i = 0; i < size; i++) {
            remainder = (a[i] / divisor) % 10;
            bucket[remainder][bucket_count[remainder]] = a[i];
            bucket_count[remainder] += 1;
        }

        // Collect numbers from the buckets after the pass
        i = 0;
        for (k = 0; k < 10; k++) {
            for (j = 0; j < bucket_count[k]; j++) {
                a[i] = bucket[k][j];
                i++;
            }
        }

        divisor *= 10;  // Move to the next digit
    }
}
