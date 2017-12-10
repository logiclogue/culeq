#include <SDL2/SDL.h>
#include "Display.h"

Display display_new(void) {
    Display self;

    self.width = 200;
    self.height = 200;

    int x = SDL_WINDOWPOS_UNDEFINED;
    int y = SDL_WINDOWPOS_UNDEFINED;

    self.window = SDL_CreateWindow("Culeq", x, y, self.width, self.height, 0);

    SDL_Surface *surface = SDL_GetWindowSurface(self.window);

    self.renderer = SDL_CreateSoftwareRenderer(surface);

    return self;
}

void display_destroy(Display self) {
    SDL_Delay(5000);
    SDL_Quit();

    free(self.window);
    free(self.renderer);
}
