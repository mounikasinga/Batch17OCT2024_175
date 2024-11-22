#include <stdio.h>

int main() {
    int x;
    x = 34 + 12 / 4 - 56;
    printf("Output of a: %d\n", x);
    int result_b = 12 + 3 - 4 / 2 < 3 + 1;
    printf("Output of b: %d\n", result_b);
    int result_c = (2 + (3 + 2)) * 10;
    printf("Output of c: %d\n", result_c);
    int result_d = 34 + 12 / 4 - 45;
    printf("Output of d: %d\n", result_d);
    return 0;
}

