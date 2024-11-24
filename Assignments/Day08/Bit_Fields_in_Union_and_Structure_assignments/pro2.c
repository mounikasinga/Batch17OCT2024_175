#include <stdio.h>
#include <string.h>
#define MAX_NAME_LENGTH 100
typedef struct {
    char name[MAX_NAME_LENGTH]; 
    unsigned char age;
} Person;
int main() {
    Person p1;
    strcpy(p1.name, "Rama Krishna Reddy");
    p1.age =50;
    printf("Person Details:\n");
    printf("Name: %s\n", p1.name);
    printf("Age: %d\n", p1.age);
    return 0;
}

