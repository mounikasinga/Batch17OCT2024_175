/*read the contents in the database the record of the employees
store in  structure and display
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Employee
{
	char eName[20];
	char eGender;
	int Phone;
	int eId;
	float eSalary;
};

typedef struct Employee Emp;
void disp_details(EMP [], int);
int get_details(Emp , char []);
int main()
{
	Emp e;
	FILE *file=NULL;
	file = fopen("db.txt","r");
	if(file == NULL)
	{
		perror("fopen: ");
		return 1;
	}

	while(fgets(line,BUFF,file)!=NULL)
	{
		line[strlen(line)-1]='\0';
		get_details(e,line);
		e++;
`	}
	e=temp;
}
int get_details(Emp *e, char line[])
{
	char *token=NULL;
	e1->id = atoi(token);
	strcpy(e1->Name,token);
	e1.Gender = Names[2][0];
	e1->phone = atoi(token);
	e1.Salary = atoi(token);
	file = strtok(line e[],"|");
disp_details(e,2);
}
void disp_details(Emp e[], int n)
{
	int i;
	printf("\nEmployee Details are\n");
	for(i=0;i<n;i++){
		printf("\n=========================\n");
		printf("\nID: %d",e[i].eId);
		printf("\nName: %s",e[i].eName);
		printf("\nGender: %c",e[i].eGender);
		printf("\nPhone: %d",e[i].ePhone);
		printf("\nSalary: %f",e[i].eSalary);
		printf("\n=========================\n");
	}
}
