#include <SDL2/SDL.h>
#include "ball.h"
#include "connect.h"



void init_ball(struct ball *ball){
    ball->bball.h = 12;
    ball->bball.w = 12;
    ball->bball.x = 0;
    ball->bball.y = 200;

    ball->vel.x = 1;
    ball->vel.y = 1;
    int direction = 0;
    
}

void ball_behavior_online(struct ball *ball){

    ball->bball.x = get_ball_poss();

}

void ball_behavior(struct ball *ball){

    if (ball->direction == 0 && ball->bball.x < 690){
        //command = ball->direction;
        ball->bball.x += ball->vel.x;
    }
    else
        ball->direction = 1;

    if (ball->direction == 1 && ball->bball.x > 0)
        ball->bball.x -= ball->vel.x;
    else
        ball->direction = 0;


}



void ball_render(struct ball *ball, SDL_Renderer *rend){
    SDL_SetRenderDrawColor(rend, 255, 255, 255, 255);
    SDL_RenderFillRect(rend, &ball->bball);
}