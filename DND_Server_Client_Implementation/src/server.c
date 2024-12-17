#include"server.h"
#define BUFFER_SIZE 1024  /* Define buffer size for reading data*/
/* Log level definitions*/
#define LOG_LEVEL_FATAL 0
#define LOG_LEVEL_INFO 1
#define LOG_LEVEL_WARNING 2
#define LOG_LEVEL_DEBUG 3
/* Array for log levels to print readable log messages*/
const char *log_levels[] = {
    "FATAL",                     /* Fatal errors, program should exit*/
    "INFO",                      /* General info about program execution*/
    "WARNING",                   /* Warnings that indicate potential issues*/
    "DEBUG"                      /* Detailed debug messages*/
};

/*************************************************************************************************************************************************
*Function Name:LOG                                                                                                                               *
*Description:Logs a message with a specified severity level, printing it to the console if the level is greater than or equal to LOG_LEVEL_INFO. *
*Return Type:void                                                                                                                                *
**************************************************************************************************************************************************/

void LOG(int level, const char *msg) {
    if (level >= LOG_LEVEL_INFO) {
        printf("[%s] %s", log_levels[level], msg); 
    }
}

/**************************************************************************************************************************************
*Function Name:processClient                                                                                                          *
*Description:Processes a client connection by handling the client socket and executing relevant commands before closing the socket.   *
*Return Type:void* (Returns NULL after completing the client processing).                                                             *
***************************************************************************************************************************************/


void *processClient(void *client_socket_ptr) {
    int client_socket = *((int *)client_socket_ptr);
    free(client_socket_ptr);
    processCommand(client_socket);
    close(client_socket);
    return NULL;
}

/*****************************************************************************************************************************************************
*Function Name:main                                                                                                                                  *
*Description:Sets up and runs a server that listens for incoming client connections, accepts them, and creates a new thread to process each client.  *
*Return Type:int (Returns 0 upon successful execution).                                                                                              *
******************************************************************************************************************************************************/

int main() {
    int server_socket;
    struct sockaddr_in server_address, client_address;
    socklen_t addrlen = sizeof(client_address);
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        LOG(LOG_LEVEL_FATAL,"Socket Failed!\n");
        exit(EXIT_FAILURE);
    }

    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        LOG(LOG_LEVEL_FATAL,"Bind Failed!\n");
        exit(EXIT_FAILURE);
    }

    if (listen(server_socket, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d...\n", PORT);

    while (1) {
        int *client_socket = malloc(sizeof(int));
        if (!client_socket) {
            LOG(LOG_LEVEL_FATAL, "Memory Allocation Failed!\n");
            exit(EXIT_FAILURE);
        }

        *client_socket = accept(server_socket, (struct sockaddr *)&client_address, &addrlen);
        if (*client_socket < 0) {
            LOG(LOG_LEVEL_FATAL,"Accept Error!\n");
            free(client_socket);
            exit(EXIT_FAILURE);
        }
        pthread_t thread_id;
        if (pthread_create(&thread_id, NULL, processClient, client_socket) != 0) {
            LOG(LOG_LEVEL_FATAL,"Thread Creation Failed!\n");
            free(client_socket);
            exit(EXIT_FAILURE);
        }
        pthread_detach(thread_id);
    }

    return 0;
}

/************************************************************************************
*Function Name:sendToClient                                                         *
*Description:Sends a message to the specified client socket.                        *
*Return Type:void                                                                   *
*************************************************************************************/

void sendToClient(int client_socket, const char *message) {
    send(client_socket, message, strlen(message),0);
}

/*******************************************************************************************************************************
*Function Name:processCommand                                                                                                  *
*Description:Reads and processes the command from the client, handles incoming calls, retrieves phone number and other data,   *
 and performs actions based on the client's choice.                                                                            *
*Return Type:void                                                                                                              *
********************************************************************************************************************************/

void processCommand(int client_socket) {
    char phone_number[15];
    char choice;
    char num_groups[50] = "NA";
    char global = '-';
    ssize_t bytes_read = read(client_socket, &choice, sizeof(choice));

    if (bytes_read <= 0) {
        LOG(LOG_LEVEL_WARNING, "Error reading choice from client.\n");
        return;
    }

    if (choice == 'M') {
        processIncomingCall(client_socket);
    } else {
        bytes_read = read(client_socket, phone_number, sizeof(phone_number));
        if (bytes_read <= 0) {
            LOG(LOG_LEVEL_WARNING, "Error reading phone number from client.\n");
            return;
        }

        if (choice == 'A') {
            read(client_socket, &global, sizeof(global));
        }
        if (choice == 'A' && global == 'S') {
            read(client_socket, &num_groups, sizeof(num_groups));
        }
        ViewFile(client_socket, phone_number, choice, global, num_groups);
    }
    sendToClient(client_socket, "\nReady for next action...\n");
}

/*********************************************************************************************************************************
*Function Name:processIncomingCall                                                                                               *
*Description:Handles an incoming call by checking the recipient's DND (Do Not Disturb) status and determining whether the call   *
should be blocked or allowed based on global and selective DND settings.                                                         *
*Return Type:void                                                                                                                *
**********************************************************************************************************************************/

void processIncomingCall(int client_socket) {
    char caller_number[15], recipient_number[15];
    ssize_t bytes_read = read(client_socket, caller_number, sizeof(caller_number));
    if (bytes_read <= 0) {
        LOG(LOG_LEVEL_WARNING, "Error reading caller phone number from client.\n");
        return;
    }

    bytes_read = read(client_socket, recipient_number, sizeof(recipient_number));
    if (bytes_read <= 0) {
        LOG(LOG_LEVEL_WARNING, "Error reading recipient phone number from client.\n");
        return;
    }
    FILE *file = fopen("data.txt", "r");
    if (!file) {
        LOG(LOG_LEVEL_FATAL, "Error opening file!\n");
	  exit(1);
    }

    char line[256];
    char stored_phone_number[15], stored_choice, stored_global, stored_blocked[BUFFER_SIZE];
    bool isRecipientFound = false;

    while (fgets(line, sizeof(line), file)) {
        sscanf(line, "%15[^,],%c,%c,%s", stored_phone_number, &stored_choice, &stored_global, stored_blocked);

        if (strcmp(stored_phone_number, recipient_number) == 0) {
            isRecipientFound = true;

            if (stored_choice == 'A') {
                if (stored_global == 'G') {
                    sendToClient(client_socket, "Recipient is in global DND mode.All Calls blocked.");
                } else if (stored_global == 'S') {
                    if (strstr(stored_blocked, caller_number)) {
                        sendToClient(client_socket, "Recipient is in selective DND mode. Your number is blocked.");
                    } else {
                        sendToClient(client_socket, "Calls established.");
                    }
                }
            } else {
                sendToClient(client_socket, "Call established. Recipient is not in DND mode.");
            }

            fclose(file);
            return;
        }
    }

    if (!isRecipientFound) {
        sendToClient(client_socket, "Recipient number not registered.");
    }

    fclose(file);
}

/********************************************************************************************************************
*Function Name: ViewFile                                                                                            *
*Description:Reads and processes the client's phone number from a file, checks if the client is new or existing,    *
and either modifies their data or adds a new entry based on the client's choice.                                    *
*Return Type:Void                                                                                                   *
*********************************************************************************************************************/

void ViewFile(int client_socket, const char *phone_number, char choice, char global, char num_groups[]) {
    FILE *file;
    file = fopen("data.txt", "r+");
    if (file == NULL) {
        LOG(LOG_LEVEL_FATAL, "Error opening file!\n");
        exit(1);
    }

    bool isNewClient = true;
    rewind(file);
     char c;
    char line[256];
    while (fgets(line, sizeof(line), file)) {
        int len = strlen(line);
        char *token = strtok(line, ",");
        if (token != NULL) {
            char stored_phone_number[15];
            strcpy(stored_phone_number, token);
            if (strcmp(stored_phone_number, phone_number) == 0) {
                isNewClient = false;
                token = strtok(NULL, ",");
                if (token != NULL) {
                    c = token[0];
                    if (choice == c) {
                        warningToClient(client_socket, &c, choice);
                        break;
                    } else {
                        ModifyClientDataFile(client_socket, file, len, &c, phone_number, choice, global, num_groups);
                        break;
                    }
                }
            }
        }
    }
    if (isNewClient) {
        newClient(file, client_socket, phone_number, choice, global, num_groups);
    }
    fclose(file);
}

/********************************************************************************************************************************************************
*Function Name:ModifyClientDataFile                                                                                                                     *
*Description:Modifies the client's data in the file, updating their DND status based on the new choice and sending a corresponding message to the client.
*Return Type:void                                                                                                                                       *
********************************************************************************************************************************************************/

void ModifyClientDataFile(int client_socket, FILE *file, int len, const char *stored_choice, const char *phone_number, char choice, char global, char num_groups[]) {
    fseek(file, -len, SEEK_CUR);
    fprintf(file, "%s,%c,%c,%s\n", phone_number, choice, global, num_groups);
    fflush(file);

    if (*stored_choice == 'A') {
        LOG(LOG_LEVEL_INFO, "Previously it was activated, now it's DEACTIVATED");
        sendToClient(client_socket, "Previously it was activated, now it's DEACTIVATED");
    } else {
        LOG(LOG_LEVEL_INFO, "Previously it was deactivated, now it's ACTIVATED");
        sendToClient(client_socket, "Previously it was deactivated, now it's ACTIVATED");
    }
    printf("\n");
}

/**************************************************************************************************************************************
*Function Name:warningToClient                                                                                                        *
*Description:Sends a warning to the client if they attempt to activate or deactivate DND when it's already in the desired state.      *
*Return Type:void                                                                                                                     *
***************************************************************************************************************************************/

void warningToClient(int client_socket, const char *stored_choice, char choice) {
    if (choice == 'A' && *stored_choice == 'A') {
        LOG(LOG_LEVEL_WARNING, "Already Activated, please deactivate first.\n");
        sendToClient(client_socket, "Already Activated, please deactivate first");
    } else if (choice == 'D' && *stored_choice == 'D') {
              LOG(LOG_LEVEL_WARNING, "Already Deactivated, please activate first.\n");
        sendToClient(client_socket, "Already Deactivated, please Activate first");
    }
}

/**************************************************************************************************************************************
*Function Name:newClient                                                                                                              *
*Description:Sends a warning to the client if they attempt to activate or deactivate DND when it's already in the desired state.      *
**Return Type:void                                                                                                                    *
***************************************************************************************************************************************/

void newClient(FILE *file, int client_socket, const char *phone_number, char choice, char global, char num_groups[]) {
    fseek(file, 0, SEEK_END);
    fprintf(file, "%s,%c,%c,%s\n", phone_number, choice, global, num_groups);
    LOG(LOG_LEVEL_DEBUG, "Data entered in file successfully\n");

    if (choice == 'A') {
        LOG(LOG_LEVEL_INFO, "DND Activated Successfully");
        sendToClient(client_socket, "New User, DND Activated Successfully");
    } else if (choice == 'D') {
        LOG(LOG_LEVEL_INFO, "DND Deactivated Successfully");
        sendToClient(client_socket, "New User, DND Deactivated Successfully");
    }

    fflush(file);
}
