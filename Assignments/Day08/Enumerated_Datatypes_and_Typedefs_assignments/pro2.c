#include <stdio.h>
#include <string.h>

typedef struct {
    char host[100];
    int port;
    char username[50];
    char password[50];
    int timeout;
    int ssh_enabled;
} PuttyServerConfig;

int main() {
    PuttyServerConfig config;
    strcpy(config.host, "192.168.1.100");
    config.port = 22;
    strcpy(config.username, "admin");
    strcpy(config.password, "password123");
    config.timeout = 300; 
    config.ssh_enabled = 1; 
    printf("Putty Server Configuration:\n");
    printf("Host: %s\n", config.host);
    printf("Port: %d\n", config.port);
    printf("Username: %s\n", config.username);
    printf("Password: %s\n", config.password);
    printf("Timeout: %d seconds\n", config.timeout);
    printf("SSH Enabled: %s\n", config.ssh_enabled ? "Yes" : "No");
    return 0;
}

