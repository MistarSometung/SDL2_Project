#ifndef _HERO_H_
#define _HERO_H_

#include <SDL2/SDL.h>
#include "ball.h"

extern bool run;

struct hero{
    SDL_Rect bbox;
    SDL_Point vel;
    SDL_Event ev;
    int points;
};

void init_hero(struct hero *hero);
void hero_rend(struct hero *hero, SDL_Renderer *rend);
void hero_input(struct hero *hero);
void rebater(struct hero *hero, struct ball *ball);
const char *Teste(void);

void ponto(struct hero *hero,  struct ball *ball);

#endif