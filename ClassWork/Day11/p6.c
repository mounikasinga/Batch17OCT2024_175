#include<stdio.h>
#include<string.h>
int reverse(char* str) {
    int i;
    int rev = strlen(str) - 1;
    char temp=0;
    for(i=0;i<rev;i++,rev--) 
    {
        temp = str[i];
        str[i] = str[rev];
        str[rev] = temp;
    }
}

int main() {
    char str1[100],res;
    scanf("%s",str1);
    reverse(str1);
    printf("%s",str1);
}
