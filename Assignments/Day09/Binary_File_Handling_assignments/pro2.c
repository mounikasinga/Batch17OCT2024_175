#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CFG 2 
#define MAX_LEN 50
typedef struct config {
    char *ipaddress;
    char name[MAX_LEN];
    unsigned short port;
} CONFIG;
CONFIG cfgarr_in[MAX_CFG];
CONFIG cfgarr_out[MAX_CFG];
int read_store_cfg(CONFIG cfgarr[]) {
    for (int i = 0; i < MAX_CFG; i++) {
        cfgarr[i].ipaddress = (char *)malloc(MAX_LEN * sizeof(char));
        if (cfgarr[i].ipaddress == NULL) {
            printf("Memory allocation failed.\n");
            return -1;
        }
        printf("Enter IP address for configuration %d: ", i + 1);
        fgets(cfgarr[i].ipaddress, MAX_LEN, stdin);
        cfgarr[i].ipaddress[strcspn(cfgarr[i].ipaddress, "\n")] = '\0';
        printf("Enter name for configuration %d: ", i + 1);
        fgets(cfgarr[i].name, MAX_LEN, stdin);
        cfgarr[i].name[strcspn(cfgarr[i].name, "\n")] = '\0';
        printf("Enter port number for configuration %d: ", i + 1);
        scanf("%hu", &cfgarr[i].port);
        getchar();
    }
    return 0;
}
void display(CONFIG cfgarr[], int count) {
    for (int i = 0; i < count; i++) {
        printf("Configuration %d:\n", i + 1);
        printf("IP Address: %s\n", cfgarr[i].ipaddress);
        printf("Name: %s\n", cfgarr[i].name);
        printf("Port: %hu\n", cfgarr[i].port);
    }
}
int main() {
    FILE *file;
    if (read_store_cfg(cfgarr_in) != 0) {
        return -1;
    }
    display(cfgarr_in, MAX_CFG);
    file = fopen("configurations.bin", "wb");
    if (file == NULL) {
        printf("File opening failed.\n");
        return -1;
    }
    for (int i = 0; i < MAX_CFG; i++) {
        fwrite(cfgarr_in[i].ipaddress, sizeof(char), strlen(cfgarr_in[i].ipaddress) + 1, file);
        fwrite(cfgarr_in[i].name, sizeof(char), strlen(cfgarr_in[i].name) + 1, file);
        fwrite(&cfgarr_in[i].port, sizeof(unsigned short), 1, file);
    }
    fclose(file);
    file = fopen("configurations.bin", "rb");
    if (file == NULL) {
        printf("File opening failed.\n");
        return -1;
    }
    for (int i = 0; i < MAX_CFG; i++) {
        cfgarr_out[i].ipaddress = (char *)malloc(MAX_LEN * sizeof(char));
        if (cfgarr_out[i].ipaddress == NULL) {
            printf("Memory allocation failed.\n");
            return -1;
        }
        fread(cfgarr_out[i].ipaddress, sizeof(char), MAX_LEN, file);
        fread(cfgarr_out[i].name, sizeof(char), MAX_LEN, file);
        fread(&cfgarr_out[i].port, sizeof(unsigned short), 1, file);
    }
    fclose(file);
    printf("\nContents read from file:\n");
    display(cfgarr_out, MAX_CFG);
    for (int i = 0; i < MAX_CFG; i++) {
        free(cfgarr_in[i].ipaddress);
        free(cfgarr_out[i].ipaddress);
    }
    return 0;
}

