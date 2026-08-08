#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int counter = 0;  // 共享变量

void* increment(void* arg) {
    for (int i = 0; i < 10000000; i++) {
        counter++;  // 这不是原子操作！
    }
    return NULL;
}

void* decrement(void* arg) {
    for (int i = 0; i < 10000000; i++) {
        counter--;  // 这也不是原子操作！
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
 * root@hcss-ecs-2dee:~/dev/mutex-demo# ./no-mutex 
 * 最终结果: 1398828 (期望值: 0)
 * root@hcss-ecs-2dee:~/dev/mutex-demo# ./no-mutex 
 * 最终结果: 8404035 (期望值: 0)
 */