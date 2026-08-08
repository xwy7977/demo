#include "globals.h"

/*
 * 建议3个C文件（如`var1.c`、`var2.c`、`var3.c`）都`#include "globals.h"`头文件。
 * 这样可以确保全局变量的声明与定义一致，避免类型不匹配等问题。
 * 如果类型不匹配，编译器会报错，提示类型不一致。
 * 例如，如果下面的`var2`定义为`int`，编译器会报如下错误。
 * error: conflicting types for ‘var2’; have ‘int’
 */

float var2 = 3.14;