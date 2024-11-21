#include <stdio.h>
int factorial(int num) {
    int fact = 1;
    for (int i = 1; i <= num; i++) {
        fact *= i;
    }
    return fact;
}

int main() {
    int n, sum = 0;
    printf("Enter a number: ");
    scanf("%d", &n);
    
    for (int i = 1; i <= n; i++) {
        sum += factorial(i);
    }
    
    printf("Cumulative sum of factorials up to %d: ", n);
    for (int i = n; i > 0; i--) {
        printf("%d!%s", i, (i == 1) ? " = " : " + ");
    }
    printf("%d\n", sum);
    
    return 0;
}

