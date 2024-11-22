#include <stdio.h>

int main() {
    int age = 20, height = 50;
    if ((age < 18 && height < 48) || (age > 60 && height > 72)) {
        printf("Condition is true\n");
    } else {
        printf("Condition is false\n");
    }
    char name = 'M';
    printf("Name: %c\n", name);
    char name$ = 'S';
    printf("Name$: %c\n", name$);

    return 0;
}

