#include<stdio.h>
#define MAX 5
int rear=0;
int front=0;
void enqueue(int);
void dequeue();
void displayqueue();
int main()
{
	enqueue(10);
	enqueue(20);
	enqueue(30);
	enqueue(40);
	enqueue(50);
	
	dequeue();
	dequeue();
	dequeue();
	dequeue();
	dequeue();
	displayqueue();
}


