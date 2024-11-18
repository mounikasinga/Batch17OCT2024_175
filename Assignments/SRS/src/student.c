#include<common.h>
#include<student.h>
int validate_record(const Student *record) {
    return strlen(record->student_id) > 0 &&
           strlen(record->name) > 0 &&
           strlen(record->email) > 0 &&
           strlen(record->dob) > 0;
}

int load_records(const char *filename, Student *records, int *num_records) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Could not open file");
        return -1;
    }

    char line[MAX_LINE_LENGTH];
    *num_records = 0;

    while (fgets(line, sizeof(line), file)) {
        Student record;
        if (sscanf(line, "%49[^,],%99[^,],%99[^,],%19[^\n]",
                   record.student_id, record.name, record.email, record.dob) == 4) {
            if (validate_record(&record)) {
                records[(*num_records)++] = record;
            } else {
                fprintf(stderr, "Invalid record: %s\n", line);
            }
        } else {
            fprintf(stderr, "Malformed line: %s\n", line);
        }
    }
    fclose(file);
    return 0;
}

void *process_record(void *arg) {
    Student *record = (Student *)arg;
    FILE *file;

    pthread_mutex_lock(&file_mutex);

    file = fopen(output_file, "a");
    if (file == NULL) {
        perror("Could not open output file");
        pthread_mutex_unlock(&file_mutex);
        return NULL;
    }

    fprintf(file, "%s,%s,%s,%s\n", record->student_id, record->name, record->email, record->dob);
    fclose(file);

    pthread_mutex_unlock(&file_mutex);
    return NULL;
}
void view_processed_records() {
    FILE *file = fopen(output_file, "r");
    if (file == NULL) {
        printf("No records found.\n");
        return;
    }

    char line[MAX_LINE_LENGTH];
    printf("\nProcessed Records:\n");
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }

    fclose(file);
}
