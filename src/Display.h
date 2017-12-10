#ifndef DISPLAY_H
#define DISPLAY_H

#include <SDL2/SDL.h>

typedef struct DisplayTag Display;

struct DisplayTag {
    int width;
    int height;
    SDL_Window *window;
    SDL_Renderer *renderer;
};

Display display_new(void);
void display_destroy(Display self);
Display display_clear(Display self);
Display display_draw_square(Display self, int x, int y, int width, int height);

#endif
