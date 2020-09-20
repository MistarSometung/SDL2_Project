#include "screen.h"


static const int height = 500;
static const int width = 700;




void init(struct game *game){

    game->window = SDL_CreateWindow("Pong", SDL_WINDOWPOS_UNDEFINED, 
    SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_OPENGL);

    game->rend = SDL_CreateRenderer(game->window, -1, 0);

}



void Input_screen(struct game *screen){
    
    while(SDL_PollEvent(&screen->e_screen))
        switch(screen->e_screen.type){
            case SDL_QUIT:
                run = false;
                break;
        }

}


void render(struct game *game){
    SDL_SetRenderDrawColor(game->rend, 0, 0, 0, 0);
    SDL_RenderClear(game->rend);
    //SDL_RenderPresent(game->rend);
}