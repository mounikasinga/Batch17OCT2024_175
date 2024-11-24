#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct url {
    char *host;
    char *domain;
};
int isValidURL(char *url) {
    if (strncmp(url, "http://", 7) == 0) {
        return 1;
    }
    return 0;
}
char *gethost(char *url) {
    char *host_start = url + 7;
    char *host_end = strchr(host_start, '.');
    size_t len = host_end - host_start;
    char *host = malloc(len + 1);
    strncpy(host, host_start, len);
    host[len] = '\0';
    return host;
}

char *getdomain(char *url) {
    char *domain_start = strchr(url + 7, '.') + 1;
    char *domain_end = strchr(domain_start, '\0');
    size_t len = domain_end - domain_start;
    char *domain = malloc(len + 1);
    strncpy(domain, domain_start, len);
    domain[len] = '\0';
    return domain;
}

void display(struct url *obj) {
    printf("Host: %s\n", obj->host);
    printf("Domain: %s\n", obj->domain);
}
void free_url(struct url *obj) {
    free(obj->host);
    free(obj->domain);
}
int main() {
    char url[100];
    printf("Enter URL: ");
    fgets(url, sizeof(url), stdin);
    url[strcspn(url, "\n")] = '\0';
    if (isValidURL(url)) {
        struct url obj;
        obj.host = gethost(url);
        obj.domain = getdomain(url);
        display(&obj);
        free_url(&obj);
    } else {
        printf("Invalid URL.\n");
    }
    return 0;
}

