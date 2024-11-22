#include <stdio.h>
#include <string.h>

void replace_vowels_with_ay(char *word) {
    char vowels[] = "aeiouAEIOU";
    char result[80];
    int j = 0;
    for (int i = 0; word[i] != '\0'; i++) {
        if (strchr(vowels, word[i])) {
            result[j++] = 'a';
            result[j++] = 'y';
        } else {
            result[j++] = word[i];
        }
    }
    result[j] = '\0';
    strcpy(word, result);
}

int main() {
    char word[40];
    printf("Enter a word: ");
    fgets(word, sizeof(word), stdin);
    word[strcspn(word, "\n")] = '\0'; 
    replace_vowels_with_ay(word);
    printf("Updated word: %s\n", word);
    return 0;
}

