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
