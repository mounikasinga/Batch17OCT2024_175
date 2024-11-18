#ifndef STUDENT_H
#define STUDENT_H
#define MAX_LINE_LENGTH 1024
#define MAX_THREADS 10
#include<common.h>
pthread_mutex_t file_mutex;
extern const char *output_file;
typedef struct {
    char student_id[50];
    char name[100];
    char email[100];
    char dob[20];
} Student;
int validate_record(const Student *record);
int load_records(const char *filename, Student *records, int *num_records);
void *process_record(void *arg);
void view_processed_records();
#endif
