#include <stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>
int main(int argc,char *argv[])
{
    printf("\n In the p2.c\n");
    execl(argv[1],argv[2],argv[3],(char *)0);
    printf("\n This line will not print\n\n");
    return 0;
}
