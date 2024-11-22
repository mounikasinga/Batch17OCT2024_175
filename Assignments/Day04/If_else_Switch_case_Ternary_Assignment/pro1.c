#include <stdio.h>

int main() {
    int a, b, c;
    
    printf("Enter three numbers: ");
    scanf("%d %d %d", &a, &b, &c);
    
    int smallest = (a < b && a < c) ? a : (b < c) ? b : c;
    
    printf("The smallest number is: %d\n", smallest);
    
    return 0;
}

