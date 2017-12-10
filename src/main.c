#include <stdio.h>
#include "Memory.h"
#include "Display.h"

void test(void);

int main(void) {
    Display display = display_new();

    display = display_draw_square(display, 0, 0, 10, 10);

    display_destroy(display);

    test();

    return 0;
}

void test(void) {
    memory_test();

    printf("All tests pass :)\n");
}
