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
#include "colours_bin.h"
#include "sprites_bin.h"
#include "test_screen_bin.h"
#include "machine.h"

void test(void);

int main(void) {
    Display display = display_new();
    Memory memory = memory_new();
    CharMap char_map = char_map_new((Word)0xFE80, 32, 12);
    PixelDisplay pd = pixel_display_new(
        display, char_map.width * 4, char_map.height * 8);
    SpriteMap sprite_map = sprite_map_new((Word)0xFC70);
    MemoryMap colour_map = memory_map_new((Word)0xFE70);

    memory = memory_load(
        memory, sprite_map.start_address,
        (Word *)sprites_bin, sprites_bin_len);
    memory = memory_load(
        memory, colour_map.start_address,
        (Word *)colours_bin, colours_bin_len);
    printf("%x\n", char_map.start_address);
    memory = memory_load(
        memory, char_map.start_address,
        (Word *)test_screen_bin, test_screen_bin_len);

    int x, y;
    Word current_word;
    int foreground_colour, background_colour;
    Word program_counter = 0x1000;
    Word a, b, c;

    test();

    SDL_Event e;

    for (;;) {
        SDL_PollEvent(&e);

        a = memory_get(memory, program_counter);
        b = memory_get(memory, program_counter + 1);
        c = memory_get(memory, program_counter + 2);

        memory = memory_set(memory, b, memory_get(memory, b) - memory_get(memory, a));

        if (memory_get(memory, b) > 0) {
            program_counter += 3;
        } else {
            program_counter = c;
        }

        if (e.type == SDL_QUIT) {
            break;
        } else if (e.type == SDL_WINDOWEVENT
            && e.window.event == SDL_WINDOWEVENT_RESIZED) {

            pd.display = display_resize(
                pd.display, e.window.data1, e.window.data2);
            pd = pixel_display_resize(pd, pd.display);
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
    machine_test();

    printf("All tests pass :)\n");
}
