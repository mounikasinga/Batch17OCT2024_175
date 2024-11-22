#include <stdio.h>
int func1(int (*ptr)[3]) {
    for (int i = 0; i < 3; i++) {
        printf("%d ", ptr[0][i]); 
    }
    return 0;
}
int func2(int **ptr) {
    for (int i = 0; i < 3; i++) {
        printf("%d ", ptr[i][0]); 
    }
    printf("\n\n");
    return 0;
}
int main() {
    int arr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int *pArr[3] = {arr[0], arr[1], arr[2]};
    func1(arr);
    printf("\n");
    func2(pArr); 
    return 0;
}

