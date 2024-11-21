#include <stdio.h>

int main() {
    char choice;
    printf("Enter your choice (Y|N): ");
    scanf("%c", &choice);
    if (choice == 'y' || choice == 'Y') {
        printf("Yes\n");
    } else if (choice == 'n' || choice == 'N') {
        printf("No\n");
    } else {
        printf("Invalid character\n");
    }

    return 0;
}

