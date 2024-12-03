//it is used to read the massage from the memory
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

typedef struct msgText{
	long msgtype;
	char txtMsg[1024];
}MSG;

int main()
{
	int msgid, len=0;
	MSG msg1;
	msgid = msgget((key_t)15,IPC_CREAT|PERMS);
	if(msgid < 0){
		perror("msgget ");
		_exit(EXIT_SUCCESS);
	}
	printf("\nMSG queue created with %d id\n",msgid);
	printf("\nTO recv msg from msgid = %d\n",msgid);
	
	if(msgrcv(msgid,&msg1,BUFF,0,0)<0)
	{
		perror("msgrcv ");
		return (EXIT_FAILURE);
	}

	printf("\nReceived message: Type:  %ld\n",msg1.msgtype);
	printf("\nReceived message: Msg: %s\n",msg1.txtMsg);

	printf("\n\n");
	return 0;
}
