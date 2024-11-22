#include <stdio.h>

int main() {
    int code;
    
    printf("Enter the designation code: ");
    scanf("%d", &code);
    
    switch (code) {
        case 2:
            printf("Designation: Software Developer\n");
            break;
        case 3:
            printf("Designation: Senior Software Developer\n");
            break;
        case 4:
            printf("Designation: Team Lead\n");
            break;
        case 5:
            printf("Designation: Senior Team Lead\n");
            break;
        default:
            printf("Incorrect designation code\n");
    }
    
    return 0;
}

