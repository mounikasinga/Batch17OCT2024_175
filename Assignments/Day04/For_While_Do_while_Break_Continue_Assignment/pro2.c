#include <stdio.h>

int main() {
    float cnt = 1, num = 1000;
    
    do { 
        printf("\n%.2f\n%.2f", num, cnt);
        num /= cnt;      
    } while (cnt++ < 10);  
    
    return 0;
}

