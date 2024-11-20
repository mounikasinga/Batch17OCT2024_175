#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "emp.h"
int getDetails(EMP *e, char line[]) {
    char *token = strtok(line, "|");
    if (token != NULL) {
        e->id = atoi(token);
        token = strtok(NULL, "|");
        strcpy(e->Name, token);
        token = strtok(NULL, "|");
        e->g = *token;
        token = strtok(NULL, "|");
        e->phno = atoi(token);
        token = strtok(NULL, "|");
        e->sal = atoi(token);
        return 0;
    }
    return 1;
}

int printDetails(EMP *e) {
    printf("\nEmployee Details:\n");
    printf("===============================\n");
    printf("ID: %d\n", e->id);
    printf("Name: %s\n", e->Name);
    printf("Gender: %c\n", e->g);
    printf("Phone: %d\n", e->phno);
    printf("Salary: %d\n", e->sal);
    printf("===============================\n");
    return 0;
}

EMP* appendNode(EMP *head, EMP *nn) {
    EMP *temp = head;

    if (head == NULL) {
        head = nn;
    } else {
        while (head->next != NULL) {
            head = head->next;
        }
        head->next = nn;
    }
    return temp;  
}

void printList(EMP *head) {
    if (head == NULL) {
        printf("\nList is Empty\n");
        return;
    }

    printf("\nList of Employees:\n=====================\n");
    while (head != NULL) {
        printDetails(head);
        head = head->next;
    }
    printf("=====================\n");
}

EMP* searchById(EMP* head, int id) {
    while (head != NULL) {
        if (head->id == id) {
            return head;  
        }
        head = head->next;
    }
    return NULL;  
}

EMP* searchByLastName(EMP* head, const char* lastName) {
    while (head != NULL) {
        char* token = strtok(head->Name, " ");
        token = strtok(NULL, " ");

        if (token != NULL && strcmp(token, lastName) == 0) {
            return head;  
        }
        head = head->next;
    }
    return NULL;  
}

void searchBySalaryRange(EMP* head, int minSal, int maxSal) {
    int found = 0;
    while (head != NULL) {
        if (head->sal >= minSal && head->sal <= maxSal) {
            printDetails(head);
            found = 1;
        }
        head = head->next;
    }
    if (!found) {
        printf("\nNo employees found in the specified salary range.\n");
    }
}

int updateLastName(EMP* head, int id, const char* newLastName) {
    EMP* emp = searchById(head, id);
    if (emp != NULL) {
        char* firstName = strtok(emp->Name, " ");  
        snprintf(emp->Name, sizeof(emp->Name), "%s %s", firstName, newLastName);
        printf("\nEmployee last name updated successfully.\n");
        return 0;  
    }
    return 0;
}

