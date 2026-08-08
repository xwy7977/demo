// #define HELLO_IMPLEMENTATION // 如果打开注释，会出现多重定义的问题。
#include "hello.h"
#include "test_multi_definition.h"

int main() {
    hello("World");
    Hi();
    return 0;
}