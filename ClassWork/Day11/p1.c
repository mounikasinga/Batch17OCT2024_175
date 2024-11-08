/*string compare program*/

#include<stdio.h>
#include<string.h>
int main()
{
    char s1[20],s2[20];
    int ret=0;
    scanf("%s%s",s1,s2);
    printf("s1=%s\t s2=%s\n",s1,s2);
    ret=strcmp(s1,s2);
    printf("Ret=%d",ret);
}
