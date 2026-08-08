#include <stdio.h>
#include <pthread.h>

int counter = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void* increment(void* arg) {
    for (int i = 0; i < 10000; i++) {
        pthread_mutex_lock(&mutex);
        counter++;
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

void* decrement(void* arg) {
    for (int i = 0; i < 10000; i++) {
        pthread_mutex_lock(&mutex);
        counter--;
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

int main() {
    pthread_t t1, t2;
    
    pthread_create(&t1, NULL, increment, NULL);
    pthread_create(&t2, NULL, decrement, NULL);
    
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    
    printf("最终结果: %d (期望值: 0)\n", counter);
    return 0;
}

/*
 * root@hcss-ecs-2dee:~/dev/mutex-demo# ./mutex 
 * 最终结果: 0 (期望值: 0)
 */
