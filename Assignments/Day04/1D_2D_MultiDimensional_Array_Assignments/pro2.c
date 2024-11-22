#include <stdio.h>

#define MAX 100

void init(int arr[], int n, int start_value) {
    for (int i = 0; i < n; i++) {
        arr[i] = start_value + i;
    }
}

void update(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i]++;
    }
}

void display(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[MAX];
    int n, start_value;
    printf("Enter number of elements (N): ");
    scanf("%d", &n);
    printf("Enter the start value: ");
    scanf("%d", &start_value);
    init(arr, n, start_value);
    printf("Initialized array: ");
    display(arr, n);
    update(arr, n);
    printf("Updated array: ");
    display(arr, n);

    return 0;
}

