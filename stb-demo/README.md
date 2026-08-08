# STB Demo

这是一个演示 STB（Sean T.Barrett, 一个人的名字）风格单头文件库（Single-Header Library）的例子。STB 库是一种将声明和实现放在同一个头文件中的库，通过条件编译来避免多重定义。

## 项目概述

单头文件库将函数声明和实现放在同一个 `.h` 文件中。用户只需要包含头文件，并在某个地方定义特定的宏（如 `HELLO_IMPLEMENTATION`）来包含实现。这样可以简化分发和使用。

## 文件说明

### hello.h
单头文件库的核心。包含：
- 函数声明：`void hello(const char* name);`
- 条件实现：当定义 `HELLO_IMPLEMENTATION` 时，包含函数实现。

### main.c
简单使用例子：
- 定义 `HELLO_IMPLEMENTATION` 来包含实现。
- 调用 `hello("World")`。

### multi_definition.c
演示如何在多个文件中使用单头文件库而不发生多重定义：
- 包含 `hello.h` 和 `test_multi_definition.h`。
- 调用 `hello` 和 `Hi` 函数。

### test_multi_definition.h
声明 `Hi` 函数。

### test_multi_definition.c
实现 `Hi` 函数，并定义 `HELLO_IMPLEMENTATION` 来包含 `hello` 的实现。

## 编译和运行

### 编译 main.c
```bash
gcc -o main main.c
./main
```

### 编译 multi_definition.c 和 test_multi_definition.c
```bash
gcc -o multi test_multi_definition.c multi_definition.c
./multi
```

注意：`test_multi_definition.c` 中定义了 `HELLO_IMPLEMENTATION`，所以实现只包含一次，避免多重定义错误。

## 使用方法

1. 包含头文件：`#include "hello.h"`
2. 在一个源文件中定义实现宏：`#define HELLO_IMPLEMENTATION`
3. 在其他文件中正常包含头文件即可。

这种方式确保实现只编译一次，而声明在所有需要的地方可见。

## 注意事项
- 确保只有一个源文件定义实现宏，否则会发生多重定义错误。
- STB 风格库常用于小型库，简化依赖管理。