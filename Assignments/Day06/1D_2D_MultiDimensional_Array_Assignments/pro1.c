#include <stdio.h>

#define MAX 100

int getmax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int main() {
    int arr[MAX] = {11, 22, 33, 99, 7}; 
    int n = 5; 

    int max_value = getmax(arr, n);
    printf("The maximum value in the array is: %d\n", max_value);

    return 0;
}

