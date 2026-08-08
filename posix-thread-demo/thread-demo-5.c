#include <pthread.h>
#include <stdio.h>

/*
 * pthread_self() function returns the thread ID of the calling thread. This is
 * useful when you need to identify or store the ID of the current thread in 
 * multi-threaded programs.
 */

void* myThreadFunc(void* arg) {
    pthread_t currentThread = pthread_self();  // Get the current thread ID
    printf("Current thread ID: %lu\n", (unsigned long)currentThread);
    return NULL;
}

int main() {
    pthread_t thread1;
    pthread_create(&thread1, NULL, myThreadFunc, NULL);
    pthread_join(thread1, NULL);  // Wait for the thread to finish
    return 0;
}