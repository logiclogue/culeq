#include <inttypes.h>
#include "pixel_display.h"
#include "sprite_map.h"
#include "display.h"
#include "word.h"

PixelDisplay pixel_display_new(Display display, int width, int height) {
    PixelDisplay self;

    self.display = display;
    self.width = width;
    self.height = height;
    self.pixel_width = display.width / width;
    self.pixel_height = display.height / height;

    return self;
}

void pixel_display_destroy(PixelDisplay self) {
    display_destroy(self.display);
}

PixelDisplay pixel_display_draw(PixelDisplay self, int x, int y) {
    self.display = display_draw_square(
        self.display,
        x * self.pixel_width,
        y * self.pixel_height,
        self.pixel_width,
        self.pixel_height);

    return self;
}

PixelDisplay pixel_display_draw_block(
    PixelDisplay self, Word b, int x_offset, int y_offset) {
    int x, y, i;
    int block_height = WORD_BYTES * 2;

    for (y = 0; y < block_height; y += 1) {
        for (x = 0; x < 4; x += 1) {
            i = (y * 4) + x;
            
            if (b & (0x8000 >> i)) {
                pixel_display_draw(self, x + x_offset, y + y_offset);
            }
        }
    }

    return self;
}

PixelDisplay pixel_display_draw_char(
    PixelDisplay self, SpriteMap sprite_map, Memory memory, char c, int x, int y) {
    Word sprite_top = sprite_map_top_block(sprite_map, memory, c);
    Word sprite_bottom = sprite_map_bottom_block(sprite_map, memory, c);

    pixel_display_draw_block(self, sprite_top, x * 4, y * 8);
    pixel_display_draw_block(self, sprite_bottom, x * 4, (y * 8) + 4);

    return self;
}
