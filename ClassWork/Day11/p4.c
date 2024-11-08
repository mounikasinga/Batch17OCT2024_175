/*string copy program and string Concatenating  */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    char s1[20],s2[20],d1[20],d2[20];
    char *ptr=NULL;
    printf("Main string:");
    scanf("%s",s1);
    printf("Sub string:");
    scanf("%s",s2);
    ptr=strstr(s1,s2);
    if(ptr==NULL)
        printf("Sub string %s Not found",s2);
    else
        printf("\n Base Address of s1=%s",);
        printf("\n Address of d1=%u\n Address of ptr=%u\n"ptr,&ptr[0]);
}