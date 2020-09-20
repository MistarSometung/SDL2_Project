#ifndef _SCREEN_H_
#define _SCREEN_H_


#include <SDL2/SDL.h>
#include <stdbool.h>

extern bool run;

struct game{

    SDL_Window *window;
    SDL_Renderer *rend;
    SDL_Event e_screen;

};

void init(struct game *game);
void Input_screen(struct game *screen);
void render(struct game *game);


#endif