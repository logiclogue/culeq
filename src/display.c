#include <SDL2/SDL.h>
#include "display.h"

Display display_new(void) {
    Display self;

    self.width = 400;
    self.height = 400;
    self.red = 255;
    self.green = 255;
    self.blue = 255;
    self.alpha = 255;

    int x = SDL_WINDOWPOS_UNDEFINED;
    int y = SDL_WINDOWPOS_UNDEFINED;

    self.window = SDL_CreateWindow("Culeq", x, y, self.width, self.height, 0);

    SDL_Surface *surface = SDL_GetWindowSurface(self.window);

    self.renderer = SDL_CreateSoftwareRenderer(surface);

    display_clear(self);

    return self;
}

Display display_clear(Display self) {
    SDL_SetRenderDrawColor(self.renderer, 0, 0, 0, 255);
    SDL_RenderClear(self.renderer);
    SDL_UpdateWindowSurface(self.window);

    return self;
}

Display display_draw_square(Display self, int x, int y, int width, int height) {
    SDL_SetRenderDrawColor(
        self.renderer,
        self.red,
        self.green,
        self.blue,
        self.alpha);

    SDL_Rect rect;
    rect.x = x;
    rect.y = y;
    rect.w = width;
    rect.h = height;

    SDL_RenderFillRect(self.renderer, &rect);
    
    return self;
}

Display display_update(Display self) {
    SDL_UpdateWindowSurface(self.window);

    return self;
}

void display_destroy(Display self) {
    SDL_Quit();

    free(self.window);
    free(self.renderer);
}
