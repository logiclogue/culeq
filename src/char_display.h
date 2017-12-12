#ifndef CHAR_DISPLAY_H
#define CHAR_DISPLAY_H

typedef struct CharDisplayTag CharDisplay;

struct CharDisplayTag {
    PixelDisplay pixel_display;
    int width;
    int height;
};

#endif
