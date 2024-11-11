
/*
WAP to which should have the following functionalities
1. scan employee recs 
2. display
3. search for a particulary employee based on
  a. id
  b. lName
4. search for employess whos salary fall in
   between 6-10K and display only those records

5. update employee rec to change his/her lName*/
#include<stdio.h>
#include <string.h>
struct employee
{
	char fName[20];
	char lName[20];
	char eGender;
	int eId;
	float eSal;
	
};
typedef struct employee emp;
void scan_records(emp [],int);
void disp(emp [],int);
void search_id_name(emp [],int);
void search_salary_fall(emp [],int);
void update_lname(emp [],int);
int main()
{
	int n;
	emp e;
	printf("Enter n Value:");
	scanf("%d",&n);
	emp e1[n];
	scan_records(e1,n);
	update_lname(e1,n);
}
void scan_records(emp e1[], int n)
 {
         int i;
         printf("\nEnter Employee Details\n");
         for(i=0;i<n;i++)
         {
                 printf("\nFName: ");
                 scanf("%s",e1[i].fName);
		 printf("\nLName: ");
                 scanf("%s",e1[i].lName);
                 printf("\nID: ");
                 scanf("%d",&e1[i].eId);
                 printf("\nGender: ");
                 scanf(" ");
                 scanf("%c",&e1[i].eGender);
                 printf("\nSalary: ");
                 scanf("%f",&e1[i].eSal);

         }
	 search_id_name(e1,n);	
}
 void disp(emp e1[], int n)
 {
         int i;
	 char name[50];
         printf("\nEmployee Details are\n");
         for(i=0;i<n;i++){
                 printf("\n==========Employee Details=================\n");
                 printf("\nID: %d",e1[i].eId);
                // printf("\nFName: %s",e1[i].fName);
		 strcat(e1[i].fName  ," ");
		 strcat(e1[i].fName  ,e1[i].lName);
		 printf("\nName: %s",e1[i].fName);
                 printf("\nGender: %c",e1[i].eGender);
                 printf("\nSalary: %f",e1[i].eSal);
                 printf("\n===========================================\n");
         }
 }

void search_id_name(emp e1[], int n)
{
	char cmp_name[20];
	int id,i;
	scanf("Name: %s",cmp_name);
	scanf("Id: %d",&id);
	disp(e1,n);
	for(i=0;i<n;i++)
	{
		if((strcmp(e1[i].fName,cmp_name)==0)&&(strcmp(e1[i].lName,cmp_name)==0)&&(e1[i].eId==id)){
				printf("\n=============Matched Details===============\n");
				printf("\nFNAME: %s",e1[i].fName);
				printf("\nLNAME: %s",e1[i].lName);
				printf("\nID: %d",e1[i].eId);	
				printf("\n===========================================\n");
		}
		else
			break;
	}
search_salary_fall(e1,n);
printf("\n\n");
}
void search_salary_fall(emp e1[], int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(e1[i].eSal>=6000 && e1[i].eSal<=10000){
			printf("\n=====Matched Details Who salary b/w 6k-10k======\n");
			printf("\nSALARY: %f",e1[i].eSal);
			printf("\n================================================\n");
			
		}
		else
			printf("Not Matched any Employee details is b/w 6k-10k");
	}
}
void update_lname(emp e1[],int n)
{
	int i;
	printf("\nEnter your update  lname:");
	scanf("%s",e1[0].lName);
	for(i=0;i<n;i++)
	{
                   printf("\n=========Updated Employee Details==========\n");
                   printf("\nID: %d",e1[i].eId);
		   strcat(e1[i].fName  ," ");
                   strcat(e1[i].fName  ,e1[i].lName);
                   printf("\nName: %s",e1[i].fName);
                   printf("\nGender: %c",e1[i].eGender);
                   printf("\nSalary: %f",e1[i].eSal);
                   printf("\n===========================================\n");
         }
}

