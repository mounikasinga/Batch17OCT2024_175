#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <ctype.h>
int is_palindrome = 0;
int not_palindrome = 0;
pthread_mutex_t mutex;
int is_palindrome_func(const char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1]) {
            return 0;
        }
    }
    return 1;
}
void *check_palindrome(void *arg) {
    char *input_string = (char *)arg;
    int result = is_palindrome_func(input_string);
    pthread_mutex_lock(&mutex);
    if (result) {
        is_palindrome++;
        printf("\"%s\" is a palindrome\n", input_string);
    } else {
        not_palindrome++;
        printf("\"%s\" is not a palindrome\n", input_string);
    }
    pthread_mutex_unlock(&mutex);
    return (void *)input_string;
}
int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <string1> <string2> ... <stringN>\n", argv[0]);
        return 1;
    }
    pthread_mutex_init(&mutex, NULL);
    pthread_t *threads = malloc((argc - 1) * sizeof(pthread_t));
    for (int i = 1; i < argc; i++) {
        pthread_create(&threads[i - 1], NULL, check_palindrome, (void *)argv[i]);
    }
    for (int i = 0; i < argc - 1; i++) {
        void *result;
        pthread_join(threads[i], &result);
        printf("Thread returned: \"%s\"\n", (char *)result);
    }
    printf("\nTotal Palindromes: %d\n", is_palindrome);
    printf("Total Non-Palindromes: %d\n", not_palindrome);
    free(threads);
    pthread_mutex_destroy(&mutex);
    return 0;
}

