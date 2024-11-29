#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>
#include<sys/msg.h>
#include<sys/ipc.h>
int main()
{
    key_t key=ftok("/home2/user60/Batch17OCT2024_175/ClassWork/day24",10010);
    printf("\n%u",key);
    printf("\n%X",key);
    printf("\n\n");
    return 0;
}
