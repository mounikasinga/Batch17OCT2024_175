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
int main() {
    char operator;
    int num1, num2,result;
    printf("Enter an operator (+, -, *, /): ");
    scanf(" %c", &operator);
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);
    int (*operation)(int, int) = getaddr(operator);
    if (operation != NULL) {
        result = operation(num1, num2);
        printf("Result: %d\n", result);
    }
    return 0;
}

