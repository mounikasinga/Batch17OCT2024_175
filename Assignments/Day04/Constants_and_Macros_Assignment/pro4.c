#include <stdio.h>
#define CUST_PRINT
#ifdef CUST_PRINT
    #define MYPRINT(x) printf(x)
#else
    #define MYPRINT(x)
#endif
int main() {
    MYPRINT("Hello World\n");  
    printf("Test\n");       
    
    return 0;
}

