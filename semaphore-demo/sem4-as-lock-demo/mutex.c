#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t mutex;

int global_counter = 0;

int loop_count = 1000000;

int thread_1_global_count = 0;
int thread_2_global_count = 0;

// =============================================================
// void* increment(void* arg)
// {
//     for (int i = 0; i < loop_count; i++) {
//         global_counter++;
//     }
//     thread_1_global_count = global_counter;
// }

// void* decrement(void* arg)
// {
//     for (int i = 0; i < loop_count; i++) {
//         global_counter--;
//     }
//     thread_2_global_count = global_counter;
// }

// =============================================================
// void* increment(void* arg)
// {
//     for (int i = 0; i < loop_count; i++) {
//         sem_wait(&mutex);
//         global_counter++;
//         sem_post(&mutex);
//     }
//     thread_1_global_count = global_counter;
// }

// void* decrement(void* arg)
// {
//     for (int i = 0; i < loop_count; i++) {
//         sem_wait(&mutex);
//         global_counter--;
//         sem_post(&mutex);
//     }
//     thread_2_global_count = global_counter;
// }

// =============================================================
void* increment(void* arg)
{
    sem_wait(&mutex);
    for (int i = 0; i < loop_count; i++) {
        global_counter++;
    }
    sem_post(&mutex);
    thread_1_global_count = global_counter;
}

void* decrement(void* arg)
{
    sem_wait(&mutex);
    for (int i = 0; i < loop_count; i++) {
        global_counter--;
    }
    sem_post(&mutex);
    thread_2_global_count = global_counter;
}

int main()
{
    sem_init(&mutex, 0, 1);
    pthread_t t1,t2;
    pthread_create(&t1,NULL,increment,NULL);
    pthread_create(&t2,NULL,decrement,NULL);
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    printf("Final Global Counter Value: %d\n", global_counter);
    printf("Thread 1 Global Counter Value: %d\n", thread_1_global_count);
    printf("Thread 2 Global Counter Value: %d\n", thread_2_global_count);
    sem_destroy(&mutex);
    return 0;
}