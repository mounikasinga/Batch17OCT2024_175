#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NAME_LENGTH 50
enum designation {
    MANAGER,
    ENGINEER,
    CLERK,
    HR,
    SALES
};
struct employee {
    char name[MAX_NAME_LENGTH];
    unsigned int age;
    enum designation job_title;
};
void read(struct employee *emp) {
    int choice;
    printf("Enter name (max 50 characters): ");
    fgets(emp->name, MAX_NAME_LENGTH, stdin);
    emp->name[strcspn(emp->name, "\n")] = 0; 
    printf("Enter age: ");
    scanf("%u", &emp->age);
    getchar(); 
    printf("Enter job title (0: Manager, 1: Engineer, 2: Clerk, 3: HR, 4: Sales): ");
    scanf("%d", &choice);
    getchar(); 
    emp->job_title = (enum designation)choice;
}
void display(struct employee emp) {
    printf("\nEmployee Details:\n");
    printf("Name: %s\n", emp.name);
    printf("Age: %u\n", emp.age);
    switch (emp.job_title) {
        case MANAGER:
            printf("Designation: Manager\n");
            break;
        case ENGINEER:
            printf("Designation: Engineer\n");
            break;
        case CLERK:
            printf("Designation: Clerk\n");
            break;
        case HR:
            printf("Designation: HR\n");
            break;
        case SALES:
            printf("Designation: Sales\n");
            break;
        default:
            printf("Designation: Unknown\n");
    }
}
int update(struct employee *emp) {
    printf("Update employee details:\n");
    printf("Enter new name (max 50 characters): ");
    fgets(emp->name, MAX_NAME_LENGTH, stdin);
    emp->name[strcspn(emp->name, "\n")] = 0; 
    printf("Enter new age: ");
    scanf("%u", &emp->age);
    getchar();
    int choice;
    printf("Enter new job title (0: Manager, 1: Engineer, 2: Clerk, 3: HR, 4: Sales): ");
    scanf("%d", &choice);
    getchar();
    emp->job_title = (enum designation)choice;
    return 1; 
}
struct employee copy(struct employee emp) {
    struct employee new_emp;
    strcpy(new_emp.name, emp.name);
    new_emp.age = emp.age;
    new_emp.job_title = emp.job_title;
    return new_emp;
}
int main() {
    struct employee employees[3];
    for (int i = 0; i < 3; i++) {
        printf("\nEnter details for Employee %d:\n", i + 1);
        read(&employees[i]);
        display(employees[i]);
    }
    printf("\nUpdating Employee 1 details:\n");
    update(&employees[0]);
    display(employees[0]);
    printf("\nCopying Employee 2 details:\n");
    struct employee copied_emp = copy(employees[1]);
    display(copied_emp);
    return 0;
}

