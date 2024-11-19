#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int bottom=-1;
int top=0;
int push(int);
int pop();
int stackcontainer[max];
void displaystack();
int push (int v)
{
	if(top==MAX-1)
	{
		printf("\nStack container is full");
		return 0;
	}
	top++;
	stackcontainer[top]=v;
 printf("\n\n");
}
int pop()
{
	int v;
	if(top==bottom)
	{
		printf("\n stack container is empty");
		return 0;
	}
	v=stackcontainer[top];
	top--;
	return v;
 printf("\n\n");
}
void displaystack()
{
	int i;
	for(i=top;i>bottom;i++)
	{
		printf("\n%d",stackcontainer[i]);
	}
	if(top==bottom)
        {
                printf("\n stack container is empty");
                return 0;
        }
printf("\n\n");
}	

