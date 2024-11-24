#include "header.h"

// Main function to drive the queue operations
int main(void) {
    node *front = NULL, *rear = NULL;
    int status, value;
    char input_string[MAX_STRING_LENGTH];  // Buffer to hold user input string
    char *str = NULL;

    while (1) {
        printf("\n1.Insert\n2.Remove\n3.Display\n4.Exit\n");
        int choice;
        scanf("%d", &choice);
        getchar(); // To consume the newline character after scanf

        switch (choice) {
            case 1: // Insert a new element
                printf("Enter an integer value: ");
                scanf("%d", &value);
                getchar(); // To consume the newline character after integer input

                printf("Enter a string (max %d characters): ", MAX_STRING_LENGTH);
                fgets(input_string, sizeof(input_string), stdin);
                input_string[strcspn(input_string, "\n")] = '\0'; // Remove newline character

                enqueue(&front, &rear, value, input_string);
                break;

            case 2: // Remove an element
                status = dequeue(&front, &rear, &value, &str);
                if (status == SUCCESS) {
                    printf("Element removed: Integer = %d, String = %s\n", value, str);
                    free(str);  // Free the string memory after use
                }
                break;

            case 3: // Display the queue
                display(front);
                break;

            case 4: // Exit
                status = free_queue(front, rear);
                if (status == SUCCESS) {
                    printf("Memory freed.\n");
                } else {
                    printf("Queue was already empty.\n");
                }
                exit(0);
                break;

            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    }

    return 0;
}

