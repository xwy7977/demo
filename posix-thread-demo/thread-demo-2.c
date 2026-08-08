#include <pthread.h>
#include <stdio.h>

/*
 * pthread_exit() function allows a thread to terminate its execution explicitly.
 * pthread_exit is called when a thread needs to terminate its execution and
 * optionally return a value to threads that are waiting for it.
 */

void* foo(void* arg) {
    printf("Thread is running.\n");
    
    // Explicity terminate the thread
    pthread_exit(NULL);
    
    printf("This will not be executed\n");
    
    return NULL;
}

int main() {
    pthread_t thread;
    pthread_create(&thread, NULL, foo, NULL);
    pthread_join(thread, NULL);
    return 0;
}