#ifndef HELLO_H
#define HELLO_H
#include <stdio.h>

void hello(const char* name);

#if defined(HELLO_IMPLEMENTATION)
void hello(const char* name) {
    printf("Hello, %s!\n", name);
}
#endif // HELLO_IMPLEMENTATION

#endif // HELLO_H