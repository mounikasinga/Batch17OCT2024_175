#include <stdio.h>
#include <string.h>

#define ROWS 3
#define COLS 3

void init(int arr[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            arr[i][j] = 0;
        }
    }
}

int search_update(int arr[ROWS][COLS], int old_val, int new_val) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (arr[i][j] == old_val) {
                arr[i][j] = new_val;
                return 0;  
            }
        }
    }
    return 1; 
}

void display(int arr[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int arr[ROWS][COLS] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    
    printf("Initial array:\n");
    display(arr);

    int old_val, new_val;
    printf("Enter value to search: ");
    scanf("%d", &old_val);
    printf("Enter new value: ");
    scanf("%d", &new_val);

    if (search_update(arr, old_val, new_val) == 0) {
        printf("Array after update:\n");
        display(arr);
    } else {
        printf("Element not found\n");
    }

    return 0;
}

