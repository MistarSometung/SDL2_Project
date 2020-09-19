#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL.h>

struct txt_ttf{
    SDL_Color txtcolor;
    TTF_Font *font;
    SDL_Surface *msg_surface;
    SDL_Texture *texture;
    SDL_Rect txtrect;
    
};

void ttf_init(struct txt_ttf *txt_ttf, SDL_Renderer *rend, char *c_txt);
void text_rend(SDL_Renderer *rend, SDL_Texture *texture, const SDL_Rect *dstrect);