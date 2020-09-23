#include <SDL2/SDL.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "hero.h"
#include "screen.h"
#include "ball.h"
#include "connect.h"


void init_hero(struct hero *hero, bool eny){

    hero->enemy = eny;
    hero->name = "Master";

    hero->bbox.h = 100;
    hero->bbox.w = 10;

    if (hero->enemy == false)
        hero->bbox.x = 50;
    else{
        hero->bbox.x = 650;
        printf("Enemy\n");
    }

    hero->bbox.y = 0;

    hero->vel.x = 10;
    hero->vel.y = 10;

    int points = 0;

}


void rebater(struct hero *hero, struct ball *ball){
    if (SDL_HasIntersection(&hero->bbox, &ball->bball)){
        if (connected == 0)
            if (ball->direction == 0)
                ball->direction = 1;
            else
                ball->direction = 0;

        

    }
        
}

void send_hero_info(struct hero *hero){
    char x[20];
    char y[20];


    sprintf(x, "%03d", hero->bbox.x);
    sprintf(y, "%03d", hero->bbox.y);

    strcat(x,y);

    hero_action(x);

}

void ponto(struct hero *hero, struct ball *ball){
    if (SDL_HasIntersection(&hero->bbox, &ball->bball)){
        hero->points += 1;
        printf("Ponto!!\n");
    }

}



void hero_rend(struct hero *hero, SDL_Renderer *rend){

    SDL_SetRenderDrawColor(rend, 127, 0, 127, 255);
    SDL_RenderFillRect(rend, &hero->bbox);

}



void hero_input(struct hero *hero){

    while(SDL_PollEvent(&hero->ev)){
    
        switch(hero->ev.type){
            case SDL_QUIT:
                run = false;
                break;

            case SDL_KEYDOWN:
                if (hero->ev.key.keysym.sym == SDLK_RIGHT && hero->bbox.x != 600){
                    hero->bbox.x += hero->vel.x;
                    //printf("POSX: %d\n", hero->bbox.x);
                    
                }

                else if (hero->ev.key.keysym.sym == SDLK_LEFT && hero->bbox.x != 0){
                    hero->bbox.x -= hero->vel.x;
                    //printf("POSX: %d\n", hero->bbox.x);
                }

                else if (hero->ev.key.keysym.sym == SDLK_DOWN && hero->bbox.y != 400){
                    hero->bbox.y += hero->vel.y;
                    //printf("POSY: %d\n", hero->bbox.y);
                }

                else if (hero->ev.key.keysym.sym == SDLK_UP && hero->bbox.y != 0){
                    hero->bbox.y -= hero->vel.y;
                    //printf("POSY: %d\n", hero->bbox.y);
                }

        }
    }
}
