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
int (*getaddr(char mychar))(int, int) {
    switch (mychar) {
        case '+': 
		return add;
        case '-': 
		return sub;
        case '*': 
		return multiply;
        case '/': 
		return divide;
        default:
            printf("Invalid operator.\n");
            return NULL;
    }
}
int invokefunc(int (*func)(int, int), int val1) {
    int val2;
    printf("Enter the second value: ");
    scanf("%d", &val2);
    return func(val1, val2);
}
int main() {
    char operator;
    int num1 = 10;
    printf("Enter an operator (+, -, *, /): ");
    scanf(" %c", &operator);
    int (*operation)(int, int) = getaddr(operator);
    if (operation != NULL) {
        int result = invokefunc(operation, num1);
        printf("Result: %d\n", result);
    }
    return 0;
}

