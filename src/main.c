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
    SpriteMap sprite_map = sprite_map_new((Word)0x4000);

    memory = memory_set(memory, 0x4000 + ('J' * 2), (Word)0x2222);
    memory = memory_set(memory, 0x4001 + ('J' * 2), (Word)0x2A40);
    memory = memory_set(memory, 0x4000 + ('o' * 2), (Word)0x0004);
    memory = memory_set(memory, 0x4001 + ('o' * 2), (Word)0xAA40);

    //pixel_display_memory_draw(pd, memory);
    pixel_display_draw_char(pd, sprite_map, memory, 'J', 0, 0);
    pixel_display_draw_char(pd, sprite_map, memory, 'o', 1, 0);

    test();

    display_destroy(display);

    return 0;
}

void test(void) {
    memory_test();
    sprite_map_test();

    printf("All tests pass :)\n");
}
