#include <stdio.h>

#define FILE_NAME __FILE__
#define FUNC_NAME __FUNCTION__
#define LINE_NUMBER __LINE__

int main() {
    printf("File Name: %s\n", FILE_NAME);
    printf("Function Name: %s\n", FUNC_NAME);
    printf("Line Number: %d\n", LINE_NUMBER);

    return 0;
}

