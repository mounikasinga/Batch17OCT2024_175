#include <stdio.h>

int main() {
    float test1, test2, test3, project;
    
    // Input scores
    printf("Enter Test1 score (out of 100): ");
    scanf("%f", &test1);
    printf("Enter Test2 score (out of 100): ");
    scanf("%f", &test2);
    printf("Enter Test3 score (out of 100): ");
    scanf("%f", &test3);
    printf("Enter Project score (out of 100): ");
    scanf("%f", &project);
    
    if (test1 >= 75 && test2 >= 75 && test3 >= 70 && project >= 75) {
        switch(1) {
            case 1:
                printf("You are eligible for deployment post training.\n");
                break;
        }
    } else {
        printf("You are not eligible for deployment. Ensure all conditions are met.\n");
    }
    
    return 0;
}

