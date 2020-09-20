#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <SDL2/SDL.h>

#include "hero.h"
#include "screen.h"
#include "text.h"
#include "connect.h"
#include "ball.h"

#include "placar.h"


bool run = true;
bool new_player = false;
bool ball = false;
char ball_posx = 0;


char *val;

int command = 0;
char strgo[12];


int main(int argc, char *argv[]){

    struct game game;
    struct ball b;
    struct hero hero[2];

    //Initializations 
    SDL_Init(SDL_INIT_VIDEO);
    init(&game);
    init_hero(&hero[0]);

    init_ball(&b);

    init_conn();

    while(run){

        render(&game);
        hero_rend(&hero[0], game.rend);


        //Input
        hero_input(&hero[0]);
        
        //Server
        if (connected == 1){
            //printf("Conectado mesmo");
            sprintf(strgo, "%d", command);
            listening(&b, strgo);
            
            ball_behavior(&b);
            printf("Direção: %d\n", b.direction);
            printf("b->bball.x: %d\n", b.bball.x);
            printf("Comando: %d\n", command);
            
        }

        ball_render(&b, game.rend);

        //Present
        //SDL_RenderPresent(game.rend);
        SDL_RenderPresent(game.rend);

        //Delay
        SDL_Delay(10);
        
    }
    
    return 0;
}