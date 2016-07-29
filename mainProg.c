#include "busycircle_SDL.h"
#include "busycircle.h"

int mainProg(void){
    SDL_Rect renderRect;
    SDL_Renderer *renderer;
    SDL_Texture *texture;

    initResources();
    renderer = getRenderer();
    texture = getTexture();

    SDL_QueryTexture(texture, 0, 0, &(renderRect.w), &(renderRect.h));

    while(!SDL_checkQuitEvent()) {

        SDL_RenderClear(renderer);
        plotDiscs(renderer, texture, renderRect);
        SDL_RenderPresent(renderer);
        //SDL_Delay(1000/70);
    }

    return 0;
}

