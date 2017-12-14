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
    memory = memory_set(memory, 0x3900, 'J');
    memory = memory_set(memory, 0x3901, 'o');
    memory = memory_set(memory, 0x3902, 'r');
    memory = memory_set(memory, 0x3903, 'd');
    memory = memory_set(memory, 0x3904, 'a');
    memory = memory_set(memory, 0x3905, 'n');

    int x, y;
    Word current_word;
    int foreground_colour, background_colour;

    test();

    SDL_Event e;

    for (;;) {
        SDL_PollEvent(&e);

        if (e.type == SDL_QUIT) {
            break;
        } else if (e.type == SDL_WINDOWEVENT && e.window.event == SDL_WINDOWEVENT_RESIZED) {
            printf("RESIZE\n");
        } else {
            for (x = 0; x < char_map.width; x += 1) {
                for (y = 0; y < char_map.height; y += 1) {
                    current_word = char_map_get(char_map, memory, x, y);
                    foreground_colour = memory_map_get(
                        colour_map, memory, word_char_foreground(current_word));
                    background_colour = memory_map_get(
                        colour_map, memory, word_char_background(current_word));

                    pixel_display_draw_char(
                        pd, sprite_map, memory,
                        word_char(current_word), x, y,
                        foreground_colour, background_colour);
                }
            }

            display_update(pd.display);
        }
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
