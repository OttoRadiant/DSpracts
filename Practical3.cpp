#define _CRT_SECURE_NO_WARNINGS  
#include<stdio.h>

int smallest(int[], int, int);

int main() {
    int a[10] = { 10, 9, 7, 101, 23, 44, 12, 78, 34, 23 };
    int i, j, pos, temp;
    for (i = 0; i < 10; i++) {
        pos = smallest(a, 10, i);
        temp = a[i];
        a[i] = a[pos];
        a[pos] = temp;
    }

    printf("\nPrinting sorted elements...\n");
    for (i = 0; i < 10; i++) {
        printf("%d\n", a[i]);
    }

    return 0;
}

int smallest(int a[], int n, int i) {
    int small, pos, j;
    small = a[i];
    pos = i;
    for (j = i + 1; j < n; j++) {  // Use dynamic array size here
        if (a[j] < small) {
            small = a[j];
            pos = j;
        }
    }
    return pos;
}
