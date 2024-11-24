#include <stdio.h>
int add(int x, int y) {
    return x + y;
}
int sub(int x, int y) {
    return x - y;
}
int multiply(int x, int y) {
    return x * y;
}
int divide(int x, int y) {
    if (y == 0) {
        printf("Error! Division by zero.\n");
        return 0;
    }
    return x / y;
}
int main() {
    int (*operations[])(int, int) = {add, sub, multiply, divide};
    char operator;
    int num1, num2;
    printf("Enter an operator (+, -, *, /): ");
    scanf(" %c", &operator);
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);
    int result;
    switch (operator) {
        case '+':
            result = operations[0](num1, num2);
            break;
        case '-':
            result = operations[1](num1, num2);
            break;
        case '*':
            result = operations[2](num1, num2);
            break;
        case '/':
            result = operations[3](num1, num2);
            break;
        default:
            printf("Invalid operator.\n");
            return -1;
    }
    printf("Result: %d\n", result);
    return 0;
}

