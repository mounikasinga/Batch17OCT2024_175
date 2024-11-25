#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <ctype.h>
int validmail_count = 0;
pthread_mutex_t mutex;
int validate_email(const char *email) {
    char username[256], domain[256];
    if (sscanf(email, "%255[^@]@%255s", username, domain) != 2) {
        return 0;
    }
    if (!isalpha(username[0])) {
        return 0;
    }
    if (strcmp(domain + strlen(domain) - 4, ".com") != 0 && strcmp(domain + strlen(domain) - 4, ".edu") != 0) {
        return 0;
    }
    return 1;
}
void *validate_email_thread(void *arg) {
    char *email = (char *)arg;
    int result = validate_email(email);
    pthread_mutex_lock(&mutex);
    if (result) {
        validmail_count++;
        printf("Valid email: %s\n", email);
    } else {
        printf("Invalid email: %s\n", email);
    }
    pthread_mutex_unlock(&mutex);
    return result ? email : NULL;
}
int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <email1;email2;...;emailN>\n", argv[0]);
        return 1;
    }
    pthread_mutex_init(&mutex, NULL);
    char *email_list = argv[1];
    char *email = strtok(email_list, ";");
    pthread_t *threads = malloc(256 * sizeof(pthread_t));
    int thread_count = 0;
    while (email != NULL) {
        pthread_create(&threads[thread_count], NULL, validate_email_thread, (void *)email);
        email = strtok(NULL, ";");
        thread_count++;
    }
    for (int i = 0; i < thread_count; i++) {
        void *result;
        pthread_join(threads[i], &result);
        if (result != NULL) {
            printf("Thread returned: %s\n", (char *)result);
        }
    }
    printf("\nTotal valid emails: %d\n", validmail_count);
    free(threads);
    pthread_mutex_destroy(&mutex);
    return 0;
}

