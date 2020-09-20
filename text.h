#ifndef _TEXT_H
#define _TEXT_H_



#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL.h>

struct txt_ttf{
    SDL_Color txtcolor;
    TTF_Font *font;
    SDL_Surface *msg_surface;
    SDL_Texture *texture;
    SDL_Rect txtrect;
    
};

void ttf_init(struct txt_ttf *txt_ttf, SDL_Renderer *rend, char *c_txt,
int posx, int posy, int rectH, int rectW);

void new_text(struct txt_ttf *txt, char *texto);

void text_rend(SDL_Renderer *rend, SDL_Texture *texture, const SDL_Rect *dstrect);

#endif