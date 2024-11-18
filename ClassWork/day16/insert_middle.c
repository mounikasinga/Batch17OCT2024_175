#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int value;
	struct node *ptr;
}NODE;
int main(){
	//creating node in single linkedlist
	NODE h1,h2,h3,h4,h5;
	NODE *ptr1;
	//initialalze values to each node
	h1.value=10;
	h2.value=20;
	h3.value=30;
	h1.ptr=NULL;
	h2.ptr=NULL;
	h3.ptr=NULL;
	printf("\nAddress of the h1=%p",&h1);
	printf("\nAddress of the h1=%p",&h2);
	printf("\nAddress of the h1=%p",&h3);
	printf("\nAddress of the h1=%p\n",&ptr1);
	printf("\nh1.value=%d and ptr=%p",h1.value,h1.ptr);
	printf("\nh1.value=%d and ptr=%p",h2.value,h2.ptr);
	printf("\nh1.value=%d and ptr=%p\n",h3.value,h3.ptr);
	h1.ptr=&h2;
	h2.ptr=&h3;
	ptr1=&h1;
	//ptr1=&h2;
	//ptr1=&h3;
	printf("\n%d",h1.value);
	printf("\n%d",ptr1->value);
	ptr1=h1.ptr;
	printf("\n%d",ptr1->value);
	ptr1=h2.ptr;
	printf("\n%d",ptr1->value);
	h4.value=40;
	h4.ptr=NULL;
	h1.ptr=&h4;
	h4.ptr=&h2;
	ptr1=&h1;
	printf("\n%d",ptr1->value);
	ptr1=h1.ptr;
	printf("\n%d",ptr1->value);
	ptr1=h4.ptr;
	printf("\n%d",ptr1->value);
	ptr1=h2.ptr;
	printf("\n%d\n",ptr1->value);
	ptr1=&h1;
	while(ptr1 !=NULL)
	{
		printf("%d -> ",ptr1->value);
 	        ptr1=ptr1->ptr;
	}
	printf("NULL");

	printf("\n\n");
	return 0;
}
		
