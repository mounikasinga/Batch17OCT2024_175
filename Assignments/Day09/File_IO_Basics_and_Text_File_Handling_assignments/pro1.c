#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 80
int write(FILE *fptr, char *line) {
    if (fptr == NULL || line == NULL) {
        return -1;
    }
    fprintf(fptr, "%s\n", line);
    return 0;
}
int read(FILE *fptr, char *linebuf) {
    if (fptr == NULL || linebuf == NULL) {
        return -1;
    }
    if (fgets(linebuf, MAX_LEN, fptr) == NULL) {
        return -1;
    }
    linebuf[strcspn(linebuf, "\n")] = '\0'; 
    return 0;
}
int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Please provide exactly two lines of text as command-line arguments.\n");
        return -1;
    }
    FILE *fptr = fopen("fout.txt", "w");
    if (fptr == NULL) {
        printf("Error opening file for writing.\n");
        return -1;
    }
    if (write(fptr, argv[1]) == -1 || write(fptr, argv[2]) == -1) {
        printf("Error writing to file.\n");
        fclose(fptr);
        return -1;
    }
    fclose(fptr);
    fptr = fopen("fout.txt", "r");
    if (fptr == NULL) {
        printf("Error opening file for reading.\n");
        return -1;
    }
    char linebuf[MAX_LEN];
    printf("Contents of fout.txt:\n");
    while (read(fptr, linebuf) == 0) {
        printf("%s\n", linebuf);
    }
    fclose(fptr);
    return 0;
}

