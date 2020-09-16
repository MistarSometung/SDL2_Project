#ifndef _HERO_H_
#define _HERO_H_

#include <SDL2/SDL.h>

extern bool run;


struct hero{
    SDL_Rect bbox;
    SDL_Point vel;
    SDL_Event ev;
};

void hero_init(struct hero *hero);
void hero_rend(struct hero *hero, SDL_Renderer *rend);
void hero_input(struct hero *hero);
const char *Teste(void);

#endif