#include <stdio.h>
#include "Memory.h"

void test(void);

int main(void) {
    test();

    return 0;
}

void test(void) {
    memory_test();

    printf("All tests pass :)\n");
}
