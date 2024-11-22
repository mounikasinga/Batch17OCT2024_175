#include <stdio.h>

int main(void) {
    int i = 10;
    char a = 'd';
    a += 10; 
    printf("Value of a after a += 10: %d\n", a);
    a *= 5; 
    printf("Value of a after a *= 5: %d\n", a);
    a /= 4; 
    printf("Value of a after a /= 4: %d\n", a);
    a %= 2;
    printf("Value of a after a %%= 2: %d\n", a);
    a *= a + i;  
    printf("Final value of a: %d\n", a);

    return 0;
}

