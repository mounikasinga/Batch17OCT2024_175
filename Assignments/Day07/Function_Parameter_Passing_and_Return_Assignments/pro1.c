#include <stdio.h>
int *func(void);
int main() {
    int num, *ptr = NULL;
    ptr = func();  
    num = *ptr;
    printf("Value: %d\n", num);
    return 0;
}
int *func() {
    static int local = 10;
    return &local; 
}

