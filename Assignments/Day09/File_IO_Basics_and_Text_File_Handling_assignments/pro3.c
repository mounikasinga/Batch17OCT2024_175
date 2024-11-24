#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 80
void display(FILE *file) {
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }
    char line[MAX_LEN];
    while (fgets(line, MAX_LEN, file) != NULL) {
        printf("%s", line);
    }
}
int main() {
    FILE *file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error opening input file.\n");
        return -1;
    }
    display(file);
    fclose(file);
    return 0;
}

