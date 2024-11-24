#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct student {
    char *name;
    unsigned int age;
};
int main() {
    struct student students[2];
    FILE *file;
    size_t name_size;
    size_t total_size;
    for (int i = 0; i < 2; i++) {
        students[i].name = (char *)malloc(20 * sizeof(char));
        if (students[i].name == NULL) {
            printf("Memory allocation failed.\n");
            return -1;
        }
        printf("Enter name for student %d (max 20 chars): ", i + 1);
        fgets(students[i].name, 20, stdin);
        students[i].name[strcspn(students[i].name, "\n")] = '\0';
        printf("Enter age for student %d: ", i + 1);
        scanf("%u", &students[i].age);
        getchar();
    }
    file = fopen("out.bin", "wb");
    if (file == NULL) {
        printf("File opening failed.\n");
        return -1;
    }
    for (int i = 0; i < 2; i++) {
        fwrite(students[i].name, sizeof(char), strlen(students[i].name) + 1, file);
        fwrite(&students[i].age, sizeof(unsigned int), 1, file);
    }
    fclose(file);
    file = fopen("out.bin", "rb");
    if (file == NULL) {
        printf("File opening failed.\n");
        return -1;
    }
    struct student read_students[2];
    for (int i = 0; i < 2; i++) {
        read_students[i].name = (char *)malloc(20 * sizeof(char));
        if (read_students[i].name == NULL) {
            printf("Memory allocation failed.\n");
            return -1;
        }
        fread(read_students[i].name, sizeof(char), 20, file);
        fread(&read_students[i].age, sizeof(unsigned int), 1, file);
    }
    fclose(file);
    printf("\nContents read from file:\n");
    for (int i = 0; i < 2; i++) {
        printf("Name: %s, Age: %u\n", read_students[i].name, read_students[i].age);
    }
    for (int i = 0; i < 2; i++) {
        if (strcmp(students[i].name, read_students[i].name) != 0 || students[i].age != read_students[i].age) {
            printf("Data mismatch!\n");
        }
    }
    name_size = strlen(students[0].name) + strlen(students[1].name);
    total_size = name_size + 2 * sizeof(unsigned int);
    printf("\nSize of each name and age pair: %zu bytes\n", sizeof(students[0].name) + sizeof(students[0].age));
    printf("Total size of 2 name and age pairs: %zu bytes\n", total_size);
    file = fopen("out.bin", "rb");
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fclose(file);
    printf("Size of the file: %ld bytes\n", file_size);
    for (int i = 0; i < 2; i++) {
        free(students[i].name);
        free(read_students[i].name);
    }
    return 0;
}

