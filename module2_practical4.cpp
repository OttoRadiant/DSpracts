#include<stdio.h> 

// Change return type to void since we don't need to return anything
void digit_extraction(int key) {
    int first_digit = 0;
    int fourth_digit = 0;

    // Extract the first digit (1st position) from the key
    first_digit = key % 10000000;      // Get last 7 digits
    first_digit = first_digit / 1000000;  // Extract the 7th digit from the left (i.e., first digit)

    // Extract the fourth digit (4th position) from the key
    fourth_digit = key % 1000;          // Get last 3 digits
    fourth_digit = fourth_digit / 100;  // Extract the 4th digit

    // Print the result: Location is formed by first_digit and fourth_digit
    printf("%d key would be hashed at location %d%d\n", key, first_digit, fourth_digit);
}

int main() {
    digit_extraction(1347878); // Should print hashed location based on extracted digits
    digit_extraction(1234678); // Should print hashed location based on extracted digits
    return 0;
}
