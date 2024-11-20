#include <stdio.h>

int main() {
    int number;
    printf("Enter a number (0-127): ");
    scanf("%d", &number);
    if (number >= 0 && number <= 127) {
        printf("The number in hexadecimal: %02X\n", number);
    } else {
        printf("Invalid input! Enter a number between 0 and 127.\n");
    }

    return 0;
}

