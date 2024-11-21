#include <stdio.h>

#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define FIND_SMALLEST(arr, size)   ({   \
    int min = arr[0];                  \
    for (int i = 1; i < size; i++) {   \
        min = MIN(min, arr[i]);        \
    }                                   \
    min;                               \
}) 

int main() {
    int arr[] = {10, 5, 15, 20, 1};
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("Smallest number: %d\n", FIND_SMALLEST(arr, size));
    return 0;
}

