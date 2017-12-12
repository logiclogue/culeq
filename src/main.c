#include <stdio.h>
#include "memory.h"
#include "display.h"
#include "pixel_display.h"
#include "pixel_display_memory.h"
#include "memory.h"
#include "sprite_map.h"

void test(void);

int main(void) {
    Display display = display_new();
    PixelDisplay pd = pixel_display_new(display, 64, 64);
    Memory memory = memory_new();

    //pixel_display_memory_draw(pd, memory);
    pixel_display_draw_block(pd, 0x2222, 0, 0);
    pixel_display_draw_block(pd, 0x2A40, 0, 4);

    test();

    display_destroy(display);

    return 0;
}

void test(void) {
    memory_test();
    sprite_map_test();

    printf("All tests pass :)\n");
}
