#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct student {
    char *name;
    int percentage;
};
char *read_update_name(char *name) {
    char temp[100];
    printf("Enter student's name: ");
    fgets(temp, sizeof(temp), stdin);
    temp[strcspn(temp, "\n")] = '\0';
    name = (char *)malloc(strlen(temp) + 1);
    if (name == NULL) {
        printf("Memory allocation failed for name\n");
        return NULL;
    }
    strcpy(name, temp);
    return name;
}
int read_update_percentage(int *percent) {
    printf("Enter student's percentage: ");
    scanf("%d", percent);
    return *percent;
}
void free_student(struct student *stu) {
    if (stu != NULL) {
        free(stu->name);
    }
}
void display_student(struct student stu) {
    printf("Student Name: %s\n", stu.name);
    printf("Percentage: %d%%\n", stu.percentage);
}
int main() {
    struct student stu;
    stu.name = NULL;
    stu.name = read_update_name(stu.name);
    if (stu.name == NULL) {
        return -1;
    }
    read_update_percentage(&stu.percentage);
    display_student(stu);
    free_student(&stu);
    return 0;
}

