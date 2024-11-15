#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#define N 10
void  using_hello_threads();
int main()
{
	pthread_t tid;
	int status;
	printf("\nI am Main Program/Process/MainThread\n");
	status = pthread_create(&tid,NULL,using_hello_threads,NULL);
	//pthread_join(tid,NULL);
	sleep(1);
	printf("\n After completing (main)");
	printf("\n\n");
}
void using_hello_threads()
{
	int i;
	printf("\n Hello World\n");
	for(i=0;i<N;i++)
	{
		printf("\n%d",i);
	}
	printf("\n\n");
}
