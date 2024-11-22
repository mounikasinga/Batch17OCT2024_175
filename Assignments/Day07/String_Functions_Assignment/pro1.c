#include <stdio.h>
#include <string.h>

int tokenise(char *arr) {
    char *token;
    int count = 0;
    token = strtok(arr, "|");
    while (token != NULL) {
        printf("%s\n", token);
        count++;
        token = strtok(NULL, "|");
    }
    return count;
}
int main() {
    char str[100];
    printf("Enter a line of text: ");
    fgets(str, sizeof(str), stdin);
    int numTokens = tokenise(str);
    printf("Total number of tokens: %d\n", numTokens);
    return 0;
}

