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

// O command em forma de string
char str_command[12];


int main(int argc, char *argv[]){

    struct game game;
    struct ball b;
    struct hero hero[2];

    //Initializations 
    SDL_Init(SDL_INIT_VIDEO);
    init(&game);    
    init_hero(&hero[0], false);
    init_hero(&hero[1], true);

    init_ball(&b);

    init_conn();

    while(run){

        render(&game);
        hero_rend(&hero[0], game.rend);
        hero_rend(&hero[1], game.rend);
        ball_render(&b, game.rend);

        //Input
        hero_input(&hero[0]);
        rebater(&hero[0], &b);
                
        //Server
        if (connected == 1){
            sprintf(str_command, "%d", command);
            ball_behavior_online(&b);
            send_hero_info(&hero[0]);
        }
        else
            ball_behavior(&b);
            

        

        //Present
        SDL_RenderPresent(game.rend);

        //Delay
        SDL_Delay(10);
        
    }
    
    return 0;
}