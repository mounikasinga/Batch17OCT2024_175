#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/msg.h>
#include <string.h>
#define BUFF 1024
#define PERMS 0666

int main() {
    int semid,nsem;
    key_t key=ftok("/home2/user60/Batch17OCT2024_175/ClassWork/day24",17102);
    nsem=1;
    semid =semget(key,nsem,PERMS|IPC_CREAT);
    if(semid<0)
    {
        perror("semget()");
        exit(EXIT_SUCCESS);
    }
    printf("Semaphore is created with id %d",semid);
    printf("\n\n");
    return 0;
}
