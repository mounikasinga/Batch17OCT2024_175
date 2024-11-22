#include <stdio.h>

int factorial_tail_recursive(int n, int accumulator) {
    if (n <= 1) {
        return accumulator;
    }
    return factorial_tail_recursive(n - 1, n * accumulator);
}
int main() {
    int number,result;
    printf("Enter a number to calculate its factorial: ");
    scanf("%d", &number);
    result = factorial_tail_recursive(number, 1);
    printf("Factorial of %d is %d\n", number, result);
    return 0;
}

