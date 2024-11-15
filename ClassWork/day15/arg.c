#include<stdio.h>
int main(int argc, char *argv[])
{
	int i;
	printf("\nNo of args=%d",argc);
	for(i=0;i<argc;i++)
	{
		printf("\n argv[%d]=%s",i,argv[i]);
		printf("\n\n");
	}
}
