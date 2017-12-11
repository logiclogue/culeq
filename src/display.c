#include <SDL2/SDL.h>
#include "display.h"

Display display_new(void) {
    Display self;

    self.width = 200;
    self.height = 200;

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
    SDL_SetRenderDrawColor(self.renderer, 255, 255, 255, 255);

    SDL_Rect rect;
    rect.x = x;
    rect.y = y;
    rect.w = width;
    rect.h = height;

    SDL_RenderFillRect(self.renderer, &rect);
    SDL_UpdateWindowSurface(self.window);
    
    return self;
}

void display_destroy(Display self) {
    SDL_Delay(5000);
    SDL_Quit();

    free(self.window);
    free(self.renderer);
}
