#include <stdio.h>
#include <math.h>

int count_digits(int key) {
    int count = 0;
    while (key != 0) {
        key /= 10;
        ++count;
    }
    return count;
}

int reversDigits(int num) {
    int rev_num = 0;
    while (num > 0) {
        rev_num = rev_num * 10 + num % 10;
        num = num / 10;
    }
    return rev_num;
}

int fold_boundary(int key, int size) {
    int key_roll = key;
    int key_sum = 0;
    int key_frac = 0;
    int left = 0;
    int right = 0;
    int middle = 0;
    int digits = 0;
    int key_length = 0;
    int fraction = size;

    key_length = count_digits(key_roll);

    key_frac = key_roll / (int)pow(10, (key_length - fraction)); // start digit
    left = reversDigits(key_frac);
    key_roll = key_roll % (int)pow(10, key_length - fraction);  // remove left part

    right = reversDigits(key_roll); // reverse remaining right part
    digits = count_digits(key);     // number of digits in the original key
    middle = (key / (int)pow(10, digits / 2)) % 10; // middle digit

    key_sum = left + middle + right; // sum the parts
    return key_sum % (int)pow(10, fraction); // ignore carry
}

int main() {
    printf("\n\n%d", fold_boundary(3347878, 3)); // Expected Output: 318
    printf("\n\n%d", fold_boundary(1234678, 3)); // Expected Output: 201
    return 0;
}
