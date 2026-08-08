#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*
 * pthread_detach() function is used to detach a thread from the calling thread.
 * Once a thread is detached, it cannot be joined, and its resources will be
 * automatically released when the thread terminates. Detaching a thread is useful
 * when you want the system to handle resource deallocation without waiting for
 * the thread to complete
 */

void* myThreadFunc(void* arg) {
    printf("Thread1 is running...\n");
    sleep(2);
    printf("Thread1 finished.\n");
    return NULL;
}

int main() {
    pthread_t thread1;
    pthread_create(&thread1, NULL, myThreadFunc, NULL);

    // Detach the thread so that its resources will be automatically cleaned up
    pthread_detach(thread1);

    // Main thread continues without waiting for the detached thread
    printf("Main thread continues...\n");

    // Sleep to allow detached thread to finish
    sleep(3);
    return 0;
}