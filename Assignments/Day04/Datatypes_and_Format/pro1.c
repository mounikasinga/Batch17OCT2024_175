#include <stdio.h>

int main() {
    char username[125];
    int age;
    float salary;
    short designation_code;
    char gender;
    printf("Enter username: ");
    fgets(username, sizeof(username), stdin); 

    printf("Enter age: ");
    scanf("%d", &age);

    printf("Enter salary: ");
    scanf("%f", &salary);

    printf("Enter designation code (1-6): ");
    scanf("%hd", &designation_code);
    printf("Enter gender (M/F): ");
    scanf(" %c", &gender); 
    printf("\n************************************\n");
    printf("Username: %s", username); 
    printf("Age: %d\n", age);
    printf("Salary: %.2f\n", salary);
    printf("Designation Code: %hd\n", designation_code);
    printf("Gender: %c\n", gender);
    printf("\n************************************\n");

    return 0;
}

