#ifndef _BALL_H_
#define _BALL_H_


#include <SDL2/SDL.h>


extern int command;

struct ball{

    SDL_Rect bball;
    SDL_Point vel;
    int direction;

};

void init_ball(struct ball *ball);
void ball_render(struct ball *ball, SDL_Renderer *rend);
void ball_behavior(struct ball *ball);


#endif