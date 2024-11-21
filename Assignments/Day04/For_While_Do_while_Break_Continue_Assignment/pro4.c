#include <stdio.h>

int main() {
    int N, num;
    int positive = 0, negative = 0, zero = 0;
    
    printf("Enter number of integers to be entered: ");
    while (scanf("%d", &N) != 1) {
        printf("Invalid input. Please enter an integer for N: ");
        while (getchar() != '\n');  
   }
    
    for (int i = 0; i < N; i++) {
        printf("Enter integer %d: ", i + 1);
        while (scanf("%d", &num) != 1) {
            printf("Invalid input. Please enter a valid integer: ");
            while (getchar() != '\n');
        }
        
        if (num > 0) {
            positive++;
        } else if (num < 0) {
            negative++;
        } else {
            zero++;
        }
    }
    
    printf("Positive numbers: %d\n", positive);
    printf("Negative numbers: %d\n", negative);
    printf("Zeroes: %d\n", zero);
    
    return 0;
}

