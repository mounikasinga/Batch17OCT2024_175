#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_EMAIL_LEN 80
char *getuser(char input[]) {
    static char username[MAX_EMAIL_LEN];
    char *atSign = strchr(input, '@');
    if (atSign != NULL) {
        size_t len = atSign - input;
        strncpy(username, input, len);
        username[len] = '\0';
        return username;
    }
    return NULL;
}
char *gethost(char input[]) {
    static char host[MAX_EMAIL_LEN];
    char *atSign = strchr(input, '@');
    if (atSign != NULL) {
        char *dot = strchr(atSign + 1, '.');
        if (dot != NULL) {
            size_t len = dot - atSign - 1;
            strncpy(host, atSign + 1, len);
            host[len] = '\0';
            return host;
        }
    }
    return NULL;  
}
char *getdomain(char input[]) {
    static char domain[MAX_EMAIL_LEN];
    char *dot = strrchr(input, '.');
    if (dot != NULL && (strcmp(dot, ".com") == 0 || strcmp(dot, ".edu") == 0)) {
        strcpy(domain, dot);  
        return domain;
    }
    return NULL;
}
int isValidDomain(char input[]) {
    char *domain = getdomain(input);
    return (domain != NULL);
}
int main() {
    char email[MAX_EMAIL_LEN];
    printf("Enter an email address (max 80 characters): ");
    fgets(email, sizeof(email), stdin);
    email[strcspn(email, "\n")] = '\0';  
    if (isValidDomain(email)) {
        printf("Valid email!\n");

        char *username = getuser(email);
        char *host = gethost(email);
        char *domain = getdomain(email);

        printf("Username: %s\n", username);
        printf("Host: %s\n", host);
        printf("Domain: %s\n", domain);
    } else {
        printf("Invalid email address.\n");
    }
    return 0;
}

