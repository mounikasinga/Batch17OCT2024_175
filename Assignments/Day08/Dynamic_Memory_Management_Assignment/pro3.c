#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **allocate_array_memory(char **ptr, int n) {
    ptr = malloc(n * sizeof(char *));
    return ptr;
}

char *allocate_string_memory(char *string) {
    char *new_string = malloc(strlen(string) + 1);
    strcpy(new_string, string);
    return new_string;
}

void display(char **arr, int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%s\n", arr[i]);
    }
}

void free_array_memory(char **ptr, int n) 
{
    int i;
    for (i = 0; i < n; i++) {
        free(ptr[i]);
    }
    free(ptr);
}

void free_string_memory(char *ptr) {
    free(ptr);
}

int main() {
    int n,count = 0;
    char **arr = NULL;
    char input[80];
    printf("Enter the number of strings: ");
    scanf("%d", &n);
    getchar();
    arr = allocate_array_memory(arr, n);
    while (count < n) {
        printf("Enter string %d (or 'end' to stop): ", count + 1);
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';

        if (strcmp(input, "end") == 0 || strcmp(input, "END") == 0) {
            break;
        }

        arr[count] = allocate_string_memory(input);
        count++;
    }

    display(arr, count);
    free_array_memory(arr, count);
    return 0;
}

