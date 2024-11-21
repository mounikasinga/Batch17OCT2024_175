#include <stdio.h>
#include <stdlib.h>

int binarySearchRecursive(int arr[], int low, int high, int key) {
    if (low > high) {
        return -1;
    }
    int mid = low + (high - low) / 2;
    if (arr[mid] == key) {
        return mid; 
    }
    else if (arr[mid] < key) {
        return binarySearchRecursive(arr, mid + 1, high, key); 
    }
    else
        return binarySearchRecursive(arr, low, mid - 1, key);
}

int main() {
    int *a, n, key, i;
    printf("Enter n value: ");
    scanf("%d", &n);
    printf("Enter the key: ");
    scanf("%d", &key);
    a = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int result = binarySearchRecursive(a, 0, n - 1, key);
    if (result != -1) {
        printf("\nKey is found\n");
    } else {
        printf("\nKey is not found\n");
    }
    free(a);
    printf("\n\n");

    return 0;
}

