#include <common.h>
#include <emp.h>
#include <stack.h>

int bottom=-1;
int top = -1;
EMP stackcontainer[MAX];
int getDetails(EMP *e, char line[])
{
	char *token = NULL;
	token = strtok(line,"|");
	if(token != NULL)
	{
		e->id = atoi(token);
		token = strtok(NULL,"|");
		strcpy(e->Name,token);
		token = strtok(NULL,"|");
		e->g = *token;
		token = strtok(NULL,"|");
		e->phno = atoi(token);
		token = strtok(NULL,"|");
		e->sal = atoi(token);
		return 0;
	}
	return 1;
}

int displayStack(EMP *e)
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
		printf("\nEmployee Details are\n");
		printf("\n===============================\n");
		printf("\nID: %d",e->id);
		printf("\nName: %s",e->Name);
		printf("\nGender: %c",e->g);
		printf("\nPhNo: %d",e->phno);
		printf("\nSalary: %d",e->sal);
		printf("\n===============================\n");
	}
	printf("\n\n");
}
int push(EMP *e)
{
	if(top==MAX-1)
	{
		printf("\nStack container is full");
		return 0;
	}
		top++;
		stackcontainer[top]=*e;
}
EMP pop()
{
	EMP e;
	if(top==bottom)
	{
		printf("\n stack container is empty");
		return 0;
	}
	e=stackcontainer[top];
	top--;
	return e;
 printf("\n\n");
}
