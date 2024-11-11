/*demo on structure*/
#include<stdio.h>
#include<string.h>
struct Employee{
	int eid;
	float esal;
	char ename[20];	
	char eGender;
	char eAddress[20];
};
typedef struct Employee emp;

int main()
{
emp e1;
int i;
for(i=0;i<2;i++)
{
	printf("\n Id:");
	scanf("%d",&e1[i].eid);
	printf("\n Salary");
	scanf("%f",&e1[i].esal);
	printf("\nName:");
	scanf("%s",&e1[i].ename);
	printf("\nGender:");
	scanf("%c",&e1[i].eGender);
	printf("\n Address:");
	scanf("%s",&e1[i].eAddress);
}
for(i=0;i<2;i++)
{
	printf("\n=========== Employee Details are================\n");
	printf("\nID: %d",e1[i].eid);
	printf("\nsalary: %f",e1[i].esal);
	printf("\nEmp Name: %s",e1[i].ename);
	printf("\nGennder: %c",e1[i].eGender);
	printf("\nAddress: %s",e1[i].eAddress);
	printf("\n=================================================");
	printf("\n ");
}
}
