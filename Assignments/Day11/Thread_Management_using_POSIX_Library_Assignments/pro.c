#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
void* thread1_func(void *arg);
void* thread2_func(void *arg);
void* thread3_func(void *arg);
int main() {
    pthread_t t1, t2, t3;
    pthread_create(&t1, NULL, thread1_func, NULL);
    pthread_detach(t1);
    pthread_create(&t2, NULL, thread2_func, NULL);
    pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);
    pthread_setcanceltype(PTHREAD_CANCEL_DEFERRED, NULL);
    pthread_create(&t3, NULL, thread3_func, NULL);
    pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);
    pthread_setcanceltype(PTHREAD_CANCEL_ASYNCHRONOUS, NULL);
    sleep(180);
    pthread_cancel(t1);
    pthread_cancel(t2);
    pthread_cancel(t3);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);
    return 0;
}
void* thread1_func(void *arg) {
    while(1) {
        time_t now = time(NULL);
        printf("<%ld> T1: Health OK\n", now);
        sleep(2);
    }
}
void* thread2_func(void *arg) {
    int count = 1000;
    while(1) {
        time_t now = time(NULL);
        printf("<%ld> T2: %ld %d\n", now, pthread_self(), count);
        count += 2;
        sleep(3);
    }
}
void* thread3_func(void *arg) {
    int count = 2000;
    while(1) {
        time_t now = time(NULL);
        printf("<%ld> T3: %ld %d\n", now, pthread_self(), count);
        count += 2;
        sleep(3);
    }
}

