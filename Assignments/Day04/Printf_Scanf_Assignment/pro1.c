#include <stdio.h>
#include <string.h>
#include <ctype.h>

void readdisplay() {
    char ch;
    int num;
    char str[81]; 
    short s;
    float f;

    printf("Enter a char: ");
    scanf(" %c", &ch);  

    printf("Enter an integer: ");
    scanf("%d", &num);

    printf("Enter a string (max 80 characters): ");
    scanf(" %[^\n]%*c", str);  

    printf("Enter a short integer: ");
    scanf("%hd", &s);

    printf("Enter a float: ");
    scanf("%f", &f);

    printf("\nYou entered:\n");
    printf("Character: %c\n", ch);
    printf("Integer: %d\n", num);
    printf("String: %s\n", str);
    printf("Short: %hd\n", s);
    printf("Float: %.2f\n", f);

    printf("\nSize of each data type:\n");
    printf("Size of char: %zu bytes\n", sizeof(ch));
    printf("Size of int: %zu bytes\n", sizeof(num));
    printf("Size of char array: %zu bytes\n", sizeof(str));
    printf("Size of short: %zu bytes\n", sizeof(s));
    printf("Size of float: %zu bytes\n", sizeof(f));
}

void readdisplay2() {
    char ch;
    int num;
    char str[81];
    short s;
    float f;
    printf("Enter a char, integer, string (max 80 characters), short, and float: ");
    scanf(" %c %d %[^\n] %hd %f", &ch, &num, str, &s, &f);
    printf("\nYou entered:\n");
    printf("Character: %c\n", ch);
    printf("Integer: %d\n", num);
    printf("String: %s\n", str);
    printf("Short: %hd\n", s);
    printf("Float: %.2f\n", f);
    printf("\nSize of each data type:\n");
    printf("Size of char: %zu bytes\n", sizeof(ch));
    printf("Size of int: %zu bytes\n", sizeof(num));
    printf("Size of char array: %zu bytes\n", sizeof(str));
    printf("Size of short: %zu bytes\n", sizeof(s));
    printf("Size of float: %zu bytes\n", sizeof(f));
}
void displayUppercase() {
    char str[81];
    printf("Enter a string (max 80 characters): ");
    scanf(" %[^\n]%*c", str);
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = toupper(str[i]);
    }
    printf("String in uppercase: %s\n", str);
}

int main() {
    printf("Running readdisplay() function:\n");
    readdisplay();
    printf("\nRunning readdisplay2() function:\n");
    readdisplay2();
    printf("\nRunning displayUppercase() function:\n");
    displayUppercase();

    return 0;
}

