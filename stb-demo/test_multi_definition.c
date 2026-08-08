#define HELLO_IMPLEMENTATION
#include "hello.h"
#include "test_multi_definition.h"

void Hi() {
    hello("Multi-definition");
}