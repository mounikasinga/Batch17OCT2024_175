#include <stdio.h>
#include <stdlib.h>
#include <stack.h>

int bottom=-1;
int top = -1;


int push(int *max)
{
	int i,v;
	if(top == sizeof(max)-1)
	{
		printf("\nStack/Container is Full\n");
		return 0;
	}
	for(i=0;i<sizeof(max);i++)
	{
		printf("\npush the values in stack\n");
		scanf("%d",&v);
		top++;
		stackCont[top]= v;
	}
	

	return 0;
}

int pop()
{
	int v;
	if(top == bottom)
	{
		printf("\nStack/Container is empty\n");
		return 0;
	}
	v = stackCont[top];
	top--;
	return v;

}


void dispStack()
{
	int iter;
	if(top == bottom)
	{
		printf("\nStack/Container is empty\n");
		return;
	}
	printf("\nStack elements are\n");
	for(iter=top; iter>bottom;iter--)
	{
		printf("\n%d",stackCont[iter]);
	}
	printf("\n\n");

}
