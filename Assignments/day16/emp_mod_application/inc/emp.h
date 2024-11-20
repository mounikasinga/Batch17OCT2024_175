#ifndef EMP_H
#define EMP_H

typedef struct employee {
    int id;
    char Name[50]; 
    char g;        
    int phno;
    int sal;       
    struct employee *next;  
} EMP;

int getDetails(EMP *e, char line[]);
int printDetails(EMP *e);
EMP* appendNode(EMP *head, EMP *nn);
void printList(EMP *head);
EMP* searchById(EMP* head, int id);
EMP* searchByLastName(EMP* head, const char* lastName);
void searchBySalaryRange(EMP* head, int minSal, int maxSal);
int updateLastName(EMP* head, int id, const char* newLastName);

#endif 

