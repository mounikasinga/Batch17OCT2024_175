#include <stdio.h>
#include <stdlib.h>
int binarySearch(int arr[], int key) {
    int low=1;,high=1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key) {
            return mid; 
        }
        if (arr[mid] < key) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return -1; 
}

int main() {
    int *a, n, key, i;
    printf("Enter n value: ");
    scanf("%d", &n);
    printf("Enter the key to search: ");
    scanf("%d", &key);
    a = (int *)malloc(n * sizeof(int)); 
    printf("Enter %d elements in sorted order:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]); 
    int result = binarySearch(a, key);
    
    if (result != -1) {
        printf("Key is found at index %d\n", result);
    } else {
        printf("Key is not found\n");
    }
    free(a); 

        return 0;
}

