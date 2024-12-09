/*A1. Check whether a given number can be expressed as the sum of two prime number

i/p
Enter a positive integer: 34
Output
34 = 3 + 31

34 = 5 + 29
34 = 11 + 23
34 = 17 + 17
NoofWays = 4
*/


#include <stdio.h>
#include <math.h>
#include <stdbool.h>
int isPrime(int n)
{
    int i;
    if(n<=1)
        return false;
    for(i=2;i<=sqrt(n);i++)
    {
        if(n%i==0)
            return false;
    }
    return true;
}
int find_prime(int N){
    int count=0,i;
    for(i=2;i<=N/2;i++){
        if(isPrime(i)&&isPrime(N-i)){
            printf("\n%d = %d + %d",N,i,N-i);
            count++;
        }
    }
    printf("\n\nNoofWays = %d",count);
}
int main() {
    int n;
    printf("Enter a positive integer: ");
    scanf("%d",&n);
    find_prime(n);
    return 0;
}
client.h
#ifndef CLIENT_H
#define CLIENT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 5000

// Log levels
#define LOG_LEVEL_FATAL    0
#define LOG_LEVEL_INFO     1
#define LOG_LEVEL_WARNING  2
#define LOG_LEVEL_DEBUG    3

// Function to print log messages
#define LOG(level, msg) \
    do { \
        if (level <= LOG_LEVEL_DEBUG) { \
            printf("[%s] %s\n", log_levels[level], msg); \
        } \
    } while (0)

extern const char *log_levels[];

// Function declarations
void activateDND(int client_socket, char choice, char global, char *num_groups);
void deactivateDND(int client_socket);
void handleIncomingCall(int client_socket, int client_id);

#endif // CLIENT_H
___________________________________________________________
server.h
#ifndef SERVER_H
#define SERVER_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <time.h>

#define PORT 5000

// Log levels
#define LOG_LEVEL_FATAL    0
#define LOG_LEVEL_INFO     1
#define LOG_LEVEL_WARNING  2
#define LOG_LEVEL_DEBUG    3

// Function to print log messages
#define LOG(level, msg) \
    do { \
        if (level <= LOG_LEVEL_DEBUG) { \
            printf("[%s] %s\n", current_time(), log_levels[level], msg); \
        } \
    } while (0)

extern const char *log_levels[];

// Function declarations
void sendToClient(int client_socket, const char *message);
void handleIncomingCall(int client_socket, int client_id);
void updateClientDNDStatus(int client_socket, int client_id, char choice, char global, char *num_groups);
void deactivateDNDService(int client_socket, int client_id);
void processClientRequest(int client_socket);

#endif // SERVER_H
_____________________________________________
server.c


#include "server.h"

const char *log_levels[] = {
    "FATAL",
    "INFO",
    "WARNING",
    "DEBUG"
};

// Simulate a database for client DND status
typedef struct {
    int client_id;
    char current_dnd_choice;
    char current_dnd_global;
    char num_groups[50];
} Client;

Client clients[100];
int client_count = 0;

void sendToClient(int client_socket, const char *message) {
    write(client_socket, message, strlen(message) + 1);
}

void handleIncomingCall(int client_socket, int client_id) {
    for (int i = 0; i < client_count; i++) {
        if (clients[i].client_id == client_id) {
            if (clients[i].current_dnd_choice == 'A') {
                if (clients[i].current_dnd_global == 'S') {
                    // Selective DND: Check if client_id is in blocked list
                    char *blocked = clients[i].num_groups;
                    if (strstr(blocked, "123") != NULL) { // Example of blocked number checking
                        sendToClient(client_socket, "Incoming call blocked due to Selective DND.");
                        return;
                    }
                } else if (clients[i].current_dnd_global == 'G') {
                    // Global DND: Block all calls
                    sendToClient(client_socket, "Incoming call blocked due to Global DND.");
                    return;
                }
            }
        }
    }
    sendToClient(client_socket, "Incoming call allowed.");
}

void updateClientDNDStatus(int client_socket, int client_id, char choice, char global, char *num_groups) {
    for (int i = 0; i < client_count; i++) {
        if (clients[i].client_id == client_id) {
            if (clients[i].current_dnd_choice != 'D') {
                sendToClient(client_socket, "Deactivate DND first before changing service.");
                return;
            }
            clients[i].current_dnd_choice = choice;
            clients[i].current_dnd_global = global;
            strcpy(clients[i].num_groups, num_groups);
            sendToClient(client_socket, "DND service activated.");
            return;
        }
    }
    sendToClient(client_socket, "Client not found.");
}

void deactivateDNDService(int client_socket, int client_id) {
    for (int i = 0; i < client_count; i++) {
        if (clients[i].client_id == client_id) {
            clients[i].current_dnd_choice = 'D';
            clients[i].current_dnd_global = 'D';
            strcpy(clients[i].num_groups, "");
            sendToClient(client_socket, "DND service deactivated.");
            return;
        }
    }
    sendToClient(client_socket, "Client not found.");
}

void processClientRequest(int client_socket) {
    int client_id;
    char choice, global;
    char num_groups[50] = "";

    read(client_socket, &choice, sizeof(choice));
    read(client_socket, &client_id, sizeof(client_id));

    if (choice == 'A') {
        read(client_socket, &global, sizeof(global));
        if (global == 'S') {
            read(client_socket, num_groups, sizeof(num_groups));
        }
        updateClientDNDStatus(client_socket, client_id, choice, global, num_groups);
    } else if (choice == 'D') {
        deactivateDNDService(client_socket, client_id);
    } else if (choice == 'H') {
        handleIncomingCall(client_socket, client_id);
    }
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_address, client_address;
    socklen_t addrlen = sizeof(client_address);
    
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        LOG(LOG_LEVEL_FATAL, "Socket creation failed.");
        exit(EXIT_FAILURE);
    }

    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        LOG(LOG_LEVEL_FATAL, "Bind failed.");
        exit(EXIT_FAILURE);
    }

    if (listen(server_socket, 3) < 0) {
        LOG(LOG_LEVEL_FATAL, "Listen failed.");
        exit(EXIT_FAILURE);
    }

    LOG(LOG_LEVEL_INFO, "Server listening...");

    while (1) {
        if ((client_socket = accept(server_socket, (struct sockaddr *)&client_address, &addrlen)) < 0) {
            LOG(LOG_LEVEL_FATAL, "Accept failed.");
            exit(EXIT_FAILURE);
        }

        processClientRequest(client_socket);

        close(client_socket);
    }

    return 0;
}
______________________________________________________
client.c




#include "client.h"

const char *log_levels[] = {
    "FATAL",
    "INFO",
    "WARNING",
    "DEBUG"
};

void activateDND(int client_socket, char choice, char global, char *num_groups) {
    write(client_socket, &choice, sizeof(choice));
    write(client_socket, &global, sizeof(global));
    if (global == 'S') {
        write(client_socket, num_groups, strlen(num_groups) + 1);
    }
    LOG(LOG_LEVEL_INFO, "DND service requested.");
}

void deactivateDND(int client_socket) {
    char choice = 'D';
    write(client_socket, &choice, sizeof(choice));
    LOG(LOG_LEVEL_INFO, "DND deactivation requested.");
}

void handleIncomingCall(int client_socket, int client_id) {
    char choice = 'H';
    write(client_socket, &choice, sizeof(choice));
    write(client_socket, &client_id, sizeof(client_id));
    LOG(LOG_LEVEL_INFO, "Incoming call request sent.");
}

void printMenu() {
    printf("\nMenu:\n");
    printf("1) Activate DND\n");
    printf("2) Deactivate DND\n");
    printf("3) Call Handling\n");
    printf("4) Exit\n");
}

int main() {
    int client_socket;
    struct sockaddr_in server_address;
    
    // Create socket
    if ((client_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        LOG(LOG_LEVEL_FATAL, "Socket creation failed.");
        exit(EXIT_FAILURE);
    }

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    server_address.sin_addr.s_addr = INADDR_ANY;

    // Connect to server
    if (connect(client_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        LOG(LOG_LEVEL_FATAL, "Connection failed.");
        exit(EXIT_FAILURE);
    }

    int choice, client_id;
    char global, num_groups[50];

    LOG(LOG_LEVEL_INFO, "Connected to the server.");

    while (1) {
        printMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // to consume the newline character

        switch (choice) {
            case 1:  // Activate DND
                printf("Select DND type:\n");
                printf("1) Global (Block all calls)\n");
                printf("2) Selective (Block specific calls)\n");
                printf("Enter your choice: ");
                int dndChoice;
                scanf("%d", &dndChoice);
                getchar(); // to consume the newline character

                if (dndChoice == 1) {
                    global = 'G';  // Global DND
                    activateDND(client_socket, 'A', global, num_groups);
                } else if (dndChoice == 2) {
                    global = 'S';  // Selective DND
                    printf("Enter comma-separated numbers to block: ");
                    fgets(num_groups, sizeof(num_groups), stdin);
                    num_groups[strcspn(num_groups, "\n")] = '\0';  // Remove newline character
                    activateDND(client_socket, 'A', global, num_groups);
                } else {
                    printf("Invalid choice. Please try again.\n");
                }
                break;

            case 2:  // Deactivate DND
                deactivateDND(client_socket);
                break;

            case 3:  // Call Handling
                printf("Enter client ID to handle the call: ");
                scanf("%d", &client_id);
                handleIncomingCall(client_socket, client_id);
                break;

            case 4:  // Exit
                close(client_socket);
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
}



