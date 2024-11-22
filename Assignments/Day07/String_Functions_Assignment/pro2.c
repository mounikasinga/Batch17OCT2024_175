#include <stdio.h>
#include<string.h>
char *strncat_custom(char *dest, const char *src, size_t n) {
    char *destPtr = dest;
    while (*destPtr != '\0') {
        destPtr++;
    }
    while (n-- && *src != '\0') {
        *destPtr++ = *src++;
    }
    *destPtr = '\0';
    return dest;
}
int main() {
    char dest[100] = "Hello, ";
    char src[] = "world!";
    strncat_custom(dest, src, 3);  
    printf("Concatenated string: %s\n", dest);
    return 0;
}

