#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "emp.h"

int main() {
    EMP* head = NULL;
    EMP* temp;
    char line[256];
    int choice;
    int id;
    char lastName[50];

    while (1) {
        printf("\n1. Scan Employee Record\n");
        printf("2. Display Employee Records\n");
        printf("3. Search Employee by ID\n");
        printf("4. Search Employees by Last Name\n");
        printf("5. Search Employees by Salary Range\n");
        printf("6. Update Employee Last Name\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // To consume the newline character after scanf

        switch (choice) {
            case 1:
                printf("Enter employee details (ID|Name|Gender|PhoneNo|Salary): ");
                fgets(line, sizeof(line), stdin);
                temp = (EMP*)malloc(sizeof(EMP));
                getDetails(temp, line);
                head = appendNode(head, temp);
                break;
            case 2:
                printList(head);
                break;
            case 3:
                printf("Enter employee ID to search: ");
                scanf("%d", &id);
                temp = searchById(head, id);
                if (temp) {
                    printDetails(temp);
                } else {
                    printf("Employee not found.\n");
                }
                break;
            case 4:
                printf("Enter last name to search: ");
                fgets(lastName, sizeof(lastName), stdin);
                lastName[strcspn(lastName, "\n")] = 0;  // Remove newline
                temp = searchByLastName(head, lastName);
                if (temp) {
                    printDetails(temp);
                } else {
                    printf("Employee not found.\n");
                }
                break;
            case 5:
                searchBySalaryRange(head, 6000, 10000);
                break;
            case 6:
                printf("Enter employee ID to update last name: ");
                scanf("%d", &id);
                getchar();  // Consume the newline
                printf("Enter new last name: ");
                fgets(lastName, sizeof(lastName), stdin);
                lastName[strcspn(lastName, "\n")] = 0;  // Remove newline
                updateLastName(head, id, lastName);
                break;
            case 7:
                exit(0);
        }
    }

    return 0;
}

