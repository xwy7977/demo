# POSIX Thread Demo

This directory contains several example programs based on the POSIX threads (pthread) API, demonstrating common usage patterns in multithreaded programming.

## Directory Structure

- `thread-demo-1.c`: Thread creation and joining (`pthread_create`, `pthread_join`)
- `thread-demo-2.c`: Thread terminate (`pthread_exit`)
- `thread-demo-3.c`: Thread cancel (`pthread_cancel`)
- `thread-demo-4.c`: Detached threads (`pthread_detach`)
- `thread-demo-5.c`: Getting the current thread ID (`pthread_self`)
- `thread-demo-6.c`: Comparing thread IDs (`pthread_equal`)

## How to Compile

Run the following commands in this directory:

```sh
gcc thread-demo-1.c -o demo1 -lpthread
gcc thread-demo-2.c -o demo2 -lpthread
gcc thread-demo-3.c -o demo3 -lpthread
gcc thread-demo-4.c -o demo4 -lpthread
gcc thread-demo-5.c -o demo5 -lpthread
gcc thread-demo-6.c -o demo6 -lpthread
```

## Example Descriptions

### 1. thread-demo-1.c

Demonstrates how to create two threads and use `pthread_join` to wait for them to finish.

### 2. thread-demo-2.c

Demonstrates how to terminate a thread.

### 3. thread-demo-3.c

Demonstrates how to cancel a thread.

### 4. thread-demo-4.c

Demonstrates how to set a thread as detached so that its resources are automatically reclaimed after it finishes.

### 5. thread-demo-5.c

Demonstrates how to use `pthread_self` to get the current thread's ID.

### 6. thread-demo-6.c

Demonstrates how to use `pthread_equal` to compare two thread IDs.

## How to Run

After compiling, run the corresponding executable:

```sh
./demo1
./demo2
./demo3
./demo4
./demo5
./demo6
```

Each demo will output relevant information in the terminal to help you understand how pthread works.

---

For more details on each demo, please refer to the corresponding source code file.

