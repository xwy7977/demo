# Mutex Demo

这是一个演示互斥锁（Mutex）在多线程编程中使用的例子。互斥锁用于保护共享资源，避免数据竞争（data race）。

## 文件说明

### no-mutex.c
演示不使用互斥锁时发生数据竞争的情况。两个线程同时对共享变量 `counter` 进行增减操作，由于操作不是原子的，最终结果可能不是期望的 0。

### mutex.c
演示使用互斥锁保护共享变量。两个线程在访问 `counter` 时使用 `pthread_mutex_lock` 和 `pthread_mutex_unlock` 来确保原子性，最终结果为 0。

### mutex-type-normal.c
演示普通类型互斥锁（PTHREAD_MUTEX_NORMAL）。第二次尝试锁定同一个互斥锁会导致死锁。

### mutex-type-errorcheck.c
演示错误检查类型互斥锁（PTHREAD_MUTEX_ERRORCHECK）。可以检测死锁并返回错误码 `EDEADLK`。

### mutex-type-recursive.c
演示递归类型互斥锁（PTHREAD_MUTEX_RECURSIVE）。允许同一线程多次锁定互斥锁，而不会死锁。

### mutex-type-trylock.c
演示使用 `pthread_mutex_trylock` 非阻塞尝试锁定。如果锁已被占用，返回 `EBUSY` 而不是阻塞。

## 编译和运行

使用 GCC 编译这些 C 文件。例如：

```bash
gcc -o no-mutex no-mutex.c -lpthread
gcc -o mutex mutex.c -lpthread
gcc -o mutex-type-normal mutex-type-normal.c -lpthread
gcc -o mutex-type-errorcheck mutex-type-errorcheck.c -lpthread
gcc -o mutex-type-recursive mutex-type-recursive.c -lpthread
gcc -o mutex-type-trylock mutex-type-trylock.c -lpthread
```

然后运行可执行文件：

```bash
./no-mutex
./mutex
./mutex-type-normal
./mutex-type-errorcheck
./mutex-type-recursive
./mutex-type-trylock
```

## 注意事项
- 这些例子使用了 POSIX 线程库（pthread），需要在支持 pthread 的系统上运行。
- `no-mutex.c` 的结果每次运行可能不同，取决于线程调度。
- 互斥锁类型会影响锁定行为，选择合适的类型很重要。