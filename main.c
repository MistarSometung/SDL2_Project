#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL.h>

#include "hero.h"
#include "screen.h"


bool run = true;


int main(int argc, char *argv[]){

    struct game game;
    struct hero hero;
    
    //Initializations 
    SDL_Init(SDL_INIT_VIDEO);
    init(&game);
    hero_init(&hero);


    while(run){
        //input
        //Hero_Input();
        hero_input(&hero);
        // Render
        render(&game);
        
        hero_rend(&hero, game.rend);

        SDL_RenderPresent(game.rend);

        SDL_Delay(10);
        
    }
    
    return 0;
}