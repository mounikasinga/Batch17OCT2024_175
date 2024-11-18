#include<common.h>
#include<student.h>
void display_menu();
const char *output_file = "processed_records.txt";
int main() {
    int choice;
    char filename[MAX_LINE_LENGTH];
    Student records[1000];
    int num_records = 0;
    pthread_t threads[MAX_THREADS];
    int active_threads = 0;

    pthread_mutex_init(&file_mutex, NULL);

    while (1) {
        display_menu();
        scanf("%d", &choice); 
        getchar(); 

        switch (choice) {
            case 1: 
                printf("Enter the CSV file path: ");
                fgets(filename, sizeof(filename), stdin);
                filename[strcspn(filename, "\n")] = '\0'; 

                if (load_records(filename, records, &num_records) != 0) {
                    fprintf(stderr, "Failed to load records\n");
                    break;
                }

                FILE *file = fopen(output_file, "w");
                if (file != NULL) fclose(file);

                active_threads = 0;
                for (int i = 0; i < num_records; i++) {
                    if (pthread_create(&threads[active_threads], NULL, process_record, &records[i]) != 0) {
                        fprintf(stderr, "Error creating thread for record %s\n", records[i].student_id);
                    } else {
                        active_threads++;
                    }

                  
                    if (active_threads >= MAX_THREADS || i == num_records - 1) {
                        for (int j = 0; j < active_threads; j++) {
                            pthread_join(threads[j], NULL);
                        }
                        active_threads = 0; 
                    }
                }
                printf("CSV file processed successfully.\n");
                break;

            case 2: 
                view_processed_records();
                break;

            case 3:
                printf("Exiting the program.\n");
                pthread_mutex_destroy(&file_mutex); 
                return EXIT_SUCCESS;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return EXIT_SUCCESS;

}

void display_menu() {
    printf("\nMenu:\n");
    printf("1. Load and validate CSV file\n");
    printf("2. View processed records\n");
    printf("3. Exit\n");
    printf("Choose an option: ");
}
