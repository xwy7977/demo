#include <stdio.h>
#include "globals.h"

int main() {
    // Print the values of the global variables
    printf("Value of var1: %d\n", var1);
    printf("Value of var2: %.2f\n", var2);
    printf("Value of var3: %c\n", var3);

    return 0;
}