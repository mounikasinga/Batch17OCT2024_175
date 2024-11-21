#include <stdio.h>
#include <ctype.h>

int main() {
    char str[81]; 
    
    while (1) {
        printf("Enter a string (type 'END' to exit): ");
        fgets(str, 81, stdin);
        
        if (strncmp(str, "END", 3) == 0 && (str[3] == '\n' || str[3] == '\0')) {
            break;  
       }
        

        for (int i = 0; str[i]; i++) {
            str[i] = toupper(str[i]);
        }
        
        printf("Uppercase String: %s", str);
    }
    
    return 0;
}

