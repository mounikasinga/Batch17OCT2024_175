#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <stdbool.h>
#include <pthread.h>
#define PORT 2222

void LOG(int level, const char *msg);
void sendToClient(int client_socket, const char *message);
void processCommand(int client_socket);
void processIncomingCall(int client_socket);
void ViewFile(int client_socket, const char *phone_number, char choice, char global, char num_groups[]);
void ModifyClientDataFile(int client_socket, FILE *file, int len, const char *stored_choice, const char *phone_number, char choice, char global, char num_groups[]);
void warningToClient(int client_socket, const char *stored_choice, char choice);
void newClient(FILE *file, int client_socket, const char *phone_number, char choice, char global, char num_groups[]);

