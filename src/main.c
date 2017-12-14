#include <stdio.h>
#include "memory.h"
#include "display.h"
#include "pixel_display.h"
#include "pixel_display_memory.h"
#include "memory.h"
#include "sprite_map.h"
#include "char_map.h"
#include "memory_map.h"
#include "word_colour.h"
#include "word_char.h"

void test(void);

int main(void) {
    Display display = display_new();
    PixelDisplay pd = pixel_display_new(display, 64, 48);
    Memory memory = memory_new();
    CharMap char_map = char_map_new((Word)0x3900, 16, 6);
    SpriteMap sprite_map = sprite_map_new((Word)0x4000);
    MemoryMap colour_map = memory_map_new((Word)0x3500);

    memory = memory_set(memory, 0x4000 + ('J' * 2), (Word)0x2222);
    memory = memory_set(memory, 0x4001 + ('J' * 2), (Word)0x2A40);
    memory = memory_set(memory, 0x4000 + ('o' * 2), (Word)0x0004);
    memory = memory_set(memory, 0x4001 + ('o' * 2), (Word)0xAA40);
    memory = memory_set(memory, 0x3900, 0x1600 + 'J');
    memory = memory_set(memory, 0x3901, 0x1600 + 'o');
    memory = memory_set(memory, 0x3902, 0x1600 + 'r');
    memory = memory_set(memory, 0x3903, 0x1600 + 'd');
    memory = memory_set(memory, 0x3904, 0x1600 + 'a');
    memory = memory_set(memory, 0x3905, 0x1600 + 'n');
    memory = memory_set(memory, 0x3500, (Word)0x0000);
    memory = memory_set(memory, 0x3501, (Word)0xFFF0);
    memory = memory_set(memory, 0x3502, (Word)0xF000);
    memory = memory_set(memory, 0x3503, (Word)0x0F00);
    memory = memory_set(memory, 0x3504, (Word)0x00F0);
    memory = memory_set(memory, 0x3505, (Word)0xFF00);
    memory = memory_set(memory, 0x3506, (Word)0xF0F0);
    memory = memory_set(memory, 0x3507, (Word)0x0FF0);

    int x, y;
    Word current_word;
    int foreground_colour, background_colour;

    test();

    SDL_Event e;

    for (;;) {
        SDL_PollEvent(&e);

        if (e.type == SDL_QUIT) {
            break;
        } else if (e.type == SDL_WINDOWEVENT
            && e.window.event == SDL_WINDOWEVENT_RESIZED) {

            display.width = e.window.data1;
            display.height = e.window.data2;

            pd = pixel_display_resize(pd, display);
        }

        for (x = 0; x < char_map.width; x += 1) {
            for (y = 0; y < char_map.height; y += 1) {
                current_word = char_map_get(char_map, memory, x, y);
                foreground_colour = memory_map_get(
                    colour_map, memory, word_char_foreground(current_word));
                background_colour = memory_map_get(
                    colour_map, memory, word_char_background(current_word));

                pd = pixel_display_draw_char(
                    pd, sprite_map, memory,
                    word_char(current_word), x, y,
                    foreground_colour, background_colour);
            }
        }

        pd.display = display_update(pd.display);
    }

    display_destroy(display);

    return 0;
}

void test(void) {
    memory_test();
    sprite_map_test();
    char_map_test();
    memory_map_test();
    word_colour_test();
    word_char_test();

    printf("All tests pass :)\n");
}
