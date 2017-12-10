#include <stdio.h>
#include "Memory.h"
#include "Display.h"
#include "PixelDisplay.h"

void test(void);

int main(void) {
    Display display = display_new();
    PixelDisplay pd = pixel_display_new(display, 128, 128);

    pixel_display_draw(pd, 5, 5);

    display_destroy(display);

    test();

    return 0;
}

void test(void) {
    memory_test();

    printf("All tests pass :)\n");
}
