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
e1.eid=101;
e1.esal=30000;
strcpy(e1.ename,"mounika");
e1.eGender='M';
strcpy(e1.eAddress,"main raod");

printf("\n=========== Employee Details are================\n");
printf("\nID: %d",e1.eid);
printf("\nsalary: %f",e1.esal);
printf("\nEmp Name: %s",e1.ename);
printf("\nGennder: %c",e1.eGender);
printf("\nAddress: %s",e1.eAddress);
printf("\n=================================================");
printf("\n ");
}
