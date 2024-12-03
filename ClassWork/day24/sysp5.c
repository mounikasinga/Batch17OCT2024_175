//it is send the msg to the memoey
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/msg.h>
#include <string.h>
#define PERMS 0666

typedef struct msgText{
	long msgtype;
	char txtMsg[1024];
}MSG;

int main()
{
	int msgid, len=0;
	MSG msg1;
	msgid = msgget((key_t)19,IPC_CREAT|PERMS);
	if(msgid < 0){
		perror("msgget ");
		_exit(EXIT_SUCCESS);
	}
	printf("\nMSG queue created with %d id\n",msgid);
	printf("\nTO send msg to msgid = %d\n",msgid);
	msg1.msgtype = 1;
	strcpy(msg1.txtMsg,"Hi Bhima, Hope you are doing good\n"); 
	len = strlen(msg1.txtMsg);

	if(msgsnd(msgid,&msg1,len,IPC_NOWAIT)==-1)
	{
		perror("msgsnd ");
		return (EXIT_FAILURE);
	}
	
	
	printf("\n\n");
	return 0;
}
