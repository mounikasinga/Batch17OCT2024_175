#include<stdio.h>
int main()
{
    char Name[5];
    int i;
    for(i=0;i<5;i++)
        scanf("%c",&Name[i]);
    for(i=0;i<5;i++)
        printf("\n%c=%d",Name[i],Name[i]);
    printf("\n%s\n",Name);
    puts(Name);
}
