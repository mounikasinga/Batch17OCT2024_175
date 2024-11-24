#include <stdio.h>
#include <stdlib.h>
void merge_files(const char *int_file, const char *str_file, const char *out_file) {
    FILE *fint = fopen(int_file, "r");
    FILE *fstr = fopen(str_file, "r");
    FILE *fout = fopen(out_file, "w");

    if (fint == NULL || fstr == NULL || fout == NULL) {
        printf("Error opening files.\n");
        return;
    }
    int num;
    char str[80];
    while (fscanf(fint, "%d", &num) == 1 && fgets(str, 80, fstr) != NULL) {
        fprintf(fout, "%d%s", num, str);
    }
    fclose(fint);
    fclose(fstr);
    fclose(fout);
}
void display_file(const char *file_name) {
    FILE *file = fopen(file_name, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }
    char ch;
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }
    fclose(file);
}
int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Please provide 3 file names as command line arguments.\n");
        return -1;
    }
    merge_files(argv[1], argv[2], argv[3]);
    printf("Contents of the merged file:\n");
    display_file(argv[3]);
    return 0;
}

