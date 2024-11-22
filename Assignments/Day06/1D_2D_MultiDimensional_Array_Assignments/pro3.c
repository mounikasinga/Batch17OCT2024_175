#include <stdio.h>
#include <string.h>

void sort(char arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                char temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
    char arr[] = "xaybz";
    int n = sizeof(arr) / sizeof(arr[0]) - 1; 

    sort(arr, n);
    printf("Sorted string: %s\n", arr);

    return 0;
}

