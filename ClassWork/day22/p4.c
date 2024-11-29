#include <stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>
int main(int argc,int arg,char *argv)
{
	
	switch(argv)
	{
		case '+':
		printf("\n%d+%d\n",argc+arg);
		break;
		case '-':
		printf("\n%d-%d\n",argc-arg);
		break;
		printf("\n%d*%d\n",
		
