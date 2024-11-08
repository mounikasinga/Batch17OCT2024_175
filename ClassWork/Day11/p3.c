/*string copy program using ptr also */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    char s1[20],s2[20],d1[20];
    char *ptr=NULL;
    scanf("%s%s",s1,s2);
    printf("\ns1=%s\t s2=%s\n",s1,s2);
    ptr=(char *)malloc(strlen(s1)+1);
    ptr=strcpy(d1,s1);
    //printf("\nd1=%s",d1);
    printf("\nptr=%s",ptr);
    printf("\n Address of d1=%u\n Address of ptr=%u\n",&d1,ptr);
}
