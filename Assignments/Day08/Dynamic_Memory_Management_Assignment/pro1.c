#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *process_str(char *line) {
    char *result = malloc(80 * sizeof(char));
    char *token = strtok(line, " ");
    result[0] = '\0';
    while (token != NULL) {
        strcat(result, token);
        strcat(result, "_");
        token = strtok(NULL, " ");
    }
    result[strlen(result) - 1] = '\0';
    return result;
}
int main() {
    char line[80];
    char *final_str;
    printf("Enter a line of text: ");
    fgets(line, sizeof(line), stdin);
    line[strcspn(line, "\n")] = '\0';
    final_str = process_str(line);
    printf("Concatenated String: %s\n", final_str);
    free(final_str);
    return 0;
}

