#include <stdio.h>

int main() {
    int a = 12, b = 3;
    printf("Output of a: %d\n", (a > 100) && (b < 10));
    printf("Output of b: %d\n", (a == 4) && (b == 2));
    printf("Output of c: %d\n", (a == 11) && (a++));
    return 0;
}

