#include <SDL2/SDL_ttf.h>
#include "text.h"

void ttf_init(struct txt_ttf *txt_ttf, SDL_Renderer *rend, char *c_txt){
    TTF_Init();

    txt_ttf->txtcolor.a = 255; txt_ttf->txtcolor.r = 255; txt_ttf->txtcolor.g = 255;
    txt_ttf->txtcolor.b = 255;

    txt_ttf->font = TTF_OpenFont("fonts/Roboto-Regular.ttf", 80);

    txt_ttf->msg_surface = TTF_RenderText_Solid(txt_ttf->font, c_txt,
    txt_ttf->txtcolor);

    txt_ttf->txtrect.h = 20;
    txt_ttf->txtrect.w = 200;
    txt_ttf->txtrect.x = 10;
    txt_ttf->txtrect.y = 10;

    txt_ttf->texture = SDL_CreateTextureFromSurface(rend, txt_ttf->msg_surface);

}

void text_rend(SDL_Renderer *rend, SDL_Texture *texture, const SDL_Rect *dstrect){
    SDL_RenderCopy(rend, texture, NULL, dstrect);
}