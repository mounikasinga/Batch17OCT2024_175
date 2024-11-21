#include <stdio.h>

int main() {
    int n;
    float sum = 0.0;
    
    printf("Enter a number n: ");
    scanf("%d", &n);
    
    for (int i = 1; i <= n; i++) {
        sum += 1.0 / i;
    }
    
    printf("Sum of the harmonic series for %d terms: %.2f\n", n, sum);
    
    return 0;
}

