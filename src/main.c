#include <stdio.h>
#include "Memory.h"
#include "Display.h"

void test(void);

int main(void) {
    Display display = display_new();

    display_destroy(display);

    test();

    return 0;
}

void test(void) {
    memory_test();

    printf("All tests pass :)\n");
}
