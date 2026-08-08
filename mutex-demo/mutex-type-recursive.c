#include <stdio.h>
#include <pthread.h>
#include <errno.h>

int main() {
    int ret = 0;
    pthread_mutex_t mutex;
    pthread_mutexattr_t attr;
    
    pthread_mutexattr_init(&attr);
    pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_RECURSIVE); // normal mutex
    pthread_mutex_init(&mutex, &attr);
    
    if (pthread_mutex_lock(&mutex) != 0) {
        printf("The first attempt to obtain the lock failed!\n");
    }

    ret = pthread_mutex_lock(&mutex); // deadlock, below line will not be reached
    if (ret != 0) {
        printf("The second attempt to obtain the lock failed!\n");
    }
    else {
        printf("The second attempt to obtain the lock succeeded!\n");
        pthread_mutex_unlock(&mutex); // Unlock if successful
    }

    pthread_mutex_unlock(&mutex);

    pthread_mutexattr_destroy(&attr);
    pthread_mutex_destroy(&mutex);

    return 0;
}