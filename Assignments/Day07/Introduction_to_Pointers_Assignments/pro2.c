#include <stdio.h>
#include <string.h>
#define MAX 100
#define SUCCESS 0
#define FAILURE 1

int append(char *ptr, char *appendstr) {
    while (*ptr) {
        ptr++;  
    }
    while (*appendstr) {
        *ptr = *appendstr; 
        ptr++;
        appendstr++;
    }
    *ptr = '\0';  
    return SUCCESS;
}
void display(char *ptr) {
    printf("Address: 0x%x\n", ptr);
    printf("Content: %s\n", ptr);
}
int main() {
    char arr[MAX] = "Learning C";
    char *ptr = arr;
    char appendstr[3] = "in my org";
    printf("Address of ptr: 0x%x\n", (unsigned int)ptr);
    int ret = append(ptr, appendstr);
    printf("Address of ptr: 0x%x\n", (unsigned int)ptr);
    if (ret == SUCCESS) {
        display(ptr);
    }
    return 0;
}

