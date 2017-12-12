#include <inttypes.h>
#include "pixel_display.h"
#include "display.h"

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
    display_draw_square(
        self.display,
        x * self.pixel_width,
        y * self.pixel_height,
        self.pixel_width,
        self.pixel_height);

    return self;
}

PixelDisplay pixel_display_draw_block(
    PixelDisplay self, uint16_t b, int x_offset, int y_offset) {
    int x, y, i;

    for (y = 0; y < 4; y += 1) {
        for (x = 0; x < 4; x += 1) {
            i = (y * 4) + x;
            
            if (b & (0x8000 >> i)) {
                pixel_display_draw(self, x + x_offset, y + y_offset);
            }
        }
    }

    return self;
}
