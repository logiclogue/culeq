#ifndef PIXEL_DISPLAY_H
#define PIXEL_DISPLAY_H

#include "display.h"
#include "sprite_map.h"
#include "memory.h"
#include "word.h"

typedef struct PixelDisplayTag PixelDisplay;

struct PixelDisplayTag {
    Display display;
    int width;
    int height;
    int pixel_width;
    int pixel_height;
};

PixelDisplay pixel_display_new(Display display, int width, int height);
void pixel_display_destroy(PixelDisplay self);
PixelDisplay pixel_display_draw(PixelDisplay self, int x, int y);
PixelDisplay pixel_display_draw_block(
    PixelDisplay self, Word b, int x_offset, int y_offset);
PixelDisplay pixel_display_draw_char(
    PixelDisplay self, SpriteMap sprite_map, Memory memory, char c, int x, int y);

#endif
