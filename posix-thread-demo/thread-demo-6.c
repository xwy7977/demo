#include <pthread.h>
#include <stdio.h>

/*
 * pthread_equal() function is used to compare two thread IDs to determine if they refer to the same thread.
 * It returns a non-zero value if the threads are equal, and zero if they are not.
 */

void* myThreadFunc(void* arg) {
    pthread_t threadId = pthread_self();  // Get the current thread ID
    printf("ID of Current thread: %lu\n", (unsigned long)threadId);
    return NULL;
}

int main() {
    pthread_t thread1, thread2;
    
    // Creating the threads
    pthread_create(&thread1, NULL, myThreadFunc, NULL);
    pthread_create(&thread2, NULL, myThreadFunc, NULL);

    // Joining the threads
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    if (pthread_equal(thread1, thread2)) {
        printf("The threads are the same.\n");
    } else {
        printf("The threads are different.\n");
    }

    return 0;
}