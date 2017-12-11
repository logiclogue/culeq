#include <stdio.h>
#include "memory.h"
#include "display.h"
#include "pixel_display.h"
#include "pixel_display_memory.h"
#include "memory.h"

void test(void);

int main(void) {
    Display display = display_new();
    PixelDisplay pd = pixel_display_new(display, 128, 128);
    Memory memory = memory_new();

    pixel_display_draw(pd, 5, 5);
    pixel_display_memory_draw(pd, memory);

    display_destroy(display);

    test();

    return 0;
}

void test(void) {
    memory_test();

    printf("All tests pass :)\n");
}
