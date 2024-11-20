#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int push(int *);
int pop();
void dispStack();

int stackCont[MAX];
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
int main()
{
	int v,i;
	/*
	v = pop();
	printf("\n%d element is deleted from the container/stack",v);
	*/

	/*push(10);
	push(11);
	push(12);
	push(13);
	push(14);
	push(15);*/
	int *max,n;
	printf("Enter n values");
	scanf("%d",&n);
	max=(int *)malloc(n*sizeof(int));
	push(max);
	
	
	dispStack();

	for(i=0;i<sizeof(max);i++)
	{
		v = pop();
		printf("\n%d element is deleted from the container/stack",v);
		dispStack();
	}

	printf("\n\n");

	return 0;

}
