#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node *ptr;
}NODE;
void printlist(NODE *);
NODE *appendnode(NODE *,NODE *);
int main()
{
	NODE h1,h2,h3,h4,h5;
	NODE *Head=NULL,*n;
	h1.data=10;
	h2.data=20;
	h3.data=30;
	h4.data=40;
	h5.data=50;
	h1.ptr=NULL;
	h2.ptr=NULL;
	h3.ptr=NULL;
	h4.ptr=NULL;
	h5.ptr=NULL;
	h1.ptr=&h2;
	h2.ptr=&h3;
	h3.ptr=&h4;
	Head=&h1;
	appendnode(Head,&h5);
	Head=&h1;
	printlist(Head);
	printf("\n\n");
	
}
void printlist(NODE *Head)
{
	while(Head!=NULL)
	{
		printf("%d -> ",Head->data);
		Head=Head->ptr;
	}
	printf("NULL");
}
NODE *appendnode(NODE *Head ,NODE *n)
{
	NODE *temp=Head;
	printf("\nIn append mode");
	if(Head==NULL)
	{
		Head=n;
		temp=Head;
	}
	else
	{
		while(Head->ptr!=NULL)
		{
			printf("%d ->",Head->data);
			Head=Head->ptr;
		}
		Head->ptr=n;
	}	
	//printf("\n%d",Head->data);
	//printf("\n%d",Head->ptr);
	Head=temp;
	return Head;
}

