#include "main.h"

#define MAX 10
EMP stackcontainer[MAX];
int top = -1;

int push(EMP *e) {
    if (top == MAX - 1) {
        printf("\nStack container is full\n");
        return 0;
    }
    stackcontainer[++top] = *e; 
    return 1;
}

EMP pop() {
    EMP e;
    if (top == -1) {
        printf("\nStack container is empty\n");
        e.id = -1;  
        return e;
    }
    e = stackcontainer[top--];  
    return e;
}

void displayStack() {
    if (top == -1) {
        printf("\nStack is empty\n");
        return;
    }

    printf("\nStack elements are:\n");
    for (int i = top; i >= 0; i--) {
        printf("\nEmployee Details:\n");
        printf("===============================\n");
        printf("ID: %d\n", stackcontainer[i].id);
        printf("Name: %s\n", stackcontainer[i].Name);
        printf("Gender: %c\n", stackcontainer[i].g);
        printf("Phone No: %d\n", stackcontainer[i].phno);
        printf("Salary: %d\n", stackcontainer[i].sal);
        printf("===============================\n");
    }
}

void printList(EMP *head) {
    EMP *temp = head;
    while (temp != NULL) {
        printDetails(temp);
        temp = temp->next;
    }
}

int getDetails(EMP *e, char line[]) {
    char *token = strtok(line, "|");
    if (token != NULL) {
        e->id = atoi(token); #include "main.h"
#define MAX 10
EMP stackcontainer[MAX];
int top = -1;
int push(EMP *e) {
    if (top == MAX - 1) {
        printf("\nStack container is full\n");
        return 0;
    }
    stackcontainer[++top] = *e;  
    return 1;
}
EMP pop() {
    EMP e;
    if (top == -1) {
        printf("\nStack container is empty\n");
        e.id = -1; 
        return e;
    }
    e = stackcontainer[top--];  
    return e;
}

void displayStack() {
    if (top == -1) {
        printf("\nStack is empty\n");
        return;
    }

    printf("\nStack elements are:\n");
    for (int i = top; i >= 0; i--) {
        printf("\nEmployee Details:\n");
        printf("===============================\n");
        printf("ID: %d\n", stackcontainer[i].id);
        printf("Name: %s\n", stackcontainer[i].Name);
        printf("Gender: %c\n", stackcontainer[i].g);
        printf("Phone No: %d\n", stackcontainer[i].phno);
        printf("Salary: %d\n", stackcontainer[i].sal);
        printf("===============================\n");
    }
}

void printList(EMP *head) {
    EMP *temp = head;
    while (temp != NULL) {
        printDetails(temp);
        temp = temp->next;
    }
}

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

int main() {
    FILE *fp;
    EMP *e = NULL;
    EMP *head = NULL;
    char line[BUFF];

    system("clear");

    fp = fopen("./data/db.txt", "r");
    if (fp == NULL) {
        perror("fopen: ");
        return 1;
    }

    memset(line, '\0', BUFF);

    while (fgets(line, BUFF, fp) != NULL) {
        line[strlen(line) - 1] = '\0';
        e = (EMP *)malloc(sizeof(EMP));
        if (getDetails(e, line) == 0) {
            e->next = head;
            head = e;
            push(e);
        }
    }

    fclose(fp);

    displayStack();

    printf("\nLinked list of employees:\n");
    printList(head);


    EMP *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}

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
