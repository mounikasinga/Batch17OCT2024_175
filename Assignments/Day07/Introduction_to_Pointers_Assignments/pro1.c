#include <stdio.h>

void display(int *ptr) {
    printf("Address: 0x%x\n", ptr);
    printf("Content: %s\n", ptr);
}
int main() {
    char arr[] = "hello hi ";
    int *ptr = (int *)arr;
    printf("sizeof ptr: %d, arr: %d\n", sizeof(ptr), sizeof(arr));
    display(ptr);
    return 0;
}

