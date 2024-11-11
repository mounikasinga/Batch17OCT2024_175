/*string program "strtok"  */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    char s1[20],s2[20];
    char *ptr=NULL;
    printf("\n Enter the line  with delimiter: \n");
    scanf("%[^\n]s",s1);
    ptr=strtok(s1,",");
    printf("\n ptr=%s",ptr);
    printf("\n\n");
    
}

/*output:
Enter the line  with delimiter:
moun,nika
ptr=mou*/
