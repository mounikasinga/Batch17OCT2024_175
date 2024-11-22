#include <stdio.h>
#include <string.h>
#define MAX 80
#define SUCCESS 1
#define FAILURE 0
int search_insert(char name[], char search_char) {
    int len = strlen(name);
    for (int i = 0; i < len; i++) {
        if (name[i] == search_char) 
            for (int j = len; j >= i; j--) {
                name[j + 1] = name[j];
            }
            name[i + 1] = '_'; 
            return SUCCESS;
        }
    return FAILURE;  
}
int main() {
    char name[MAX] = "ABC";
    char search_char = 'B';
    int ret = search_insert(name, search_char);
    if (ret == SUCCESS) {
        printf("Updated string: %s\n", name);
    } else {
        printf("Character not found.\n");
    }
    return 0;
}

