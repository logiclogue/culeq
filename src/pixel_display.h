#ifndef PIXEL_DISPLAY_H
#define PIXEL_DISPLAY_H

#include "display.h"

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
PixelDisplay pixel_display_draw_block(PixelDisplay self, uint16_t b);

#endif
