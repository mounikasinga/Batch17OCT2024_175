#include <stdio.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>
#include<sys/msg.h>
#include<sys/ipc.h>

int main() {
    int msgid;
    //msgid=msgget((key_t)16,IPC_CREAT);//
    //msgid=msgget((key_t)16,IPC_EXCL);
    msgid=msgget((key_t)17,IPC_CREAT|IPC_EXCL|0644);
    printf("\nMSG Queue Created with %d id\n",msgid);
    printf("\n\n");
    return 0;
}
