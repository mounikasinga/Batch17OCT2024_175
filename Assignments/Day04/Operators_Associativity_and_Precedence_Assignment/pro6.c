#include <stdio.h>

int main() {
    int age = 10, height = 45, year = 2000;
    printf("Output of a: %d\n", (age < 12 && height < 48) || (age > 65 && height > 72));
    printf("Output of b: %d\n", (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
    return 0;
}

