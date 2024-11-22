#include <stdio.h>

int max_depth = 0;
int current_depth = 0;
int factorial(int n) {
    int result;
    current_depth++;
    if (current_depth > max_depth) {
        max_depth = current_depth;
    }
    if (n <= 1) {
        current_depth--;
        return 1;
    }
    result = n * factorial(n - 1);
    current_depth--;
    return result;
}
int main() {
    int number,result;
    printf("Enter a number to calculate its factorial: ");
    scanf("%d", &number);
    result = factorial(number);
    printf("Factorial of %d is %d\n", number, result);
    printf("Maximum stack depth: %d\n", max_depth);
    return 0;
}

