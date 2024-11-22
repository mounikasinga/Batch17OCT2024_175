#include <stdio.h>
#include <stdlib.h>
int compare_chars(const void *a, const void *b) {
    return (*(char*)a - *(char*)b);
}
#define SORT_CHAR_ARRAY(arr, size) qsort(arr, size, sizeof(char), compare_chars)

int main() {
    char arr[] = {'z', 'd', 'a', 'r', 'e', 'c', 'b'};
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("Before sorting: ");
    for (int i = 0; i < size; i++) {
        printf("%c ", arr[i]);
    }
    printf("\n");
    SORT_CHAR_ARRAY(arr, size);
    printf("After sorting: ");
    for (int i = 0; i < size; i++) {
        printf("%c ", arr[i]);
    }
    printf("\n");
    return 0;
}

