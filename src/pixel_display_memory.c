#include "pixel_display_memory.h"
#include "pixel_display.h"
#include "memory.h"
#include <assert.h>

PixelDisplay pixel_display_memory_draw(PixelDisplay self, Memory memory) {
    for (int x = 0; x < self.width; x += 1) {
        for (int y = 0; y < self.height; y += 1) {
            if (memory_get(memory, (x * self.width) + y) & 1) {
                pixel_display_draw(self, x, y);
            }
        }
    }

    return self;
}

void pixel_display_memory_test(void) {
    assert(0);
}
