#include"client.h"
#define BUFFER_SIZE 1024
#define LOG_LEVEL_FATAL 0
#define LOG_LEVEL_INFO 1
#define LOG_LEVEL_WARNING 2
#define LOG_LEVEL_DEBUG 3

const char *log_levels[] = {
    "FATAL",
    "INFO",
    "WARNING",
    "DEBUG"
};
void LOG(int level, const char *msg) {
    if (level >= LOG_LEVEL_INFO) {
        printf("[%s] %s", log_levels[level], msg);
    }
}


void display() {
    printf("\nClient is running...\n");
    printf("************ Menu Display *********************\n");
    printf("A: Activate DND\n");
    printf("D: Deactivate DND\n");
    printf("M: Make call\n");
    printf("Q: Quit\n");
    printf("***********************************************\n");
}
int main() {
    int client_socket;
    struct sockaddr_in server_address;
    if ((client_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        LOG(LOG_LEVEL_FATAL, "Socket Creation Failed!\n");
        exit(EXIT_FAILURE);
    }
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    server_address.sin_addr.s_addr = INADDR_ANY;
    if (connect(client_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        LOG(LOG_LEVEL_FATAL, "Connection failed!\n");
        exit(EXIT_FAILURE);
    }
     char phone_number[15];
    char choice, global;
    char num_groups[100];

    LOG(LOG_LEVEL_INFO, "Connection established.\n");
    while (1) {
        display();
        scanf(" %c", &choice);
        switch (choice) {
            case 'Q':
                printf("Exiting program...\n");
                close(client_socket);
                return 0;

            case 'M': {
                char caller_number[15], recipient_number[15];
                printf("Enter your phone number (caller): ");
                scanf("%s", caller_number);
                printf("Enter recipient phone number: ");
                scanf("%s", recipient_number);

                send(client_socket, &choice, sizeof(choice),0);
                getchar();
                send(client_socket, caller_number, sizeof(caller_number),0);
                getchar();
                send(client_socket, recipient_number, sizeof(recipient_number),0);
                break;
            }

            case 'D': {
                printf("Enter Phone number to Deactivate: ");
                scanf("%s", phone_number);
                getchar();
                send(client_socket, &choice, sizeof(choice),0);
                send(client_socket, phone_number, sizeof(phone_number),0);
                getchar();
                break;
            }

            case 'A': {
                printf("Enter Phone number: ");
                scanf("%s", phone_number);
                printf("Enter S for selective & G for global:\n");
                scanf(" %c", &global);

                if (global == 'S') {
                    printf("Enter comma-separated numbers you want to block: ");
                    scanf("%49s", num_groups);
                    getchar();
                    send(client_socket, &choice, sizeof(choice),0);
                    send(client_socket, phone_number, sizeof(phone_number),0);
                    send(client_socket, &global, sizeof(global),0);
                    send(client_socket, num_groups, sizeof(num_groups),0);
                } else if (global == 'G') {
                    send(client_socket, &choice, sizeof(choice),0);
                    send(client_socket, phone_number, sizeof(phone_number),0);
                    send(client_socket, &global, sizeof(global),0);
                }
                break;
            }

            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
        ssize_t bytes_received;
        char response[BUFFER_SIZE];
        while ((bytes_received = read(client_socket, response, sizeof(response))) > 0) {
            write(STDOUT_FILENO, response, bytes_received);
            printf("\n");
        }
    }

    close(client_socket);
    return 0;
}
