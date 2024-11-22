#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* read_extract_characters() {
    char input[51];  
    printf("Enter a string (max 50 characters): ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0'; 
    int length = strlen(input);
    int newLength = (length + 1) / 2;  
    char *extracted = (char *)malloc(newLength + 1);

    int j = 0;
    for (int i = 1; i < length; i += 2) {
        extracted[j++] = input[i];
    }
    extracted[j] = '\0';  

    return extracted;  
}

int main() {
    char *oddChars = read_extract_characters(); 
    printf("Extracted characters at odd indices: %s\n", oddChars);
    free(oddChars);

    return 0;
}

