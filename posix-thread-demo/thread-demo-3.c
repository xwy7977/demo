#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*
 *  pthread_cancel() function is used to request the cancellation of a thread.
 *  It sends a cancellation request to the target thread, but the actual
 *  termination depends on whether the thread is in a cancelable state and
 *  if it handles cancellation.
 */

void* myThreadFunc(void* arg) {
    while(1) {
        printf("Thread is running...\n");
        sleep(1);
    }
    return NULL;
}

int main() {
    pthread_t thread;
    pthread_create(&thread, NULL, myThreadFunc, NULL);
    sleep(5);
    //Requesting to cancel the thread after 5 seconds. 
    pthread_cancel(thread);
    // Wait for the thread to terminate
    pthread_join(thread, NULL);  

    printf("Main thread finished.\n");
    return 0;
}