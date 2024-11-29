#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>
int main()
{
	printf("\n This is sprog04\n");
	if(fork()>0){
		wait(0);
		printf("\n prg04 PID :%d",getpid());
	}
	else{
		execl("/bin/ls","/bin/ls",(char *)0);
	}
	printf("\n Ending sprg04");
	printf("\n\n");
	return 0;
}
