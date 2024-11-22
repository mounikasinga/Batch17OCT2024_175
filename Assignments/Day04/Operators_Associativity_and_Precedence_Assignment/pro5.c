#include <stdio.h>

int main() {
    int a = 10, b = 11;
    printf("Output of a: %d\n", (a > 10) || (b < 10));
    printf("Output of b: %d\n", a || 12.12);
    printf("Output of c: %d\n", a || b);
    printf("Output of d: %d\n", !(a > 5));

    return 0;
}

