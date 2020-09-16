#ifndef _SCREEN_H_
#define _SCREEN_H_


#include <SDL2/SDL.h>
#include <stdbool.h>


struct game{

    SDL_Window *window;
    SDL_Renderer *rend;

};

void init(struct game *game);
void render(struct game *game);


#endif