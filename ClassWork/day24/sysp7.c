#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/msg.h>
#include <string.h>
#define MAXBUFF 1024
#define PERMS 0666
typedef struct Empolyee{
    int id;
    int sal;
    char name[MAXBUFF];
}EMP;
int main() {
    key_t key =1043;
    EMP *e=NULL;
    int shimd;
    char *msg;
    shimd=shmget(key,sizeof(EMP)*1,PERMS/IPC_CREAT);
    if(shimd<0)
    {
        perror("shmget()");
        printf("\n Directly use this shm mem to read and write");
        exit(EXIT_FAILURE);
    }
    printf("\n Shared mem id=%d\n",shimd);
    e=(EMP *)shmat(shimd,(void *)0,0);
    printf("\nEnter Emp details\n");
    printf("\nName:");
    scanf("%[^\n]s",e->name);
    scanf(" ");
    printf("\nID:");
    scanf("%d",&e->id);
    printf("\nSalary:");
    scanf("%d",&e->sal);
    shmdt(e);
    return 0;
}

