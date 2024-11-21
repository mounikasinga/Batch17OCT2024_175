#include <stdio.h>
#include <stdlib.h>
int swap(int *, int *);
int bubbleSort(int *arr, int n) {
    int i, j, temp, swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = 0;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) 
                swap(&arr[j],&arr[j + 1]);
                swapped = 1; 
        }
        if (swapped == 0)
            break;
    }
    return 0;
}
int swap(int *a, int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

int main() {
    int *arr, n;
    scanf("%d", &n);
    arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    bubbleSort(arr, n);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    free(arr);
    return 0;
}

