#include <stdio.h>

void swap_nums(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
    printf("In swap_nums, a: %d, b: %d\n", a, b);
}
void swap_pointers(int **a, int **b) {
    int *temp = *a;
    *a = *b;
    *b = temp;
}
int main() {
    int x = 10, y = 20;
    int *px = &x, *py = &y;
    printf("Before swap_nums: x = %d, y = %d\n", x, y);
    swap_nums(x, y);
    printf("After swap_nums: x = %d, y = %d\n", x, y);
    printf("Before swap_pointers: *px = %d, *py = %d\n", *px, *py);
    swap_pointers(&px, &py);
    printf("After swap_pointers: *px = %d, *py = %d\n", *px, *py);
    return 0;
}

