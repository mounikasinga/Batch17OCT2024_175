#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#define MAX_WORDS 100
#define MAX_LINE_LENGTH 1000
typedef struct {
    char *line;
    char *sorted_line;
} thread_data_t;
void sort_words(char *line) {
    char *words[MAX_WORDS];
    int word_count = 0;
    char *token = strtok(line, " ");
    while (token != NULL) {
        words[word_count++] = token;
        token = strtok(NULL, " ");
    }
    for (int i = 0; i < word_count - 1; i++) {
        for (int j = i + 1; j < word_count; j++) {
            if (strcmp(words[i], words[j]) > 0) {
                char *temp = words[i];
                words[i] = words[j];
                words[j] = temp;
            }
        }
    }
    char *sorted = (char *)malloc(MAX_LINE_LENGTH);
    sorted[0] = '\0';
    for (int i = 0; i < word_count; i++) {
        strcat(sorted, words[i]);
        if (i < word_count - 1) {
            strcat(sorted, " ");
        }
    }

    line = sorted;
}
void *sort_line(void *arg) {
    thread_data_t *data = (thread_data_t *)arg;
    sort_words(data->line);
    data->sorted_line = data->line;
    return NULL;
}
int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Please provide 3 lines as command-line arguments.\n");
        return 1;
    }
    pthread_t threads[3];
    thread_data_t thread_data[3];
    for (int i = 0; i < 3; i++) {
        thread_data[i].line = argv[i + 1];
        pthread_create(&threads[i], NULL, sort_line, (void *)&thread_data[i]);
    }
    for (int i = 0; i < 3; i++) {
        pthread_join(threads[i], NULL);
        printf("Sorted line %d: %s\n", i + 1, thread_data[i].sorted_line);
    }
    return 0;
}

